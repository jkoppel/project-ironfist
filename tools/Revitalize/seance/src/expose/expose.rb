require 'import/db.rb'
require 'expose/db.rb'
require 'syntax/cpp.rb'

module Seance

  module Expose

    def self.expose_func(nam, root)
      imp = Import::FuncDB.new(root)
      exp = Expose::FuncDB.new(root)

      if imp.has_func? nam
        dec = imp.get_func(nam)
        exp.add_func(dec.type, nam, dec.raw_name,
                     CppGen.keyword_to_cc(dec.conv),
                     dec.args,
                     imp.get_func_body(nam))
      else
        raise "Function #{nam} not found"
      end
    end

  end

end
