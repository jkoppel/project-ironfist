#include "tied/base.h"
#include "tied/adventure/adv.h"
#include "tied/combat/combat.h"
#include "tied/game/game.h"
#include "tied/artifacts.h"
#include "tied/skills.h"

extern int giNextAction;
extern signed char gbCombatSurrender;
extern signed char gbRetreatWin;


int squaresAroundCaster[2][3] = {
	{14,27,40},
	{11,24,37}
};

void combatManager::InitNonVisualVars() {
	this->field_F2B3 = 0;
	this->field_F357 = 0;
	for(int i = 0; i < 2; i++) {
		this->heroSpellpowers[i] = 0;
		if ( this->heroes[i] )
			this->heroSpellpowers[i] = this->heroes[i]->Stats(PRIMARY_SKILL_SPELLPOWER);
		if(this->castles[i] && this->castles[i]->factionID == FACTION_NECROMANCER) {
			if(this->castles[i]->buildingsBuiltFlags & BUILDING_SPECIAL_DEFENSE_BUILT)
				this->heroSpellpowers[i] += 2;
		}
	}
	this->heroFlagIconIdx[0] = 0;
	this->heroFlagIconIdx[1] = 3;
	this->field_F377[0] = 0;
	this->field_F377[1] = 0;
	this->winningSide = 3;
	this->field_33A2 = 0;
	this->field_33A1 = this->field_33A2;
	this->field_33A3[1] = 0;
	this->field_33A3[0] = this->field_33A3[1];
	this->field_339D[1] = 0;
	this->field_339D[0] = this->field_339D[1];
	this->field_339F[1] = 0;
	this->field_339F[0] = this->field_339F[1];
	this->eagleEyeSpellLearned[0] = -1;
	this->eagleEyeSpellLearned[1] = -1;
	giNextAction = 0;
	this->summonedCreatureType[0] = 0;
	this->summonedCreatureType[1] = 0;
	this->field_F2C3 = -1;
	this->field_F2BB = -1;
	this->field_F2CB = -99;
	this->currentActionSide = 1;
	this->otherCurrentSideThing = 1;
	this->field_F2AB = 15;
	gbRetreatWin = 0;
	gbCombatSurrender = 0;
	this->field_351F[0] = 0;
	this->field_351F[1] = 0;
	this->field_F2B7 = 1;
	this->numCombatObjs = 0;
	SetupAdjacencyArray();
	GenerateMap();
	LoadArmies();

	for(int i = 0; i < 2; i++) {
		HandlePandoraBox(i);
	}
}


/*
 * What happens when a hero wins a battle using Pandora's Box, but loses their
 * main army? They walk around with stacks of 0 creatures, of course! 
 * 0-creature stacks are still useful in combat though, since all attacks do at least 1 damage.
 *
 * On a related note, in the original game, what happens when a hero wins a battle
 * using temporarily-resurrected creatures, but has no army left at the end? They
 * walk around with no creatures, and instantly lose their next battle.
 *
 * Winning a battle with nothing but summoned elementals remaining works, however.
 *
 * TL, DR: There is a bug when winning a battle with nothing but temporary creatures left,
 * but it's also present in the original game.
 */
void combatManager::HandlePandoraBox(int side) {
	if(this->heroes[side] && this->heroes[side]->HasArtifact(ARTIFACT_PANDORA_BOX)) {

		//The HoMM II code appears to lack a definition of creature tier. This deserves investigation.
		//We temporarily hardcode the tier-1 creatures
		int creatChoices[] = {
			CREATURE_PEASANT, CREATURE_SPRITE,CREATURE_HALFLING, CREATURE_GOBLIN,
			CREATURE_SKELETON, CREATURE_CENTAUR, CREATURE_ROGUE, CREATURE_KOBOLD
		};
		int creat = creatChoices[SRandom(0, ELEMENTS_IN(creatChoices)-1)];

		int hex = -1;
		int poss = ELEMENTS_IN(squaresAroundCaster[side]);
		int tryFirst = SRandom(0, poss-1);
		for(int i = 0; i < poss; i++) {
			int square = squaresAroundCaster[side][(i+tryFirst)%poss];
			if(gMonsterDatabase[creat].creature_flags & TWO_HEXER) {
				int dir = side == 0 ? 1 : -1;
				if(this->combatGrid[square+dir].unitOwner != -1)
					continue;
			}
			if(this->combatGrid[square].unitOwner == -1)
				hex = square;
		}

		if(hex==-1)
			return;

		int amt = gpGame->GetRandomNumTroops(creat);
		AddArmy(side, creat, amt, hex, 0x8000, 0);

		hexcell* cell = &this->combatGrid[hex];
		this->creatures[cell->unitOwner][cell->stackIdx].temporaryQty = amt;
	}
}