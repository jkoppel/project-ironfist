import idaapi
import general
import function
import data

class code_segment_node(general.masm_ast_node):

    def __init__(self, seg):

        self.content = None

        self.segclass = idaapi.get_segm_class(seg)
        self.name = idaapi.get_segm_name(seg)

        self.content = function.functions_node(seg.startEA, seg.endEA)

    def to_masm(self):
        #Shortcuts for the win?
        #return ("%s segment para public '%s' use32\n%s\n%s ends" %
        return (".code\nassume es:nothing, ss:nothing, ds:_data, fs:nothing, gs:nothing\n%s\n\n" %
                self.content.to_masm())

class verbatim_segment_node(general.masm_ast_node):

    def __init__(self, seg):

        self.content = None

        self.segclass = idaapi.get_segm_class(seg)
        self.name = idaapi.get_segm_name(seg)
        
        self.content = data.data_node(seg.startEA, seg.endEA)

    def to_masm(self):
        return self.content.to_masm()
        

def create_segment_node(seg):
    segclass = idaapi.get_segm_class(seg)
    if segclass == "CODE":
        return code_segment_node(seg)
    else:
        return verbatim_segment_node(seg)

class segments_node(general.masm_ast_node):

    def __init__(self):
        self.segs = []
        for i in range(idaapi.get_segm_qty()):
            self.segs.append(create_segment_node(idaapi.getnseg(i)))

    def to_masm(self):
        return "\n\n\n".join(map(lambda e: e.to_masm(),
                                 self.segs))
