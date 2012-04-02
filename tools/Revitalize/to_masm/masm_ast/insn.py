import idaapi
import idc
import general
import re

##From intel.hpp; not exported to IDAPython
##When one of these is set, the programmatic
##way of accessing mnemonics won't work,
##but verbatim assembly lines will
aux_rep = 0x0002 #Also for repe
aux_repne = 0x0004

def has_prefix(insn):
    return insn.auxpref & (aux_rep | aux_repne) != 0

#Ilfak said there wasn't really a reliable way to know if something had a suffix, so...

suffixed_insns = set([idaapi.NN_movs,
                      idaapi.NN_scas,
                      idaapi.NN_cmps,
                      idaapi.NN_stos,
                      idaapi.NN_lods])

def should_print_verbatim(insn):
    return (has_prefix(insn) or
            insn.itype in suffixed_insns)

special_op_replacements = {"large fs:0" : "fs:0", #I don't know why
                           "large dword ptr fs:0" : "dword ptr fs:0", #ditto
                           "$+5" : "NEAR32 PTR $+5", #IDA does not distinguish between near and short jumps.
                           "$+6" : "NEAR32 PTR $+6" #These are really the only cases where you get incorrect reassembly as a result
                           }

op_arity_overrides = {idaapi.NN_fcompp : []}

def do_special_op_replacements(s):
    if special_op_replacements.has_key(s):
        return special_op_replacements[s]
    else:
        return s

#Stack-allocated structures are uncommon in H2,
#and in general. In fact, I have no examples 
#of stack-allocated structures with non-primitive members,
#so this simple string replace will likely fail for programs
#which do have them. Still, it should handle H2 nicely.
#
#In practices, struct_vars will almost always be 0 or 1,
#so this is not that inefficient.
def qualify_stack_struct_references(s, struct_vars):
    for (nam, tid) in struct_vars:
        p = re.compile('\+'+nam+'\.([^\]]+)\]')
        if p.search(s) != None:
            return p.sub('+'+nam+'].'+idaapi.get_struc_name(tid)+'.\g<1>', s)
        
    return s
        

class op_node(general.masm_ast_node):
    
    def __init__(self, ea, n, struct_vars):
        self.ea = ea
        self.idx = n
        self.struct_vars = struct_vars

    def to_masm(self):
        s = idaapi.tag_remove(idaapi.ua_outop2(self.ea, self.idx))
        s = do_special_op_replacements(s)
        return qualify_stack_struct_references(s, self.struct_vars)
            

class insn_node(general.masm_ast_node):

    def __init__(self, ea, struct_vars):
        self.ea = ea
        self.ops = []
        self.verbatim = False

        idaapi.decode_insn(ea)


        #poor man's get_num_ops; can't find real one
        n = 0

        if should_print_verbatim(idaapi.cmd):
            self.verbatim = True
        else:
            to_iter_over = range(idaapi.UA_MAXOP)
            
            if op_arity_overrides.has_key(idaapi.cmd.itype):
                to_iter_over = op_arity_overrides[idaapi.cmd.itype]

            for n in to_iter_over:
                if (idaapi.cmd.Operands[n].type != idaapi.o_void and
                    idaapi.cmd.Operands[n].flags & idaapi.OF_SHOW != 0):
                    self.ops.append(op_node(ea, n, struct_vars))
        

    def to_masm(self):
        if self.verbatim:
            return "\t%s" % (idaapi.tag_remove(idaapi.generate_disasm_line(self.ea)))
        else:
            return "\t%s  %s" % (idaapi.ua_mnem(self.ea),
                                 ", ".join(map(lambda e: e.to_masm(),
                                               self.ops)))
