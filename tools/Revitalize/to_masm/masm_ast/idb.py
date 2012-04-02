import enum
import general
import struct
import segment
import util

class idb_node (general.masm_ast_node):
    def __init__(self, directives):
        self.directives = directives
        self.enums = enum.enums_node()
        self.structs = struct.structs_node()
        self.segments = segment.segments_node()

    def to_masm(self):
        return util.postprocess("\n\n".join([self.directives,
                                               self.enums.to_masm(),
                                               self.structs.to_masm(),
                                               self.segments.to_masm()]))
