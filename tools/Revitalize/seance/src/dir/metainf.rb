require 'yaml'
require 'dir/dirmanager.rb'

module Seance
  
  class MetaInf

    include DirManager

    attr_reader :root

    def initialize(root)
      @root = root+"/.seance"
      ensure_dir
    end
  end
end
