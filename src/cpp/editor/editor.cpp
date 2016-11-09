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

	if (undoStack.size() > 10)
	{
		//undoStack.back().Close();
		undoStack.pop_front();
	}
	fullMap *tmp = new fullMap();
	tmp->Clone(&gMap2);

	undoStack.push_back(tmp);
	return NULL;
}

void * fullMap::Clone(fullMap *oth) {
	if(this->cellExtras)
		delete(this->cellExtras);
	/*if (this->tiles)
		delete (this->tiles);*/

	this->height = oth->height;
	this->width = oth->width;
	// copy data to another fullMap
	this->numCellExtras = oth->numCellExtras;
	this->cellExtras = (mapCellExtra *)operator new(sizeof(mapCellExtra) * this->numCellExtras);
	memcpy(this->tiles, oth->tiles, sizeof(mapCell) * this->height * this->width);
	memcpy(this->cellExtras, oth->cellExtras, 15 * this->numCellExtras);

	if (this == &gpMap)
	{
		if (undoStack.size() > 2)
		{
			// Close?
			undoStack.pop_back();
		}
		if(undoStack.size())
			gMap2 = *undoStack.back();
	}
	return NULL;
}
