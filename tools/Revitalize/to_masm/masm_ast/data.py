import idaapi
import idc
import general
import value
import names
import util

#There's probably a better way for this, but I did not find it
def get_prim_unit_size(flags):
    if idaapi.isByte(flags):
        return 1
    elif idaapi.isWord(flags):
        return 2
    elif idaapi.isDwrd(flags):
        return 4
    elif idaapi.isQwrd(flags):
        return 8
    elif idaapi.isOwrd(flags):
        return 16
    elif idaapi.isTbyt(flags):
        return 10
    elif idaapi.isFloat(flags):
        return 4
    elif idaapi.isDouble(flags):
        return 8
    #elif idaapi.isPackReal(flags):
    elif idaapi.isASCII(flags):
        return 1
    elif idaapi.isStruct(flags):
        raise "Struct sent to get_prim_size"
    #elif idaapi.isAlign(flags):
    #elif idaapi.is3byte(flags):
    #elif idaapi.isCustom(flags):

def get_member_unit_size(mem, struc):
    if idaapi.isStruct(mem.flag):
        return idaapi.get_struc_size(util.member_str_id(mem, struc))
    else:
        return get_prim_unit_size(mem.flag)
    

def get_decl_for_prim(flags):
    s = get_prim_unit_size(flags)

    if s == 1:
        return "db"
    elif s == 2:
        return "dw"
    elif s == 4:
        return "dd"
    elif s == 8:
        return "dq"
    elif s == 10:
        return "dt"
    else:
        raise Exception("Unimplemented size %s sent to get_decl_for_prim" % str(s))

def get_name_of_size(size):
    
    if size == 1:
        return "byte"
    elif size == 2:
        return "word"
    elif size == 4:
        return "dword"
    elif size == 8:
        return "qword"
    elif size == 10:
        return "tbyte"
    else:
        raise Exception("Unimplemented size %d sent to get_name_of_size" % size)

def get_decl_for_member(mem, struc):
    if idaapi.isStruct(mem.flag):
        return idaapi.get_struc_name(util.member_str_id(mem, struc))
    else:
        return get_decl_for_prim(mem.flag)

class datum_node(general.masm_ast_node):

    #really just a placeholder for when/if I decide to focus on appearance
    name_spacing = "\t"

    def __init__(self, val):
        self.val = val

    def get_decl(self):
        return get_decl_for_prim(self.flags)

    def wrap_dup(self, s):
        q = self.get_quant()
        
        if q == 1:
            return s
        else:
            return str(q) + " dup(" + s + ")"

    def to_masm(self):
        return (self.name+datum_node.name_spacing+self.get_decl()+
                " "+self.wrap_dup(self.get_val().to_masm()))

    #This existence of these methods belie my
    #understanding of Python OOP
    def get_val(self):
        raise "Unimplemented"

    def get_quant(self):
        raise "Unimplemented"




class data_node(general.masm_ast_node):

    def __init__(self, low, high):
        self.elts = []
        
        ea = low
        while ea < high:
            #if idaapi.isStruct(idaapi.getFlags(ea)):
            #    self.elts.append(struct_instance_node(ea))
            #else:
            self.elts.append(names.name_wrap_data(ea,general.verbatim_node(ea)))
            ea = idaapi.next_not_tail(ea)

    def to_masm(self):
        return "\n".join(map(lambda e: e.to_masm(),
                             self.elts))
