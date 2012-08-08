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

      ASM_INC_FILE      = "revitalize_exports.inc"
      EXPORT_THUNK_FILE = "export_thunk.cpp"
      IMPORT_THUNK_FILE = "import_thunk.cpp"

      HIGH_LEVEL_MODE    = :high_level 
      LOW_LEVEL_MODE     = :low_level
      INDETERMINATE_MODE = :indeterminate

      DEFSTRUCT     = "defstruct"
      DEFCLASS      = "defclass"
      ENDCLASS      = "endclass"
      METHDECL      = "methdecl"
      METHDEFN      = "methdefn"
      FUNIMPORT     = "funimport"
      CUSTOM_EXPORT = "custom-export"
      RAW_DIRECTIVE = "raw-directive"
      
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

      def needs_thunk(fun)
        not fun.raw_name.start_with?(CppGen.prefix_for_cc(fun.conv))
      end

      def export_flag_symbol_raw(nam)
        "IMPORT_"+CppGen.to_c_name(nam)
      end

      def export_flag_symbol(meth)
        export_flag_symbol_raw(meth.raw_name)
      end

      def methsig(meth)
        @rawfundb.get_func(meth)
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
      
      def initialize(root, subproj)
        @root = root
        @templ_folder = Directory.templ_subdir(root, subproj)
        @src_folder = Directory.src_subdir(root, subproj)
        @fundb = Expose::FuncDB.new(@root)
        @rawfundb = Import::FuncDB.new(@root)
        @typedb = Import::TypeDB.new(@root)
        @commands = {
          DEFSTRUCT => method(:defstruct),
          DEFCLASS => method(:defclass),
          ENDCLASS => method(:endclass),
          METHDECL => method(:methdecl),
          METHDEFN => method(:methdefn),
          FUNIMPORT => method(:funimport),
          CUSTOM_EXPORT => method(:custom_export),
          RAW_DIRECTIVE => method(:raw_directive),
        }
        @modes = {
          DEFSTRUCT => HIGH_LEVEL_MODE,
          DEFCLASS => HIGH_LEVEL_MODE,
          ENDCLASS => HIGH_LEVEL_MODE,
          METHDECL => HIGH_LEVEL_MODE,
          METHDEFN => HIGH_LEVEL_MODE,
          FUNIMPORT => HIGH_LEVEL_MODE,
          CUSTOM_EXPORT => LOW_LEVEL_MODE,
          RAW_DIRECTIVE => LOW_LEVEL_MODE,
        }

        @class_methdecls = Hash.new {|h,k| h[k] = [] }
        @class_methdefs = Hash.new {|h,k| h[k] = [] }
        @fns_to_import = {}
        @custom_exports = []
        @raw_directives = []
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

        imported_meths.select{|m| needs_thunk(m)}.each do |m|
          out.puts("\t%s %s();" % [m.type, CppGen.to_c_name(m.name)])
        end

        out.puts("");

        imported_fns.each do |fn|
          if needs_thunk(fn)
            out.puts("\t%s %s();" % [fn.type, asm_name(CppGen.to_c_name(fn.name))])
          else
            out.puts("\t%s;" % fn.gen_decl)
          end
        end

        out.puts("}\n")

        imported_meths.each do |m|
          put_imported_fun_defn(out, m, true) if needs_thunk(m)
        end

        imported_fns.each do |m|
          put_imported_fun_defn(out, m, false) if needs_thunk(m)
        end

        out.close
      end


      def gen_export_thunks(exported)
        ##Assuming all are methods
        out = File.open(DirOps.file_in(@src_folder, EXPORT_THUNK_FILE), "w")

        exported.select{|m| needs_thunk(m) }.each do |meth|

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
      
      def gen_asm_inc(exported, custom_exports, raw_directives, imported_fns)
        out = File.open(DirOps.file_in(@src_folder, ASM_INC_FILE), "w")

        raw_directives.each { |l| out.puts l }

        exported.each do |meth|
          if needs_thunk(meth)
            out.puts("%s EQU %s" % [CppGen.to_c_name(meth.name), decorated_name(meth.name)])
          end
          out.puts("%s = 1" % export_flag_symbol(meth))
        end

        custom_exports.each do |(c_nam, asm_nam)|
          out.puts("%s EQU %s" % [asm_nam, c_nam])
          out.puts("%s = 1" % export_flag_symbol_raw(asm_nam))
        end

        imported_fns.select {|fn| needs_thunk(fn) }.each do |fn|
          out.puts("%s EQU %s" % [CppGen.to_c_name(fn.name), asm_name(CppGen.to_c_name(fn.name))])
        end

        out.close
      end

      def check_imported(imported_fn_names)
        safe = true

        imported_fn_names.each do |m|
          if not @rawfundb.has_func? m
            safe = false
            Seance::Logger::error("Function '#{m}' not imported")
          end
        end
        
        safe
      end

      def check_exported(exported_names)
        safe = true
        
        exported_names.each do |m|
          if not @fundb.has_func? m
            safe = false
            Seance::Logger::error("Method #{m} not exposed")
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

        if not (check_exported(exported) and check_imported(imported+imported_funs))
          return
        end

        exported_sig = exported.map{|m| methsig(m)}
        imported_sig = imported.map{|m| methsig(m)}
        imported_fun_sig = imported_funs.map{|m| funsig(m)}

        gen_export_thunks(exported_sig)
        gen_import_file(imported_sig, imported_fun_sig)
        gen_asm_inc(exported_sig, @custom_exports, @raw_directives, imported_fun_sig)
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

      def raw_directive(line)
        @raw_directives << line
        nil
      end
      
      def set_mode(mode)
        if @mode == mode || @mode == INDETERMINATE_MODE
          @mode = mode
        else
          Seance::Logger::error("Attempting to use #{mode} and #{@mode} commands in the same file")
        end
      end

      def transform_line(line)
        md = /^#seance\s+([-_\w]+)(.*)/.match(line)
        if md
          cmd = md[1]
          args = md[2]
          if @commands[cmd]
            Seance::Logger.with_error_handling(proc{""}) do
              set_mode(@modes[cmd])
              @commands[cmd].call(args)
            end
          else
            raise TemplateException, "Invalid directive #{cmd}"
          end
        else
          line
        end
      end

      def begin_template
        @mode = INDETERMINATE_MODE
      end

      def end_template
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
            
            begin_template
            yield orig, exported
            end_template
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


    def self.reify_templates(root, subproj)
      reifier = TemplateReifier.new(root, subproj)

      reifier.reify_templates
    end
    
  end
end
