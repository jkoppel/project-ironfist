import idaapi
import idc
import general
import data
import member
import util

class struct_node(general.masm_ast_node):

    def __init__(self, struc):
        self.mems = []
        self.src = struc
        self.tid = struc.id
        self.name = idaapi.get_struc_name(self.tid)
        self.deps = set([])
        for i in range(struc.memqty):
            m = struc.get_member(i)
            self.mems.append(member.create_member_node(m, struc))
            d = util.member_str_id(m, struc)
            if d != None:
                self.deps = self.deps | set([d])

    def dependencies_handled(self, outputted):
        return self.deps <= outputted

    def wrapDecl(self, s):
        header = ""
        if self.src.has_union():
            header = "union"
        else:
            header = "struct"

        return (self.name + " " + header + " \n" + 
                s + "\n" + 
                self.name + " ends\n\n")

    def to_masm(self):
        return self.wrapDecl(
            "\n".join(map(lambda e: e.to_masm(),
                          self.mems)))
            

###It looks like outputting ordered by dependency would be somewhat
###painful to code, and would be trumped anyway once struct output is controlled by formats
class structs_node(general.masm_ast_node):

    def __init__(self):
        self.elts = []
        for i in range(idaapi.get_struc_qty()):
            self.elts.append(struct_node(idaapi.get_struc(idaapi.get_struc_by_idx(i))))

    def to_masm(self):
        s = ""
        sep = ""
        #Quick and dirty, but inefficient, topological sort.
        #Constructing the graph and handling the correspondence between
        #structure ids and struct_ast_node's would have been painful,
        #so I'm doing this since the dependency DAGs tend to be flat
        outputted = set([])
        while len(outputted) < len(self.elts):
            for struc in self.elts:
                if struc.tid not in outputted and struc.dependencies_handled(outputted):
                    outputted = outputted | set([struc.tid])
                    s += sep+struc.to_masm()
                    sep = "\n\n\n"

        return s


class frame_node(struct_node):

    def __init__(self, struc, parent):
        super(frame_node, self).__init__(struc)
        self.struct_vars = []

        for m in self.mems:
            m.set_esp_soff(parent.frsize)
            if m.is_struct():
                self.struct_vars.append((m.get_name(), m.get_struc_id()))
            

    def to_masm(self):
        return ("".join(map(lambda e: e.to_masm(),
                             self.mems)) +
                " \n")
