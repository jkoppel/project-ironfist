#include "gui.h"

#include <stdio.h>

#define Elements_in(arrayname) (sizeof arrayname/sizeof *arrayname)

extern widgetVtable textEntryWidget_vftable;
extern widgetVtable border_vftable;
extern widgetVtable iconWidget_vftable;
extern widgetVtable textWidget_vftable;
extern widgetVtable dimmerWidget_vftable;
extern widgetVtable listBoxWidget_vftable;
extern widgetVtable dropListWidget_vftable;
extern widgetVtable button_vftable;

struct widget_printerInfo {
	char* widgetName;
	int n;
	char** names;
	int* offsets;
	char* types;
	widgetVtable* vtable;

	widget_printerInfo(char* w, int n1, char** n2, int* o, char* t, widgetVtable* v) :
		widgetName(w), n(n1), names(n2), offsets(o), types(t), vtable(v) {}
};


char *textEntryWidget_names[] =
	{"fieldId", "field_12", "field_14", "field_16", "offsetX", "offsetY", "width", "height",
	"field_28", "field_2A", "field_2F", "field_31", "fifthShort", "field_35", "field_37",
	"field_39", "field_3B", "field_3D", "field_3F", "field_41", "field_43", "field_45", "field_47",
	"type", "field_4B", "_2"};
int textEntryWidget_offsets[] = {16,18,20,22,24,26,28,30,40,42,47,49,51,53,55,57,59,61,63,65,67,69,71,73,75,77};

widget_printerInfo textEntryWidgetInfo(
	"textEntryWidget",
	26,
	textEntryWidget_names,
	textEntryWidget_offsets,
	"wwwwwwwwwbwwwwwwwwwwwwwwwb",
	&textEntryWidget_vftable
	);

char *border_names[] = {"fieldId", "field_12", "backgroundType", "flags", "offsetX", "offsetY", "width", "height",
	"color"};
int border_offsets[] = {16,18,20,22,24,26,28,30,40};

widget_printerInfo borderInfo(
	"border",
	9,
	border_names,
	border_offsets,
	"wwwwwwwww",
	&border_vftable
	);


char* button_names[] = {
  "fieldID", "field_12", "field_14", "flags", "offsetY", "width", "height", "normalImageIdx",
  "armedImageIdx", "field_28", "field_2A", "icnFileID"};

int button_offsets[] = {16,18,20,22,26,28,30,36,38,40,42,44};

widget_printerInfo buttonInfo(
	"button",
	12,
	button_names,
	button_offsets,
	"wwwdwwwwwwwd",
	&button_vftable
	);

char *textWidget_names[] =
	{"fieldId", "field_12", "field_14", "field_16", "offsetX", "offsetY", "width", "height",
	"field_28", "field_2A"};
int textWidget_offsets[] = {16,18,20,22,24,26,28,30,40,42};

widget_printerInfo textWidgetInfo(
	"textWidget",
	10,
	textWidget_names,
	textWidget_offsets,
	"wwwwwwwwwb",
	&textWidget_vftable
	);


  __int16 fieldID;
  __int16 componentIndex;
  __int16 field_14;
  __int16 field_16;
  __int16 offsetX;
  __int16 offsetY;
  __int16 width;
  __int16 height;
  __int16 imgIdx;
  char mirror;
  __int16 field_27;
  int iconFileID;
  

char *iconWidget_names[] =
	{"fieldId", "componentIndex", "field_14", "field_16", "offsetX", "offsetY", "width", "height",
	"imgIdx", "mirror", "field_27", "iconFileId"};
int iconWidget_offsets[] = {16,18,20,22,24,26,28,30,36,38,39,41};

widget_printerInfo iconWidgetInfo(
	"iconWidget",
	12,
	iconWidget_names,
	iconWidget_offsets,
	"wwwwwwwwwbwd",
	&iconWidget_vftable
	);

widget_printerInfo *widgetInfos[] = {&borderInfo, &textEntryWidgetInfo,
										&buttonInfo, &iconWidgetInfo, &textWidgetInfo};

void inspect(widget_printerInfo *inf, widget *w) {
	printf("Detected %s\n", inf->widgetName);
	for(int i = 0; i < inf->n; i++) {
		switch(inf->types[i]) {
		case 'w':
			printf("%s: %d\n", inf->names[i], (int)*(__int16*)((char*)w+inf->offsets[i]));
			break;
		case 'b':
			printf("%s: %d\n", inf->names[i], (int)*(char*)((char*)w+inf->offsets[i]));
			break;
		case 'd':
			printf("%s: %d\n", inf->names[i], *(int*)((char*)w+inf->offsets[i]));
			break;
		}
	}
	printf("\n");
}

void inspect_widget(widget* w) {
	for(int i = 0; i < Elements_in(widgetInfos); i++) {
		if(w->vtable == widgetInfos[i]->vtable) {
			inspect(widgetInfos[i], w);
			return;
		}
	}
	printf("Unsupported widget detected (list box, drop down, or dimmer)\n\n");
}