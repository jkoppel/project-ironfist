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
	int v1; // eax@12
	int v2; // eax@138
	char *v4; // [sp+40h] [bp-1ACh]@132
	char *v5; // [sp+44h] [bp-1A8h]@127
	char *v6; // [sp+48h] [bp-1A4h]@124
	bitmap *v7; // [sp+54h] [bp-198h]@55
	signed int v8; // [sp+58h] [bp-194h]@0
	army *targ; // [sp+5Ch] [bp-190h]@113
	int v10; // [sp+60h] [bp-18Ch]@16
	float v11; // [sp+64h] [bp-188h]@24
	char v12; // [sp+68h] [bp-184h]@103
	int v13; // [sp+6Ch] [bp-180h]@20
	int startY; // [sp+70h] [bp-17Ch]@49
	int v15; // [sp+74h] [bp-178h]@46
	int damageDone; // [sp+78h] [bp-174h]@1
	int v17; // [sp+7Ch] [bp-170h]@18
	int v18; // [sp+80h] [bp-16Ch]@43
	signed int startX; // [sp+84h] [bp-168h]@47
	int v20; // [sp+88h] [bp-164h]@46
	int creaturesKilled; // [sp+8Ch] [bp-160h]@1
	int v22; // [sp+90h] [bp-15Ch]@43
	int offsetY; // [sp+94h] [bp-158h]@46
	signed int hexIdx; // [sp+98h] [bp-154h]@25
	int offsetX; // [sp+9Ch] [bp-150h]@46
	bitmap *from; // [sp+A0h] [bp-14Ch]@56
	int v27; // [sp+A4h] [bp-148h]@43
	__int16 y[2]; // [sp+A8h] [bp-144h]@58
	int sourceFacingRight; // [sp+ACh] [bp-140h]@1
	army *v30; // [sp+B0h] [bp-13Ch]@1
	float v31; // [sp+B4h] [bp-138h]@25
	int v32; // [sp+B8h] [bp-134h]@49
	__int16 x[2]; // [sp+BCh] [bp-130h]@58
	char targetRowHex; // [sp+C0h] [bp-12Ch]@1
	int v35; // [sp+C4h] [bp-128h]@43
	signed int endY; // [sp+C8h] [bp-124h]@49
	int v37; // [sp+CCh] [bp-120h]@53
	int v38; // [sp+D0h] [bp-11Ch]@55
	int v39; // [sp+D4h] [bp-118h]@12
	int v40; // [sp+D8h] [bp-114h]@33
	signed int endX; // [sp+DCh] [bp-110h]@49
	int v42; // [sp+E0h] [bp-10Ch]@49
	int v43; // [sp+E4h] [bp-108h]@53
	int v44; // [sp+E8h] [bp-104h]@55
	char targetColumnHex; // [sp+ECh] [bp-100h]@1
	char sourceRowHex; // [sp+F0h] [bp-FCh]@1
	int v47; // [sp+F4h] [bp-F8h]@49
	int animIdx; // [sp+F8h] [bp-F4h]@103
	int a5; // [sp+FCh] [bp-F0h]@103
	char sourceColumnHex; // [sp+100h] [bp-ECh]@1
	char v51; // [sp+104h] [bp-E8h]@18
	int v52; // [sp+108h] [bp-E4h]@49
	int v53; // [sp+10Ch] [bp-E0h]@58
	int a4; // [sp+110h] [bp-DCh]@103
	char message; // [sp+114h] [bp-D8h]@135
	int v56; // [sp+1DCh] [bp-10h]@18
	int v57; // [sp+1E0h] [bp-Ch]@12
	int spriteIdx; // [sp+1E4h] [bp-8h]@22
	int v59; // [sp+1E8h] [bp-4h]@58

	damageDone = 0;
	creaturesKilled = 0;
	sourceFacingRight = this->facingRight;
	this->field_125 = 0;
	v30 = (army*)&gpCombatManager->creatures[21 * this->targetOwner] + this->targetStackIdx;
	targetColumnHex = v30->occupiedHex % 13;
	targetRowHex = v30->occupiedHex / 13;
	sourceColumnHex = this->occupiedHex % 13;
	sourceRowHex = this->occupiedHex / 13;
	sourceFacingRight = this->facingRight;
	this->facingRight = targetColumnHex > sourceColumnHex || !(sourceRowHex & 1) && targetColumnHex == sourceColumnHex;
	if (this->facingRight != sourceFacingRight)
	{
		if (this->creature.creature_flags & 1)
		{
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
	v1 = 80 * this->owningSide + 4 * this->stackIdx;
	++*(int *)((char *)gpCombatManager->limitCreature + v1);
	gpCombatManager->DrawFrame(0, 1, 0, 1, 75, 1, 1);
	v57 = this->MidX();
	v39 = this->MidY();
	if (this->creatureIdx == CREATURE_LICH || this->creatureIdx == CREATURE_POWER_LICH)
	{
		v57 = gpCombatManager->combatGrid[v30->occupiedHex].centerX;
		v39 = gpCombatManager->combatGrid[v30->occupiedHex].occupyingCreatureBottomY - 17;
	}
	if (this->facingRight == 1)
		v10 = (short)this->frameInfo.projectileStartOffset[2] + gpCombatManager->combatGrid[this->occupiedHex].centerX;
	else
		v10 = gpCombatManager->combatGrid[this->occupiedHex].centerX - (short)this->frameInfo.projectileStartOffset[2];
	v56 = (short)this->frameInfo.projectileStartOffset[3]
		+ gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY;
	v17 = v57 - v10;
	v51 = 0;
	if (v57 - v10 < 0)
	{
		v51 = 1;
		v17 = -v17;
	}
	v13 = v39 - v56;
	if (v17)
	{
		v31 = (double)-v13 / (double)v17;
		v11 = atan(v31) * 180.0 / 3.14159;
		for (hexIdx = 1;
			this->frameInfo.numMissileDirs > hexIdx
			&& (*(float *)((char *)&this->frameInfo.projectileStartOffset[2 * hexIdx + 4] + 1)
				+ this->frameInfo.projDirAngle[hexIdx])
			/ 2.0 >= v11;
			++hexIdx)
			;
		if (this->frameInfo.numMissileDirs <= hexIdx)
			spriteIdx = this->frameInfo.numMissileDirs - 1;
		else
			spriteIdx = hexIdx - 1;
	}
	else
	{
		if (v13 <= 0)
			spriteIdx = 0;
		else
			spriteIdx = this->frameInfo.numMissileDirs - 1;
		v11 = (double)((((v13 <= 0) - 1) & 0xFFFFFF4C) + 90);
	}
	if (v11 <= 25.0)
	{
		if (v11 <= -25.0)
		{
			this->animationType = 32;
			v40 = 2;
		}
		else
		{
			this->animationType = 30;
			v40 = 1;
		}
	}
	else
	{
		this->animationType = 28;
		v40 = 0;
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
			* *(float *)&(&gfCombatSpeedMod)[*(_DWORD *)&giCombatSpeed]
			/ (double)this->frameInfo.animationLengths[this->animationType]);
	}
	this->animationFrame = this->frameInfo.animationLengths[this->animationType] - 1;
	v27 = 25;
	v18 = 25;
	v35 = 31;
	v22 = 25;
	if (this->creatureIdx == CREATURE_LICH || this->creatureIdx == CREATURE_POWER_LICH)
	{
		v35 = 26;
		v22 = 7;
		v27 = 10;
		v18 = 10;
	}
	v20 = 0;
	offsetX = 639;
	v15 = 0;
	offsetY = 479;
	if (this->facingRight == 1)
		startX = gpCombatManager->combatGrid[this->occupiedHex].centerX + (short)this->frameInfo.projectileStartOffset[2 * v40];
	else
		startX = gpCombatManager->combatGrid[this->occupiedHex].centerX - (short)this->frameInfo.projectileStartOffset[2 * v40];
	startY = gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY
		+ (short)this->frameInfo.projectileStartOffset[2 * v40 + 1];
	endX = this->MidX();
	endY = this->MidY();
	v42 = endX - startX;
	v47 = endY - startY;
	v32 = (signed __int64)sqrt((double)(v47 * v47 + (endX - startX) * (endX - startX)));
	v52 = (v32 + (v35 >> 1)) / v35;
	if (this->creatureIdx != CREATURE_MAGE && this->creatureIdx != CREATURE_ARCHMAGE)
	{
		if (v52 <= 1)
		{
			v43 = v42;
			v37 = v47;
		}
		else
		{
			v43 = v42 / (v52 - 1);
			v37 = v47 / (v52 - 1);
		}
		v44 = startX;
		v38 = startY;
		//v7 = (bitmap *)operator new(26);
		v7 = new bitmap(33, 2 * v27, 2 * v18);
		if (v7)
			from = v7;
			//from = v7(33, 2 * v27, 2 * v18);
		else
			from = 0;
		from->GrabBitmapCareful(gpWindowManager->screenBuffer, v44 - v27, v38 - v18);
		v59 = v44;
		v53 = v38;
		*(_DWORD *)x = 0;
		*(_DWORD *)y = 0;
		for (hexIdx = 0; hexIdx < v52; ++hexIdx)
		{
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
			if (hexIdx)
			{
				from->DrawToBufferCareful(x[0], y[0]);
			}
			else
			{
				if (giMinExtentX > offsetX)
					giMinExtentX = offsetX;
				if (v20 > giMaxExtentX)
					giMaxExtentX = v20;
				if (offsetY < giMinExtentY)
					giMinExtentY = offsetY;
				if (v15 > giMaxExtentY)
					giMaxExtentY = v15;
			}
			*(_DWORD *)x = v44 - v27;
			if (v44 - v27 < 0)
				*(_DWORD *)x = 0;
			if (*(_DWORD *)x + (signed int)from->width > 640)
				*(_DWORD *)x = 640 - from->width;
			*(_DWORD *)y = v38 - v18;
			if (v38 - v18 < 0)
				*(_DWORD *)y = 0;
			if (*(_DWORD *)y + (signed int)from->height > 640)
				*(_DWORD *)y = 640 - from->height;
			from->GrabBitmapCareful(gpWindowManager->screenBuffer, x[0], y[0]);
			this->missileIcon->DrawToBuffer(v44, v38, spriteIdx, v51);
			if (hexIdx)
			{
				DelayTil(&glTimers);
				gpWindowManager->UpdateScreenRegion(offsetX, offsetY, v20 - offsetX + 1, v15 - offsetY + 1);
			}
			else
			{
				gpWindowManager->UpdateScreenRegion(
					giMinExtentX,
					giMinExtentY,
					giMaxExtentX - giMinExtentX + 1,
					giMaxExtentY - giMinExtentY + 1);
			}
			glTimers = (signed __int64)((double)KBTickCount()
				+ (double)v22 * *(float *)&(&gfCombatSpeedMod)[*(_DWORD *)&giCombatSpeed]);
			v59 = v44;
			v53 = v38;
			v44 += v43;
			v38 += v37;
			offsetX = v44 - v27;
			v20 = v27 + v44;
			offsetY = v38 - v18;
			v15 = v18 + v38;
		}
		from->DrawToBuffer(x[0], y[0]);
		gpWindowManager->UpdateScreenRegion(v59 - v27, v53 - v18, 2 * v27, 2 * v18);
		if (from)
			(*(void(__thiscall **)(bitmap *, signed int))from->vtable)(from, 1);
	}
	else
	{
		gpWindowManager->UpdateScreenRegion(
			giMinExtentX,
			giMinExtentY,
			giMaxExtentX - giMinExtentX + 1,
			giMaxExtentY - giMinExtentY + 1);
		DelayMilli((signed __int64)(*(float *)&(&gfCombatSpeedMod)[*(_DWORD *)&giCombatSpeed] * 115.0));
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
	v12 = this->creature.attack;
	animIdx = -1;
	a4 = -1;
	a5 = -1;
	if (this->creatureIdx != CREATURE_LICH && this->creatureIdx != CREATURE_POWER_LICH)
	{
		this->DamageEnemy(v30, &damageDone, &creaturesKilled, 1, 0);
	}
	else
	{
		gpCombatManager->ClearEffects();
		for (hexIdx = 0; hexIdx < 7; ++hexIdx)
		{
			if (hexIdx >= 6)
				v8 = v30->occupiedHex;
			else
				v8 = v30->GetAdjacentCellIndex(v30->occupiedHex, hexIdx);
			if (v8 != -1)
			{
				if (gpCombatManager->combatGrid[v8].unitOwner != -1)
				{
					targ = (army*)&gpCombatManager->creatures[21 * gpCombatManager->combatGrid[v8].unitOwner]
						+ gpCombatManager->combatGrid[v8].stackIdx;
					if (!gArmyEffected[*(int *)((char *)&gpCombatManager->creatures[21
						* gpCombatManager->combatGrid[v8].unitOwner]->owningSide
						+ 1154 * gpCombatManager->combatGrid[v8].stackIdx)][*(int *)((char *)&gpCombatManager->creatures[21 * gpCombatManager->combatGrid[v8].unitOwner]->stackIdx
							+ 1154
							* gpCombatManager->combatGrid[v8].stackIdx)])
					{
						if (v30 != targ || hexIdx == 6)
						{
							gArmyEffected[*(int *)((char *)&gpCombatManager->creatures[21 * gpCombatManager->combatGrid[v8].unitOwner]->owningSide
								+ 1154 * gpCombatManager->combatGrid[v8].stackIdx)][*(int *)((char *)&gpCombatManager->creatures[21 * gpCombatManager->combatGrid[v8].unitOwner]->stackIdx
									+ 1154
									* gpCombatManager->combatGrid[v8].stackIdx)] = 1;
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
	this->creature.attack = v12;
	if (creaturesKilled <= 0)
	{
		if (this->quantity <= 1)
			v4 = (&gArmyNames)[4 * this->creatureIdx];
		else
			v4 = (&gArmyNamesPlural)[4 * this->creatureIdx];
		sprintf(gText, "%s %s %d %s.", v4, &aDo_0[("does" - "do") & ((this->quantity > 1) - 1)], damageDone, "damage");
		gText[0] -= 32;
	}
	else
	{
		if (damageDone == -1)
		{
			sprintf(gText, "The mirror image is destroyed!");
		}
		else
		{
			if (creaturesKilled <= 1)
				v6 = (&gArmyNames)[4 * v30->creatureIdx];
			else
				v6 = (&gArmyNamesPlural)[4 * v30->creatureIdx];
			if (this->quantity <= 1)
				v5 = (&gArmyNames)[4 * this->creatureIdx];
			else
				v5 = (&gArmyNamesPlural)[4 * this->creatureIdx];
			sprintf(
				gText,
				"%s %s %d %s.\n%d %s %s.",
				v5,
				&aDo[("does" - "do") & ((this->quantity > 1) - 1)],
				damageDone,
				"damage",
				creaturesKilled,
				v6,
				&aPerish_0[("perishes" - "perish") & ((creaturesKilled > 1) - 1)]);
			gText[0] -= 32;
		}
	}
	strcpy(&message, gText);
	if (this->creatureIdx == CREATURE_ARCHMAGE)
	{
		if (SRandom(1, 100) < 20)
		{
			if (v30)
			{
				LOBYTE(v2) = v30->SpellCastWorks(SPELL_ARCHMAGI_DISPEL);
				if (v2)
					v30->spellEnemyCreatureAbilityIsCasting = 102;
			}
		}
	}
	this->PowEffect(animIdx, 0, a4, a5);
	gpCombatManager->CombatMessage(&message, 1, 1, 0);
	this->WaitSample(3);
	if (this->facingRight != sourceFacingRight)
	{
		if (this->creature.creature_flags & 1)
		{
			if (this->facingRight == 1)
				++this->occupiedHex;
			else
				--this->occupiedHex;
		}
		this->facingRight = sourceFacingRight;
	}
	if (!bSecondAttack
		&& (this->creatureIdx == CREATURE_ELF
			|| this->creatureIdx == CREATURE_GRAND_ELF
			|| this->creatureIdx == CREATURE_RANGER)
		&& v30->quantity > 0)
	{
		bSecondAttack = 1;
		this->SpecialAttack();
		bSecondAttack = 0;
	}
	if (this->effectStrengths[5] || this->effectStrengths[7])
	{
		this->CancelSpellType(CREATURE_TOOK_TURN_EVENT_CODE);
		gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
	}
}