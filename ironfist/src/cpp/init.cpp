#include "adventure/adv.h"
#include "analytics.h"
#include "base.h"
#include "combat/combat.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "gui/gui.h"
#include "manager.h"
#include "resource/resourceManager.h"
#include "resource/resources.h"
#include "sound/sound.h"
#include "town/town.h"

#pragma pack(push,1)

class executive {
public:
  char _[16];
  executive();

  int DoDialog(baseManager *a2);
};

class inputManager {
public:
	char _[2154];
	inputManager();
};

class mouseManager {
public:
	char _[138];
	mouseManager();
	void ShowColorPointer();
};

class highScoreManager {
public:
	char _[99];
	highScoreManager();
};

class searchArray {
public:
	char _[9496];
	searchArray();
};

class philAI {
public:
	char _;
	philAI();
};

extern executive* gpExec;
extern inputManager* gpInputManager;
extern mouseManager* gpMouseManager;
extern heroWindowManager* gpWindowManager;
extern resourceManager* gpResourceMAnager;
extern soundManager* gpSoundManager;
extern highScoreManager* gpHighScoreManager;
extern advManager* gpAdvManager;
extern searchArray* gpSearchArray;
extern philAI* gpPhilAI;
extern armyGroup* gpMonGroup;


#pragma pack(pop)

void __fastcall InitMainClasses()
{
	gpExec = new executive;
	gpInputManager = new inputManager;
	gpMouseManager = new mouseManager;
	gpWindowManager = new heroWindowManager;
	gpResourceManager = new resourceManager;
	gpSoundManager = new soundManager;
	gpHighScoreManager = new highScoreManager;
	gpGame = new game;
	gpAdvManager = new advManager;
	gpCombatManager = new combatManager;
	gpTownManager = new townManager;
	gpSearchArray = new searchArray;
	gpPhilAI = new philAI;
	gpMonGroup = new armyGroup;
	gpBufferPalette = new palette;
}

void __fastcall DeleteMainClasses() {
	delete gpExec;
	delete gpInputManager;
	delete gpMouseManager;
	delete gpWindowManager;
	delete gpResourceManager;
	delete gpSoundManager;
	delete gpHighScoreManager;
	delete gpGame;
	delete gpAdvManager;
	delete gpCombatManager;
	delete gpTownManager;
	delete gpSearchArray;
	delete gpPhilAI;
	delete gpMonGroup;
	delete gpBufferPalette;
}

extern int iCDRomErr;
extern int gbNoCDRom;
extern int gbNoSound;

extern void __fastcall SetFullScreenStatus(int);
extern void __fastcall ResizeWindow(int,int,int,int);

void __fastcall SetupCDRom() {
	
	/*
	 * Previously, this contained a workaround for the problem
	 * described in 
	 * http://stackoverflow.com/questions/13541084/in-newer-windows-window-is-tiny-with-no-borders
     * The workaround was to set the game to fullscreen and back.
	 *
	 * This problem seems to have magically gone away, or
	 * at least was never present on Windows 7 and 8. One
	 * user also complained of frequent Ironfist crashes,
	 * which went away when this was removed. Dr. Memory
	 * reported that those lines did cause a memory error
	 * down the stack.
	 */

	// Sending an Open event to Google Analytics
	send_event(gameAction, open);

	//This was part of the workaround; leaving in,
	//because not yet tested that it can be removed
	HKEY hKey;
	DWORD old_x, old_y, old_width, old_height;
	hKey = 0;
	DWORD cData = 4;
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\New World Computing\\Heroes of Might and Magic 2\\1.0"), 0, KEY_QUERY_VALUE, &hKey);
	RegQueryValueExA(hKey, "Main Game X", 0, NULL, (LPBYTE)&old_x, &cData);
	RegQueryValueExA(hKey, "Main Game Y", 0, NULL, (LPBYTE)&old_y, &cData);
	RegQueryValueExA(hKey, "Main Game Width", 0, NULL, (LPBYTE)&old_width, &cData);
	RegQueryValueExA(hKey, "Main Game Height", 0, NULL, (LPBYTE)&old_height, &cData);
	RegCloseKey(hKey);

	ResizeWindow(old_x, old_y, old_width, old_height);

	if(iCDRomErr == 1 || iCDRomErr == 2) {
		//Setting to no-CD mode, but not showing message forbidding play
		SetPalette(gPalette->contents, 1);
		gpMouseManager->ShowColorPointer();
		gbNoCDRom = 1;
		int oldNoSound = gbNoSound;
		gbNoSound = 1;
		H2MessageBox("Welcome to no-CD mode. Video, opera, and the campaign menus will not work, "
						"but otherwise, have fun!");
		gbNoSound = oldNoSound;
	} else if(iCDRomErr == 3) {
		EarlyShutdown("Startup Error", "Unable to change to the Heroes II directory."
						"  Please run the installation program.");
		exit(0);
	} else if(iCDRomErr == 4) {
		EarlyShutdown("Startup Error", "Unable to find the Heroes II data files.  "
										"Please run the installation program.");
		exit(0);
	}

}
