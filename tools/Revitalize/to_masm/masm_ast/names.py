import idaapi
import idc
import general
import util

class named_code_node(general.masm_ast_node):

    def __init__(self, ea, insn):
        self.name = idaapi.get_name(ea,ea)
        self.insn = insn

    def to_masm(self):
        #Until I figure out how to handle names, I've just been
        #replace-alling :: with __
        #Now that I'm making all labels public, doesn't work so well...
        return "%sdoublecolon\n%s" % (self.name, self.insn.to_masm())

def name_wrap_insn(ea, insn):
    if idaapi.get_name(ea,ea) == None:
        return insn
    else:
        return named_code_node(ea, insn)

###A list of names to #define to their C equivalents
###
###Although there is some workaround to be done to use C names
###for C++ m, this work was all done before we obtained
###the original C++-mangled names for HoMM II. This will
###slowly be converted to use extern "C++" instead

###Based on the MNG_ values in demangle.hpp, not exposed to idapython
INHIBITOR = 0xFFFF

# FORBIDDEN_MANGLED_PREFIXES = ("??0", #Constructor
#                               "??1", #Destructor
#                               "??_G", #scalar deleting destructor
#                               )

# names_list = []

def get_demangled_name(ea):
    return idaapi.get_demangled_name(idaapi.BADADDR, ea, INHIBITOR, 0, 0)

def is_mangled(name, ea):
    return util.postprocess(name) != get_demangled_name(ea)

# def should_rename(name, ea):
#     dname = get_demangled_name(ea)
#     if dname == util.postprocess(name):
#         return False

#     if name.startswith(FORBIDDEN_MANGLED_PREFIXES):
#         return False

#    return True

# def add_c_rename(name, ea):
#     dname = get_demangled_name(ea)
#     if dname != name:
#         names_list.append((name, dname))

# def get_c_renames():
#     return "\n".join(map(lambda (a,b): a+" EQU "+b,
#                           names_list))
