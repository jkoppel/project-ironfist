import idaapi
import general

def import_token(name):
    return "IMPORT_"+name

###Wraps definition with MASM directives such that defining a flag in an include file
###can toggle whether C++ or MASM version is used
def import_toggle_wrap(defn, name):
    return ("IFDEF %s\n%s PROTO SYSCALL\nELSE\n%s\nENDIF" %
            (import_token(name), name, defn))

def import_guard(defn, name):
    return ("IFDEF %s\n%s\nENDIF" % (import_token(name), defn))

def import_antiguard(defn, name):
    return ("IFNDEF %s\n%s\nENDIF" % (import_token(name), defn))

def data_import_toggle_wrap(dec, name,type):
    return ("IFDEF %s\nextern %s : %s\nELSE\n%s\nENDIF" %
            (import_token(name), name, type, dec))

def declare_public(name):
    return ("IFNDEF %s\nPUBLIC %s\nENDIF" % (import_token(name), name))
