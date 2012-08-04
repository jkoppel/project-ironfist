require 'dir/metainf.rb'

module Seance

  class Directory
    
    include DirManager

    attr_reader :root
    
    IMPORTS_DIR = "imports"
    IMPORTS_FUNCS_DIR = DirOps.subdir IMPORTS_DIR, "funcs"
    IMPORTS_TYPES_DIR = DirOps.subdir IMPORTS_DIR, "types"
    TRANS_DIR = "trans"
    TRANS_FUNCS_DIR = DirOps.subdir TRANS_DIR, "funcs"
    TRANS_TEMPL_DIR = DirOps.subdir TRANS_DIR, "template"
    SRC_DIR = "src"
    
    SUBDIRS = [IMPORTS_DIR,
               IMPORTS_FUNCS_DIR,
               IMPORTS_TYPES_DIR,
               TRANS_DIR,
               TRANS_FUNCS_DIR,
               TRANS_TEMPL_DIR,
               SRC_DIR]
    
    def self.type_import_dir(root)
      DirOps.subdir root, IMPORTS_TYPES_DIR
    end
    
    def self.func_import_dir(root)
      DirOps.subdir root, IMPORTS_FUNCS_DIR
    end
    
    def self.func_expose_dir(root)
      DirOps.subdir root, TRANS_FUNCS_DIR
    end
    
    def self.imports_dir(root)
      DirOps.subdir root, IMPORTS_DIR
    end
    
    def self.src_dir(root)
      DirOps.subdir root, SRC_DIR
    end

    def self.src_subdir(root, dir)
      DirOps.subdir(src_dir(root), dir)
    end

    def self.make_src_subdir(root, dir)
      pth = src_subdir(root, dir)
      DirOps.ensure_dir(pth)
      MetaInf.new(pth)
    end
    
    def self.templ_dir(root)
      DirOps.subdir root, TRANS_TEMPL_DIR
    end

    def self.templ_subdir(root, dir)
      DirOps.subdir(templ_dir(root), dir)
    end

    def self.make_templ_subdir(root, dir)
      pth = templ_subdir(root, dir)
      DirOps.ensure_dir(pth)
      MetaInf.new(pth)
    end

    def self.make_subproject(root, proj)
      make_src_subdir(root, proj)
      make_templ_subdir(root, proj)
    end

    def initialize(root)
      @root = root
    end
    
    def init_seance
      SUBDIRS.each do |name|
        DirOps.ensure_dir(path(name))
        meta = MetaInf.new(path(name))
      end
    end
    
  end
end
