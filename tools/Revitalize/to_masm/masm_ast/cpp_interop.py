def import_token(name):
    return "IMPORT_"+name.upper()

###Wraps definition with MASM directives such that defining a flag in an include file
###can toggle whether C++ or MASM version is used
def import_toggle_wrap(defn, name):
    return ("IFDEF %s\n%s PROTO SYSCALL\nELSE\n%s\nENDIF" %
            (import_token(name), name, defn))
