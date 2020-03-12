#include "adventure\adv.h"
#include "combat\animation.h"
#include "combat\combat.h"
#include "combat\speed.h"
#include "gui\dialog.h"
#include "resource\resourceManager.h"
#include "spell\spells.h"

#include "artifacts.h"
#include "base.h"
#include "expansions.h"
#include "scripting/callback.h"
#include "scripting/deepbinding.h"
#include "skills.h"
#include "sound/sound.h"

#include <algorithm>
#include <set>

extern int castX;
extern int castY;

extern heroWindowManager *gpWindowManager;

extern ironfistExtra gIronfistExtra;
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
  double chance = 1.0;
  if (spell == SPELL_SHADOW_MARK && this->dead)
    chance = 0.0;
  
  if((spell == SPELL_MIRROR_IMAGE || spell == SPELL_ANTI_MAGIC) && this->creature.creature_flags & ATTR_MIRROR_IMAGE)
    chance = 0.0;

  if(chance > 0.0 && spell == SPELL_DISPEL_MAGIC || spell == SPELL_MASS_DISPEL) {
    bool hasEffect = false;
    for(int i = 0; i < NUM_SPELL_EFFECTS; ++i) {
      if(this->effectStrengths[i]) {
        hasEffect = true;
        break;
      }
    }
    if(!hasEffect)
      chance = 0.0;
  }
  
  bool isUndead = this->creature.creature_flags & ATTR_UNDEAD;
  if(chance > 0.0 && this->effectStrengths[EFFECT_ANTI_MAGIC] || this->creature.creature_flags & CREATURE_FLAGS::DEAD
    && spell != SPELL_RESURRECT
    && spell != SPELL_RESURRECT_TRUE
    && spell != SPELL_ANIMATE_DEAD
    || this->dead
    || creatureIdx == CREATURE_GREEN_DRAGON
    || creatureIdx == CREATURE_RED_DRAGON
    || creatureIdx == CREATURE_BLACK_DRAGON)
    chance = 0.0;

  if(chance > 0.0 && spell == SPELL_MIRROR_IMAGE && this->mirrorIdx != -1)
    chance = 0.0;
  if(chance > 0.0 && (spell == SPELL_RESURRECT || spell == SPELL_RESURRECT_TRUE) && (isUndead || this->initialQuantity == this->quantity))
    chance = 0.0;
  if(chance > 0.0 && spell == SPELL_ANIMATE_DEAD && (!isUndead || this->initialQuantity == this->quantity))
    chance = 0.0;
  if(chance > 0.0 && (spell == SPELL_HOLY_WORD || spell == SPELL_HOLY_SHOUT) && !isUndead)
    chance = 0.0;
  if(chance > 0.0 && (spell == SPELL_DEATH_RIPPLE || spell == SPELL_DEATH_WAVE) && isUndead)
    chance = 0.0;
  if(chance > 0.0 && creatureIdx == CREATURE_PHOENIX
    && (spell == SPELL_FIREBALL
      || spell == SPELL_FIREBLAST
      || spell == SPELL_LIGHTNING_BOLT
      || spell == SPELL_CHAIN_LIGHTNING
      || spell == SPELL_COLD_RAY
      || spell == SPELL_COLD_RING
      || spell == SPELL_ELEMENTAL_STORM))
    chance = 0.0;
  if(chance > 0.0 && creatureIdx == CREATURE_CRUSADER && (spell == SPELL_CURSE || spell == SPELL_MASS_CURSE))
    chance = 0.0;
  if(chance > 0.0 && (isUndead
    || creatureIdx == CREATURE_EARTH_ELEMENTAL
    || creatureIdx == CREATURE_AIR_ELEMENTAL
    || creatureIdx == CREATURE_FIRE_ELEMENTAL
    || creatureIdx == CREATURE_WATER_ELEMENTAL
    || creatureIdx == CREATURE_GIANT
    || creatureIdx == CREATURE_TITAN)
    && (spell == SPELL_BERZERKER || spell == SPELL_HYPNOTIZE || spell == SPELL_PARALYZE || spell == SPELL_BLIND))
    chance = 0.0;
  if(chance > 0.0 && isUndead && (spell == SPELL_CURSE || spell == SPELL_MASS_CURSE || spell == SPELL_BLESS || spell == SPELL_MASS_BLESS))
    chance = 0.0;
  if(chance > 0.0 && creatureIdx == CREATURE_EARTH_ELEMENTAL && (spell == SPELL_LIGHTNING_BOLT || spell == SPELL_CHAIN_LIGHTNING || spell == SPELL_ELEMENTAL_STORM))
    chance = 0.0;
  if(chance > 0.0 && creatureIdx == CREATURE_AIR_ELEMENTAL && spell == SPELL_METEOR_SHOWER)
    chance = 0.0;
  if(chance > 0.0 && creatureIdx == CREATURE_FIRE_ELEMENTAL && (spell == SPELL_FIREBALL || spell == SPELL_FIREBLAST))
    chance = 0.0;
  if(chance > 0.0 && creatureIdx == CREATURE_WATER_ELEMENTAL && (spell == SPELL_COLD_RAY || spell == SPELL_COLD_RING))
    chance = 0.0;

  hero* ownHero = gpCombatManager->heroes[this->owningSide];
  if(ownHero) {
    if(chance > 0.0 && ownHero->HasArtifact(ARTIFACT_HOLY_PENDANT) && (spell == SPELL_CURSE || spell == SPELL_MASS_CURSE))
      chance = 0.0;
    if(chance > 0.0 && ownHero->HasArtifact(ARTIFACT_PENDANT_OF_FREE_WILL) && spell == SPELL_HYPNOTIZE)
      chance = 0.0;
    if(chance > 0.0 && ownHero->HasArtifact(ARTIFACT_PENDANT_OF_LIFE) && (spell == SPELL_DEATH_RIPPLE || spell == SPELL_DEATH_WAVE))
      chance = 0.0;
    if(chance > 0.0 && ownHero->HasArtifact(ARTIFACT_SERENITY_PENDANT) && spell == SPELL_BERZERKER)
      chance = 0.0;
    if(chance > 0.0 && ownHero->HasArtifact(ARTIFACT_SEEING_EYE_PENDANT) && spell == SPELL_BLIND)
      chance = 0.0;
    if(chance > 0.0 && ownHero->HasArtifact(ARTIFACT_KINETIC_PENDANT) && spell == SPELL_PARALYZE)
      chance = 0.0;
    if(chance > 0.0 && ownHero->HasArtifact(ARTIFACT_PENDANT_OF_DEATH) && (spell == SPELL_HOLY_WORD || spell == SPELL_HOLY_SHOUT))
      chance = 0.0;
    if(chance > 0.0 && ownHero->HasArtifact(ARTIFACT_WAND_OF_NEGATION) && (spell == SPELL_DISPEL_MAGIC || spell == SPELL_MASS_DISPEL || spell == SPELL_ARCHMAGI_DISPEL)) {
      chance = 0.0;
    }
  } else {
    hero* curHero = gpCombatManager->heroes[gpCombatManager->currentActionSide];
    if(chance > 0.0 && spell == SPELL_RESURRECT || spell == SPELL_RESURRECT_TRUE || spell == SPELL_ANIMATE_DEAD) {
      if(!this->quantity) {
        int ressurectionStrength = 50 * gpCombatManager->heroSpellpowers[gpCombatManager->currentActionSide];
        if(curHero && curHero->HasArtifact(ARTIFACT_ANKH))
          ressurectionStrength *= 2;
        if(this->creature.hp <= ressurectionStrength)
          chance = 1.0;
      } else
        chance = 0.0;
    }
    if(chance > 0.0 && spell == SPELL_HYPNOTIZE) {
      int hypnotizeStrength = 25 * curHero->Stats(PRIMARY_SKILL_SPELLPOWER);
      if(curHero->HasArtifact(ARTIFACT_GOLD_WATCH))
        hypnotizeStrength *= 2;
      if(this->quantity * this->creature.hp <= hypnotizeStrength)
        chance = CheckApplyDwarfSpellChance();
      else
        chance = 0.0;
    }
    if(chance > 0.0 && spell == SPELL_ARCHMAGI_DISPEL) {
      if(this->effectStrengths[EFFECT_HASTE]
        || this->effectStrengths[EFFECT_BLESS]
        || this->effectStrengths[EFFECT_DRAGON_SLAYER]
        || this->effectStrengths[EFFECT_BLOOD_LUST]
        || this->effectStrengths[EFFECT_SHIELD]
        || this->effectStrengths[EFFECT_ANTI_MAGIC]
        || this->effectStrengths[EFFECT_STONESKIN]
        || this->effectStrengths[EFFECT_STEELSKIN])
        chance = 1.0;
      else
        chance = 0.0;
    }
    if(chance > 0.0) {
      if(spell == SPELL_TELEPORT
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
        || spell == SPELL_MIRROR_IMAGE
        || spell == SPELL_SHIELD
        || spell == SPELL_MASS_SHIELD
        || spell == SPELL_FORCE_SHIELD
        || spell == SPELL_MASS_FORCE_SHIELD)
        chance = 1.0;
      else
        chance = CheckApplyDwarfSpellChance();
    }
  }

  auto res = ScriptCallbackResult<double>("OnCalcSpellChance", deepbind<army*>(this), spell, chance);
  if(res.has_value())
    chance = res.value();
  chance = max(0.0, min(chance, 1.0));
  return chance;
}

float army::CheckApplyDwarfSpellChance() {
  if(creatureIdx == CREATURE_DWARF && creatureIdx == CREATURE_BATTLE_DWARF)
    return 0.75;
  else
    return 1.0;
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
      float angles[9] = {90.0, 68.5, 45.0, 20.8, 0.0, -20.8, -45.0, -68.5, -90.0};
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
      this->ColdRing(hexIdx);
      break;
    case SPELL_FIREBALL:
      this->FireBall(hexIdx);
      break;
    case SPELL_FIREBLAST:
      this->FireBlast(hexIdx);
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
      this->PlasmaCone(hexIdx);
      break;
    case SPELL_FORCE_SHIELD:
      this->ShowSpellMessage(isCreatureAbility, proto_spell, stack);
      stack->SetSpellInfluence(EFFECT_FORCE_SHIELD, spellpower);
      stack->SpellEffect(gsSpellInfo[SPELL_FORCE_SHIELD].creatureEffectAnimationIdx, 0, 0);
    break;
    case SPELL_FIRE_BOMB:
      this->FireBomb(hexIdx);
      break;
    case SPELL_IMPLOSION_GRENADE:
      this->ImplosionGrenade(hexIdx);
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

// This function copies the functionality needed from CheckSetMouseDirection with everything else removed 
CURSOR_DIRECTION combatManager::GetCursorDirection(int screenX, int screenY, int hex) {
  int offsetX = screenX - 44 * (hex % 13 - 1) - 67;
  if ( !(hex / 13 & 1) )
    offsetX = screenX - 44 * (hex % 13 - 1) - 89;
  int offsetY = screenY - 63 - 42 * (hex / 13) - 26;

  // Hex is divided into 24 equal parts (triangles)
  // The code below calculates in which part the cursor is
  int hexPart = 0;
  int offsetXfromHexCenter = offsetX - 22;
  if(offsetXfromHexCenter >= 0) {
    if(offsetY >= 0)
      hexPart = 6;
  } else if(offsetY >= 0) {
    hexPart = 12;
  } else {
    hexPart = 18;
  }

  float v9 = (double)abs(offsetXfromHexCenter) / (double)abs(offsetY);

  if(hexPart && hexPart != 12) {
    if(v9 >= 0.27) {
      if(v9 >= 0.58) {
        if(v9 >= 1.0) {
          if(v9 >= 1.73) {
            if(v9 < 3.73)
              ++hexPart;
          } else {
            hexPart += 2;
          }
        } else {
          hexPart += 3;
        }
      } else {
        hexPart += 4;
      }
    } else {
      hexPart += 5;
    }
  } else if(v9 <= 3.73) {
    if(v9 <= 1.73) {
      if(v9 <= 1.0) {
        if(v9 <= 0.58) {
          if(v9 > 0.27)
            ++hexPart;
        } else {
          hexPart += 2;
        }
      } else {
        hexPart += 3;
      }
    } else {
      hexPart += 4;
    }
  } else {
    hexPart += 5;
  }

  switch(hexPart) {
    case 0: case 1: case 2: case 3:
      return CURSOR_DIRECTION_LEFT_DOWN;
    case 4: case 5: case 6: case 7:
      return CURSOR_DIRECTION_LEFT;
    case 8: case 9: case 10: case 11: 
      return CURSOR_DIRECTION_LEFT_UP;
    case 12: case 13: case 14: case 15:
      return CURSOR_DIRECTION_RIGHT_UP;
    case 16: case 17: case 18: case 19:
      return CURSOR_DIRECTION_RIGHT;
    case 20: case 21: case 22: case 23:
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
  int spellNeighbourDirections[][3] = {
    {5, 0, 1}, // right up
    {0, 1, 2}, // right
    {1, 2, 3}, // right down
    {2, 3, 4}, // left down
    {3, 4, 5}, // left
    {4, 5, 0},  // left up
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

double GetDistanceBetweenPoints(int fromX, int fromY, int toX, int toY) {
  return sqrt(pow(fromX - toX, 2) + pow(fromY - toY, 2));
}

std::vector<int> GetSpellMask(Spell spell, int fromHex, int direction) {
  std::vector<int> mask;
  switch(spell) {
    case SPELL_PLASMA_CONE:
      mask = GetPlasmaConeSpellMask(fromHex, direction);
      break;
    case SPELL_FIREBALL: case SPELL_FIRE_BOMB: case SPELL_METEOR_SHOWER:
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
    case SPELL_IMPLOSION_GRENADE: {
      const int SPELL_HEX_RADIUS = 5;
      double maxDistance = HEX_SIZE_IN_PIXELS * SPELL_HEX_RADIUS - HEX_SIZE_IN_PIXELS / 2;
      for(int i = 0; i < NUM_HEXES; i++) {
        if(!gpCombatManager->ValidSpellTarget(spell, i))
          continue;
        int toHex = i;
        hexcell* hexcellFrom = &gpCombatManager->combatGrid[fromHex];
        hexcell* hexcellTo = &gpCombatManager->combatGrid[toHex];
        double dist = GetDistanceBetweenPoints(hexcellFrom->centerX, hexcellFrom->otherY2, hexcellTo->centerX, hexcellTo->otherY2);
        if(dist < maxDistance)
          mask.push_back(i);
      }
    }
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

      // save hex colors
      char savedHexes[NUM_HEXES];
      for(int i = 0; i < NUM_HEXES; i++)
        savedHexes[i] = gpCombatManager->field_49F[i];

      // marking all hexes depending on their validity for cast
      for(int i = 0; i < NUM_HEXES; i++) {
        if(gpCombatManager->ValidSpellTarget(currentSpell, i)) {
          gpCombatManager->field_49F[i] = 3;
          if(gpCombatManager->combatGrid[i].unitOwner != -1)
            gpCombatManager->field_49F[i] = 1; // for troop hexes make it darker
        } else if(i % 13 && i % 13 != 12)
          gpCombatManager->field_49F[i] = 0; // invalid hexes are transparent
      }

      if(gpCombatManager->ValidSpellTarget(currentSpell, hex)) {
        indexToCastOn = hex;        

        std::vector<int> spellMask;
        switch(currentSpell) {
          case SPELL_PLASMA_CONE:
          {
            // changing cursor
            CURSOR_DIRECTION dir = gpCombatManager->GetCursorDirection(evt.altXCoord, evt.altYCoord, indexToCastOn);
            int cursorIdx = 0;
            switch(dir) {
              case CURSOR_DIRECTION_LEFT_DOWN:
                cursorIdx = 10;
                break;
              case CURSOR_DIRECTION_LEFT:
                cursorIdx = 11;
                break;
              case CURSOR_DIRECTION_LEFT_UP:
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
            gpMouseManager->SetPointer("cmbtmous.mse", cursorIdx, -999);

            // Getting spell direction
            gSpellDirection = dir;
            
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

        gpCombatManager->SpellMessage(currentSpell, hex);
      } else {
        indexToCastOn = -1;
        gpMouseManager->SetPointer(0);
        if(currentSpell == SPELL_TELEPORT && bInTeleportGetDest)
          gpCombatManager->CombatMessage("Invalid Teleport Destination", 1, 0, 0);
        else
          gpCombatManager->CombatMessage("Select Spell Target", 1, 0, 0);
      }

      // showing affected hexes
      gbLimitToExtent = 0;
      gpCombatManager->UpdateGrid(0, 0);
      gpCombatManager->DrawFrame(1, 0, 0, 0, 0, 1, 1);

      //reverting hex colors to pre-spell-cast state
      for(int i = 0; i < NUM_HEXES; i++)
        gpCombatManager->field_49F[i] = savedHexes[i];
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
        gpCombatManager->DrawFrame(1, 0, 0, 0, 0, 1, 1);
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
      gpCombatManager->DrawFrame(1, 0, 0, 0, 0, 1, 1);
      return 2;
    default:
      return 1;
  }
}

void combatManager::AreaSpellMessage(Spell spell, long damage) {
  switch(spell) {
    case SPELL_FIREBALL:
      sprintf(gText, "The fireball does %d damage.", damage);
      break;
    case SPELL_FIREBLAST:
      sprintf(gText, "The fireblast does %d damage.", damage);
      break;
    case SPELL_COLD_RING:
      sprintf(gText, "The cold ring does %d damage.", damage);
      break;
    case SPELL_METEOR_SHOWER:
      sprintf(gText, "The meteor shower does %d damage.", damage);
      break;
    case SPELL_PLASMA_CONE:
      sprintf(gText, "The plasma cone stream does %d damage.", damage);
      break;
    case SPELL_FIRE_BOMB:
      sprintf(gText, "The fire bomb does %d damage.", damage);
      break;
    case SPELL_IMPLOSION_GRENADE:
      sprintf(gText, "The implosion grenade does %d damage.", damage);
      break;
    default:
      sprintf(gText, "Area spell %d does %d damage.", spell, damage);
      break;
  }
  this->CombatMessage(gText, 1, 1, 0);
}

void combatManager::AreaSpellDrawImpact(int hexIdx, icon* spellIcon, double speedMult, int drawTimes, AOE_SPELL_DRAW_FLIP_TYPE flip) {
  if(!gbNoShowCombat) {
    int x = this->combatGrid[hexIdx].centerX;
    int y = this->combatGrid[hexIdx].occupyingCreatureBottomY - 17;

    int numSprites = spellIcon->numSprites;
    for(int i = 0; i < drawTimes; i++) {
      for(int spriteID = 0; spriteID < numSprites; spriteID++) {
        glTimers = (signed __int64)((double)KBTickCount() + gfCombatSpeedMod[giCombatSpeed] * speedMult);
        IconToBitmap(spellIcon, gpWindowManager->screenBuffer, x, y, spriteID, 1, 0, 0, 640, 443, 0);
        if(flip)
          FlipIconToBitmap(spellIcon, gpWindowManager->screenBuffer, x, y, spriteID, 1, 0, 0, 640, 443, 0);
        this->UpdateCombatArea();
        this->DrawFrame(0, 0, 0, 0, 75, 1, 1);
        DelayTil(&glTimers);
      }
    }
    gpResourceManager->Dispose((resource *)spellIcon);
  }
  this->DrawFrame(1, 0, 0, 0, 75, 1, 1);
}

void combatManager::AreaSpellDoDamage(long spellDamage, Spell spell, army* target) {
  this->ModifyDamageForArtifacts(&spellDamage, spell, this->heroes[this->currentActionSide], this->heroes[1 - this->currentActionSide]);
  this->AreaSpellMessage(spell, spellDamage);
  target->PowEffect(-1, 1, -1, -1);
}

bool combatManager::AreaSpellAffectHexes(int hexIdx, army *target, Spell spell, long spellDamage, std::vector<int> &affectedHexes) {
  affectedHexes = GetSpellMask(spell, hexIdx, gSpellDirection);
  bool anyoneDamaged = false;
  for(auto hex : affectedHexes) {
    hexcell *curHexcell = &this->combatGrid[hex];
    char unitOwner = curHexcell->unitOwner;
    char stackIdx = curHexcell->stackIdx;
    if(spell == SPELL_FIRE_BOMB) {
      int wallHex = hex;
      const int turnsLeft = 2;
      int currentFrame = 0;
      bool wallExists = false;
      for(auto &wall : gIronfistExtra.combat.spell.fireBombWalls) {
        if(wall.hexIdx == wallHex) {
          wallExists = true;
          wall.turnsLeft = turnsLeft;
          wall.currentFrame = currentFrame;
          break;
        }
      }
      if(!wallExists)
        gIronfistExtra.combat.spell.fireBombWalls.push_back({ wallHex, turnsLeft, currentFrame });
    }
    if(unitOwner == -1)
      continue;
    target = &this->creatures[unitOwner][stackIdx];
    if(!target->SpellCastWorks(spell))
      continue;
    if(gArmyEffected[unitOwner][stackIdx])
      continue;
    gArmyEffected[unitOwner][stackIdx] = 1;
    if(!target->damageTakenDuringSomeTimePeriod) {
      int damage = spellDamage;
      if(target->creatureIdx == CREATURE_FIRE_ELEMENTAL && spell == SPELL_COLD_RING)
        damage *= 2;
      if(target->creatureIdx == CREATURE_WATER_ELEMENTAL && (spell == SPELL_FIREBALL || spell == SPELL_FIREBLAST))
        damage *= 2;
      if(target->creatureIdx == CREATURE_IRON_GOLEM || target->creatureIdx == CREATURE_STEEL_GOLEM)
        damage /= 2;
      if(target->creatureIdx == CREATURE_EARTH_ELEMENTAL && spell == SPELL_METEOR_SHOWER)
        damage *= 2;
      if(spell == SPELL_FIRE_BOMB)
        CheckBurnCreature(target);
      else
        target->Damage(damage, spell);
      anyoneDamaged = true;
    }
  }
  return anyoneDamaged;
}

bool combatManager::AreaSpellAffectHexes(int hexIdx, army *target, Spell spell, long spellDamage) {
  std::vector<int> affectedHexes;
  return AreaSpellAffectHexes(hexIdx, target, spell, spellDamage, affectedHexes);
}

void combatManager::FireBall(int hexIdx) {
  if(!ValidHex(hexIdx))
    return;
  
  this->AreaSpellDrawImpact(hexIdx, gpResourceManager->GetIcon("fireball.icn"), 75.0, 1, AOE_SPELL_DRAW_NO_FLIP);
  combatManager::ClearEffects();

  long spellDamage = 10 * this->heroSpellpowers[this->currentActionSide];
  army *target = &this->creatures[this->currentActionSide][this->someSortOfStackIdx];
  if(AreaSpellAffectHexes(hexIdx, target, SPELL_FIREBALL, spellDamage))
    AreaSpellDoDamage(spellDamage, SPELL_FIREBALL, target);
}

void combatManager::FireBlast(int hexIdx) {
  if(!ValidHex(hexIdx))
    return;
  
  this->AreaSpellDrawImpact(hexIdx, gpResourceManager->GetIcon("firebal2.icn"), 75.0, 1, AOE_SPELL_DRAW_NO_FLIP);
  combatManager::ClearEffects();

  long spellDamage = 10 * this->heroSpellpowers[this->currentActionSide];
  army *target = &this->creatures[this->currentActionSide][this->someSortOfStackIdx];
  if(AreaSpellAffectHexes(hexIdx, target, SPELL_FIREBLAST, spellDamage))
    AreaSpellDoDamage(spellDamage, SPELL_FIREBLAST, target);
}

void combatManager::ColdRing(int hexIdx) {
  if(!ValidHex(hexIdx))
    return;
  
  this->AreaSpellDrawImpact(hexIdx, gpResourceManager->GetIcon("coldring.icn"), 75.0, 1, AOE_SPELL_DRAW_FLIP);
  combatManager::ClearEffects();

  long spellDamage = 10 * this->heroSpellpowers[this->currentActionSide];
  army *target = &this->creatures[this->currentActionSide][this->someSortOfStackIdx];
  if(AreaSpellAffectHexes(hexIdx, target, SPELL_COLD_RING, spellDamage))
    AreaSpellDoDamage(spellDamage, SPELL_COLD_RING, target);
}

void combatManager::MeteorShower(int hexIdx) {
  if(!ValidHex(hexIdx))
    return;
  
  this->AreaSpellDrawImpact(hexIdx, gpResourceManager->GetIcon("meteor.icn"), 112.5, 2, AOE_SPELL_DRAW_NO_FLIP);
  combatManager::ClearEffects();

  long spellDamage = 25 * this->heroSpellpowers[this->currentActionSide];
  army *target = &this->creatures[this->currentActionSide][this->someSortOfStackIdx];
  if(AreaSpellAffectHexes(hexIdx, target, SPELL_METEOR_SHOWER, spellDamage))
    AreaSpellDoDamage(spellDamage, SPELL_METEOR_SHOWER, target);
}

void combatManager::PlasmaCone(int hexIdx) {
  if(!ValidHex(hexIdx))
    return;

  this->AreaSpellDrawImpact(hexIdx, gpResourceManager->GetIcon("fireball.icn"), 75.0, 1, AOE_SPELL_DRAW_NO_FLIP);
  combatManager::ClearEffects();

  long spellDamage = 10 * this->heroSpellpowers[this->currentActionSide];
  army *target = &this->creatures[this->currentActionSide][this->someSortOfStackIdx];
  if(AreaSpellAffectHexes(hexIdx, target, SPELL_PLASMA_CONE, spellDamage))
    AreaSpellDoDamage(spellDamage, SPELL_PLASMA_CONE, target);
}

void combatManager::FireBomb(int hexIdx) {
  if(!ValidHex(hexIdx))
    return;

  this->AreaSpellDrawImpact(hexIdx, gpResourceManager->GetIcon("fireball.icn"), 75.0, 1, AOE_SPELL_DRAW_NO_FLIP);
  combatManager::ClearEffects();

  long spellDamage = 10 * this->heroSpellpowers[this->currentActionSide];
  army *target = &this->creatures[this->currentActionSide][this->someSortOfStackIdx];
  if(AreaSpellAffectHexes(hexIdx, target, SPELL_FIRE_BOMB, spellDamage))
    AreaSpellDoDamage(spellDamage, SPELL_FIRE_BOMB, target);
}

void combatManager::ImplosionGrenade(int hexIdx) {
  if(!ValidHex(hexIdx))
    return;

  this->AreaSpellDrawImpact(hexIdx, gpResourceManager->GetIcon("fireball.icn"), 75.0, 1, AOE_SPELL_DRAW_NO_FLIP);
  combatManager::ClearEffects();

  long spellDamage = 10 * this->heroSpellpowers[this->currentActionSide];
  army *target = &this->creatures[this->currentActionSide][this->someSortOfStackIdx];
  std::vector<int>affectedHexes;
  bool anyoneDamaged = AreaSpellAffectHexes(hexIdx, target, SPELL_IMPLOSION_GRENADE, spellDamage, affectedHexes);
  
  // Don't do anything with center hex
  affectedHexes.erase(std::remove(affectedHexes.begin(), affectedHexes.end(), hexIdx), affectedHexes.end());

  // Find creature destination hexes after spell sucking affected creatures to the center
  std::map<int, int> implosionHexMoveDirections;
  int rowCentHex = hexIdx / 13;
  int colCentHex = hexIdx % 13;
  for(auto affHex : affectedHexes) {
    int rowAffHex = affHex / 13;
    int colAffHex = affHex % 13;
    int rowdiff = rowCentHex - rowAffHex;
    int coldiff = colCentHex - colAffHex;
    int resultDir;
    if(rowdiff < 0) {
      if(coldiff < 0) {
        if(abs(coldiff) > abs(rowdiff))
          resultDir = 4;
        else
          resultDir = 5;
      } else {
        if(abs(coldiff) > abs(rowdiff))
          resultDir = 1;
        else
          resultDir = 0;
      }
    } else {
      if(coldiff < 0) {
        if(abs(coldiff) > abs(rowdiff))
          resultDir = 4;
        else
          resultDir = 3;
      } else {
        if(abs(coldiff) > abs(rowdiff))
          resultDir = 1;
        else
          resultDir = 2;
      }
    }
    implosionHexMoveDirections[affHex] = GetAdjacentCellIndexNoArmy(affHex, resultDir);
  }

  // Move every affected creature in the direction of the spell center starting from closest to center
  hexcell* centerHexcell = &gpCombatManager->combatGrid[hexIdx];
  // Saving initial hexes of creatures beforehand
  std::map<army*, int> creatureMovesFrom;
  for(int size = 1; size <= 5; size++) {
    double maxDistance = HEX_SIZE_IN_PIXELS * size - HEX_SIZE_IN_PIXELS / 2;
    auto it = affectedHexes.begin();
    while(it != affectedHexes.end()) {
      int affHex = *it;
      hexcell* movableHexcell = &gpCombatManager->combatGrid[affHex];
      if(movableHexcell->unitOwner == -1) {
        it = affectedHexes.erase(it);
        continue;
      }
      double dist = GetDistanceBetweenPoints(centerHexcell->centerX, centerHexcell->otherY2, movableHexcell->centerX, movableHexcell->otherY2);
      if(dist < maxDistance) {
        it = affectedHexes.erase(it);

        int destHex = implosionHexMoveDirections[affHex];
        if(destHex == -1)
          continue;
        hexcell *destHexcell = &this->combatGrid[destHex];
        army *creatureToMove = &this->creatures[movableHexcell->unitOwner][movableHexcell->stackIdx];
        // check if hex is occupied by something
        if(destHexcell->isBlocked)
          continue;
        if(!creatureToMove->CanFit(destHex, 0, 0))
          continue;
        if(destHexcell->unitOwner != -1)
          if(!(movableHexcell->unitOwner == destHexcell->unitOwner && movableHexcell->stackIdx == destHexcell->stackIdx))
            continue;

        if(creatureToMove->creature.creature_flags & TWO_HEXER) {
          hexcell *destSecondHexcell;
          hexcell *movableSecondHexcell;
          int destHexSecond;
          int affHexSecond;
          if(movableHexcell->occupiersOtherHexIsToLeft == 1) {
            destHexSecond = destHex - 1;
            affHexSecond = affHex - 1;
            destSecondHexcell = &this->combatGrid[destHexSecond];
            movableSecondHexcell = &this->combatGrid[affHexSecond];

            if(destSecondHexcell->isBlocked) 
              continue;
            if(destSecondHexcell->unitOwner != -1)
              if(!(movableSecondHexcell->unitOwner == destSecondHexcell->unitOwner && movableSecondHexcell->stackIdx == destSecondHexcell->stackIdx))
                continue;

            if(creatureToMove->facingRight) {
              if(IsOutOfBoundsHex(destHex))
                continue;
              creatureMovesFrom[creatureToMove] = creatureToMove->occupiedHex;
              creatureToMove->occupiedHex = destHexSecond;
            } else {
              if(IsOutOfBoundsHex(destHexSecond))
                continue;
              creatureMovesFrom[creatureToMove] = creatureToMove->occupiedHex;
              creatureToMove->occupiedHex = destHex;
            }
          } else {
            destHexSecond = destHex + 1;
            affHexSecond = affHex + 1;
            destSecondHexcell = &this->combatGrid[destHexSecond];
            movableSecondHexcell = &this->combatGrid[affHexSecond];

            if(destSecondHexcell->isBlocked)
              continue;
            if(destSecondHexcell->unitOwner != -1)
              if(!(movableSecondHexcell->unitOwner == destSecondHexcell->unitOwner && movableSecondHexcell->stackIdx == destSecondHexcell->stackIdx))
                continue;

            if(creatureToMove->facingRight) {
              if(IsOutOfBoundsHex(destHex))
                continue;
              creatureMovesFrom[creatureToMove] = creatureToMove->occupiedHex;
              creatureToMove->occupiedHex = destHex;
            } else {
              if(IsOutOfBoundsHex(destHexSecond))
                continue;
              creatureMovesFrom[creatureToMove] = creatureToMove->occupiedHex;
              creatureToMove->occupiedHex = destHexSecond;
            }
          }
          int stackIdx = movableHexcell->stackIdx;
          movableHexcell->stackIdx = movableSecondHexcell->stackIdx = -1;
          destHexcell->stackIdx = destSecondHexcell->stackIdx = stackIdx;

          int unitOwner = movableHexcell->unitOwner;
          movableHexcell->unitOwner = movableSecondHexcell->unitOwner = -1;
          destHexcell->unitOwner = destSecondHexcell->unitOwner = unitOwner;

          int occupiersOtherHexIsToLeft = movableHexcell->occupiersOtherHexIsToLeft;
          int occupiersOtherHexIsToLeft2 = movableSecondHexcell->occupiersOtherHexIsToLeft;
          movableHexcell->occupiersOtherHexIsToLeft = movableSecondHexcell->occupiersOtherHexIsToLeft = -1;
          destHexcell->occupiersOtherHexIsToLeft = occupiersOtherHexIsToLeft;
          destSecondHexcell->occupiersOtherHexIsToLeft = occupiersOtherHexIsToLeft2;

          // erase second hex from looping if it was also affected
          auto itFound = std::find(affectedHexes.begin(), affectedHexes.end(), affHexSecond);
          if(itFound != affectedHexes.end())
            it = affectedHexes.erase(itFound);
        } else {
          creatureMovesFrom[creatureToMove] = creatureToMove->occupiedHex;
          creatureToMove->occupiedHex = destHex;
          destHexcell->stackIdx = movableHexcell->stackIdx;
          destHexcell->unitOwner = movableHexcell->unitOwner;
          movableHexcell->stackIdx = -1;
          movableHexcell->unitOwner = -1;
        }
      }
      else
        ++it;
    }
  }

  // ANIMATING the creatures moving towards the center of the spell
  const int NUM_FRAMES = 10;
  for(int frame = 0; frame < NUM_FRAMES; frame++) {
    for(auto currentlyAnimated : creatureMovesFrom) {
      army* cr = currentlyAnimated.first;
      int initialHex = currentlyAnimated.second;
      cr->animationType = ANIMATION_TYPE_WINCE_RETURN;
      cr->animationFrame = 0;

      int startX = gpCombatManager->combatGrid[initialHex].centerX;
      int startY = gpCombatManager->combatGrid[initialHex].occupyingCreatureBottomY;
      int deltaX = gpCombatManager->combatGrid[cr->occupiedHex].centerX - startX;
      int deltaY = gpCombatManager->combatGrid[cr->occupiedHex].occupyingCreatureBottomY - startY;
      int dist = (signed __int64)sqrt((double)(deltaY * deltaY + deltaX * deltaX));
      float stepX = (double)deltaX / (double)NUM_FRAMES;
      float stepY = (double)deltaY / (double)NUM_FRAMES;
      double currentDrawX = startX + stepX * frame;
      double currentDrawY = startY + stepY * frame;

      cr->DrawToBuffer((int)currentDrawX, (int)currentDrawY, 0);
    }
    gpWindowManager->UpdateScreenRegion(0, 0, INTERNAL_WINDOW_WIDTH, INTERNAL_WINDOW_HEIGHT);
    DelayTil(&glTimers);
    glTimers = (signed __int64)((double)KBTickCount() + 100 * gfCombatSpeedMod[giCombatSpeed] * 1.3);
  }

  if(anyoneDamaged)
    AreaSpellDoDamage(spellDamage, SPELL_IMPLOSION_GRENADE, target);
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
      case SPELL_MASS_FORCE_SHIELD:
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