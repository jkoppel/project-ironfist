#include <stack>

#include "editor.h"
#include "artifacts.h"
#include "base.h"
#include "string.h"
#include "game/game.h"
#include "gui/gui.h"
#include "gui/msg.h"
#include "overlay.h"
#include "spell/spell_constants.h"

// That "const" is a fiction -- the original ShowErrorMessage mutates
// its arguments. This was fine in the original Heroes II, which
// placed constant strings in read-write memory, but not for a
// modern compiler
extern void __fastcall ShowErrorMessage_orig(const char *str);

void __fastcall ShowErrorMessage(const char *str) {
	std::string buf(str);
	ShowErrorMessage_orig(&buf[0]);
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
    if (msg.xCoordOrKeycode == GUI_MESSAGE_MOUSE_CLICK) {
      if (msg.yCoordOrFieldID == FIELD_ID_SPELL_SCROLL_PAYLOAD) {
        OriginalSpell = GUIGetDropdownSelection(gpCellEditDialog, FIELD_ID_SPELL_SCROLL_PAYLOAD);
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

int __cdecl WinConditionHandler() {
  if (gpMapHeader.winConditionType != WIN_CONDITION_FIND_ARTIFACT) {
    return WinConditionHandler_orig();
  }

  const int WIN_CONDITION_EXTRA = 251;

  // Add artifact names to the dropdown list.
  GUIDroplistClear(gpSpecEditDialog, WIN_CONDITION_EXTRA);
  GUIDroplistAdd(gpSpecEditDialog, WIN_CONDITION_EXTRA, "Ultimate Artifact");
  for (int i = 0; i <= MAX_BASE_ARTIFACT; ++i) {
    GUIDroplistAdd(gpSpecEditDialog, WIN_CONDITION_EXTRA, GetArtifactName(i));
  }
  for (int i = MIN_EXPANSION_ARTIFACT; i < NUM_SUPPORTED_ARTIFACTS; ++i) {
    if (IsArtifactValid(i)) {
      GUIDroplistAdd(gpSpecEditDialog, WIN_CONDITION_EXTRA, GetArtifactName(i));
    }
  }

  // Select the current winning artifact in the list.
  int index = gpMapHeader.winConditionArgumentOrLocX;
  if (index - 1 > MAX_BASE_ARTIFACT) {  // -1 allows for generic ultimate artifact at index 0
    // Skip the unused artifacts between the base game and expansion lists.
    index -= MIN_EXPANSION_ARTIFACT - MAX_BASE_ARTIFACT - 1;
  }
  GUISetDropdownSelection(gpSpecEditDialog, WIN_CONDITION_EXTRA, index);
  return 0;
}

// Convert the index of the selected artifact from the droplist to the real
// artifact id.
int __fastcall FillInWinCondition(int index) {
  if (gpMapHeader.winConditionType != WIN_CONDITION_FIND_ARTIFACT) {
    return FillInWinCondition_orig(index);
  }

  int artifactId = index - 1;  // generic ultimate artifact at index 0
  if (artifactId > MAX_BASE_ARTIFACT) {
    // Skip the unused artifacts between the base game and expansion lists.
    artifactId += MIN_EXPANSION_ARTIFACT - MAX_BASE_ARTIFACT - 1;
  }

  // Win condition stores an off-by-one value to allow for the generic
  // ultimate artifact at index 0.
  gpMapHeader.winConditionArgumentOrLocX = artifactId + 1;
  return 0;
}

signed int editManager::GetOverlayID(int x, int y) {
  unsigned __int16 v3; // ax@23
  signed int result; // eax@41
  mapCell *tile; // [sp+10h] [bp-20h]@1
  signed int v6; // [sp+14h] [bp-1Ch]@1
  signed int j; // [sp+18h] [bp-18h]@46
  int i; // [sp+1Ch] [bp-14h]@42
  int v9; // [sp+20h] [bp-10h]@1
  mapCellExtra *v10; // [sp+24h] [bp-Ch]@7
  mapCellExtra *v11; // [sp+24h] [bp-Ch]@26
  signed int objIndex; // [sp+28h] [bp-8h]@1
  int v13; // [sp+2Ch] [bp-4h]@1

  v6 = -1;
  v9 = -1;
  objIndex = -1;
  v13 = 0;
  tile = &gpMap.tiles[y * gpMap.width + x];
  if(gpMap.tiles[y * gpMap.width + x].overlayIndex == -1) {
    if(tile->objectIndex != 0xFF) {
      if(!tile->isShadow && tile->objTileset != TILESET_FLAG && tile->objTileset != TILESET_EXTRA_OVERLAY) {
        v9 = tile->objTileset;
        objIndex = tile->objectIndex;
        v3 = tile->extraInfo;
        v13 = v3 & 1;
      }

      if(tile->extraIdx && gpMap.cellExtras[tile->extraIdx].objectIndex != 255)
        v11 = &gpMap.cellExtras[tile->extraIdx];
      else
        v11 = nullptr;
      while(v11) {
        if((!(v11->field_4_1) || v13)
          && !v11->field_4_2 && v11->objTileset != TILESET_FLAG && v11->objTileset != TILESET_EXTRA_OVERLAY) {
          v9 = v11->objTileset;
          objIndex = v11->objectIndex;
          v13 = v11->field_4_1;
        }
        if(v11->nextIdx && gpMap.cellExtras[v11->nextIdx].objectIndex != 255)
          v11 = &gpMap.cellExtras[v11->nextIdx];
        else
          v11 = nullptr;
      }
    }
  } else {
    if(tile->overlayTileset != TILESET_FLAG && tile->overlayTileset != TILESET_EXTRA_OVERLAY) {
      v9 = tile->overlayTileset;
      objIndex = tile->overlayIndex;
    }

    if(tile->extraIdx && gpMap.cellExtras[tile->extraIdx].overlayIndex != 255)
      v10 = &gpMap.cellExtras[tile->extraIdx];
    else
      v10 = nullptr;
    while(v10) {
      if(v10->tileset != TILESET_FLAG && v10->tileset != TILESET_EXTRA_OVERLAY) {
        v9 = v10->tileset;
        objIndex = v10->overlayIndex;
      }
      if((unsigned short)v10->nextIdx && gpMap.cellExtras[(unsigned short)v10->nextIdx].overlayIndex != 255)
        v10 = &gpMap.cellExtras[(unsigned short)v10->nextIdx];
      else
        v10 = nullptr;
    }
  }

  if(v9 == -1) {
    result = -1;
  } else {
    for(i = 0; i < gNumOverlays; ++i) {
      if(gOverlayDatabase[i].tileset == v9) {
        for(j = 0; j < 48; ++j) {
          if(gOverlayDatabase[i].fullGridIconIndices[j] == objIndex) {
            v6 = i;
            goto LABEL_52;
          }
        }
      }
    }
  LABEL_52:
    result = v6;
  }
  return result;
}