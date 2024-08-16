#include "swapManager.h"

#include "gui/dialog.h"
#include "resource/resourceManager.h"

extern int giMonoIconSkip;

int swapManager::Open(int a2) {
	heroWindow *win; // [sp+10h] [bp-28h]@1
	tag_message evt; // [sp+14h] [bp-24h]@6

	swapManager::Reset();

	this->window = new heroWindow(0, 0, "swapwin.bin");

	SetWinText(this->window, 21);
	evt.eventCode = INPUT_GUI_MESSAGE_CODE;
	evt.xCoordOrKeycode = 9;
	sprintf(gText, "port%04d.icn", this->heroes[0]->heroID);
	evt.yCoordOrFieldID = 65;
	evt.payload = gText;
	this->window->BroadcastMessage(evt);
	sprintf(gText, "port%04d.icn", this->heroes[1]->heroID);
	evt.yCoordOrFieldID = 66;
	this->window->BroadcastMessage(evt);
	evt.xCoordOrKeycode = 3;
	sprintf(gText, "%s meets %s", this->heroes[0]->name, this->heroes[1]->name);
	evt.payload = gText;
	evt.yCoordOrFieldID = 77;
	this->window->BroadcastMessage(evt);
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 8; ++j) {
			if(this->heroes[i]->numSecSkillsKnown <= j) {
				evt.xCoordOrKeycode = 6;
				evt.yCoordOrFieldID = j + 8 * i + 200;
				evt.payload = (void *)4;
				this->window->BroadcastMessage(evt);
			} else {
				evt.xCoordOrKeycode = 4;
				evt.yCoordOrFieldID = j + 8 * i + 200;
				int imgIdx;
				int sSkill = this->heroes[i]->GetNthSS(j);
				if(sSkill == SECONDARY_SKILL_WISDOM & this->heroes[i]->factionID == FACTION_CYBORG)
					imgIdx = 14; // Cybernetics secondary skill small image
				else
					imgIdx = sSkill;				
				evt.payload = (void *)imgIdx;
				this->window->BroadcastMessage(evt);
				evt.xCoordOrKeycode = 3;
				evt.yCoordOrFieldID = j + 8 * i + 216;
				evt.payload = gText;
				
				int skillLevel = this->heroes[i]->GetSSLevel(sSkill);
				sprintf(gText, "%d", skillLevel);
				this->window->BroadcastMessage(evt);
			}
		}
	}
	evt.eventCode = INPUT_GUI_MESSAGE_CODE;
	evt.xCoordOrKeycode = 6;
	evt.payload = (void *)2;
	for(int i = 1; i <= 6; i++) {
		evt.yCoordOrFieldID = i;
		gpAdvManager->adventureScreen->BroadcastMessage(evt);
	}
	this->Update();
	gpWindowManager->AddWindow(this->window, -1, 1);
	KBChangeMenu(hmnuAdv);
	giMonoIconSkip = 2;
	this->swapButtonIcn = gpResourceManager->GetIcon("swapbtn.icn");
	giMonoIconSkip = -1;
	gpMouseManager->SetPointer(0);
	this->type = 256;
	this->idx = a2;
	this->ready = 1;
	strcpy(this->name, "swapManager");
	return 0;
}