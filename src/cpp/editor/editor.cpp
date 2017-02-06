#include <stack>

#include "editor.h"

#include "base.h"

#include "string.h"

#include "spell\spells.cpp"

// That "const" is a fiction -- the original ShowErrorMessage mutates
// its arguments. This was fine in the original Heroes II, which
// placed constant strings in read-write memory, but not for a
// modern compiler
extern void __fastcall ShowErrorMessage_orig(const char *str);

void __fastcall ShowErrorMessage(const char *str) {
	char *buf = (char*)ALLOC(strlen(str) + 1);
	strcpy(buf, str);

	ShowErrorMessage_orig(buf);

	FREE(buf);
}

extern fullMap gpMap;

std::stack<fullMap*> undoStack;

// This is used for Undo action in editor
// It copies the map and saves it in a stack
void * __cdecl CopyMap(void) {
	fullMap *tmp = (fullMap *)operator new (sizeof(fullMap));
	tmp->height = gpMap.height;
	tmp->width = gpMap.width;
	tmp->numCellExtras = gpMap.numCellExtras;
	tmp->cellExtras = (mapCellExtra *)operator new(sizeof(mapCellExtra) * tmp->numCellExtras);
	tmp->tiles = (mapCell *)operator new(sizeof(mapCell) * tmp->height * tmp->width);
	memcpy(tmp->tiles, gpMap.tiles, sizeof(mapCell) * tmp->height * tmp->width);
	memcpy(tmp->cellExtras, gpMap.cellExtras, 15 * tmp->numCellExtras);
	undoStack.push(tmp);
	return NULL;
}

// Read it as "Point to previously saved map"
// In the original game it was just "Make a duplicate and return a pointer to it"
// The assembly code was changed for this to work. Search for "undo" in assembly
void * fullMap::Clone(fullMap *oth) {
	if (undoStack.size()) {
		delete gpMap.cellExtras;
		delete gpMap.tiles;
		gpMap = *undoStack.top();
		undoStack.pop();
	}
	return NULL;
}

void editManager::InitializeMap(int random, int width, int height) {
	while (undoStack.size()) {
		fullMap *i = undoStack.top();
		if (i->cellExtras)
			delete i->cellExtras;
		if (i->tiles)
			delete i->tiles;
		undoStack.pop();
	}
	this->InitializeMap_orig(random, width, height);
}

void editManager::SpellScrollEditDialog(int *a1) {
  tag_message evt; // [sp+1Ch] [bp-20h]@4
  int i; // [sp+38h] [bp-4h]@4
  heroWindow *gpCellEditDialog;
  int OriginalValue;

  OriginalValue = *a1;
  gpCellEditDialog = new heroWindow(0, 0, "x_spedit.bin");
  
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.xCoordOrKeycode = GUI_MESSAGE_SET_TEXT;  //change to GUI_MESSAGE_SET_TEXT??? They have equal values and the type would be correct
  evt.payload = &gText;
  evt.yCoordOrFieldID = 101;
  strcpy((char *)&gText, "Spell Scroll");
  gpCellEditDialog->BroadcastMessage(evt);
  evt.yCoordOrFieldID = 102;
  strcpy((char *)&gText, "Attach Spell");
  gpCellEditDialog->BroadcastMessage(evt);
  evt.xCoordOrKeycode = GUI_MESSAGE_DROPLIST_ADD;
  evt.yCoordOrFieldID = 100;
  for (i = 0; i < NUM_SPELLS; ++i) {
    sprintf((char *)&gText, "%s", gSpellNames[i]);
    evt.payload = &gText;
    gpCellEditDialog->BroadcastMessage(evt);
  }
  evt.xCoordOrKeycode = 54;
  evt.payload = (void *)*a1;
  gpCellEditDialog->BroadcastMessage(evt);
  gpWindowManager->DoDialog(gpCellEditDialog, sub_418DE3, 0);
  delete(gpCellEditDialog);
  if (gpWindowManager->buttonPressedCode != 30721) {
    *a1 = OriginalValue;
    gpEditManager->setOnEventUpdate = 1;
  }
  gpEditManager->UpdateCursor();
  RedrawEditPane();
}

signed int __fastcall sub_418DE3(tag_message *msg) {
  int v2; // [sp+14h] [bp-14h]@3
  int v3; // [sp+18h] [bp-10h]@2
  INPUT_EVENT_CODE evtCode; // [sp+1Ch] [bp-Ch]@1

  evtCode = msg->eventCode;
  if (evtCode == INPUT_KEYDOWN_EVENT_CODE) {
    if (msg->xCoordOrKeycode == 1) {
      msg->eventCode = INPUT_GUI_MESSAGE_CODE;
      msg->yCoordOrFieldID = 10;
      msg->xCoordOrKeycode = msg->yCoordOrFieldID;
      return 2;
    }
  } else if (evtCode == INPUT_GUI_MESSAGE_CODE) {
    v3 = msg->xCoordOrKeycode;
    if (v3 == 12) {
      if (msg->yCoordOrFieldID == 100) {
        msg->xCoordOrKeycode = 55;
        gpCellEditDialog->BroadcastMessage(msg);
        OriginalValue = (int)msg->payload;
      }
    } else if (v3 == 13) {
      v2 = msg->yCoordOrFieldID;
      if (v2 >= 30721 && v2 <= 30722) {
        gpWindowManager->buttonPressedCode = msg->yCoordOrFieldID;
        msg->eventCode = INPUT_GUI_MESSAGE_CODE;
        msg->yCoordOrFieldID = 10;
        msg->xCoordOrKeycode = msg->yCoordOrFieldID;
        return 2;
      }
    }
  }
  return 1;
}