#include "resource/resourceManager.h"
#include "base.h"
#include "manager.h"

#include "artifacts.h"
#include "editor.h"
#include "gui/gui.h"
#include "manager.h"
#include "resource/resources.h"


#pragma pack(push,1)

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

extern inputManager* gpInputManager;
extern mouseManager* gpMouseManager;
extern heroWindowManager* gpWindowManager;
extern resourceManager* gpResourceMAnager;
extern soundManager* gpSoundManager;

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
