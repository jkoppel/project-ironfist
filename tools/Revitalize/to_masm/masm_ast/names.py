import idaapi
import idc
import general
import util
import cpp_interop

class named_code_node(general.masm_ast_node):

    def __init__(self, ea, insn):
        self.name = idaapi.get_name(ea,ea)
        self.insn = insn

    def to_masm(self):
        return "%sdoublecolon\n%s" % (self.name, self.insn.to_masm())

def name_wrap_insn(ea, insn):
    if idaapi.get_name(ea,ea) == None:
        return insn
    else:
        return named_code_node(ea, insn)


class named_data_node(general.masm_ast_node):

    def __init__(self, ea, dec):
        self.name = idaapi.get_name(ea,ea)
        self.dec = dec
        self.type = "dword"

    def to_masm(self):
        return cpp_interop.data_import_toggle_wrap(self.dec.to_masm(),
                                                   self.name,
                                                   self.type)

def name_wrap_data(ea, dec):
    if idaapi.get_name(ea,ea) == None:
        return dec
    else:
        return named_data_node(ea, dec)

def get_public_decls():
    names = []
    for i in range(idaapi.get_nlist_size()):
        names.append(cpp_interop.declare_public(idaapi.get_nlist_name(i)))

    return "\n".join(names)

###Based on the MNG_ values in demangle.hpp, not exposed to idapython
INHIBITOR = 0xFFFF

def get_demangled_name(ea):
    return idaapi.get_demangled_name(idaapi.BADADDR, ea, INHIBITOR, 0, 0)

def is_mangled(name, ea):
    return util.postprocess(name) != get_demangled_name(ea)
