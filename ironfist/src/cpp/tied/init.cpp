#include "lifted/resource/resourceManager.h"
#include "tied/manager.h"
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

class heroWindowManager {
public:
	char _[98];
	heroWindowManager();
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

class fullMap {
public:
	char _[20];
	fullMap();
};

class town {
public:
	char _[0x64];
	town();
};

class hero {
public:
	char _[0xFA];
	hero();
};

class game {
public:
	char _[0xB3E];
	fullMap f;
	char numObelisks;
	town castles[72];
	char _7[81];
	hero h[54];
	char _8[2447];
};

class advManager {
public:
	char _[894];
	advManager();
};

class combatManager {
public:
	char _[63607];
	combatManager();
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

class armyGroup {
public:
	char _[15];
	armyGroup();
};

extern executive* gpExec;
extern inputManager* gpInputManager;
extern mouseManager* gpMouseManager;
extern heroWindowManager* gpWindowManager;
extern resourceManager* gpResourceMAnager;
extern soundManager* gpSoundManager;
extern highScoreManager* gpHighScoreManager;
extern game* gpGame;
extern advManager* gpAdvManager;
extern combatManager* gpCombatManager;
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
	gpGame = new game; //de-inline constructor
	gpAdvManager = new advManager;
	gpCombatManager = new combatManager;
	gpTownManager = new townManager;
	gpSearchArray = new searchArray;
	gpPhilAI = new philAI;
	gpMonGroup = new armyGroup;
	gpBufferPalette = new palette;
}