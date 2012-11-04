#include "base.h"
#include "game/game.h"
#include "spell/spells.h"
#include "combat/creatures.h"


int game::GetRandomNumTroops(int creat) {
	return Random(gMonRandBound[creat][0], gMonRandBound[creat][1]);
}

extern int gbNoCDRom;

int game::SetupGame() {
	int oldNoCDRom = gbNoCDRom;
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