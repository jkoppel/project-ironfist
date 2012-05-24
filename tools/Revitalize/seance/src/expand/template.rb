require 'dir/structure.rb'
require 'dir/ops.rb'
require 'expose/db.rb'
require 'import/db.rb'
require 'syntax/cpp.rb'
require 'logging/msg.rb'

module Seance

  module Expand

    class TemplateException < Exception
    end

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

      def asm_name(meth)
        meth+"_asm"
      end
      
      def export_flag_symbol(meth)
        "IMPORT_"+CppGen.to_c_name(meth).upcase
      end

      def methsig(meth)
        @fundb.get_func(meth)
      end

      def funsig(fn)
        @rawfundb.get_func(fn)
      end

      def decorated_name(meth)
        "@"+CppGen.to_c_name(meth)+"@"+methsig(meth).arg_size(CppGen::FASTCALL).to_s
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
          "methdefn" => method(:methdefn),
          "funimport" => method(:funimport),
          "custom-export" => method(:custom_export),
        }
        @class_methdecls = Hash.new {|h,k| h[k] = [] }
        @class_methdefs = Hash.new {|h,k| h[k] = [] }
        @fns_to_import = {}
        @custom_exports = []
        @indentation = 0
      end

      def indent(str)
        str.gsub(/^/, INDENT * @indentation)
      end

      def put_imported_fun_defn(out, fn, is_method)
        if not is_method
          fn = fn.to_function_sig
        end

        stack_args = fn.stack_arg_names
        reg_args = fn.register_args
        
        out.puts(fn.gen_decl(:implicit_this => is_method) + " {")
        out.puts("\t__asm {")
        
        stack_args.reverse.each do |arg|
          out.puts("\t\tpush #{arg}")
        end
        
        reg_args.each do |(reg, arg)|
          out.puts("\t\tmov #{reg}, #{arg}")
        end
        
        if is_method
          out.puts("\t\tcall %s" % CppGen.to_c_name(fn.name))
        else
          out.puts("\t\tcall %s" % asm_name(CppGen.to_c_name(fn.name)))
        end
        out.puts("\t\tadd esp, %d" % fn.esp_diff)
        
        out.puts("\t}")
        out.puts("}\n")
      end

      def gen_import_file(imported_meths, imported_fns)
        out = File.open(DirOps.file_in(@src_folder, IMPORT_THUNK_FILE), "w")

        out.puts('extern "C" {')

        imported_meths.each do |m|
          out.puts("\t%s %s();" % [m.type, CppGen.to_c_name(m.name)])
        end

        out.puts("");

        imported_fns.each do |fn|
          out.puts("\t%s %s();" % [fn.type, asm_name(CppGen.to_c_name(fn.name))])
        end

        out.puts("}\n")

        imported_meths.each do |m|
          put_imported_fun_defn(out, m, true)
        end

        imported_fns.each do |m|
          put_imported_fun_defn(out, m, false)
        end

        out.close
      end


      def gen_export_thunks(exported)
        ##Assuming all are methods
        out = File.open(DirOps.file_in(@src_folder, EXPORT_THUNK_FILE), "w")

        exported.each do |meth|

          out.puts('extern "C" %s {' % meth.gen_decl(:force_cc => CppGen::FASTCALL))
          
          _, meth_part = Expose::FuncDB.decompose_meth(meth.name)


          out.puts("\t%s%s->%s(%s);" % [meth.type == 'void' ? '' : 'return ',
                                        CppGen::FASTCALL_THIS,
                                        meth_part, 
                                        meth.stack_arg_names.join(",")])
          out.puts("}\n")
          
        end
        
        
        out.close
      end
      
      def gen_asm_inc(exported, custom_exports, imported_fns)
        out = File.open(DirOps.file_in(@src_folder, ASM_INC_FILE), "w")

        exported.each do |meth|
          out.puts("%s EQU %s" % [CppGen.to_c_name(meth.name), decorated_name(meth.name)])
          out.puts("%s = 1" % export_flag_symbol(meth.name))
        end

        custom_exports.each do |(c_nam, asm_nam)|
          out.puts("%s EQU %s" % [asm_nam, c_nam])
          out.puts("%s = 1" % export_flag_symbol(asm_nam))
        end

        imported_fns.each do |fn|
          out.puts("%s EQU %s" % [CppGen.to_c_name(fn.name), asm_name(CppGen.to_c_name(fn.name))])
        end

        out.close
      end

      def check_exposed(imported_meth_names, imported_fn_names)
        safe = true
        
        imported_meth_names.each do |m|
          if not @fundb.has_func? m
            safe = false
            Seance::Logger::error("Method #{m} not exposed")
          end
        end
        
        imported_fn_names.each do |m|
          if not @rawfundb.has_func? m
            safe = false
            Seance::Logger::error("Function '#{m}' not imported")
          end
        end
        
        safe
      end

      def gen_asm_interop

        exported = []
        imported = []

        @class_methdecls.each_key do |klass|
          exported += @class_methdefs[klass].map{|m| Seance::Expose::FuncDB.recompose_meth(klass, m)}
          imported += (@class_methdecls[klass]-@class_methdefs[klass]).map{|m| Seance::Expose::FuncDB.recompose_meth(klass, m)}
        end

        imported_funs = @fns_to_import.keys

        if not check_exposed(imported, imported_funs)
          return
        end

        exported_sig = exported.map{|m| methsig(m)}
        imported_sig = imported.map{|m| methsig(m)}
        imported_fun_sig = imported_funs.map{|m| funsig(m)}

        gen_export_thunks(exported_sig)
        gen_import_file(imported_sig, imported_fun_sig)
        gen_asm_inc(exported_sig, @custom_exports, imported_fun_sig)
      end
      
      def defstruct(line)
        name = line.strip
        sc = @typedb.get_type_sc(name)
        defn = @typedb.get_type_defn(name)
        indent("#{sc} #{name}\n{#{defn}};")
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
        indent("};")
      end

      def methdecl(line)
        name = line.strip
        class_name, meth_name = Seance::Expose::FuncDB.decompose_meth(name)
        @class_methdecls[class_name] << meth_name
        indent(funsig(name).gen_decl(:name_override => meth_name, :implicit_this => true)+";")
      end

      def methdefn(line)
        name = line.strip
        class_name, meth_name = Seance::Expose::FuncDB.decompose_meth(name)
        @class_methdefs[class_name] << meth_name
        indent(@fundb.get_func_def(name, :implicit_this => true))
      end

      def funimport(line)
        name = line.strip
        @fns_to_import[name] = true
        nil
      end

      def custom_export(line)
        c_nam, asm_nam = line.scan(/\S+/)
        @custom_exports << [c_nam, asm_nam]
        nil
      end
      
      def transform_line(line)
        md = /^#seance\s+([-_\w]+)(.*)/.match(line)
        if md
          cmd = md[1]
          args = md[2]
          if @commands[cmd]
            @commands[cmd].call(args)
          else
            raise TemplateException, "Invalid directive #{cmd}"
          end
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
              outf.puts(trans) unless trans.nil?
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
