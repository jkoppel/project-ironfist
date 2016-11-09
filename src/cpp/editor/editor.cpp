#include <deque>

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
extern fullMap gMap2;

std::deque<fullMap*> undoStack;

void * __cdecl CopyMap(void) {
	gMap2.Clone(&gpMap);

	if (undoStack.size() > 10) {
		//undoStack.front().Close();
		undoStack.pop_front();
	}
	fullMap *tmp = (fullMap *)operator new (sizeof(fullMap));
	tmp->cellExtras = nullptr;
	tmp->tiles = nullptr;
	tmp->Clone(&gMap2);
	undoStack.push_back(tmp);
	return NULL;
}

void * fullMap::Clone(fullMap *oth) {
	if(this->cellExtras)
		delete(this->cellExtras);
	if (this->tiles)
		delete(this->tiles);

	// copy data to another fullMap
	this->height = oth->height;
	this->width = oth->width;
	this->numCellExtras = oth->numCellExtras;
	this->cellExtras = (mapCellExtra *)operator new(sizeof(mapCellExtra) * this->numCellExtras);
	this->tiles = (mapCell *)operator new(sizeof(mapCell) * this->height * this->width);
	
	//if(oth->cellExtras)
		memcpy(this->tiles, oth->tiles, sizeof(mapCell) * this->height * this->width);
	//if(oth->tiles)
		memcpy(this->cellExtras, oth->cellExtras, 15 * this->numCellExtras);

	if (this == &gpMap)	{
		if(undoStack.size())
			gpMap = *undoStack.back();
		if (undoStack.size() > 2) {
			undoStack.pop_back();
		}
	}
	return NULL;
}
