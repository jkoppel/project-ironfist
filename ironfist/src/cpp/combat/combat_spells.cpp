#include "adventure\adv.h"
#include "combat\animation.h"
#include "combat\combat.h"
#include "combat\speed.h"
#include "resource\resourceManager.h"
#include "spell\spells.h"

#include "artifacts.h"
#include "base.h"

#define ATTR_UNDEAD  4
#define ATTR_MIRROR_IMAGE 1
#define NUM_EFFECTS  15

extern void __fastcall IconToBitmap(icon*,bitmap*,int,int,int,int,int,int,int,int,int);

extern heroWindowManager *gpWindowManager;

#define RESURRECT_ANIMATION_LENGTH 22
#define RESURRECT_ANIMATION_NUM_STANDING_FRAMES 4

void combatManager::Resurrect(int spell, int hex, int spellpower) {
	if(this->heroes[this->currentActionSide] && this->heroes[this->currentActionSide]->HasArtifact(ARTIFACT_ANKH)) {
		spellpower *= 2;
	}

	int stackIdx = this->FindResurrectArmyIndex(this->currentActionSide, (Spell)spell, hex);
	army* creat = &this->creatures[this->currentActionSide][stackIdx];
	int processedFirstHex = 0;

	int startingQuantity = this->creatures[this->currentActionSide][stackIdx].quantity;
	creat->quantity += 50 * spellpower / this->creatures[this->currentActionSide][stackIdx].creature.hp;

	if(creat->initialQuantity < creat->quantity) {
		creat->quantity = creat->initialQuantity;
	}

	if(spell == SPELL_RESURRECT) {
		creat->temporaryQty += creat->quantity - startingQuantity;
	}

	if(startingQuantity <= 0) {
		int nextCorpseHex = -1;
		int corpseIdx = -1;
		int notDone = 1;
		int currentCorpseHex = hex;
		int firstCorpseHex = hex;
		while(notDone) {
			for(int i = 0; i < this->combatGrid[currentCorpseHex].numCorpses; i++) {
				if(this->combatGrid[currentCorpseHex].corpseOwners[i] == this->currentActionSide
					&& this->combatGrid[currentCorpseHex].corpseStackIndices[i] == stackIdx) {

						corpseIdx = i;

						if(!processedFirstHex) {
							if(this->combatGrid[currentCorpseHex].corpseOtherHexIsToLeft[i] != -1) {
								if(this->combatGrid[currentCorpseHex].corpseOtherHexIsToLeft[i]) {
									nextCorpseHex = currentCorpseHex - 1;
								} else {
									nextCorpseHex = currentCorpseHex + 1;
								}
							}
						}
				}

				if(corpseIdx != -1) {
					this->combatGrid[currentCorpseHex].unitOwner                 = this->combatGrid[currentCorpseHex].corpseOwners[i];
					this->combatGrid[currentCorpseHex].stackIdx                  = this->combatGrid[currentCorpseHex].corpseStackIndices[i];
					this->combatGrid[currentCorpseHex].occupiersOtherHexIsToLeft = -1;

					if(this->combatGrid[currentCorpseHex].numCorpses == i + 1) {
						this->combatGrid[currentCorpseHex].corpseOwners[i]       = -1;
						this->combatGrid[currentCorpseHex].corpseStackIndices[i] = -1;
					} else { //FIXME: This looks like it should cause problems when resurrecting multiple corpses in a stack
						this->combatGrid[currentCorpseHex].corpseOwners[i]       = this->combatGrid[currentCorpseHex].corpseOwners[i+1];
						this->combatGrid[currentCorpseHex].corpseStackIndices[i] = this->combatGrid[currentCorpseHex].corpseStackIndices[i+1];
					}
				}
			}

			this->combatGrid[currentCorpseHex].numCorpses--;
			if(processedFirstHex) {
				notDone = 0;
			} else if (nextCorpseHex == -1) {
				notDone = 0;
			} else {
				currentCorpseHex = nextCorpseHex;
				processedFirstHex = 1;
				corpseIdx = -1;
			}
		}
			
		creat->facingRight = 1 - creat->owningSide;
				
		if (creat->creature.creature_flags & TWO_HEXER) {
			int leftHex  = nextCorpseHex > firstCorpseHex ? firstCorpseHex : nextCorpseHex;
			int rightHex = nextCorpseHex > firstCorpseHex ? nextCorpseHex : firstCorpseHex;
			
			this->combatGrid[leftHex].occupiersOtherHexIsToLeft  = 1 - creat->facingRight;
			this->combatGrid[rightHex].occupiersOtherHexIsToLeft = creat->facingRight;

			creat->occupiedHex = creat->facingRight ? leftHex : rightHex;
		}
	}

	int x = creat->MidX();
	int y = creat->MidY();

	if(creat->quantity - startingQuantity <= 1 ) {
		sprintf(gText, "%d %s rises from the dead!", creat->quantity - startingQuantity, GetCreatureName(creat->creatureIdx));
	} else {
		sprintf(gText, "%d %s rise from the dead!", creat->quantity - startingQuantity, GetCreaturePluralName(creat->creatureIdx));
	}

	this->CombatMessage(gText, 1, 1, 0);

	if(!gbNoShowCombat) {
		icon *spellAnim = gpResourceManager->GetIcon("yinyang.icn");

		for(int i = 0; i < RESURRECT_ANIMATION_LENGTH; i++) {
			glTimers = (signed __int64)((double)KBTickCount() + gfCombatSpeedMod[giCombatSpeed] * 75.0);
			IconToBitmap(spellAnim, gpWindowManager->screenBuffer, x, y, i, 1, 0, 0, 0x280u, 443, 0);

			this->UpdateCombatArea();
			if (creat->animationType == ANIMATION_TYPE_DYING) {
				if(i < RESURRECT_ANIMATION_LENGTH - RESURRECT_ANIMATION_NUM_STANDING_FRAMES) {
					int frameNo = creat->frameInfo.animationLengths[ANIMATION_TYPE_DYING] - 1;
					if(frameNo >= RESURRECT_ANIMATION_LENGTH - RESURRECT_ANIMATION_NUM_STANDING_FRAMES - 1 - i) {
						frameNo = RESURRECT_ANIMATION_LENGTH - RESURRECT_ANIMATION_NUM_STANDING_FRAMES - 1 - i;
					}
					creat->animationFrame = frameNo;
				} else {
					creat->animationType = ANIMATION_TYPE_STANDING;
					creat->animationFrame = 0;
				}
			}
			this->DrawFrame(0, 0, 0, 0, 75, 1, 1);
			DelayTil(&glTimers);
		}
		gpResourceManager->Dispose(spellAnim);
	}
	this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
	creat->creature.creature_flags &= ~DEAD;
}

float army::SpellCastWorkChance(int spell)
{
	double result; // st7@4
	army *thisa; // [sp+Ch] [bp-14h]@1
	int v4; // [sp+10h] [bp-10h]@141
	int ressurectionStrength; // [sp+14h] [bp-Ch]@125
	signed int hasEffect; // [sp+18h] [bp-8h]@7
	int i; // [sp+1Ch] [bp-4h]@7

	thisa = this;
	if (HIBYTE(this->creature.creature_flags) & ATTR_MIRROR_IMAGE
		&& (spell == SPELL_MIRROR_IMAGE || spell == SPELL_ANTI_MAGIC))
		return 0.0;
	if (spell == SPELL_DISPEL_MAGIC || spell == SPELL_MASS_DISPEL)
	{
		hasEffect = 0;
		for (i = 0; i < NUM_EFFECTS; ++i)
		{
			if (this->effectStrengths[i])
			{
				hasEffect = 1;
				break;
			}
		}
		if (!hasEffect)
			return 0.0;
	}
	if (this->effectStrengths[12]
		|| this->creature.creature_flags & 0x10
		&& spell != 7
		&& spell != SPELL_RESURRECT_TRUE
		&& spell != SPELL_ANIMATE_DEAD
		|| this->dead
		|| this->creatureIdx == CREATURE_GREEN_DRAGON
		|| this->creatureIdx == CREATURE_RED_DRAGON
		|| this->creatureIdx == CREATURE_BLACK_DRAGON)
		return 0.0;
	if (spell == SPELL_MIRROR_IMAGE && this->mirrorIdx != -1)
		return 0.0;
	if ((spell == SPELL_RESURRECT || spell == SPELL_RESURRECT_TRUE)
		&& (HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD || this->initialQuantity == this->quantity))
		return 0.0;
	if (spell == SPELL_ANIMATE_DEAD
		&& (!(HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD) || this->initialQuantity == this->quantity))
		return 0.0;
	if ((spell == SPELL_HOLY_WORD || spell == SPELL_HOLY_SHOUT) && !(HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD))
		return 0.0;
	if ((spell == SPELL_DEATH_RIPPLE || spell == SPELL_DEATH_WAVE) && HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD)
		return 0.0;
	if (this->creatureIdx == CREATURE_PHOENIX
		&& (spell == SPELL_FIREBALL
			|| spell == SPELL_FIREBLAST
			|| spell == SPELL_LIGHTNING_BOLT
			|| spell == SPELL_CHAIN_LIGHTNING
			|| spell == SPELL_COLD_RAY
			|| spell == SPELL_COLD_RING
			|| spell == SPELL_ELEMENTAL_STORM))
		return 0.0;
	if (this->creatureIdx == CREATURE_CRUSADER && (spell == SPELL_CURSE || spell == SPELL_MASS_CURSE))
		return 0.0;
	if ((HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD
		|| this->creatureIdx == CREATURE_EARTH_ELEMENTAL
		|| this->creatureIdx == CREATURE_AIR_ELEMENTAL
		|| this->creatureIdx == CREATURE_FIRE_ELEMENTAL
		|| this->creatureIdx == CREATURE_WATER_ELEMENTAL
		|| this->creatureIdx == CREATURE_GIANT
		|| this->creatureIdx == CREATURE_TITAN)
		&& (spell == SPELL_BERZERKER || spell == SPELL_HYPNOTIZE || spell == SPELL_PARALYZE || spell == SPELL_BLIND))
		return 0.0;
	if (HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD
		&& (spell == SPELL_CURSE || spell == SPELL_MASS_CURSE || spell == SPELL_BLESS || spell == SPELL_MASS_BLESS))
		return 0.0;
	if (this->creatureIdx == CREATURE_EARTH_ELEMENTAL
		&& (spell == SPELL_LIGHTNING_BOLT || spell == SPELL_CHAIN_LIGHTNING || spell == SPELL_ELEMENTAL_STORM))
		return 0.0;
	if (this->creatureIdx == CREATURE_AIR_ELEMENTAL && spell == SPELL_METEOR_SHOWER)
		return 0.0;
	if (this->creatureIdx == CREATURE_FIRE_ELEMENTAL && (spell == SPELL_FIREBALL || spell == SPELL_FIREBLAST))
		return 0.0;
	if (this->creatureIdx == CREATURE_WATER_ELEMENTAL && (spell == SPELL_COLD_RAY || spell == SPELL_COLD_RING))
		return 0.0;
	if (!gpCombatManager->heroes[this->owningSide])
		goto LABEL_168;
	if (gpCombatManager->heroes[thisa->owningSide]->HasArtifact(55)
		&& (spell == SPELL_CURSE || spell == SPELL_MASS_CURSE))
		return 0.0;
	if (gpCombatManager->heroes[thisa->owningSide]->HasArtifact(ARTIFACT_PENDANT_OF_FREE_WILL)
		&& spell == SPELL_HYPNOTIZE)
		return 0.0;
	if (gpCombatManager->heroes[thisa->owningSide]->HasArtifact(57)
		&& (spell == SPELL_DEATH_RIPPLE || spell == SPELL_DEATH_WAVE))
		return 0.0;
	if (gpCombatManager->heroes[thisa->owningSide]->HasArtifact(58) && spell == SPELL_BERZERKER)
		return 0.0;
	if (gpCombatManager->heroes[thisa->owningSide]->HasArtifact(59) && spell == SPELL_BLIND)
		return 0.0;
	if (gpCombatManager->heroes[thisa->owningSide]->HasArtifact(60) && spell == SPELL_PARALYZE)
		return 0.0;
	if (gpCombatManager->heroes[thisa->owningSide]->HasArtifact(ARTIFACT_PENDANT_OF_DEATH)
		&& (spell == SPELL_HOLY_WORD || spell == SPELL_HOLY_SHOUT))
		return 0.0;
	if (gpCombatManager->heroes[thisa->owningSide]->HasArtifact(ARTIFACT_WAND_OF_NEGATION)
		&& (spell == SPELL_DISPEL_MAGIC || spell == SPELL_MASS_DISPEL || spell == SPELL_ARCHMAGI_DISPEL))
	{
		result = 0.0;
	}
	else
	{
	LABEL_168:
		if (thisa->quantity || spell != SPELL_RESURRECT && spell != SPELL_RESURRECT_TRUE && spell != SPELL_ANIMATE_DEAD)
			goto LABEL_169;
		ressurectionStrength = 50 * gpCombatManager->heroSpellpowers[gpCombatManager->currentActionSide];
		if (gpCombatManager->heroes[gpCombatManager->currentActionSide]
			&& gpCombatManager->heroes[thisa->owningSide]->HasArtifact(52))
			ressurectionStrength *= 2;
		if (thisa->creature.hp <= ressurectionStrength)
		{
		LABEL_169:
			if (spell != SPELL_ARCHMAGI_DISPEL
				|| thisa->effectStrengths[0]
				|| thisa->effectStrengths[3]
				|| thisa->effectStrengths[8]
				|| thisa->effectStrengths[9]
				|| thisa->effectStrengths[10]
				|| thisa->effectStrengths[12]
				|| thisa->effectStrengths[13]
				|| thisa->effectStrengths[14])
			{
				if (spell != SPELL_HYPNOTIZE)
					goto LABEL_170;
				v4 = 25 * gpCombatManager->heroes[thisa->owningSide]->Stats(PRIMARY_SKILL_SPELLPOWER);
				if (gpCombatManager->heroes[thisa->owningSide]->HasArtifact(43))
					v4 *= 2;
				if (thisa->quantity * thisa->creature.hp <= v4)
				{
				LABEL_170:
					if (thisa->creatureIdx != CREATURE_DWARF && thisa->creatureIdx != CREATURE_BATTLE_DWARF
						|| spell == SPELL_TELEPORT
						|| spell == SPELL_CURE
						|| spell == SPELL_MASS_CURE
						|| spell == SPELL_RESURRECT
						|| spell == SPELL_RESURRECT_TRUE
						|| spell == SPELL_HASTE
						|| spell == SPELL_MASS_HASTE
						|| spell == SPELL_BLESS
						|| spell == SPELL_MASS_BLESS
						|| spell == SPELL_STONESKIN
						|| spell == SPELL_STEELSKIN
						|| spell == SPELL_ANTI_MAGIC
						|| spell == SPELL_DRAGON_SLAYER
						|| spell == SPELL_BLOOD_LUST
						|| spell == 40
						|| spell == 41
						|| spell == 42)
						result = 1.0;
					else
						result = 0.75;
				}
				else
				{
					result = 0.0;
				}
			}
			else
			{
				result = 0.0;
			}
		}
		else
		{
			result = 0.0;
		}
	}
	return result;
}