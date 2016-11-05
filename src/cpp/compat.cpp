/*
* The Heroes II binary contains an old C++ runtime. When Ironfist
* is compiled, it adds a new C++ runtime. This file fixes compatibility
* problems.
*
* See also comments in revitalize_exports.inc
*/

#ifndef COMPAT_H
#define COMPAT_H

#include<Windows.h>

#include "driver.h"

/*
* Both runtimes have their own heap. We force the reassembled
* Heroes II code to put C++ objects on the new runtime's heap.
*/

extern "C" void* __cdecl op_new(unsigned int x) {
	return operator new(x);
}

extern "C" void __cdecl op_del(void* x) {
	operator delete(x);
}

/*
* We ensure that the startup routines of both
* runtimes get called.
*/

extern "C" {
	void _start_asm();
}


int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	IronfistInit();
	_start_asm();
	return 0;
}

#endif
