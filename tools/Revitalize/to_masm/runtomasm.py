import idaapi
import idc
import masm_ast.idb

# 1) Incorrect output when the last byte in a function is data (e.g.: jump table). Solution: Move function end to before data
# 2) Will warn if stack variables conflict with a global variable, but not with a keyword. Solution: Rename, or use OPTION NOKEYWORD
# 3) MASM cannot parse the literals for max and min double and long double. Solution: Mark with a type, and convert to bytes

directives = '''OPTION NOKEYWORD:<THIS STR IN NAME TYPE MOD WIDTH LENGTH MASK AAM LABEL>
                OPTION CASEMAP:none
                include revitalize_exports.inc '''

with open('C:\masmtest.asm', 'w') as f:
    idaapi.msg("Opened file\n")
    f.write(masm_ast.idb.idb_node(directives).to_masm())
