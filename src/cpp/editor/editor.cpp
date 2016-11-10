#include <stack>

#include "editor.h"

#include "base.h"

#include "string.h"

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