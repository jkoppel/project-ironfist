
#ifndef IMPORT
#define IMPORT

#include "resource/resources.h"

extern "C" {
	int Icon__drawToScreen();
	void assertTrue_asm();
	unsigned int computeFileID_asm();
	void terminate_asm();
	void * KBAlloc_asm();
	void debugLog_asm();
	void yieldToGlobalUpdater_asm();
	int getFileOffset_asm();
	AbstractManager * AbstractManager_constructor_asm();

	Font* Font_constructor_asm();
	Icon* Icon_constructor_asm();
	Sample* Sample_constructor_asm();
	Sequence* Sequence_constructor_asm();
	Tileset* Tileset_constructor_asm();
	Bitmap* Bitmap_constructorFromFile_asm();
	Palette* Palette_constructorFromFile_asm();

	void _start();
	int __open(const char*,int,...);
	int __read(UINT, void*, DWORD);
	int __lseek(int, LONG, DWORD);
}

extern "C" int main() {
	_start();
	return 0;
}

Sequence * Sequence_constructor(Sequence * __this, const char * filename) {
        __asm {
                push filename
                mov ecx, __this
                call Sequence_constructor_asm
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
        }
}
Tileset * Tileset_constructor(Tileset * __this, int  fileID) {
        __asm {
                push fileID
                mov ecx, __this
                call Tileset_constructor_asm
        }
}
Bitmap * Bitmap_constructorFromFile(Bitmap * __this, int  fileID) {
        __asm {
                push fileID
                mov ecx, __this
                call Bitmap_constructorFromFile_asm
        }
}
Palette * Palette_constructorFromFile(Palette * __this, int  fileID) {
        __asm {
                push fileID
                mov ecx, __this
                call Palette_constructorFromFile_asm
        }
}

void debugLog(void * msg) {
        __asm {
                mov ecx, msg
                call debugLog_asm
        }
}
Font * Font_constructor(Font * ecx0, int  fileID) {
        __asm {
                push fileID
                mov ecx, ecx0
                call Font_constructor_asm
        }
}
Icon * Icon_constructor(Icon * __this, int  fileID) {
        __asm {
                push fileID
                mov ecx, __this
                call Icon_constructor_asm
        }
}


int KBAlloc(size_t  a1, char * a2, int  caller_lineno) {
        __asm {
                push caller_lineno
                mov ecx, a1
                mov edx, a2
                call KBAlloc_asm
        }
}
signed int getFileOffset(int  a1) {
        __asm {
                push a1
                call getFileOffset_asm
        }
}

void yieldToGlobalUpdater() {
        __asm {
                call yieldToGlobalUpdater_asm
        }
}


int Icon::drawToScreen(int  x, int  y, int  spriteIdx, int  mirror) {
        __asm {
                push mirror
                push spriteIdx
                push y
                push x
                mov ecx, this
                call Icon__drawToScreen
        }
}

void assertTrue(int  a1, char * a2, int  lineno) {
        __asm {
                push lineno
                mov ecx, a1
                mov edx, a2
                call assertTrue_asm
        }
}
unsigned int computeFileID(const char * c) {
        __asm {
                mov ecx, c
                call computeFileID_asm
        }
}
void terminate(char * c) {
        __asm {
                mov ecx, c
                call terminate_asm
        }
}

AbstractManager * AbstractManager_constructor(AbstractManager * __this) {
        __asm {
                mov ecx, __this
                call AbstractManager_constructor_asm
        }
}


#endif