#include "resource/resourceManager.h"
#include "base.h"
#include "manager.h"
#include "gui/gui.h"
#include "resource/resources.h"


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

class soundManager {
public:
	char _[1714];
	soundManager();
};

class editManager {
public:
	char _[3746];
	editManager();
};

extern executive* gpExec;
extern inputManager* gpInputManager;
extern mouseManager* gpMouseManager;
extern heroWindowManager* gpWindowManager;
extern resourceManager* gpResourceMAnager;
extern soundManager* gpSoundManager;
extern editManager* gpEditManager;

#pragma pack(pop)

void __fastcall InitMainClasses()
{
	gpExec = new executive;
	gpInputManager = new inputManager;
	gpMouseManager = new mouseManager;
	gpWindowManager = new heroWindowManager;
	gpResourceManager = new resourceManager;
	gpSoundManager = new soundManager;
	gpBufferPalette = new palette;
	gpEditManager = new editManager;
}

void __fastcall DeleteMainClasses() {
	delete gpExec;
	delete gpInputManager;
	delete gpMouseManager;
	delete gpWindowManager;
	delete gpResourceManager;
	delete gpSoundManager;
	delete gpBufferPalette;
	delete gpEditManager;
}
