#include "swapManager.h"

#include "gui/dialog.h"
#include "resource/resourceManager.h"

extern int giMonoIconSkip;

int swapManager::Open(int a2) {
	swapManager::Reset();
	this->window = new heroWindow(0, 0, "swapwin.bin");
	SetWinText(this->window, 21);

	sprintf(gText, "port%04d.icn", this->heroes[0]->heroID);
	GUIBroadcastMessage(this->window, 65, 9, gText);

	sprintf(gText, "port%04d.icn", this->heroes[1]->heroID);
	GUIBroadcastMessage(this->window, 66, 9, gText);

	sprintf(gText, "%s meets %s", this->heroes[0]->name, this->heroes[1]->name);
	GUIBroadcastMessage(this->window, 77, 3, gText);

	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < MAX_SECONDARY_SKILLS; ++j) {
			if(this->heroes[i]->numSecSkillsKnown <= j) {
				GUIBroadcastMessage(this->window, j + 8 * i + 200, 6, (void *)4);
			} else {
				int imgIdx;
				int sSkill = this->heroes[i]->GetNthSS(j);
				if(sSkill == SECONDARY_SKILL_WISDOM && this->heroes[i]->factionID == FACTION_CYBORG)
					imgIdx = 14; // Cybernetics secondary skill small image
				else
					imgIdx = sSkill;

				GUIBroadcastMessage(this->window, j + 8 * i + 200, 4, (void *)imgIdx);

				sprintf(gText, "%d", this->heroes[i]->GetSSLevel(sSkill));
				GUIBroadcastMessage(this->window, j + 8 * i + 216, 3, gText);
			}
		}
	}
	
	for(int i = 1; i <= 6; i++) {
		GUIBroadcastMessage(this->window, i, 6, (void *)2);
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