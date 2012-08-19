#include "lifted/resource/resourceManager.h"
#include "tied/combat/combat.h"
#include "tied/game/game.h"
#include "tied/manager.h"
#include "tied/adventure/adv.h"
#include "tied/gui/gui.h"
#include "tied/resource/resources.h"


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
};

class soundManager {
public:
	char _[1714];
	soundManager();
};

class highScoreManager {
public:
	char _[99];
	highScoreManager();
};

class advManager {
public:
	char _[894];
	advManager();
};

class townManager {
public:
	char _[378];
	townManager();
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
extern townManager* gpTownManager;
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