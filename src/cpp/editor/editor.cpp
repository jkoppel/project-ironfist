#include <stack>

#include "editor.h"
#include "base.h"
#include "string.h"
#include "gui/gui.h"
#include "gui/msg.h"
#include "spell/spell_constants.h"

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

void editManager::SpellScrollEditDialog(int *RelatedToSpellIdx) {
  int i; // [sp+38h] [bp-4h]@4
  const int WINDOW_LABEL = 101;
  const int DROPLIST_LABEL = 102;
  const int FIELD_ID_SPELL_SCROLL_PAYLOAD = 100;
  const int KEYCODE_UNKNOWN_1 = 54;
  OriginalSpell = *RelatedToSpellIdx;
  gpCellEditDialog = new heroWindow(0, 0, "x_spedit.bin");
  
  GUISetText(gpCellEditDialog, WINDOW_LABEL, "Spell Scroll");
  GUISetText(gpCellEditDialog, DROPLIST_LABEL, "Attach Spell");
  for (i = 0; i < NUM_SPELLS; ++i) {
    GUIDroplistAdd(gpCellEditDialog, FIELD_ID_SPELL_SCROLL_PAYLOAD, gSpellNames[i]);
  }
  GUIBroadcastMessage(gpCellEditDialog, FIELD_ID_SPELL_SCROLL_PAYLOAD, KEYCODE_UNKNOWN_1, (void *)*RelatedToSpellIdx);
  gpWindowManager->DoDialog(gpCellEditDialog, SpellScrollEditDialogCallback, 0);
  delete(gpCellEditDialog);
  if (gpWindowManager->buttonPressedCode != BUTTON_CANCEL) {
    *RelatedToSpellIdx = OriginalSpell;
    gpEditManager->setOnEventUpdate = 1;
  }
  gpEditManager->UpdateCursor();
  RedrawEditPane();
}

int __fastcall SpellScrollEditDialogCallback(tag_message& msg) {
  const int FIELD_ID_SPELL_SCROLL_PAYLOAD = 100;
  const int KEYCODE_UNKNOWN_2 = 10;

  if (msg.eventCode == INPUT_KEYDOWN_EVENT_CODE) {
    if (msg.xCoordOrKeycode == 1) {
      msg.eventCode = INPUT_GUI_MESSAGE_CODE;
      msg.yCoordOrFieldID = KEYCODE_UNKNOWN_2;
      msg.xCoordOrKeycode = msg.yCoordOrFieldID;
      return GUI_MESSAGE_REPAINT;
    }
  } else if (msg.eventCode == INPUT_GUI_MESSAGE_CODE) {
    if (msg.xCoordOrKeycode == GUI_MESSAGE_BUTTON_NOT_PRESSED) {
      if (msg.yCoordOrFieldID == FIELD_ID_SPELL_SCROLL_PAYLOAD) {
        OriginalSpell = GUIGetDropdownSelection(gpCellEditDialog, (void *)msg.payload);
        // "return 1;" will be reached at the end of this function.
      }
    } else if (msg.xCoordOrKeycode == GUI_MESSAGE_BUTTON_PRESSED) {
      if (msg.yCoordOrFieldID >= BUTTON_CANCEL && msg.yCoordOrFieldID <= BUTTON_OK) {
        gpWindowManager->buttonPressedCode = msg.yCoordOrFieldID;
        msg.eventCode = INPUT_GUI_MESSAGE_CODE;
        msg.yCoordOrFieldID = KEYCODE_UNKNOWN_2;
        msg.xCoordOrKeycode = msg.yCoordOrFieldID;
        return GUI_MESSAGE_REPAINT;
      }
    }
  }
  return 1;
}