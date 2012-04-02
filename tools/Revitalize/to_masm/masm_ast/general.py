import idaapi
import util

#I'm thinking eventually I'll change the to_masm pipeline to a print_masm,
#and define a to_masm here which prints the MASM to Python's version of a StringIO
class masm_ast_node(object):

    def to_masm(self):
        pass

class verbatim_node(masm_ast_node):
    
    def __init__(self, ea):
        self.ea = ea

    def to_masm(self):
        over = util.get_override(self.ea)

        if over != None:
            return over
        
        _, lines = idaapi.generate_disassembly(self.ea, 5000, False, True)
        return "\n".join(filter(util.isnt_comment_line,
                                map(util.remove_lineno, lines)))
