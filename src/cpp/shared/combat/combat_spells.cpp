#include "adventure\adv.h"
#include "combat\animation.h"
#include "combat\combat.h"
#include "combat\speed.h"
#include "gui\dialog.h"
#include "resource\resourceManager.h"
#include "spell\spells.h"

#include "artifacts.h"
#include "base.h"
#include "sound/sound.h"

#include <set>

extern SCmbtHero sCmbtHero[13];
extern int castX;
extern int castY;

extern void __fastcall IconToBitmap(icon*,bitmap*,int,int,int,int,int,int,int,int,int);

extern heroWindowManager *gpWindowManager;

int gSpellDirection; // ironfist var. used for plasma cone stream spell

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

float army::SpellCastWorkChance(int spell) {
	if (this->effectStrengths[EFFECT_ANTI_MAGIC])
		return 0.0;

	if (this->creatureIdx == CREATURE_EARTH_ELEMENTAL
		&& spell == SPELL_ELEMENTAL_STORM)
		return 0.0;

	if (this->creatureIdx == CREATURE_EARTH_ELEMENTAL
		&& spell == SPELL_METEOR_SHOWER)
		return 1.0;

  if (spell == SPELL_SHADOW_MARK && this->dead)
    return 0.0;

  if(spell == SPELL_MASS_FORCE_SHIELD)
    return 1.0;

	return this->SpellCastWorkChance_orig(spell);
}

void combatManager::CastSpell(int proto_spell, int hexIdx, int isCreatureAbility, int a5) {
  hero* enemyHero = this->heroes[1 - this->currentActionSide];
  hero *currentHero = this->heroes[this->currentActionSide];

  if (!isCreatureAbility) {
    if (this->eagleEyeSpellLearned[1 - this->currentActionSide] == SPELL_NONE) {
      if (enemyHero) {
        if (!enemyHero->HasSpell(proto_spell)) {
          int eagleEyeLevel = enemyHero->secondarySkillLevel[SECONDARY_SKILL_EAGLE_EYE];
          if (eagleEyeLevel + 1 >= gsSpellInfo[proto_spell].level) {
            if (eagleEyeLevel >= SRandom(0, 9))
              this->eagleEyeSpellLearned[1 - this->currentActionSide] = proto_spell;
          }
        }
      }
    }
  }
  if (this->field_F2B7) {
    this->ResetLimitCreature();
    if (ValidHex(this->field_F2BB) && this->combatGrid[this->field_F2BB].unitOwner >= 0) {
      int v8 = 80 * this->combatGrid[this->field_F2BB].unitOwner + 4 * this->combatGrid[this->field_F2BB].stackIdx;
      ++*(signed int *)((char *)this->limitCreature[0] + v8);
    }
    this->field_F2B7 = 0;
    this->field_F2BB = -1;
    gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 1, 1);
  }
  
  if (!isCreatureAbility && currentHero)
    currentHero->UseSpell(proto_spell);

  army *stack = 0;
  int owner;
  int spellpower;
  int stackidx;

  if (proto_spell != SPELL_FIREBALL
    && proto_spell != SPELL_FIREBLAST
    && proto_spell != SPELL_COLD_RING
    && proto_spell != SPELL_METEOR_SHOWER
    && proto_spell != SPELL_SUMMON_EARTH_ELEMENTAL
    && proto_spell != SPELL_SUMMON_AIR_ELEMENTAL
    && proto_spell != SPELL_SUMMON_WATER_ELEMENTAL
    && proto_spell != SPELL_SUMMON_FIRE_ELEMENTAL
    && proto_spell != SPELL_MASS_BLESS
    && proto_spell != SPELL_MASS_HASTE
    && proto_spell != SPELL_EARTHQUAKE
    && proto_spell != SPELL_MASS_CURSE
    && proto_spell != SPELL_MASS_CURE
    && proto_spell != SPELL_HOLY_WORD
    && proto_spell != SPELL_HOLY_SHOUT
    && proto_spell != SPELL_DEATH_RIPPLE
    && proto_spell != SPELL_DEATH_WAVE
    && proto_spell != SPELL_MASS_SHIELD
    && proto_spell != SPELL_ARMAGEDDON
    && proto_spell != SPELL_ELEMENTAL_STORM
    && proto_spell != SPELL_MASS_DISPEL
    && proto_spell != SPELL_MASS_FORCE_SHIELD) {
    int targetedUnitOwner = this->combatGrid[hexIdx].unitOwner;
    int targetedUnitStackIdx = this->combatGrid[hexIdx].stackIdx;
    if (ValidHex(hexIdx) && targetedUnitOwner >= 0) {
      stack = &this->creatures[targetedUnitOwner][targetedUnitStackIdx];
      owner = targetedUnitOwner;
      stackidx = targetedUnitStackIdx;
    } else {
      stack = NULL;
    }
  } else {
    stack = NULL;
  }
  if (!isCreatureAbility)
    *(&this->field_353F + this->currentActionSide) = 1;
  if (isCreatureAbility) {
    spellpower = 3;
  } else {
    spellpower = this->heroSpellpowers[this->currentActionSide];
    int isDurationedSpell = gsSpellInfo[proto_spell].attributes & ATTR_DURATIONED_SPELL;
    if(isDurationedSpell) {
      if (currentHero->HasArtifact(ARTIFACT_ENCHANTED_HOURGLASS))
        spellpower += 2;
      if (currentHero->HasArtifact(ARTIFACT_WIZARDS_HAT))
        spellpower += 10;
    }
  }

  SCmbtHero combatHero = sCmbtHero[this->heroType[this->currentActionSide]];
  if (!isCreatureAbility) {
    int centX = -1;
    int centY = -1;
    if (stack) {
      centX = stack->MidX();
      centY = stack->MidY();
    } else if (proto_spell == SPELL_FIREBALL
            || proto_spell == SPELL_FIREBLAST
            || proto_spell == SPELL_COLD_RING
            || proto_spell == SPELL_METEOR_SHOWER) {
      centX = this->combatGrid[hexIdx].centerX;
      centY = this->combatGrid[hexIdx].occupyingCreatureBottomY - 17;
    }

    if (centX == -1) {
      this->heroAnimationType[this->currentActionSide] = 3;
    } else {
      if (this->currentActionSide) {
        castX = 610 - combatHero.castXOff;
        castY = combatHero.castYOff + 148;
      } else {
        castX = combatHero.castXOff + 30;
        castY = combatHero.castYOff + 183;
      }
      if ((centX - castX) * (this->currentActionSide < 1u ? 1 : -1) >= centY - castY) {
        this->heroAnimationType[this->currentActionSide] = 5;
      } else {
        this->heroAnimationType[this->currentActionSide] = 7;
        if (this->currentActionSide) {
          castX = 610 - combatHero.castLowXOff;
          castY = combatHero.castLowYOff + 148;
        } else {
          castX = combatHero.castLowXOff + 30;
          castY = combatHero.castLowYOff + 183;
        }
      }
    }
    for (this->heroAnimationFrameCount[this->currentActionSide] = 0;
      combatHero.animationLength[this->heroAnimationType[this->currentActionSide]] > this->heroAnimationFrameCount[this->currentActionSide];
      ++this->heroAnimationFrameCount[this->currentActionSide])
      this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    --this->heroAnimationFrameCount[this->currentActionSide];
  }

  int spell = proto_spell;
  if (proto_spell == SPELL_MEDUSA_PETRIFY)
    spell = SPELL_PARALYZE;
  if (proto_spell == SPELL_ARCHMAGI_DISPEL)
    spell = SPELL_DISPEL_MAGIC;

  SAMPLE2 res = NULL_SAMPLE2;
  if (strlen(gsSpellInfo[spell].soundName))
    sprintf(gText, "%s.82M", &gsSpellInfo[spell].soundName);
  if (isCreatureAbility || !stack || stack->SpellCastWorks(proto_spell)) {
    res = LoadPlaySample(gText);
    switch (proto_spell) {
    case SPELL_TELEPORT:
    {
      army *thisb = stack;
      int hexIdxa = a5;
      this->RippleCreature(stack->owningSide, stack->stackIdx, 1);
      this->combatGrid[stack->occupiedHex].unitOwner = -1;
      this->combatGrid[thisb->occupiedHex].stackIdx = -1;
      if (this->combatGrid[thisb->occupiedHex].occupiersOtherHexIsToLeft) {
        if (this->combatGrid[thisb->occupiedHex].occupiersOtherHexIsToLeft == 1) {
          this->combatGrid[thisb->occupiedHex - 1].unitOwner = -1;
          this->combatGrid[thisb->occupiedHex - 1].stackIdx = -1;
        }
      } else {
        this->combatGrid[thisb->occupiedHex + 1].unitOwner = -1;
        this->combatGrid[thisb->occupiedHex + 1].stackIdx = -1;
      }
      if (!gbNoShowCombat)
        WaitEndSample(res, res.sample);
      if (!gbNoShowCombat) {
        sprintf(gText, "telptin.82m");
        res = (SAMPLE2)LoadPlaySample(gText);
      }
      if (thisb->creature.creature_flags & TWO_HEXER) {
        int knownHex = a5;
        if (thisb->facingRight == 1) {
          if ((knownHex = thisb->GetAdjacentCellIndex(knownHex, 1), knownHex == -1)
            || this->combatGrid[knownHex].unitOwner != -1
            && (this->combatGrid[knownHex].unitOwner != owner || this->combatGrid[knownHex].stackIdx != stackidx)
            || this->combatGrid[knownHex].isBlocked)
            hexIdxa = a5 - 1;
        }
        if (!thisb->facingRight) {
          if ((knownHex = thisb->GetAdjacentCellIndex(knownHex, 4), knownHex == -1)
            || this->combatGrid[knownHex].unitOwner != -1
            && (this->combatGrid[knownHex].unitOwner != owner || this->combatGrid[knownHex].stackIdx != stackidx)
            || this->combatGrid[knownHex].isBlocked)
            ++hexIdxa;
        }
        thisb->occupiedHex = hexIdxa;
        int tmpFacingRight = thisb->facingRight;
        if (tmpFacingRight) {
          if (tmpFacingRight == 1) {
            this->combatGrid[thisb->occupiedHex].unitOwner = owner;
            this->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
            this->combatGrid[thisb->occupiedHex].occupiersOtherHexIsToLeft = 0;
            this->combatGrid[thisb->occupiedHex + 1].unitOwner = owner;
            this->combatGrid[thisb->occupiedHex + 1].stackIdx = stackidx;
            this->combatGrid[thisb->occupiedHex + 1].occupiersOtherHexIsToLeft = 1;
          }
        } else {
          this->combatGrid[thisb->occupiedHex].unitOwner = owner;
          this->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
          this->combatGrid[thisb->occupiedHex].occupiersOtherHexIsToLeft = 1;
          this->combatGrid[thisb->occupiedHex - 1].unitOwner = owner;
          this->combatGrid[thisb->occupiedHex - 1].stackIdx = stackidx;
          this->combatGrid[thisb->occupiedHex - 1].occupiersOtherHexIsToLeft = 0;
        }
        this->RippleCreature(thisb->owningSide, thisb->stackIdx, 2);
      } else {
        thisb->occupiedHex = a5;
        this->combatGrid[thisb->occupiedHex].unitOwner = owner;
        this->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
        this->combatGrid[thisb->occupiedHex].occupiersOtherHexIsToLeft = -1;
        this->RippleCreature(thisb->owningSide, thisb->stackIdx, 2);
      }
      break;
    }
    case SPELL_DISRUPTING_RAY: {
      int oldDefense = stack->creature.defense;
      stack->creature.defense -= 3;
      if (stack->creature.defense < 1)
        stack->creature.defense = 1;
      sprintf(gText, "The disrupting ray reduces defense by %d.", oldDefense - stack->creature.defense);
      this->CombatMessage(gText, 1, 1, 0);
      this->DoBlast(hexIdx, proto_spell);
      this->RippleCreature(stack->owningSide, stack->stackIdx, 0);
      break;
    }
    case SPELL_COLD_RAY: {
      DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 175.0));
      long damage = 20 * spellpower;
      if (stack->creatureIdx == CREATURE_FIRE_ELEMENTAL)
        damage *= 2;
      if (stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM)
        damage /= 2;
      this->ModifyDamageForArtifacts(&damage, SPELL_COLD_RAY, currentHero, enemyHero);
      char *creatureName;
      if (stack->quantity <= 1)
        creatureName = GetCreatureName(stack->creatureIdx);
      else
        creatureName = GetCreaturePluralName(stack->creatureIdx);
      sprintf(gText, "The cold ray does %d\n damage to the %s.", damage, creatureName);
      this->CombatMessage(gText, 1, 1, 0);
      this->DoBlast(hexIdx, proto_spell);
      stack->SpellEffect(gsSpellInfo[SPELL_COLD_RAY].creatureEffectAnimationIdx, 0, 0);
      stack->Damage(damage, SPELL_NONE);
      stack->PowEffect(-1, 1, -1, -1);
      break;
    }
    case SPELL_CHAIN_LIGHTNING:
      this->ChainLightning(hexIdx, spellpower);
      break;
    case SPELL_MAGIC_ARROW: {
      DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 100.0));
      long damage = 10 * spellpower;
      this->ModifyDamageForArtifacts(&damage, SPELL_MAGIC_ARROW, currentHero, enemyHero);
      char *creatureName;
      if (stack->quantity <= 1)
        creatureName = GetCreatureName(stack->creatureIdx);
      else
        creatureName = GetCreaturePluralName(stack->creatureIdx);
      sprintf(gText, "The magic arrow does %d\n damage to the %s.", damage, creatureName);
      this->CombatMessage(gText, 1, 1, 0);
      float angles[9] = {90.000000,45.000038,26.565073,18.262905,0.000000,-18.262905,-26.565073,-45.000038,-90.000000};
      icon *arrowIcon = gpResourceManager->GetIcon("keep.icn");
      this->ShootMissile(castX, castY, stack->MidX(), stack->MidY(), angles, arrowIcon);
      gpResourceManager->Dispose(arrowIcon);
      stack->Damage(damage, SPELL_NONE);
      stack->PowEffect(-1, 1, -1, -1);
      break;
    }
    case SPELL_LIGHTNING_BOLT: {
      long damage = 25 * spellpower;
      if (stack->creatureIdx == CREATURE_AIR_ELEMENTAL)
        damage *= 2;
      if (stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM) {
        damage /= 2;
      }
      this->ModifyDamageForArtifacts(&damage, SPELL_LIGHTNING_BOLT, currentHero, enemyHero);
      char *creatureName;
      if (stack->quantity <= 1)
        creatureName = GetCreatureName(stack->creatureIdx);
      else
        creatureName = GetCreaturePluralName(stack->creatureIdx);
      sprintf(gText, "The lightning bolt does %d\n damage to the %s.", damage, creatureName);
      this->CombatMessage(gText, 1, 1, 0);
      this->DoBolt(1, castX, castY, stack->MidX(), stack->MidY(), 150, 100, 9, 2, 301, -40, 40, 30, 1, 0, 0, 1);
      stack->SpellEffect(gsSpellInfo[SPELL_LIGHTNING_BOLT].creatureEffectAnimationIdx, 0, 0);
      stack->Damage(damage, SPELL_NONE);
      stack->PowEffect(-1, 1, -1, -1);
      break;
    }
    case SPELL_MASS_CURE:
    case SPELL_MASS_HASTE:
    case SPELL_MASS_SLOW:
    case SPELL_MASS_BLESS:
    case SPELL_MASS_CURSE:
    case SPELL_HOLY_WORD:
    case SPELL_HOLY_SHOUT:
    case SPELL_MASS_DISPEL:
    case SPELL_DEATH_RIPPLE:
    case SPELL_DEATH_WAVE:
    case SPELL_MASS_SHIELD:
    case SPELL_MASS_FORCE_SHIELD:
      this->CastMassSpell(proto_spell, spellpower);
      break;
    case SPELL_MIRROR_IMAGE:
      this->MirrorImage(hexIdx);
      break;
    case SPELL_SUMMON_EARTH_ELEMENTAL:
      this->SummonElemental(CREATURE_EARTH_ELEMENTAL, spellpower);
      break;
    case SPELL_SUMMON_AIR_ELEMENTAL:
      this->SummonElemental(CREATURE_AIR_ELEMENTAL, spellpower);
      break;
    case SPELL_SUMMON_FIRE_ELEMENTAL:
      this->SummonElemental(CREATURE_FIRE_ELEMENTAL, spellpower);
      break;
    case SPELL_SUMMON_WATER_ELEMENTAL:
      this->SummonElemental(CREATURE_WATER_ELEMENTAL, spellpower);
      break;
    case SPELL_RESURRECT:
    case SPELL_RESURRECT_TRUE:
    case SPELL_ANIMATE_DEAD:
      this->Resurrect(proto_spell, hexIdx, spellpower);
      break;
    case SPELL_CURE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SpellEffect(gsSpellInfo[SPELL_CURE].creatureEffectAnimationIdx, 0, 0);
      stack->Cure(spellpower);
      this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
      break;
    case SPELL_SLOW:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_SLOW, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_SLOW].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_HASTE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_HASTE, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_HASTE].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_SHIELD:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_SHIELD, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_SHIELD].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_DRAGON_SLAYER:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_DRAGON_SLAYER, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_DRAGON_SLAYER].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_BLESS:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_BLESS, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_BLESS].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_STONESKIN:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_STONESKIN, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_STONESKIN].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_STEELSKIN:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_STEELSKIN, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_STEELSKIN].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_CURSE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_CURSE, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_CURSE].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_BERZERKER:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_BERSERKER, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_BERZERKER].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_HYPNOTIZE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_HYPNOTIZE, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_HYPNOTIZE].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_PARALYZE:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_PARALYZE, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_PARALYZE].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_ARCHMAGI_DISPEL:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->DispelGood();
      stack->SpellEffect(gsSpellInfo[SPELL_DISPEL_MAGIC].creatureEffectAnimationIdx, 0, 1);
      break;
    case SPELL_DISPEL_MAGIC:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->DispelGood();
      stack->SpellEffect(gsSpellInfo[SPELL_DISPEL_MAGIC].creatureEffectAnimationIdx, 0, 0);
      for (int i = 0; i < 19; i++)
        stack->CancelIndividualSpell(i);
      break;
    case SPELL_BLIND:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_BLIND, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_BLIND].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_BLOOD_LUST:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      this->BloodLustEffect(stack, CREATURE_RED);
      stack->SetSpellInfluence(EFFECT_BLOOD_LUST, 3);
      break;
    case SPELL_ANTI_MAGIC:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_ANTI_MAGIC, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_ANTI_MAGIC].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_MEDUSA_PETRIFY:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      this->TurnToStone(stack);
      break;
    case SPELL_COLD_RING:
      this->Fireball(hexIdx, SPELL_COLD_RING);
      break;
    case SPELL_FIREBALL:
      this->Fireball(hexIdx, SPELL_FIREBALL);
      break;
    case SPELL_FIREBLAST:
      this->Fireball(hexIdx, SPELL_FIREBLAST);
      break;
    case SPELL_METEOR_SHOWER:
      this->MeteorShower(hexIdx);
      break;
    case SPELL_ELEMENTAL_STORM:
      this->ElementalStorm();
      break;
    case SPELL_ARMAGEDDON:
      this->Armageddon();
      break;
    case SPELL_EARTHQUAKE:
      this->Earthquake();
      break;
    case SPELL_SHADOW_MARK:
        this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
        stack->SetSpellInfluence(EFFECT_SHADOW_MARK, 1);
        stack->SpellEffect(gsSpellInfo[SPELL_SHADOW_MARK].creatureEffectAnimationIdx, 0, 0);
      break;
    case SPELL_MARKSMAN_PIERCE: {
      DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 100.0));
      //long damage = 10 * spellpower;
      long damage = 1000;
      if(isCastleBattle)
        if(currentActionSide == 0 && this->InCastle(stack->occupiedHex))
          damage *= 0.75;
      //this->ModifyDamageForArtifacts(&damage, SPELL_MARKSMAN_PIERCE, currentHero, enemyHero);
      char *creatureName;
      if (stack->quantity <= 1)
        creatureName = GetCreatureName(stack->creatureIdx);
      else
        creatureName = GetCreaturePluralName(stack->creatureIdx);
      sprintf(gText, "The marksman pierce round does %d\n damage to the %s.", damage, creatureName);
      this->CombatMessage(gText, 1, 1, 0);
      float angles[9] = {90.000000,45.000038,26.565073,18.262905,0.000000,-18.262905,-26.565073,-45.000038,-90.000000};
      icon *arrowIcon = gpResourceManager->GetIcon("keep.icn");
      this->ShootMissile(castX, castY, stack->MidX(), stack->MidY(), angles, arrowIcon);
      gpResourceManager->Dispose(arrowIcon);
      stack->Damage(damage, SPELL_NONE);
      
      stack->SetSpellInfluence(EFFECT_DAZE, 1);
      stack->SpellEffect(gsSpellInfo[SPELL_MARKSMAN_PIERCE].creatureEffectAnimationIdx, 0, 0);
      
      stack->PowEffect(-1, 1, -1, -1);
      break;
    }
    case SPELL_PLASMA_CONE:
      this->Fireball(hexIdx, SPELL_PLASMA_CONE);
      break;
    case SPELL_FORCE_SHIELD:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);

      stack->DispelGood();

      stack->SetSpellInfluence(EFFECT_FORCE_SHIELD, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_FORCE_SHIELD].creatureEffectAnimationIdx, 0, 0);
    break;
    default:
      this->DefaultSpell(hexIdx);
      break;
    }
  } else {
    this->ShowSpellCastFailure(stack, proto_spell);
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; this->numCreatures[i] > j; j++) {
      army *cr = &this->creatures[i][j];
      cr->hasTakenLosses = 0;
      cr->dead = cr->hasTakenLosses;
      cr->damageTakenDuringSomeTimePeriod = cr->dead;
      cr->field_6 = 1;
      cr->mightBeIsAttacking = 0;
      cr->previousQuantity = -1;
    }
  }
  if (!isCreatureAbility) {
    ++this->heroAnimationType[this->currentActionSide];
    for (this->heroAnimationFrameCount[this->currentActionSide] = 0;
      combatHero.animationLength[this->heroAnimationType[this->currentActionSide]] > this->heroAnimationFrameCount[this->currentActionSide];
      ++this->heroAnimationFrameCount[this->currentActionSide])
      this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    this->heroAnimationType[this->currentActionSide] = 0;
    this->heroAnimationFrameCount[this->currentActionSide] = 0;
    this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
  }
  WaitEndSample(res, res.sample);
  this->CheckChangeSelector();
}

void combatManager::CastMassSpell(int spell, signed int spellpower) {
  bool isDamageSpell = false;
  gpWindowManager->cycleColors = 0;
  this->ShowSpellMessage(0, spell, 0);

  char stackAffected[2][20];
  memset(stackAffected, 0, 40u);
  int thisSide = this->currentActionSide;
  int othSide = 1 - thisSide;
  switch(spell) {
    case SPELL_MASS_SLOW:
    case SPELL_MASS_CURSE:
      for(int i = 0; this->numCreatures[othSide] > i; ++i)
        if(this->creatures[othSide][i].SpellCastWorks(spell))
          stackAffected[othSide][i] = 1;
      break;
    case SPELL_MASS_CURE:
    case SPELL_MASS_HASTE:
    case SPELL_MASS_BLESS:
    case SPELL_MASS_SHIELD:
    case SPELL_MASS_FORCE_SHIELD:
      for(int i = 0; this->numCreatures[thisSide] > i; ++i)
        if(this->creatures[thisSide][i].SpellCastWorks(spell))
          stackAffected[thisSide][i] = 1;
      break;
    case SPELL_MASS_DISPEL:
      for(int side = 0; side < 2; side++)
        for(int i = 0; this->numCreatures[side] > i; ++i)
          if(this->creatures[side][i].SpellCastWorks(spell))
            stackAffected[side][i] = 1;
      break;
    case SPELL_HOLY_WORD:
    case SPELL_HOLY_SHOUT: {
      isDamageSpell = true;
      int damage;
      if(spell == SPELL_HOLY_WORD)
        damage = spellpower * 10;
      else
        damage = spellpower * 20;
      for(int side = 0; side < 2; ++side)
        for(int i = 0; ; ++i) {
          if(this->numCreatures[side] <= i)
            break;
          if(HIBYTE(this->creatures[side][i].creature.creature_flags) & ATTR_UNDEAD
            && this->creatures[side][i].SpellCastWorks(spell))
            stackAffected[side][i] = 1;
        }
      if(spell == SPELL_HOLY_WORD)
        this->Blur(0, -2, -2);
      else
        this->Blur(0, -4, -4);
      for(int side = 0; side < 2; ++side)
        for(int i = 0; this->numCreatures[side] > i; ++i)
          if(stackAffected[side][i])
            this->creatures[side][i].Damage(damage, SPELL_NONE);

      sprintf(gText, "The %s spell does %d damage\nto all undead creatures.", gSpellNames[spell], damage);
      this->CombatMessage(gText, 1, 1, 0);
      break;
    }
    case SPELL_DEATH_RIPPLE:
    case SPELL_DEATH_WAVE: {
      isDamageSpell = true;
      for(int side = 0; side < 2; ++side)
        for(int i = 0; ; ++i) {
          if(this->numCreatures[side] <= i)
            break;
          if(!(HIBYTE(this->creatures[side][i].creature.creature_flags) & ATTR_UNDEAD)
            && this->creatures[side][i].SpellCastWorks(spell))
            stackAffected[side][i] = 1;
        }
      int damage;
      if(spell == SPELL_DEATH_RIPPLE) {
        damage = spellpower * 5;
        this->Ripple(1);
      } else {
        damage = spellpower * 10;
        this->Ripple(2);
      }
      for(int side = 0; side < 2; ++side)
        for(int i = 0; this->numCreatures[side] > i; ++i)
          if(stackAffected[side][i])
            this->creatures[side][i].Damage(damage, SPELL_NONE);

      sprintf(gText, "The Death spell does %d damage\nto all living creatures.", damage);
      this->CombatMessage(gText, 1, 1, 0);
      break;
    }
    default:
      break;
  }
  if(!gbNoShowCombat) {
    int anyoneAffected = 0;
    for(int side = 0; side < 2; ++side)
      for(int i = 0; this->numCreatures[side] > i; ++i)
        if(stackAffected[side][i])
          anyoneAffected = 1;

    if(anyoneAffected) {
      int animIdx = gsSpellInfo[spell].creatureEffectAnimationIdx;
      this->ShowMassSpell((signed char(*)[20])stackAffected, animIdx, isDamageSpell);
    }
  }
  for(int affectedSide = 0; affectedSide < 2; ++affectedSide)
    for(int i = 0; this->numCreatures[affectedSide] > i; ++i)
      if(stackAffected[affectedSide][i]) {
        army *creature = &this->creatures[affectedSide][i];
        switch(spell) {
          case SPELL_MASS_CURSE:
            creature->SetSpellInfluence(EFFECT_CURSE, spellpower);
            break;
          case SPELL_MASS_SLOW:
            creature->SetSpellInfluence(EFFECT_SLOW, spellpower);
            break;
          case SPELL_MASS_HASTE:
            creature->SetSpellInfluence(EFFECT_HASTE, spellpower);
            break;
          case SPELL_MASS_BLESS:
            creature->SetSpellInfluence(EFFECT_BLESS, spellpower);
            break;
          case SPELL_MASS_SHIELD:
            creature->SetSpellInfluence(EFFECT_SHIELD, spellpower);
            break;
          case SPELL_MASS_FORCE_SHIELD:
            creature->SetSpellInfluence(EFFECT_FORCE_SHIELD, spellpower);
            break;
          case SPELL_MASS_CURE:
            creature->Cure(spellpower);
            break;
          case SPELL_MASS_DISPEL:
            for(int i = 0; i < NUM_SPELL_EFFECTS; i++)
              creature->CancelIndividualSpell(i);
            break;
          case SPELL_DEATH_RIPPLE:
          case SPELL_DEATH_WAVE:
            continue;
        }
      }
  this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
  gpWindowManager->cycleColors = 1;
}

CURSOR_DIRECTION combatManager::GetCursorDirection(int screenX, int screenY, int hex) {
  int offsetX;
  int offsetY;

  offsetX = screenX - 44 * (hex % 13 - 1) - 67;
  if ( !(hex / 13 & 1) )
    offsetX = screenX - 44 * (hex % 13 - 1) - 89;
  
  offsetY = screenY - 63 - 42 * (hex / 13) - 26;

  int clockHour = 0;
  int v15 = offsetX - 22;
  if(v15 >= 0) {
    if(offsetY >= 0)
      clockHour = 6;
  } else if(offsetY >= 0) {
    clockHour = 12;
  } else {
    clockHour = 18;
  }

  float v9 = (double)abs(v15) / (double)abs(offsetY);

  if(clockHour && clockHour != 12) {
    if(v9 >= 0.27) {
      if(v9 >= 0.58) {
        if(v9 >= 1.0) {
          if(v9 >= 1.73) {
            if(v9 < 3.73)
              ++clockHour;
          } else {
            clockHour += 2;
          }
        } else {
          clockHour += 3;
        }
      } else {
        clockHour += 4;
      }
    } else {
      clockHour += 5;
    }
  } else if(v9 <= 3.73) {
    if(v9 <= 1.73) {
      if(v9 <= 1.0) {
        if(v9 <= 0.58) {
          if(v9 > 0.27)
            ++clockHour;
        } else {
          clockHour += 2;
        }
      } else {
        clockHour += 3;
      }
    } else {
      clockHour += 4;
    }
  } else {
    clockHour += 5;
  }

  switch(clockHour) {
    case 23: case 0: case 1:
      return CURSOR_DIRECTION_DOWN;
    case 2: case 3: case 4:
      return CURSOR_DIRECTION_LEFT_DOWN;
    case 5: case 6: case 7:
      return CURSOR_DIRECTION_LEFT;
    case 8: case 9: case 10:
      return CURSOR_DIRECTION_LEFT_UP;
    case 11: case 12: case 13:
      return CURSOR_DIRECTION_UP;
    case 14: case 15: case 16:
      return CURSOR_DIRECTION_RIGHT_UP;
    case 17: case 18: case 19:
      return CURSOR_DIRECTION_RIGHT;
    case 20: case 21: case 22:
      return CURSOR_DIRECTION_RIGHT_DOWN;
  }
}

int GetHexNeighboursLine(int startingFrom, int neighbDir, int len, std::vector<int> &hexes) {
  hexes.clear();
  int curHex = startingFrom;
  hexes.push_back(startingFrom);
  for(int j = 0; j < len-1; j++) {
    int nei = GetAdjacentCellIndexNoArmy(curHex, neighbDir);
    if(nei != -1) {
      hexes.push_back(nei);
      curHex = nei;
    }
    else break;
  }
  if(hexes.size())
    return 0;
  return 1;
}

static std::vector<int> GetPlasmaConeSpellMask(int fromHex, int direction) {
  std::vector<int> mask;
  int spellNeighbourDirections[8][3] = {
    {5, 0, 1}, // right up
    {0, 1, 2}, // right
    {1, 2, 3}, // right down
    {-1, -1, -1}, // UNUSED down
    {2, 3, 4}, // left down
    {3, 4, 5}, // left
    {4, 5, 0},  // left up
    {-1, -1, -1} // UNUSED up
  };
    
  int leftDirection = spellNeighbourDirections[direction][0];
  int centerDirection = spellNeighbourDirections[direction][1];
  int rightDirection = spellNeighbourDirections[direction][2];

  // Get starting hexes for lines and their length
  struct HexLineData {
    int fromHex;
    int len;
  };
  std::vector<HexLineData> hexLineData;
  
  int centerHex = fromHex;
  hexLineData.push_back({ centerHex, 8 });

  int leftHex = GetAdjacentCellIndexNoArmy(GetAdjacentCellIndexNoArmy(centerHex, centerDirection), leftDirection);
  if(leftHex != -1)
    hexLineData.push_back({ leftHex, 6 });
  leftHex = GetAdjacentCellIndexNoArmy(leftHex, centerDirection);
  leftHex = GetAdjacentCellIndexNoArmy(GetAdjacentCellIndexNoArmy(leftHex, centerDirection), leftDirection);
  if(leftHex != -1)
    hexLineData.push_back({ leftHex, 4 });
  leftHex = GetAdjacentCellIndexNoArmy(GetAdjacentCellIndexNoArmy(leftHex, centerDirection), leftDirection);
  if(leftHex != -1)
    hexLineData.push_back({ leftHex, 2 });

  int rightHex = GetAdjacentCellIndexNoArmy(GetAdjacentCellIndexNoArmy(centerHex, centerDirection), rightDirection);
  if(rightHex != -1)
    hexLineData.push_back({ rightHex, 6 });
  rightHex = GetAdjacentCellIndexNoArmy(rightHex, centerDirection);
  rightHex = GetAdjacentCellIndexNoArmy(GetAdjacentCellIndexNoArmy(rightHex, centerDirection), rightDirection);
  if(rightHex != -1)
    hexLineData.push_back({ rightHex, 4 });
  rightHex = GetAdjacentCellIndexNoArmy(GetAdjacentCellIndexNoArmy(rightHex, centerDirection), rightDirection);
  if(rightHex != -1)
    hexLineData.push_back({ rightHex, 2 });
  
  // Getting lines of hexes and the whole mask out of all of them
  for(auto i : hexLineData) {
    std::vector<int> lineHexes;
    if(!GetHexNeighboursLine(i.fromHex, centerDirection, i.len, lineHexes))
      mask.insert(mask.end(), lineHexes.begin(), lineHexes.end());
  }
  return mask;
}

std::vector<int> GetSpellMask(Spell spell, int fromHex, int direction) {
  std::vector<int> mask;
  switch(spell) {
    case SPELL_PLASMA_CONE:
      mask = GetPlasmaConeSpellMask(fromHex, direction);
      break;
    case SPELL_FIREBALL:
      mask = GetSpellMask(SPELL_COLD_RING, fromHex, direction);
      mask.push_back(fromHex);
      break;
    case SPELL_COLD_RING:
      for(int i = 0; i < 6; i++) {
        int nei = GetAdjacentCellIndexNoArmy(fromHex, i);
        if(gpCombatManager->ValidSpellTarget(spell, nei))
          mask.push_back(nei);
      }
      break;
    case SPELL_FIREBLAST:
      mask = GetSpellMask(SPELL_FIREBALL, fromHex, direction);
      // adding hexes on straight lines from target hex
      for(int i = 0; i < 6; i++) {
        int neiOfNeiStraight = GetAdjacentCellIndexNoArmy(GetAdjacentCellIndexNoArmy(fromHex, i), i);
        if(gpCombatManager->ValidSpellTarget(spell, neiOfNeiStraight)) {
          mask.push_back(neiOfNeiStraight);
        }
      }
      // adding remaining farthest hexes
      for(int i = 0; i < 6; i++) {
        int closestNei = GetAdjacentCellIndexNoArmy(fromHex, i);
        if(gpCombatManager->ValidSpellTarget(spell, closestNei)) {
          int dirRight = i + 1;
          if(dirRight >= 6)
            dirRight -= 6;
          int rightHex = GetAdjacentCellIndexNoArmy(closestNei, dirRight);
          if(gpCombatManager->ValidSpellTarget(spell, rightHex))
            mask.push_back(rightHex);
          int dirLeft = i - 1;
          if(dirLeft < 0)
            dirLeft += 6;
          int leftHex = GetAdjacentCellIndexNoArmy(closestNei, dirLeft);
          if(gpCombatManager->ValidSpellTarget(spell, leftHex))
            mask.push_back(leftHex);
        }
      }
      break;
    default:
      mask.push_back(fromHex);
  }
  // remove duplicates and invalid values
  std::set<int> tmp;
  unsigned size = mask.size();
  for( unsigned i = 0; i < size; ++i )
    if(mask[i] != -1)
      tmp.insert(mask[i]);
  mask.assign(tmp.begin(), tmp.end());
  return mask;
}

int __fastcall HandleCastSpell(tag_message &evt) {
  Event *msg = (Event*)&evt;
  Spell currentSpell = (Spell)gpCombatManager->current_spell_id;
  switch(msg->inputEvt.eventCode) {
    case INPUT_MOUSEMOVE_EVENT_CODE: {
      int hex = gpCombatManager->GetGridIndex(msg->inputEvt.xCoordOrKeycode, msg->inputEvt.yCoordOrFieldID);
      if(gpCombatManager->ValidSpellTarget(currentSpell, hex)) {
        indexToCastOn = hex;

        // save hex colors
        char savedHexes[NUM_HEXES];
        for(int i = 0; i < NUM_HEXES; i++)
          savedHexes[i] = gpCombatManager->field_49F[i];

        // marking all valid hexes as available to be casted on
        for(int i = 0; i < NUM_HEXES; i++)
          if(gpCombatManager->ValidSpellTarget(currentSpell, i))
            gpCombatManager->field_49F[i] = 3;

        std::vector<int> spellMask;
        switch(currentSpell) {
          case SPELL_PLASMA_CONE:
          {
            // changing cursor
            CURSOR_DIRECTION dir = gpCombatManager->GetCursorDirection(evt.altXCoord, evt.altYCoord, indexToCastOn);
            int cursorIdx = 0;
            switch(dir) {
              case CURSOR_DIRECTION_LEFT_DOWN: case CURSOR_DIRECTION_DOWN:
                cursorIdx = 10;
                break;
              case CURSOR_DIRECTION_LEFT:
                cursorIdx = 11;
                break;
              case CURSOR_DIRECTION_LEFT_UP: case CURSOR_DIRECTION_UP:
                cursorIdx = 12;
                break;
              case CURSOR_DIRECTION_RIGHT_UP:
                cursorIdx = 7;
                break;
              case CURSOR_DIRECTION_RIGHT:
                cursorIdx = 8;
                break;
              case CURSOR_DIRECTION_RIGHT_DOWN:
                cursorIdx = 9;
                break;
            }
            gpMouseManager->cursorCategory = MOUSE_CURSOR_CATEGORY_COMBAT;
            gpMouseManager->SetPointer(cursorIdx);

            // Getting spell direction
            gSpellDirection = CURSOR_DIRECTION_RIGHT;
            switch(dir) {
              case CURSOR_DIRECTION_DOWN:
                gSpellDirection = CURSOR_DIRECTION_LEFT_DOWN;
                break;
              case CURSOR_DIRECTION_UP:
                gSpellDirection = CURSOR_DIRECTION_LEFT_UP;
                break;
              default:
                gSpellDirection = dir;
                break;
            }
            break;
          }
          default: {
            // changing cursor
            gpMouseManager->SetPointer(gsSpellInfo[currentSpell].magicBookIconIdx);
          }
        }
        // setting spell mask
        spellMask = GetSpellMask(currentSpell, indexToCastOn, gSpellDirection);
        
        // marking affected hexes
        for(auto i : spellMask)
          gpCombatManager->field_49F[i] = 1;

        // showing affected hexes
        gpCombatManager->UpdateGrid(0, 0);
        gpCombatManager->DrawFrame(1, 0, 0, 0, 0, 1, 1);

        //reverting hex colors before marking again if needed
        for(int i = 0; i < NUM_HEXES; i++)
          gpCombatManager->field_49F[i] = savedHexes[i];

        gpCombatManager->SpellMessage(currentSpell, hex);
      } else {
        indexToCastOn = -1;
        gpMouseManager->SetPointer(0);
        if(currentSpell == SPELL_TELEPORT && bInTeleportGetDest)
          gpCombatManager->CombatMessage("Invalid Teleport Destination", 1, 0, 0);
        else
          gpCombatManager->CombatMessage("Select Spell Target", 1, 0, 0);
      }
      return 1;
    }
    case INPUT_LEFT_CLICK_EVENT_CODE:
      if(indexToCastOn == -1)
        return 1;
      if(bInTeleportGetDest) {
        giNextActionGridIndex2 = indexToCastOn;
      } else {
        giNextActionGridIndex = indexToCastOn;
        if(currentSpell == SPELL_TELEPORT) {
          bInTeleportGetDest = 1;
          indexToCastOn = -1;
          msg->inputEvt.eventCode = INPUT_MOUSEMOVE_EVENT_CODE;
          msg->inputEvt.xCoordOrKeycode = msg->inputEvt.altXCoord;
          msg->inputEvt.yCoordOrFieldID = msg->inputEvt.altYCoord;
          HandleCastSpell((tag_message&)msg);
          gpCombatManager->CombatMessage("Select teleport destination.", 1, 0, 0);
          return 1;
        }
      }
      bInTeleportGetDest = 0;
      msg->inputEvt.eventCode = INPUT_GUI_MESSAGE_CODE;
      msg->inputEvt.xCoordOrKeycode = 10;
      // clear combatfield from marked hexes
      gpCombatManager->UpdateGrid(0, 0);
      return 2;
    case INPUT_KEYDOWN_EVENT_CODE:
      if(msg->guiMsg.messageType == 1) {
        gpCombatManager->current_spell_id = -1;
        giNextAction = 0;
        msg->inputEvt.eventCode = INPUT_GUI_MESSAGE_CODE;
        msg->inputEvt.xCoordOrKeycode = 10;
        bInTeleportGetDest = 0;
        // clear combatfield from marked hexes
        gpCombatManager->UpdateGrid(0, 0);
        return 2;
      }
      return 1;
    case INPUT_RIGHT_CLICK:
      gpCombatManager->current_spell_id = -1;
      giNextAction = 0;
      msg->inputEvt.eventCode = INPUT_GUI_MESSAGE_CODE;
      msg->inputEvt.xCoordOrKeycode = 10;
      bInTeleportGetDest = 0;
      // clear combatfield from marked hexes
      gpCombatManager->UpdateGrid(0, 0);
      return 2;
    default:
      return 1;
  }
}

void combatManager::Fireball(int hexIdx, int spell) {
  if(!ValidHex(hexIdx))
    return;

  if(!gbNoShowCombat) {
    icon *spellIcon;
    int numSprites = 12;
    switch(spell) {
      case SPELL_FIREBALL:
        spellIcon = gpResourceManager->GetIcon("fireball.icn");
        break;
      case SPELL_FIREBLAST:
        spellIcon = gpResourceManager->GetIcon("firebal2.icn");
        break;
      case SPELL_COLD_RING:
        spellIcon = gpResourceManager->GetIcon("coldring.icn");
        numSprites = 7;
        break;
      default:
        spellIcon = gpResourceManager->GetIcon("fireball.icn");
        break;
    }
    int x = this->combatGrid[hexIdx].centerX;
    int y = this->combatGrid[hexIdx].occupyingCreatureBottomY - 17;
    for(int spriteID = 0; spriteID < numSprites; spriteID++) {
      glTimers = (signed __int64)((double)KBTickCount() + gfCombatSpeedMod[giCombatSpeed] * 75.0);
      IconToBitmap(spellIcon, gpWindowManager->screenBuffer, x, y, spriteID, 1, 0, 0, 0x280u, 443, 0);
      if(spell == SPELL_COLD_RING)
        FlipIconToBitmap(spellIcon, gpWindowManager->screenBuffer, x, y, spriteID, 1, 0, 0, 640, 443, 0);
      this->UpdateCombatArea();
      this->DrawFrame(0, 0, 0, 0, 75, 1, 1);
      DelayTil(&glTimers);
    }
    gpResourceManager->Dispose((resource *)spellIcon);
  }
  this->DrawFrame(1, 0, 0, 0, 75, 1, 1);

  army *stack = &this->creatures[this->currentActionSide][this->someSortOfStackIdx];

  long spellDamage = 10 * this->heroSpellpowers[this->currentActionSide];
  combatManager::ClearEffects();

  std::vector<int>affectedHexes = GetSpellMask((Spell)spell, hexIdx, gSpellDirection);

  int anyoneDamaged = 0;
  for(auto hex : affectedHexes) {
    hexcell *curHexcell = &this->combatGrid[hex];
    char unitOwner = curHexcell->unitOwner;
    char stackIdx = curHexcell->stackIdx;
    if(unitOwner == -1)
      continue;
    stack = &this->creatures[unitOwner][stackIdx];
    if(!stack->SpellCastWorks(spell))
      continue;
    if(gArmyEffected[unitOwner][stackIdx])
      continue;
    gArmyEffected[unitOwner][stackIdx] = 1;
    if(!stack->damageTakenDuringSomeTimePeriod) {
      int damage = spellDamage;
      if(stack->creatureIdx == CREATURE_FIRE_ELEMENTAL && spell == SPELL_COLD_RING)
        damage *= 2;
      if(stack->creatureIdx == CREATURE_WATER_ELEMENTAL && (spell == SPELL_FIREBALL || spell == SPELL_FIREBLAST))
        damage *= 2;
      if(stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM)
        damage /= 2;
      stack->Damage(damage, spell);
      anyoneDamaged = 1;
    }
  }
  if(anyoneDamaged) {
    this->ModifyDamageForArtifacts(&spellDamage, spell, this->heroes[this->currentActionSide], this->heroes[1 - this->currentActionSide]);
    switch(spell) {
      case SPELL_COLD_RING:
        sprintf(gText, "The cold ring does %d damage.", spellDamage);
        break;
      case SPELL_PLASMA_CONE:
        sprintf(gText, "The plasma cone stream does %d damage.", spellDamage);
        break;
      default:
         sprintf(gText, "The fireball does %d damage.", spellDamage);
         break;
    }
    this->CombatMessage(gText, 1, 1, 0);
    stack->PowEffect(-1, 1, -1, -1);
  }
}

int combatManager::ViewSpells(int unused) {
  this->current_spell_id = gpGame->ViewSpells(this->heroes[giCurGeneral], SPELL_CATEGORY_COMBAT, CombatSpecialHandler, 0);
  if(this->current_spell_id == SPELL_NONE)
    return 0;
  else {
    switch(this->current_spell_id) {
      case SPELL_EARTHQUAKE:
        if(this->castles[1]) {
          giNextAction = 1;
          giNextActionExtra = this->current_spell_id;
          break;
        }
        NormalDialog("An earthquake will do you no good unless there are town walls to damage.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
        break;
      case SPELL_SUMMON_EARTH_ELEMENTAL: case SPELL_SUMMON_AIR_ELEMENTAL: case SPELL_SUMMON_FIRE_ELEMENTAL: case SPELL_SUMMON_WATER_ELEMENTAL: {
        CREATURES elemental_type;
        switch(this->current_spell_id) {
          case SPELL_SUMMON_EARTH_ELEMENTAL:
            elemental_type = CREATURE_EARTH_ELEMENTAL;
            break;
          case SPELL_SUMMON_AIR_ELEMENTAL:
            elemental_type = CREATURE_AIR_ELEMENTAL;
            break;
          case SPELL_SUMMON_FIRE_ELEMENTAL:
            elemental_type = CREATURE_FIRE_ELEMENTAL;
            break;
          case SPELL_SUMMON_WATER_ELEMENTAL:
            elemental_type = CREATURE_WATER_ELEMENTAL;
            break;
        }
        if(this->summonedCreatureType[this->currentActionSide] && this->summonedCreatureType[this->currentActionSide] != elemental_type) {
          NormalDialog("You may only summon one type of elemental per combat.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
          return 0;
        }
        if(this->numCreatures[this->currentActionSide] >= 20) {
          sprintf(gText, "You already have %d creatures groups in combat and cannot add any more.", this->numCreatures[this->currentActionSide]);
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          return 0;
        }
        if(!this->SpaceForElementalExists()) {
          NormalDialog("There is no open space adjacent to your hero to summon an Elemental to.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
          return 0;
        }
        giNextAction = 1;
        giNextActionExtra = this->current_spell_id;
        break;
      }
      case SPELL_MASS_CURE:
      case SPELL_MASS_HASTE:
      case SPELL_MASS_SLOW:
      case SPELL_MASS_BLESS:
      case SPELL_MASS_CURSE:
      case SPELL_HOLY_WORD:
      case SPELL_HOLY_SHOUT:
      case SPELL_MASS_DISPEL:
      case SPELL_ARMAGEDDON:
      case SPELL_ELEMENTAL_STORM:
      case SPELL_DEATH_RIPPLE:
      case SPELL_DEATH_WAVE:
      case SPELL_MASS_SHIELD:
        if(this->HasValidSpellTarget(this->current_spell_id)) {
          giNextAction = 1;
          giNextActionExtra = this->current_spell_id;
          break;
        }
        NormalDialog("That spell will affect no one!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
        return 0;
      case SPELL_MIRROR_IMAGE: {
        if(this->numCreatures[this->currentActionSide] < 20) {
          if(!this->HasValidSpellTarget(this->current_spell_id)) {
            NormalDialog("That spell will affect no one!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
            return 0;
          }
          giNextAction = 1;
          giNextActionExtra = this->current_spell_id;
          gpMouseManager->SetPointer("spelmous.mse", gsSpellInfo[this->current_spell_id].magicBookIconIdx, -999);
          gpWindowManager->DoDialog(0, HandleCastSpell, 0);
          break;
        }
        sprintf(gText, "You already have %d creatures groups in combat and cannot add any more.", this->numCreatures[this->currentActionSide]);
        NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        return 0;
      }
      default:
        if(!this->HasValidSpellTarget(this->current_spell_id)) {
          NormalDialog("That spell will affect no one!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
          return 0;
        }
        giNextAction = 1;
        giNextActionExtra = this->current_spell_id;
        gpMouseManager->SetPointer("spelmous.mse", gsSpellInfo[this->current_spell_id].magicBookIconIdx, -999);
        gpWindowManager->DoDialog(0, HandleCastSpell, 0);
        break;
    }
    gpMouseManager->SetPointer("cmbtmous.mse", 0, -999);
    if(this->current_spell_id == SPELL_NONE)
      return 0;
    return 1;
  }
}