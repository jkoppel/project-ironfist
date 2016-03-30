#include "base.h"
#include "adventure/adv.h"
#include "combat/combat.h"
#include "game/game.h"
#include "artifacts.h"
#include "skills.h"
#include "gui/dialog.h"

#include "scripting/hook.h"
#include <string>

extern int giNextAction;
extern int giSkeletonsCreated;
extern signed char gbCombatSurrender;
extern signed char gbRetreatWin;

int getFirstEmptyHex(int owningSide, int creatureIdx)
{
	for(int i = 1; i < 177; i ++)
	{
		if(gMonsterDatabase[creatureIdx].creature_flags & TWO_HEXER)
		{
			int dir = owningSide == 0 ? 1 : -1;
			if(gpCombatManager->combatGrid[i+dir].unitOwner != -1) { continue; }
		}
		if(gpCombatManager->combatGrid[i].unitOwner == -1)
		{
			return i;
		}
	}
	return -1;
}

int squaresAroundCaster[2][3] = {
	{14,27,40},
	{11,24,37}
};

void combatManager::InitNonVisualVars()
{
	combatManager::InitNonVisualVars_orig();

	ScriptSignal(SCRIPT_EVT_BATTLE_START, "");
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
			CREATURE_SKELETON, CREATURE_CENTAUR, CREATURE_ROGUE, CREATURE_BLOODSUCKER
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

void army::MoveTo(int hexIdx) {
	if(this->creature.creature_flags & FLYER) {
		this->targetHex = hexIdx;
		if(ValidFlight(this->targetHex, 0))
			FlyTo(this->targetHex);
	} else {
		WalkTo(hexIdx);
	}
}

void army::MoveAttack(int targHex, int x) {
	int startHex = this->occupiedHex;
	this->MoveAttack_orig(targHex, x);

	if( !(this->creature.creature_flags & DEAD) &&
		CreatureHasAttribute(this->creatureIdx, STRIKE_AND_RETURN)) {
		MoveTo(startHex);
	}
}

void army::DoHydraAttack(int x)
{
	DoHydraAttack_orig(x);
}
void army::DoAttack(int x)
{
	army* primaryTarget = &gpCombatManager->creatures[gpCombatManager->combatGrid[targetHex].unitOwner][gpCombatManager->combatGrid[targetHex].stackIdx];
	if( CreatureHasAttribute(this->creatureIdx, HYDRA_ABILITY) )
	{
		int quantityBeforeAttack = primaryTarget->quantity;
		if ( x ) { gpCombatManager->currentActionSide = 1 - gpCombatManager->currentActionSide; }
		//DoHydraAttack(x);
		this->DoAttack_orig(x);
		if(primaryTarget->quantity == 0)
		{
			int hex = -1;
			hex = getFirstEmptyHex(owningSide, primaryTarget->creatureIdx);
			if(hex == -1) { return; }
			gpCombatManager->AddArmy(owningSide, primaryTarget->creatureIdx, quantityBeforeAttack, hex, 0x8000, 1);
		}
		return;
	}
	this->DoAttack_orig(x);
	char buf1[80];
	char buf2[30];
	itoa(creatureIdx, buf1, 10);
	itoa(primaryTarget->creatureIdx, buf2, 10);
	strcat(buf1, ",");
	strcat(buf1, buf2);
	ScriptSignal(SCRIPT_EVT_BATTLE_ATTACK_M, buf1);
}
void combatManager::UpdateArmyGroup(int side)
{
  signed int i; // [sp+14h] [bp-4h]@1
  int j; // [sp+14h] [bp-4h]@4

  for ( i = 0; i < 5; ++i )
  {
    this->armies[side]->creatureTypes[i] = -1;
    this->armies[side]->quantities[i] = 0;
  }
  for ( j = 0; this->numCreatures[side] > j; ++j )
  {
    if ( !(this->creatures[side][j].creature.creature_flags & DEAD)
      && this->creatures[side][j].quantity > 0
      && (this->playerID[side] == -1
       || this->creatures[side][j].creatureIdx != CREATURE_EARTH_ELEMENTAL
       && this->creatures[side][j].creatureIdx != CREATURE_AIR_ELEMENTAL
       && this->creatures[side][j].creatureIdx != CREATURE_FIRE_ELEMENTAL
       && this->creatures[side][j].creatureIdx != CREATURE_WATER_ELEMENTAL
       || !(HIBYTE(this->creatures[side][j].creature.creature_flags) & 8)) )
    {
      if ( !(HIBYTE(this->creatures[side][j].creature.creature_flags) & 0x1) && !( creatures[side][j].creature.creature_flags & 0x8000 ))
      {
        this->armies[side]->creatureTypes[this->creatures[side][j].armyIdx] = LOBYTE(this->creatures[side][j].creatureIdx);
        this->armies[side]->quantities[this->creatures[side][j].armyIdx] = this->creatures[side][j].quantity;
      }
    }
  }
  if ( giSkeletonsCreated && this->winningSide == side )
    this->armies[side]->Add(47, giSkeletonsCreated, -1);
}