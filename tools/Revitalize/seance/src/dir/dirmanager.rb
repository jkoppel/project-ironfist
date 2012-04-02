####Given a "root" function, provides utilities for managing files
####in the root directory

require 'dir/ops.rb'

require 'yaml'

module DirManager
    def ensure_dir(dir="")
      DirOps.ensure_dir(path(dir))
    end

    def path(filname)
      DirOps.file_in(root,filname)
    end
    
    def dump(obj, filname)
      File.open(path(filname), "w") do |f|
        f.puts(YAML.dump(obj))
      end
    end
    
    def load(filname)
      YAML.load_file(path(filname))
    end

    def dump_raw(str, filname)
      File.open(path(filname), "w") {|f| f.print str}
    end

    def load_raw(filname)
      File.open(path(filname), "r") {|f| f.readlines.join}
    end

    def contains(filname)
      File.exists?(filname)
    end

    def ensure_file(filname, default)
      dump(default, filname) unless File.exists?(path(filname))
    end
end
