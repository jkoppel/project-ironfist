require 'set'

require "dir/metainf.rb"
require 'dir/dirmanager.rb'
require 'dir/structure.rb'
require 'syntax/cpp.rb'

module Seance
  module Import

    class TypeDB

      include DirManager

      attr_reader :root

      LIST_FILE = "list.yaml"
      SC_FILE = "sc.yaml"

      def self.name_to_filename(nam)
        "#{nam}.hpp"
      end

      def initialize(root)
        @root = Directory.type_import_dir(root)
        @meta = MetaInf.new(@root)
        @meta.ensure_file(SC_FILE, {})
        @meta.ensure_file(LIST_FILE, Set.new)
        @scs = @meta.load(SC_FILE)
        @types = @meta.load(LIST_FILE)
      end
      
      def has_type?(typ)
        @types.include? typ
      end

      def get_type_defn(typ)
        load_raw(self.class.name_to_filename(typ))
      end

      def get_type_sc(typ)
        @scs[typ]
      end

      def start_batch_add
      end

      def batch_add_type(sc, name, content)
        @types << name
        @scs[name] = sc
        dump_raw(content, self.class.name_to_filename(name))
      end

      def end_batch_add
        @meta.dump(@scs, SC_FILE)
        @meta.dump(@types, LIST_FILE)
      end

    end

    class FuncDB
      
      include DirManager

      attr_reader :root

      SIG_FILE = "sigs.yaml"
      TYPE = :type
      CONVENTION = :convention
      ARGS = :args

      #Should eventually be converted to use SafeMe
      def check_arg_structure(args)
        valid = true
        valid &&= args.class == Array
        
        args.each do |a|
          valid &&= a.class == Array 
          valid &&= a.size == 2
          a.each do |s|
            valid &&= s.class == String
          end
        end

        raise "Imported function arguments in invalid form" unless valid
      end

      def self.name_to_filename(nam)
        (nam.gsub(':','_'))+".cpp"
      end

      def initialize(root)
        @root = Directory.func_import_dir(root)
        @meta = MetaInf.new(@root)
        @meta.ensure_file(SIG_FILE, {})
        @sigs = @meta.load(SIG_FILE)
      end

      def has_func?(nam)
        @sigs.has_key? nam
      end

      def get_func_body(nam)
        load_raw(self.class.name_to_filename(nam))
      end

      def add_func(type, name, convention, args, body)
        check_arg_structure args
        dump_raw(body, self.class.name_to_filename(name))
        @sigs[name] = {TYPE => type, CONVENTION => convention, ARGS => args}
        @meta.dump(@sigs, SIG_FILE)
      end

      def get_func_type(name)
        @sigs[name][TYPE]
      end

      def get_func_convention(name)
        @sigs[name][CONVENTION]
      end

      def get_func_args(name)
        @sigs[name][ARGS]
      end

      def get_fn_list
        @sigs.keys
      end

      def get_stack_arg_names(methnam)
        meta = @sigs[methnam]

        args = nil

        case meta[CONVENTION]
        when THISCALL
          args = meta[ARGS][1..-1]
        when FASTCALL
          args = meta[ARGS][2..-1]
        when STDCALL
          args = meta[ARGS]
        end
        
        args.map{|(_,n)| n}
      end

      def get_func_decl(nam, opts = {})
        meta = @sigs[nam]
        CppGen.get_func_decl(nam, meta[TYPE], meta[ARGS], CppGen::KEYWORD_CC[meta[CONVENTION]], opts)
      end

      def get_func_body(name)
        load_raw(self.class.name_to_filename(name))
      end
    end

  end
end
