import idaapi
import general
import data
import value
import util

class member_node(data.datum_node):

    def __init__(self, member, parent):
        ##These objects below can apparently be mutated by ua stuff.
        #self.src = member
        #self.src_parent = parent

        self.name = idaapi.get_member_name(member.id)
        self.flags = member.flag
        self.val = value.get_node_for_member(member, parent)
        self.eoff = member.eoff
        self.soff = member.soff

        self.decl = data.get_decl_for_member(member, parent)
        self.unit_size = data.get_member_unit_size(member, parent)
        
        self.struc_id = None
        if idaapi.isStruct(self.flags):
            self.struc_id = util.member_str_id(member, parent)

    def get_struc_id(self):
        return self.struc_id

    def is_struct(self):
        return idaapi.isStruct(self.flags)

    def get_name(self):
        return self.name

    def get_val(self):
        return self.val

    def get_decl(self):
        return self.decl

    def get_quant(self):
        mem_size = self.eoff - self.soff
        return mem_size / self.unit_size

class frame_member_node(member_node):

    def __init__(self, member, parent):
        super(frame_member_node, self).__init__(member, parent)
        self.esp_soff = 0
        
        if(idaapi.get_name_value(idaapi.BADADDR, self.name)[0] != idaapi.NT_NONE):
            print "Warning: stack variable %s conflicts with global" % self.name
            #I got lots of erroneous warnings until I added the below line. What?
            #print str(idaapi.get_name_value(idaapi.BADADDR, self.name))

    def set_esp_soff(self, soff):
        self.esp_soff = soff

    def to_masm(self):
        if self.name == " r" or self.name == " s": #special values
            return ""
        elif(self.is_struct()):
            #still figuring out what to do in this case
            return "%s = %d\n" % (self.name, self.soff - self.esp_soff)
        else:
            return ("%s\t\t= %s ptr %d\n" %
                    (self.name,
                     data.get_name_of_size(self.unit_size),
                     self.soff - self.esp_soff))

def create_member_node(member, parent):
    if (parent.props & idaapi.SF_FRAME) != 0:
        return frame_member_node(member, parent)
    else:
        return member_node(member, parent)
