require 'import/db.rb'
require 'expose/db.rb'

module Seance

  module Expose

    # def self.expose_type(nam, root)
    #   imp = Import::TypeDB.new(root)
    #   exp = Expose::TypeDB.new(root)

    #   if imp.has_type? nam
    #     exp.add_type(imp.get_type_defn(nam), imp.get_type_sc(nam), nam)
    #   else
    #     raise "Type #{nam} not found"
    #   end
    # end

    def self.expose_func(nam, root)
      imp = Import::FuncDB.new(root)
      exp = Expose::FuncDB.new(root)

      if imp.has_func? nam
        exp.add_func(imp.get_func_type(nam),
                     nam,
                     imp.get_func_convention(nam),
                     imp.get_func_args(nam),
                     imp.get_func_body(nam))
      else
        raise "Function #{nam} not found"
      end
    end

  end

end
