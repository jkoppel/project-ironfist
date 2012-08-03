require 'set'

require "dir/metainf.rb"
require 'dir/dirmanager.rb'
require 'dir/structure.rb'
require 'syntax/cpp.rb'
require 'mgmt/funcdb.rb'

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

    class FuncDB < Manage::BaseFuncDB
      def get_root(seance_root)
        Directory.func_import_dir(seance_root)
      end
    end
  end
end
