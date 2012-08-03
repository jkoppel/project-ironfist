module DirOps
  
  def self.ensure_dir(path)
    Dir.mkdir(path) unless File.exists?(path)
  end

  class << self
    
    def subdir(root, folder)
      "#{root}/#{folder}"
    end
    
    alias file_in subdir
    
    def nested_subdir(*dirs)
      dirs.inject("") {|path, d| subdir(path,d) }
    end

    def improper_dir?(dirname)
      dirname == "." || dirname == ".." || dirname == "..."
    end

    def proper_subdir?(root, nam)
      !improper_dir?(nam) && File::directory?(subdir(root,nam))
    end
  end 
end
