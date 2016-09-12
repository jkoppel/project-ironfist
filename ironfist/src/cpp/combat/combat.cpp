#include "base.h"
#include "adventure/adv.h"
#include "combat/combat.h"
#include "game/game.h"
#include "artifacts.h"
#include "skills.h"
#include "sound/sound.h"
#include "spells.h"

#include "gui/dialog.h"

#include "scripting/hook.h"
#include <string>

extern int giNextAction;
extern signed char gbCombatSurrender;
extern signed char gbRetreatWin;
extern char *gArmyNames[256];
extern char *gArmyNamesPlural[256];
char aDo[3] = "do";
char aDo_0[3] = "do";
char aPerish_0[7] = "perish";

int squaresAroundCaster[2][3] = {
	{14,27,40},
	{11,24,37}
};

void combatManager::InitNonVisualVars() {
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

void army::DoAttack(int x) {
  army* primaryTarget = &gpCombatManager->creatures[gpCombatManager->combatGrid[targetHex].unitOwner][gpCombatManager->combatGrid[targetHex].stackIdx];
  ScriptSetSpecialVariableData("__attackingStack", this);
  ScriptSetSpecialVariableData("__targetStack", primaryTarget);
  std::string tmp = std::to_string(this->creatureIdx) + "," + std::to_string(primaryTarget->creatureIdx);
  ScriptSignal(SCRIPT_EVT_BATTLE_ATTACK_M, tmp);
  this->DoAttack_orig(x);
 }

/*
void army::SpecialAttack() {
	army* primaryTarget = &gpCombatManager->creatures[gpCombatManager->combatGrid[targetHex].unitOwner][gpCombatManager->combatGrid[targetHex].stackIdx];
	ScriptSetSpecialVariableData("__attackingStack", this);
	ScriptSetSpecialVariableData("__targetStack", primaryTarget);
	std::string tmp = std::to_string(this->creatureIdx) + "," + std::to_string(primaryTarget->creatureIdx);
	ScriptSignal(SCRIPT_EVT_BATTLE_ATTACK_S, tmp);
	if (this->creatureIdx == CREATURE_MAGE) { // temporary creature. cyber behemoth attack
		gpCombatManager->CastSpell(SPELL_FIREBLAST, primaryTarget->occupiedHex, 1, 0);
	}
	else this->SpecialAttack_orig();
}
*/
// We don't actually change anything in sElevationOverlay, but the disasm was causing some problems

#pragma pack(push, 1)
struct SElevationOverlay {
  __int16 terrains;
  char coveredHexes[15];
};
#pragma pack(pop)

SElevationOverlay sElevationOverlay[25] =
{
  {
    0,
    {
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255,
      255
    }
  },
  { 2, { 30, 31, 32, 33, 47, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255 } },
  {
    2,
    { 56, 57, 58, 59, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  { 2, { 42, 55, 56, 57, 58, 59, 60, 48, 255, 255, 255, 255, 255, 255, 255 } },
  { 2, { 69, 70, 71, 72, 73, 60, 48, 255, 255, 255, 255, 255, 255, 255, 255 } },
  { 2, { 29, 30, 31, 32, 33, 34, 35, 81, 69, 70, 71, 72, 73, 74, 87 } },
  { 2, { 29, 17, 18, 19, 20, 21, 81, 95, 96, 97, 98, 99, 255, 255, 255 } },
  { 4, { 30, 31, 32, 33, 47, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255 } },
  {
    4,
    { 56, 57, 58, 59, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  { 4, { 42, 55, 56, 57, 58, 59, 47, 255, 255, 255, 255, 255, 255, 255, 255 } },
  { 4, { 69, 70, 71, 72, 73, 60, 48, 255, 255, 255, 255, 255, 255, 255, 255 } },
  { 4, { 18, 30, 43, 84, 85, 73, 60, 255, 255, 255, 255, 255, 255, 255, 255 } },
  { 4, { 21, 34, 48, 70, 83, 97, 98, 255, 255, 255, 255, 255, 255, 255, 255 } },
  {
    64,
    { 30, 31, 32, 33, 47, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  {
    64,
    { 56, 57, 58, 59, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  { 64, { 42, 55, 56, 57, 58, 59, 60, 48, 255, 255, 255, 255, 255, 255, 255 } },
  { 64, { 69, 70, 71, 72, 73, 60, 48, 255, 255, 255, 255, 255, 255, 255, 255 } },
  { 64, { 29, 30, 31, 32, 33, 34, 35, 81, 69, 70, 71, 72, 73, 74, 87 } },
  { 64, { 29, 17, 18, 19, 20, 21, 81, 95, 96, 97, 98, 99, 255, 255, 255 } },
  {
    128,
    { 30, 31, 32, 33, 47, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  {
    128,
    { 56, 57, 58, 59, 60, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  { 128, { 42, 55, 56, 57, 58, 59, 60, 48, 255, 255, 255, 255, 255, 255, 255 } },
  {
    128,
    { 69, 70, 71, 72, 73, 60, 48, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  {
    128,
    { 43, 30, 18, 84, 85, 73, 60, 255, 255, 255, 255, 255, 255, 255, 255 }
  },
  {
    128,
    { 21, 34, 48, 70, 83, 97, 98, 255, 255, 255, 255, 255, 255, 255, 255 }
  }
};

void army::SpecialAttack()
{
	int v15; // [sp+74h] [bp-178h]@46
	int v18; // [sp+80h] [bp-16Ch]@43
	int v20; // [sp+88h] [bp-164h]@46
	int v27; // [sp+A4h] [bp-148h]@43
	int y; // [sp+A8h] [bp-144h]@58
	int x; // [sp+BCh] [bp-130h]@58
	int v38; // [sp+D0h] [bp-11Ch]@55
	int targMidY; // [sp+D4h] [bp-118h]@12
	int v43; // [sp+E4h] [bp-108h]@53
	int v44; // [sp+E8h] [bp-104h]@55
	int animIdx; // [sp+F8h] [bp-F4h]@103
	int a5; // [sp+FCh] [bp-F0h]@103
	char firingLeft; // [sp+104h] [bp-E8h]@18
	int v53; // [sp+10Ch] [bp-E0h]@58
	int a4; // [sp+110h] [bp-DCh]@103
	int targMidX; // [sp+1E0h] [bp-Ch]@12
	int spriteIdx; // [sp+1E4h] [bp-8h]@22
	int v59; // [sp+1E8h] [bp-4h]@58
	int damageDone = 0;
	int creaturesKilled = 0;
	int sourceFacingRight = this->facingRight;
	this->field_125 = 0;
	army *target = &gpCombatManager->creatures[this->targetOwner][this->targetStackIdx];
	char targetColumnHex = target->occupiedHex % 13;
	char targetRowHex = target->occupiedHex / 13;
	char sourceColumnHex = this->occupiedHex % 13;
	char sourceRowHex = this->occupiedHex / 13;
	sourceFacingRight = this->facingRight;
	this->facingRight = targetColumnHex > sourceColumnHex || !(sourceRowHex & 1) && targetColumnHex == sourceColumnHex;
	if (this->facingRight != sourceFacingRight)	{
		if (this->creature.creature_flags & 1) {
			if (this->facingRight == 1)
				--this->occupiedHex;
			else
				++this->occupiedHex;
		}
		gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
	}
	this->CheckLuck();
	gpSoundManager->MemorySample(this->combatSounds[3]);
	gpCombatManager->ResetLimitCreature();
	int v1 = 80 * this->owningSide + 4 * this->stackIdx;
	++*(int *)((char *)gpCombatManager->limitCreature + v1);
	gpCombatManager->DrawFrame(0, 1, 0, 1, 75, 1, 1);
	targMidX = target->MidX();
	targMidY = target->MidY();
	if (this->creatureIdx == CREATURE_LICH || this->creatureIdx == CREATURE_POWER_LICH)	{
		targMidX = gpCombatManager->combatGrid[target->occupiedHex].centerX;
		targMidY = gpCombatManager->combatGrid[target->occupiedHex].occupyingCreatureBottomY - 17;
	}
	int projStartX;
	if (this->facingRight == 1)
		projStartX = this->frameInfo.projectileStartOffset[1][0] + gpCombatManager->combatGrid[this->occupiedHex].centerX;
	else
		projStartX = gpCombatManager->combatGrid[this->occupiedHex].centerX - this->frameInfo.projectileStartOffset[1][0];
	int projStartY = this->frameInfo.projectileStartOffset[1][1] + gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY;
	int totXDiff = targMidX - projStartX;
	firingLeft = 0;
	if (targMidX - projStartX < 0) {
		firingLeft = 1;
		totXDiff = -totXDiff;
	}
	int yDiff = targMidY - projStartY;
	float angleDeg;
	if (totXDiff) {
		float slope = (double)-yDiff / (double)totXDiff;
		angleDeg = atan(slope) * 180.0 / 3.14159;
		int i;
		for (i = 1;	this->frameInfo.numMissileDirs > i &&
			(*(float *)((char *)&this->frameInfo.projectileStartOffset[2 * i + 4] + 1) +
				this->frameInfo.projDirAngle[i]) / 2.0 >= angleDeg;	++i)
			;
		if (this->frameInfo.numMissileDirs <= i)
			spriteIdx = this->frameInfo.numMissileDirs - 1;
		else
			spriteIdx = i - 1;
	} else {
		if (yDiff <= 0)
			spriteIdx = 0;
		else
			spriteIdx = this->frameInfo.numMissileDirs - 1;
		angleDeg = (double)(yDiff <= 0 ? 90 : -90);
	}
	int attackDirectionAnimationIdx;
	if (angleDeg <= 25.0) {
		if (angleDeg <= -25.0) {
			this->animationType = 32;
			attackDirectionAnimationIdx = 2;
		}
		else {
			this->animationType = 30;
			attackDirectionAnimationIdx = 1;
		}
	} else {
		this->animationType = 28;
		attackDirectionAnimationIdx = 0;
	}
	for (this->animationFrame = 0;
		this->frameInfo.animationLengths[this->animationType] > this->animationFrame;
		++this->animationFrame)
	{
		if (this->frameInfo.animationLengths[this->animationType] - 1 == this->animationFrame)
			gpCombatManager->DrawFrame(0, 1, 0, 0, 75, 1, 1);
		else
			gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 1, 1);
		glTimers = (signed __int64)((double)KBTickCount()
			+ (double)this->frameInfo.shootingTime
			* gfCombatSpeedMod[giCombatSpeed]
			/ (double)this->frameInfo.animationLengths[this->animationType]);
	}
	this->animationFrame = this->frameInfo.animationLengths[this->animationType] - 1;
	v27 = 25;
	v18 = 25;
	int v35 = 31;
	int v22 = 25;
	if (this->creatureIdx == CREATURE_LICH || this->creatureIdx == CREATURE_POWER_LICH) {
		v35 = 26;
		v22 = 7;
		v27 = 10;
		v18 = 10;
	}
	v20 = 0;
	int offsetX = 639;
	v15 = 0;
	int offsetY = 479;
	signed int startX;
	if (this->facingRight == 1)
		startX = this->frameInfo.projectileStartOffset[attackDirectionAnimationIdx][0] + gpCombatManager->combatGrid[this->occupiedHex].centerX;
	else
		startX = gpCombatManager->combatGrid[this->occupiedHex].centerX - this->frameInfo.projectileStartOffset[attackDirectionAnimationIdx][0];
	
	int startY = this->frameInfo.projectileStartOffset[attackDirectionAnimationIdx][1] + gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY;

	int endX = target->MidX();
	int endY = target->MidY();
	int v42 = endX - startX;
	int v47 = endY - startY;
	int v32 = (signed __int64)sqrt((double)(v47 * v47 + (endX - startX) * (endX - startX)));
	int v52 = (v32 + (v35 >> 1)) / v35;
	if (this->creatureIdx != CREATURE_MAGE && this->creatureIdx != CREATURE_ARCHMAGE) {
		int v37;
		if (v52 <= 1) {
			v43 = v42;
			v37 = v47;
		} else {
			v43 = v42 / (v52 - 1);
			v37 = v47 / (v52 - 1);
		}
		v44 = startX;
		v38 = startY;
		//v7 = (bitmap *)operator new(26);
		bitmap *from; // [sp+A0h] [bp-14Ch]@56
		bitmap *v7 = new bitmap(33, 2 * v27, 2 * v18);
		if (v7)
			from = v7;
			//from = v7(33, 2 * v27, 2 * v18);
		else
			from = 0;
		from->GrabBitmapCareful(gpWindowManager->screenBuffer, v44 - v27, v38 - v18);
		v59 = v44;
		v53 = v38;
		x = 0;
		y = 0;
		for (int i = 0; i < v52; ++i) {
			if (v59 - v27 < offsetX)
				offsetX = v59 - v27;
			if (offsetX < 0)
				offsetX = 0;
			if (v27 + v59 > v20)
				v20 = v27 + v59;
			if (v20 > 639)
				v20 = 639;
			if (v53 - v18 < offsetY)
				offsetY = v53 - v18;
			if (offsetY < 0)
				offsetY = 0;
			if (v18 + v53 > v15)
				v15 = v18 + v53;
			if (v15 > 442)
				v15 = 442;
			if (i) {
				from->DrawToBufferCareful(x, y);
			} else {
				if (giMinExtentX > offsetX)
					giMinExtentX = offsetX;
				if (v20 > giMaxExtentX)
					giMaxExtentX = v20;
				if (offsetY < giMinExtentY)
					giMinExtentY = offsetY;
				if (v15 > giMaxExtentY)
					giMaxExtentY = v15;
			}
			x = v44 - v27;
			if (v44 - v27 < 0)
				x = 0;
			if (x + (signed int)from->width > 640)
				x = 640 - from->width;
			y = v38 - v18;
			if (v38 - v18 < 0)
				y = 0;
			if (y + (signed int)from->height > 640)
				y = 640 - from->height;
			from->GrabBitmapCareful(gpWindowManager->screenBuffer, x, y);
			this->missileIcon->DrawToBuffer(v44, v38, spriteIdx, firingLeft);
			if (i) {
				DelayTil(&glTimers);
				gpWindowManager->UpdateScreenRegion(offsetX, offsetY, v20 - offsetX + 1, v15 - offsetY + 1);
			} else {
				gpWindowManager->UpdateScreenRegion(
					giMinExtentX,
					giMinExtentY,
					giMaxExtentX - giMinExtentX + 1,
					giMaxExtentY - giMinExtentY + 1);
			}

			glTimers = (signed __int64)((double)KBTickCount() + (double)v22 * gfCombatSpeedMod[giCombatSpeed]);
			v59 = v44;
			v53 = v38;
			v44 += v43;
			v38 += v37;
			offsetX = v44 - v27;
			v20 = v27 + v44;
			offsetY = v38 - v18;
			v15 = v18 + v38;
		}
		from->DrawToBuffer(x, y);
		gpWindowManager->UpdateScreenRegion(v59 - v27, v53 - v18, 2 * v27, 2 * v18);
		if (from)
			from->~bitmap();
	} else {
		gpWindowManager->UpdateScreenRegion(
			giMinExtentX,
			giMinExtentY,
			giMaxExtentX - giMinExtentX + 1,
			giMaxExtentY - giMinExtentY + 1);
		DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 115.0));
		gpCombatManager->DoBolt(
			1,
			startX,
			startY,
			endX,
			endY,
			0,
			0,
			5,
			4,
			302,
			0,
			0,
			v32 / 15 + 15,
			1,
			0,
			10,
			0);
	}
	if (!gpCombatManager->heroes[this->owningSide] || !gpCombatManager->heroes[this->owningSide]->HasArtifact(ARTIFACT_AMMO_CART))
		--this->creature.shots;
	char monAttack = this->creature.attack;
	animIdx = -1;
	a4 = -1;
	a5 = -1;
	if (this->creatureIdx != CREATURE_LICH && this->creatureIdx != CREATURE_POWER_LICH) {
		this->DamageEnemy(target, &damageDone, &creaturesKilled, 1, 0);
	} else {
		signed int v8;
		gpCombatManager->ClearEffects();
		for (int i = 0; i < 7; ++i)	{
			if (i >= 6)
				v8 = target->occupiedHex;
			else
				v8 = target->GetAdjacentCellIndex(target->occupiedHex, i);
			if (v8 != -1) {
				if (gpCombatManager->combatGrid[v8].unitOwner != -1) {
					army *targ = &gpCombatManager->creatures[gpCombatManager->combatGrid[v8].unitOwner][gpCombatManager->combatGrid[v8].stackIdx];
					if (!gArmyEffected[gpCombatManager->creatures[gpCombatManager->combatGrid[v8].unitOwner][gpCombatManager->combatGrid[v8].stackIdx].owningSide][gpCombatManager->creatures[gpCombatManager->combatGrid[v8].unitOwner][gpCombatManager->combatGrid[v8].stackIdx].stackIdx]) {
						if (target != targ || i == 6) {
							gArmyEffected[gpCombatManager->creatures[gpCombatManager->combatGrid[v8].unitOwner][gpCombatManager->combatGrid[v8].stackIdx].owningSide][gpCombatManager->creatures[gpCombatManager->combatGrid[v8].unitOwner][gpCombatManager->combatGrid[v8].stackIdx].stackIdx] = 1;
							this->DamageEnemy(targ, &damageDone, &creaturesKilled, 1, 0);
						}
					}
				}
			}
		}
		this->field_FA = 0;
		animIdx = 20;
		a4 = gpCombatManager->combatGrid[v8].centerX;
		a5 = gpCombatManager->combatGrid[v8].occupyingCreatureBottomY - 17;
		gpSoundManager->MemorySample(combatSounds[5]);
	}
	this->creature.attack = monAttack;

	// Battle messages
	if (creaturesKilled <= 0) {
		char *tmpString;
		if (this->quantity <= 1)
			tmpString = gArmyNames[this->creatureIdx];
		else
			tmpString = gArmyNamesPlural[this->creatureIdx];
		sprintf(gText, "%s %s %d %s.", tmpString, &aDo_0[("does" - "do") & ((this->quantity > 1) - 1)], damageDone, "damage");
		gText[0] -= 32;
	} else {
		if (damageDone == -1) {
			sprintf(gText, "The mirror image is destroyed!");
		} else {
			char *attackingArmyName;
			char *attackedArmyName;
			if (creaturesKilled <= 1)
				attackedArmyName = gArmyNames[target->creatureIdx];
			else
				attackedArmyName = gArmyNamesPlural[target->creatureIdx];
			if (this->quantity <= 1)
				attackingArmyName = gArmyNames[this->creatureIdx];
			else
				attackingArmyName = gArmyNamesPlural[this->creatureIdx];
			sprintf(
				gText,
				"%s %s %d %s.\n%d %s %s.",
				attackingArmyName,
				&aDo[("does" - "do") & ((this->quantity > 1) - 1)],
				damageDone,
				"damage",
				creaturesKilled,
				attackedArmyName,
				&aPerish_0[("perishes" - "perish") & ((creaturesKilled > 1) - 1)]);
			gText[0] -= 32;
		}
	}
	if (this->creatureIdx == CREATURE_ARCHMAGE) {
		if (SRandom(1, 100) < 20) {
			if (target)	{
				if (target->SpellCastWorks(SPELL_ARCHMAGI_DISPEL))
					target->spellEnemyCreatureAbilityIsCasting = 102;
			}
		}
	}
	this->PowEffect(animIdx, 0, a4, a5);
	gpCombatManager->CombatMessage(gText, 1, 1, 0);

	this->WaitSample(3);
	if (this->facingRight != sourceFacingRight) {
		if (this->creature.creature_flags & TWO_HEXER) {
			if (this->facingRight == 1)
				++this->occupiedHex;
			else
				--this->occupiedHex;
		}
		this->facingRight = sourceFacingRight;
	}
	if (!bSecondAttack
		&& (this->creatureIdx == CREATURE_ELF
		||	this->creatureIdx == CREATURE_GRAND_ELF
		||	this->creatureIdx == CREATURE_RANGER)
		&& target->quantity > 0) {
		bSecondAttack = 1;
		this->SpecialAttack();
		bSecondAttack = 0;
	}
	
	if (this->effectStrengths[5] || this->effectStrengths[7]) {
		this->CancelSpellType(CREATURE_TOOK_TURN_EVENT_CODE);
		gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
	}
}
