#ifndef IMPORT_THUNK
#define IMPORT_THUNK

#include "resource\resources.h"

extern "C" {
	int Icon__drawToScreen();

	Sample * Sample_constructor_asm();
	Icon * Icon_constructor_asm();
	void assertTrue_asm();
	void _start_asm();
	Bitmap * Bitmap_constructorFromFile_asm();
	void terminate_asm();
	unsigned int computeFileID_asm();
	Tileset * Tileset_constructor_asm();
	AbstractManager * AbstractManager_constructor_asm();
	void debugLog_asm();
	signed int getFileOffset_asm();
	Palette * Palette_constructorFromFile_asm();
	Bitmap * Bitmap_constructor_asm();
	Sequence * Sequence_constructor_asm();
	Font * Font_constructor_asm();
	void yieldToGlobalUpdater_asm();
	LPVOID KBAlloc_asm();

	void start();
	int __open(const char*,int,...);
	int __read(UINT, void*, DWORD);
	int __lseek(int, LONG, DWORD);
}
int Icon::drawToScreen( int  x, int  y, int  spriteIdx, int  mirror) {
	__asm {
		push mirror
		push spriteIdx
		push y
		push x
		mov ecx, this
		call Icon__drawToScreen
		add esp, 0
	}
}
Sample * Sample_constructor(Sample * __this, const char * filename, int  a3, int  a4, int  a5) {
	__asm {
		push a5
		push a4
		push a3
		push filename
		mov ecx, __this
		call Sample_constructor_asm
		add esp, 0
	}
}
Icon * Icon_constructor(Icon * __this, int  fileID) {
	__asm {
		push fileID
		mov ecx, __this
		call Icon_constructor_asm
		add esp, 0
	}
}
void assertTrue(int  a1, char * a2, int  lineno) {
	__asm {
		push lineno
		mov ecx, a1
		mov edx, a2
		call assertTrue_asm
		add esp, 0
	}
}
void _start() {
	__asm {
		call _start_asm
		add esp, 0
	}
}
Bitmap * Bitmap_constructorFromFile(Bitmap * __this, int  fileID) {
	__asm {
		push fileID
		mov ecx, __this
		call Bitmap_constructorFromFile_asm
		add esp, 0
	}
}
void terminate(char * __this) {
	__asm {
		mov ecx, __this
		call terminate_asm
		add esp, 0
	}
}
unsigned int computeFileID(const char * __this) {
	__asm {
		mov ecx, __this
		call computeFileID_asm
		add esp, 0
	}
}
Tileset * Tileset_constructor(Tileset * __this, int  fileID) {
	__asm {
		push fileID
		mov ecx, __this
		call Tileset_constructor_asm
		add esp, 0
	}
}
AbstractManager * AbstractManager_constructor(AbstractManager * __this) {
	__asm {
		mov ecx, __this
		call AbstractManager_constructor_asm
		add esp, 0
	}
}
void debugLog(void * __this) {
	__asm {
		mov ecx, __this
		call debugLog_asm
		add esp, 0
	}
}
signed int getFileOffset(int  a1) {
	__asm {
		push a1
		call getFileOffset_asm
		add esp, 4
	}
}
Palette * Palette_constructorFromFile(Palette * __this, int  fileID) {
	__asm {
		push fileID
		mov ecx, __this
		call Palette_constructorFromFile_asm
		add esp, 0
	}
}
Bitmap * Bitmap_constructor(Bitmap * __this, __int16  a2, __int16  width, __int16  height) {
	__asm {
		push height
		push width
		push a2
		mov ecx, __this
		call Bitmap_constructor_asm
		add esp, 0
	}
}
Sequence * Sequence_constructor(Sequence * __this, const char * filename) {
	__asm {
		push filename
		mov ecx, __this
		call Sequence_constructor_asm
		add esp, 0
	}
}
Font * Font_constructor(Font * __this, int  fileID) {
	__asm {
		push fileID
		mov ecx, __this
		call Font_constructor_asm
		add esp, 0
	}
}
void yieldToGlobalUpdater() {
	__asm {
		call yieldToGlobalUpdater_asm
		add esp, 0
	}
}
LPVOID KBAlloc(size_t  a1, char * a2, int  caller_lineno) {
	__asm {
		push caller_lineno
		mov ecx, a1
		mov edx, a2
		call KBAlloc_asm
		add esp, 0
	}
}

#endif