#include <io.h>
#include <fcntl.h>
#include "adventure/adv.h"
#include "analytics.h"
#include "base.h"
#include "combat/combat.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "gui/gui.h"
#include "manager.h"
#include "prefs.h"
#include "registry_prefs.h"
#include "resource/resourceManager.h"
#include "resource/resources.h"
#include "scripting/callback.h"
#include "sound/sound.h"
#include "town/town.h"

#pragma pack(push,1)

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

extern inputManager* gpInputManager;
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
std::string RegAppPath;
std::string RegCDRomPath;
extern void __fastcall SetFullScreenStatus(int);
extern void __fastcall ResizeWindow(int,int,int,int);
extern int __fastcall SetupCDDrive_orig();

int __fastcall SetupCDDrive() {
  RegAppPath = read_pref<std::string>("AppPath");
  std::string fileToCheck = RegAppPath + "\\HEROES2\\ANIM\\intro.smk";
  // Check if a folder with videos exists in game's folder
  int fd = _open(fileToCheck.c_str(), O_BINARY);
  if(fd == -1) {
    return SetupCDDrive_orig();
  } else {
    close(fd);
    return 1;
  }
}

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
	send_event(gameAction, analytics_open);

	//This was part of the workaround; leaving in,
	//because not yet tested that it can be removed
	DWORD old_x = read_registry_pref<DWORD>("Main Game X");
	DWORD old_y = read_registry_pref<DWORD>("Main Game Y");
	DWORD old_width = read_registry_pref<DWORD>("Main Game Width");
	DWORD old_height = read_registry_pref<DWORD>("Main Game Height");
	ResizeWindow(old_x == (DWORD)(-1) ? 0 : old_x,
		old_y == (DWORD)(-1) ? 0 : old_y,
		old_width == (DWORD)(-1) ? 640 : old_width,
		old_height == (DWORD)(-1) ? 480 : old_height);
	
  RegCDRomPath = read_pref<std::string>("CDDrive");

	if(iCDRomErr == 1 || iCDRomErr == 2) {
		//Setting to no-CD mode, but not showing message forbidding play
		SetPalette(gPalette->contents, 1);
		gpMouseManager->ShowColorPointer();
		gbNoCDRom = 1;
		int oldNoSound = gbNoSound;
		gbNoSound = 1;

    // Neither CD exists nor HEROES2 folder exists in game's folder
    if(iCDRomErr != 1)
      H2MessageBox("Welcome to no-CD mode. Videos will not work, "
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

int executive::AddManager(baseManager *mgr, int argIdx) {
  int ret = this->AddManager_orig(mgr, argIdx);
  if (mgr == gpAdvManager)
    if (!strcmp(gpGame->lastSaveFile, "NEWGAME") && !gpGame->firstDayEventDone) { // that tells us it's a NEW game, not a loaded game. A loaded game can't have NEWGAME as a save filename
        ScriptCallback("OnMapStart");
        ScriptCallback("OnNewDay", gpGame->month, gpGame->week, gpGame->day);
        gpGame->firstDayEventDone = true;
    }
  return ret;
}

extern void* hwndApp;
extern int __fastcall oldmain_orig();

int __fastcall oldmain() {
  // Disallow resizing game window using mouse
  SetWindowLong((HWND)hwndApp, GWL_STYLE, GetWindowLong((HWND)hwndApp, GWL_STYLE) &~ WS_SIZEBOX);
  return oldmain_orig();
}