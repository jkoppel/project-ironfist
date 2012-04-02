require 'dir/structure.rb'
require 'dir/ops.rb'
require 'expose/db.rb'
require 'import/db.rb'
require 'syntax/cpp.rb'

module Seance

  module Expand

    class TemplateReifier
      
      TEMPLATE_EXTENSION = ".snc"
      TEMPLATE_REGEX = /#{TEMPLATE_EXTENSION}$/

      ASM_INC_FILE = "revitalize_exports.inc"
      EXPORT_THUNK_FILE = "export_thunk.cpp"
      IMPORT_THUNK_FILE = "import_thunk.cpp"
      
      def dump_to_source_folder(name, contents)
        File.open(DirOps.file_in(@src_folder, name), "w") do |f|
          f.puts contents
        end
      end

      def template?(file)
        file =~ TEMPLATE_REGEX
      end
      
      def strip_extension(file)
        file.gsub(TEMPLATE_REGEX, '')
      end

      def export_flag_symbol(meth)
        "IMPORT_"+CppGen.to_c_name(meth).upcase
      end

      def decorated_name(meth)
        "@"+CppGen.to_c_name(meth)+"@"+(4*@fundb.get_stack_arg_names(meth).length).to_s
      end

      HEADER = <<EOF
EOF

      INDENT = "  "

      def header
        HEADER
      end
      
      def initialize(root)
        @root = root
        @templ_folder = Directory.templ_dir(root)
        @src_folder = Directory.src_dir(root)
        @fundb = Expose::FuncDB.new(@root)
        @rawfundb = Import::FuncDB.new(@root)
        @typedb = Import::TypeDB.new(@root)
        @commands = {
          "defstruct" => method(:defstruct),
          "defclass" => method(:defclass),
          "endclass" => method(:endclass),
          "methdecl" => method(:methdecl),
          "methdefn" => method(:methdefn)
        }
        @class_methdecls = Hash.new {|h,k| h[k] = [] }
        @class_methdefs = Hash.new {|h,k| h[k] = [] }
        @indentation = 0
      end

      def indent(str)
        str.gsub(/^/, INDENT * @indentation)
      end

      def put_imported_meth_defn(out, meth)
        stack_args = @fundb.get_stack_arg_names(meth)
        reg_args = @fundb.get_register_args(meth)
        
        out.puts(@fundb.get_func_decl(meth, :implicit_this => true) + " {")
        out.puts("\t__asm {")
        
        stack_args.reverse.each do |arg|
          out.puts("\t\tpush #{arg}")
        end
        
        reg_args.each do |(reg, arg)|
          out.puts("\t\tmov #{reg}, #{arg}")
        end
        
        out.puts("\t\tcall %s" % CppGen.to_c_name(meth))
        
        out.puts("\t}")
        out.puts("}\n")
      end

      def put_imported_func_defn(out, meth)
        stack_args = @fundb.get_stack_arg_names(meth)
        reg_args = @fundb.get_register_args(meth)
        
        out.puts(@fundb.get_func_decl(meth, :implicit_this => true) + " {")
        out.puts("\t__asm {")
        
        stack_args.reverse.each do |arg|
          out.puts("\t\tpush #{arg}")
        end
        
        reg_args.each do |(reg, arg)|
          out.puts("\t\tmov #{reg}, #{arg}")
        end
        
        out.puts("\t\tcall %s" % CppGen.to_c_name(meth))
        
        out.puts("\t}")
        out.puts("}\n")
      end

      def gen_import_file(imported_meths, imported_fns)
        out = File.open(DirOps.file_in(@src_folder, IMPORT_THUNK_FILE), "w")

        out.puts('extern "C" {')
        out.puts(imported_meths.map{|m| "\t%s;\n" % @fundb.get_func_decl(m, :force_cc => CppGen::STDCALL)}.join)
        out.puts(imported_fns.map{|m| "\t%s;\n" % @rawfundb.get_func_decl(m)}.join)
        out.puts("}\n")

        imported_meths.each do |meth|
          put_imported_meth_defn(out, meth)
        end

        out.close
      end


      def gen_export_thunks(exported)
        ##Assuming all are methods
        out = File.open(DirOps.file_in(@src_folder, EXPORT_THUNK_FILE), "w")

        exported.each do |meth|

          out.puts('extern "C" %s {' % @fundb.get_func_decl(meth, :force_cc => CppGen::FASTCALL))
          
          _, meth_part = Expose::FuncDB.decompose_meth(meth)

          out.puts("\t%s->%s(%s);" % [CppGen::FASTCALL_THIS,
                                      meth_part, 
                                      @fundb.get_stack_arg_names(meth).join(",")])
          out.puts("}\n")
          
        end
        
        
        out.close
      end
      
      def gen_asm_inc(exported)
        out = File.open(DirOps.file_in(@src_folder, ASM_INC_FILE), "w")

        exported.each do |meth|
          out.puts("%s EQU %s" % [CppGen.to_c_name(meth), decorated_name(meth)])
          out.puts("%s = 1" % export_flag_symbol(meth))
        end

        out.close
      end

      def gen_export_files(exported)
        gen_asm_inc(exported)
        gen_export_thunks(exported)
      end

      def gen_asm_interop
        exported = []
        imported = []

        @class_methdecls.each_key do |klass|
          exported += @class_methdefs[klass].map{|m| Seance::Expose::FuncDB.recompose_meth(klass, m)}
          imported += (@class_methdecls[klass]-@class_methdefs[klass]).map{|m| Seance::Expose::FuncDB.recompose_meth(klass, m)}
        end

        imported_funs = @rawfundb.get_fn_list - @fundb.get_fn_list

        gen_export_files(exported)
        gen_import_file(imported, imported_funs)
      end
      
      def defstruct(line)
        name = line.strip
        sc = @typedb.get_type_sc(name)
        defn = @typedb.get_type_defn(name)
        indent("#{sc} #{name}\n{#{defn}}")
      end

      def defclass(line)
        name = line.strip
        fields = @typedb.get_type_defn(name)
        res = indent("class #{name}\n{\npublic:\n#{fields}")
        @indentation += 1
        res
      end

      def endclass(line)
        @indentation -= 1
        indent("}")
      end

      def methdecl(line)
        name = line.strip
        class_name, meth_name = Seance::Expose::FuncDB.decompose_meth(name)
        @class_methdecls[class_name] << meth_name
        indent(@fundb.get_func_decl(name, :name_override => meth_name, :implicit_this => true)+";")
      end

      def methdefn(line)
        name = line.strip
        class_name, meth_name = Seance::Expose::FuncDB.decompose_meth(name)
        @class_methdefs[class_name] << meth_name
        indent(@fundb.get_func_def(name, :implicit_this => true))
      end
      
      def transform_line(line)
        md = /^#seance\s+(\w+)(.*)/.match(line)
        if md
          @commands[md[1]].call(md[2])
        else
          return line
        end
      end

      def each_template(templ_dir=@templ_folder, src_dir=@src_folder)
        dir = Dir.new(templ_dir)

        dir.each do |fname|
          if DirOps.proper_subdir?(templ_dir,fname)
            templ_subdir = DirOps.subdir(templ_dir, fname)
            src_subdir = DirOps.subdir(src_dir, fname)
            DirOps.ensure_dir(src_subdir)
            each_template(templ_subdir, src_subdir) do |orig, exported|
              yield orig, exported
            end
          elsif template? fname
            orig = DirOps.file_in(templ_dir, fname)
            exported = DirOps.file_in(src_dir, strip_extension(fname))
            yield orig, exported
          end
        end

      end

      def reify_templates
        each_template do |temfil, expfil|
          outf = File.new(expfil,"w")
          outf.puts(header)

          File.open(temfil, "r") do |inf|
            inf.each_line do |line|
              trans = transform_line(line)
              outf.puts(trans)
            end
          end
          
          outf.close
        end

        gen_asm_interop
      end
    end


    def self.reify_templates(root)
      reifier = TemplateReifier.new(root)

      reifier.reify_templates
    end
    
  end
end
