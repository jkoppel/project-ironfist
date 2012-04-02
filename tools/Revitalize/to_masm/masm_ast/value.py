import idaapi
import idc
import general
import util

class value_node (general.masm_ast_node):

    def __init__(self, val, flags):
        self.val = val
        self.flags = flags

    def to_masm(self):
        return str(self.val)

def get_node_for_member(mem, parent):
    if idaapi.isStruct(mem.flag):
        return unset_structure_node(idaapi.get_struc(util.member_str_id(mem, parent)))
    else:
        return unset_primitive_node()
        

class unset_structure_node(general.masm_ast_node):

    def __init__(self, struc):
        self.is_union = idaapi.is_union(struc.id)

    def to_masm(self):
        #if self.is_union:
        if True:
            return "<>"
        else:
            return "<?>"

class unset_primitive_node(general.masm_ast_node):

    def __init__(self):
        pass

    def to_masm(self):
        return "?"
