import idaapi
import idc
import general


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
