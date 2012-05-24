require 'set'

require "dir/metainf.rb"
require 'dir/dirmanager.rb'
require 'dir/structure.rb'
require 'syntax/cpp.rb'

require 'rubygems'
require 'typesafe'

module Seance
  module Expose

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
        CppGen::to_c_name(nam)+".cpp"
      end

      def self.decompose_meth(nam)
        nam.split(/::/)
      end

      def self.recompose_meth(klass, meth, as_cpp=true)
        klass+(as_cpp ? "::" : "__")+meth
      end

      def initialize(root)
        @root = Directory.func_expose_dir(root)
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

      def get_fn_list
        @sigs.keys
      end

      def get_func(nam)
        meta = @sigs[nam]
        CppGen::FuncSig.new(meta[TYPE], nam, meta[CONVENTION], meta[ARGS])
      end

      def get_func_def(nam, opts={})
        defaults = {:name_override => nam, :implicit_this => false}
        opts = defaults.merge(opts)
        "#{get_func(nam).gen_decl(opts)}\n#{get_func_body(nam)}"
      end

      def add_func(type, name, convention, args, body)
        check_arg_structure args
        dump_raw(body, self.class.name_to_filename(name))
        @sigs[name] = {TYPE => type, CONVENTION => CppGen::keyword_to_cc(convention), ARGS => args}
        @meta.dump(@sigs, SIG_FILE)
      end
    end

  end
end
