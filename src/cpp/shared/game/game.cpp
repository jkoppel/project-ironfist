#include<string>

#include "analytics.h"
#include "base.h"
#include "combat/creatures.h"
#include "game/game.h"
#include "prefs.h"
#include "scripting/callback.h"
#include "scripting/scripting.h"
#include "spell/spells.h"


char* gAlignmentNames[13] = {"Knight", "Barbarian", "Sorceress", "Warlock", "Wizard", "Necromancer",
                             "Multiple", "Random", NULL, NULL, NULL, NULL,
                             "Cyborg"};

int game::GetRandomNumTroops(int creat) {
	return Random(gMonRandBound[creat][0], gMonRandBound[creat][1]);
}

extern int gbNoCDRom;


int game::SetupGame() {
	int oldNoCDRom = gbNoCDRom;
	gbNoCDRom = 0;
	int res = this->SetupGame_orig();
	gbNoCDRom = oldNoCDRom;
	return res;
}

void game::RandomizeHeroPool() {
	signed int idx;

	for( idx = 0; idx < MAX_HEROES; idx++) {
		this->heroes[idx].experience = Random(0, 50) + 40;
		this->SetRandomHeroArmies(idx, 0);
		this->heroes[idx].remainingMobility = this->heroes[idx].CalcMobility();
		this->heroes[idx].mobility = this->heroes[idx].remainingMobility;
		this->heroes[idx].randomSeed = Random(1, 255);
		this->heroes[idx].wisdomLastOffered = 1;
		switch(this->heroes[idx].factionID) {
		case FACTION_SORCERESS:
			this->heroes[idx].AddSpell(SPELL_BLESS);
			break;
		case FACTION_WARLOCK:
			this->heroes[idx].AddSpell(SPELL_CURSE);
			break;
		case FACTION_NECROMANCER:
			this->heroes[idx].AddSpell(SPELL_HASTE);
			break;
		case FACTION_WIZARD:
			this->heroes[idx].AddSpell(SPELL_STONESKIN);
			break;
		}
	}
}

extern char gMapName[]; // the map selected in the list
extern char gLastFilename[];
extern signed char xIsExpansionMap;

void game::InitNewGame(struct SMapHeader *a) {
	if (!strlen(gLastFilename)) { // game just started, no map was played yet
		std::string lastPlayed;
		if (xIsExpansionMap)
			lastPlayed = read_pref<std::string>("Last Map expansion");
		else
			lastPlayed = read_pref<std::string>("Last Map");

		if (lastPlayed.length() < 20) { // otherwise means no registry keys exist yet
			strcpy(gMapName, lastPlayed.c_str());
			strcpy(this->mapFilename, lastPlayed.c_str());
		}
	}
	this->InitNewGame_orig(a);
}

void game::NewMap(char* mapname) {
  send_event(mapAction, mapname);
  if (xIsExpansionMap)
	  write_pref("Last Map expansion", std::string(gMapName));
  else
	  write_pref("Last Map", std::string(gMapName));
  this->ResetIronfistGameState();
  this->NewMap_orig(mapname);
  ScriptingInit(std::string(mapname));
  gpGame->firstDayEventDone = false;
  gpGame->allowAIArmySharing = true;
}

void game::NextPlayer() {
	/*
	 * Because heroes no longer regain movement on hire.
	 * we need to make sure all heroes in hero pool regain movement between turns.
	 */
	NextPlayer_orig();
	for(int i = 0; i < MAX_HEROES; i++) {
		hero *h = &this->heroes[i];
		h->mobility = h->CalcMobility();
		h->remainingMobility = h->mobility;
	}
}

void game::PerDay() {
	this->PerDay_orig();
	ScriptCallback("OnNewDay", this->month, this->week, this->day);
}

void game::ResetIronfistGameState() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            this->sharePlayerVision[i][j] = false;
        }
    }
}

extern int gbGameOver;
extern int giEndSequence;

void __fastcall CheckEndGame(int a, int b) {
  CheckEndGame_orig(a, b);
  if (gbGameOver) {
    if (giEndSequence) {
      ScriptCallback("OnMapVictory");
    } else {
      ScriptCallback("OnMapLoss");
    }
  }
}

class philAI {

	char _; // Yes, this is a 1-byte object.

public:
	void RedistributeTroops_orig(armyGroup *, armyGroup *, int, int, int, int, int);
	void RedistributeTroops(armyGroup *army1, armyGroup *army2, int a1, int a2, int a3, int a4, int a5);
};

void philAI::RedistributeTroops(armyGroup *army1, armyGroup *army2, int a1, int a2, int a3, int a4, int a5) {
	if (gpGame->allowAIArmySharing) {
		RedistributeTroops_orig(army1, army2, a1, a2, a3, a4, a5);
	}
}