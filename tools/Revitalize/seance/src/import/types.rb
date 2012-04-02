require "dir/metainf.rb"
require "import/db.rb"

module Seance

  module Import
    
    def self.import_header(hdr, root)
      db = TypeDB.new(root)
      
      contents = File.open(hdr, "r") {|f| f.readlines.join}

      db.start_batch_add

      contents.scan(/(union|enum|struct) (\w+)\s+\{(.+?)\};/m) do |sc, name, content|
        db.batch_add_type(sc, name, content)
      end
      
      db.end_batch_add

    end
    
  end

end
