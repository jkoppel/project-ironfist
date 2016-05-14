#include "resource/resourceManager.h"
#include "base.h"
#include "combat/combat.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "manager.h"
#include "adventure/adv.h"
#include "gui/gui.h"
#include "resource/resources.h"
#include "town/town.h"
#include "sound/sound.h"
#include "prefs.h"

#pragma pack(push,1)

class executive {
public:
	char _[16];
	executive();
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
extern resourceManager* gpResourceMAnager;
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

	//This was part of the workaround; leaving in,
	//because not yet tested that it can be removed
	DWORD old_x = read_pref<DWORD>("Main Game X");
	DWORD old_y = read_pref<DWORD>("Main Game Y");
	DWORD old_width = read_pref<DWORD>("Main Game Width");
	DWORD old_height = read_pref<DWORD>("Main Game Height");
	ResizeWindow(old_x == (DWORD)(-1) ? 0 : old_x,
				 old_y == (DWORD)(-1) ? 0 : old_y,
				 old_width == (DWORD)(-1) ? 640 : old_width,
				 old_height == (DWORD)(-1) ? 480 : old_height);

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