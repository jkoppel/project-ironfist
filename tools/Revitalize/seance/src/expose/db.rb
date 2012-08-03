require 'mgmt/funcdb.rb'
require 'dir/structure.rb'

module Seance
  module Expose
    class FuncDB < Manage::BaseFuncDB
      def get_root(seance_root)
        Directory.func_expose_dir(seance_root)
      end
    end
  end
end
