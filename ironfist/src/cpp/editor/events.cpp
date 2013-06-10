#include <windows.h>

#include "editor/events.h"
#include "editor/resource.h"

extern void* hwndApp;

int gbUsingWindowsGUI = 0;

extern long __stdcall AppWndProc_orig(void*, unsigned int, unsigned int, long);

extern "C" void __fastcall PollSound_orig();

extern "C" void __fastcall PollSound() {
	//if(!gbUsingWindowsGUI)
		PollSound_orig();
}

long __stdcall AppWndProc(void* a, unsigned int b, unsigned int c, long d) {
	//if(gbUsingWindowsGUI) {
	//	return DefWindowProc((HWND)a,b,c,d);
	//} else {
		return AppWndProc_orig(a,b,c,d);
	//}
}

BOOL CALLBACK EditTownProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	PollSound();
	switch(Message)
    {
        case WM_INITDIALOG:

        return TRUE;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case IDOK:
                    EndDialog(hwnd, IDOK);
                break;
                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                break;
            }
        break;
        default:
            return FALSE;
    }
    return TRUE;
}

extern void* hInstApp;

extern int __stdcall AppAbout(void *,unsigned int,unsigned int,long);

int eventsManager::EditTown(int x, int y) {
	gbUsingWindowsGUI = 1;
	DialogBoxParamA((HINSTANCE)hInstApp, "EDIT_TOWN",  (HWND)hwndApp, (DLGPROC)EditTownProc, 0);
	gbUsingWindowsGUI = 0;
	return this->EditTown_orig(x,y);
}