import idaapi
import idc
import general
import value
import util


class enum_member_node(general.masm_ast_node):
    
    def __init__(self, cid, val):
        self.cid = cid
        self.name = idaapi.get_enum_member_name(cid)
        self.parent = idaapi.get_enum_member_enum(cid) #yes, this could totally be passed in. Avoid premature optimization!!!
        self.flags = idaapi.get_enum_flag(self.parent)
        self.val = value.value_node(val, self.flags)

    def to_masm(self):
        return "%s = %s" % (self.name, self.val.to_masm())

class enum_node (general.masm_ast_node):
    
    def __init__(self, id):
        self.id = id
        self.members = []

        bmask = idaapi.get_first_bmask(id)

        while True:
            val = idc.GetFirstConst(id, bmask)
            
            ##for_all_enum_members is unusable in IDAPython
            ##according to Igor, who recommended this.
            ##
            ##This manner of iterating through constants
            ##does not support multiple with the same value.
            ##Since I don't even know how to create those,
            ##I'm just plain not supporting them.
            ##
            ##Also, while the docs say to pass -1 for the bmask
            ##in the IDC const functions, this produces an
            ##overflow error. Igor said to use idaapi.BADADDR
            ##instead
            ##
            ##Also, the docks said it would return -1 when done,
            ##but it actually returned BADADDR. It seems that
            ##BADADDR is -1, but unsigned -- it all makes sense now
            ndone = 0
            while val != -1 and val != idaapi.BADADDR:
                cid = util.get_const_id(id, val, bmask)
                self.members.append(enum_member_node(cid, val))
                val = idc.GetNextConst(id, val, bmask)
                ndone += 1

            if bmask == idaapi.BADADDR:
                break
            else:
                bmask = idaapi.get_next_bmask(id, bmask)

                
    def to_masm(self):
        return "\n".join(map(lambda m: m.to_masm(),
                             self.members))
        


class enums_node (general.masm_ast_node):

    def __init__(self):
        #Is this the right way to iterate through enums? Holes?
        self.elts = []
        for i in range(idaapi.get_enum_qty()):
            self.elts.append(enum_node(idaapi.getn_enum(i)))

    def to_masm(self):
        return "\n\n".join(map(lambda e: e.to_masm(),
                               self.elts))

