import idc
import idaapi
import re

#If mem is a structure type, returns that structure id
def member_str_id(mem, parent):
    if idaapi.isStruct(mem.flag):
        return idc.GetMemberStrId(parent.id, mem.soff)
    else:
        return None

#Deleting and redefining changes the serial; can't assume serial is 0
def get_const_id(eid, val, bmask):
    cid = idaapi.BADADDR
    serial = 0
    while cid == idaapi.BADADDR:
        cid = idc.GetConstEx(eid, val, serial, bmask)
        serial += 1

    return cid


def remove_lineno(s):
    i = s.find(" ")
    if i == -1:
        return ""
    else:
        return s[(i+1):]

def isnt_comment_line(s):
    return re.match(r'\s*;', s) == None

def get_override(ea):
        cmt = idaapi.get_cmt(ea, False)

        if(cmt == None):
            return None

        if(re.match(r'#override\s+.*', cmt)):
            return cmt[len("#override"):]
        else:
            return None

def postprocess(s):
    return s.replace("::","__").replace("doublecolon","::")
