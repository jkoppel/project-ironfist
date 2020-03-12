#include "artifacts.h"
#include "combat/army.h"
#include "combat/combat.h"
#include "graphics.h"
#include "resource/resourceManager.h"
#include "scripting/callback.h"
#include "scripting/deepbinding.h"
#include "sound/sound.h"
#include "spell/spells.h"
#include "expansions.h"

#include <limits.h>
#include <set>
#include <vector>

extern char *cMonFilename[]; // it's inside creature.cpp
extern char *cArmyFrameFileNames[]; // it's inside creature.cpp
extern char *cArmyProjectileFileNames[]; // it's inside creature.cpp
extern icon *gCurLoadedSpellIcon;
extern int gCurLoadedSpellEffect;
extern int gCurSpellEffectFrame;
extern int gbGenieHalf;
extern int gbRemoteOn;
extern float gfSSArcheryMod[];

bool gCloseMove; // ironfist var to differentiate between close/from a distance attack
bool gMoveAttack; // ironfist var to differentiate between move/move and attack
bool gChargePathDamage;
bool gCharging;

char *gCombatFxNames[39] =
{
  "",
  "magic01.icn",
  "magic02.icn",
  "magic03.icn",
  "magic04.icn",
  "magic05.icn",
  "magic06.icn",
  "magic07.icn",
  "magic08.icn",
  "rainbluk.icn",
  "cloudluk.icn",
  "moraleg.icn",
  "moraleb.icn",
  "reddeath.icn",
  "redfire.icn",
  "sparks.icn",
  "electric.icn",
  "physical.icn",
  "bluefire.icn",
  "icecloud.icn",
  "lichclod.icn",
  "bless.icn",
  "berzerk.icn",
  "shield.icn",
  "haste.icn",
  "paralyze.icn",
  "hypnotiz.icn",
  "dragslay.icn",
  "blind.icn",
  "curse.icn",
  "stonskin.icn",
  "stelskin.icn",
  "plasmblast.icn",
  "shdwmark.icn",
  "mrksmprc.icn",
  "plsmcone.icn",
  "forcshld.icn",
  "firebomb.icn",
  "implgrnd.icn"
};

unsigned __int8 giNumPowFrames[39] =
{
  10u,
  10u,
  10u,
  10u,
  10u,
  10u,
  10u,
  10u,
  10u,
  8u,
  8u,
  10u,
  10u,
  10u,
  10u,
  15u,
  10u,
  10u,
  10u,
  10u,
  10u,
  16u,
  16u,
  14u,
  19u,
  22u,
  10u,
  17u,
  10u,
  12u,
  11u,
  16u,
  7u,
  8u,
  8u,
  8u,
  8u,
  8u,
  8u
};

void OccupyHexes(army *a) {
  if (!(a->creature.creature_flags & TWO_HEXER))
    return;

  if (a->facingRight == 1)
    a->occupiedHex--;
  else
    a->occupiedHex++;
}

int __fastcall OppositeDirection(signed int hex) {
  int result;
  if (hex == 6) {
    result = 7;
  } else if (hex > 6) {
    result = 6;
  } else {
    result = (hex + 3) % 6;
  }
  return result;
}

void DoAttackBattleMessage(army *attacker, army *target, int creaturesKilled, int damageDone) {
  char *attackingCreature, *targetCreature;
  if (attacker->quantity <= 1)
    attackingCreature = GetCreatureName(attacker->creatureIdx);
  else
    attackingCreature = GetCreaturePluralName(attacker->creatureIdx);
  
  char* creatureString = "creature";
  char* creaturesString = "creatures";
  if(!target) {
     if (creaturesKilled <= 1)
       targetCreature = creatureString;
     else
       targetCreature = creaturesString;
  } else if (creaturesKilled <= 1)
    targetCreature = GetCreatureName(target->creatureIdx);
  else
    targetCreature = GetCreaturePluralName(target->creatureIdx);

  if (damageDone == -1) {
    sprintf(gText, "The mirror image is destroyed!");
  } else if (damageDone == -2) {
    sprintf(gText, "Cyber Shadow Assasins dodge the attack!");
  } else if (gbGenieHalf) {
    sprintf(gText, "%s %s half the enemy troops!", attackingCreature, (attacker->quantity > 1) ? "damage" : "damages");
  } else if (creaturesKilled <= 0) {
    sprintf(gText, "%s %s %d damage.", attackingCreature, (attacker->quantity > 1) ? "do" : "does", damageDone);
  } else {
    sprintf(
      gText,
      "%s %s %d damage.\n%d %s %s.",
      attackingCreature,
      (attacker->quantity > 1) ? "do" : "does",
      damageDone,
      creaturesKilled,
      targetCreature,
      (creaturesKilled > 1) ? "perish" : "perishes");
  }
  gText[0] = toupper(gText[0]);
  gpCombatManager->CombatMessage(gText, 1, 1, 0);
}

void army::SetChargingMoveAnimation(CHARGING_DIRECTION dir) {
  if(this->creatureIdx == CREATURE_CYBER_PLASMA_LANCER) {
    int inAirFrame;
    switch(dir) {
      case CHARGING_FORWARD:
        inAirFrame = 17;
        break;
      case CHARGING_UP:
        inAirFrame = 96;
        break;
      case CHARGING_DOWN:
        inAirFrame = 97;
        break;
    }
    this->creature.creature_flags |= FLYER;
    for(int i = 0; i < 8; i++) {
      this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MOVE][i] =
      this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_WALKING][i] = inAirFrame;
    }
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_STANDING][0] = inAirFrame;
  }
}

void army::RevertChargingMoveAnimation() {
  if(this->creatureIdx == CREATURE_CYBER_PLASMA_LANCER) {
    this->frameInfo.animationLengths[ANIMATION_TYPE_WALKING] = 8;
    for(int i = 0; i < 8; i++) {
      this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_WALKING][i] =
      this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MOVE][i] = 46 + i;
    }
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_STANDING][0] = 69;
    this->creature.creature_flags &= ~FLYER;
  }
}

void army::SetJumpingAnimation() {
  if(this->creatureIdx == CREATURE_CYBER_PLASMA_BERSERKER) {
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_UPWARDS] = 
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_FORWARDS] =
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS] = 1;
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_UPWARDS_RETURN] = 
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_FORWARDS_RETURN] = 
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS_RETURN] = 2;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_UPWARDS][0] =
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_FORWARDS][0] =
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS][0] = 34;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_UPWARDS_RETURN][0] =
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_FORWARDS_RETURN][0] =
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS_RETURN][0] = 35;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_UPWARDS_RETURN][1] =
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_FORWARDS_RETURN][1] =
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS_RETURN][1] = 36;
  }
}

void army::RevertJumpingAnimation() {
  if(this->creatureIdx == CREATURE_CYBER_PLASMA_BERSERKER) {
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS] = 
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_FORWARDS] = 
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_UPWARDS] = 4;
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_UPWARDS_RETURN] = 
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_FORWARDS_RETURN] = 
    this->frameInfo.animationLengths[ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS_RETURN] = 2;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_UPWARDS][0] = 17;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_FORWARDS][0] = 10;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS][0] = 24;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_UPWARDS_RETURN][0] = 21;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_FORWARDS_RETURN][0] = 14;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS_RETURN][0] = 28;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_UPWARDS_RETURN][1] = 22;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_FORWARDS_RETURN][1] = 15;
    this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS_RETURN][1] = 29;
  }
}

void army::ChargingDamage(std::vector<int> affectedHexes) {
  if(!affectedHexes.size())
    return;

  int oldFacingRight = this->facingRight;

  int totalDamage = 0;
  int totalCreaturesKilled = 0;
  
  gChargePathDamage = true;
  for(auto i : affectedHexes) {
    int targHex = i;
    army *primaryTarget = &gpCombatManager->creatures[gpCombatManager->combatGrid[targHex].unitOwner][gpCombatManager->combatGrid[targHex].stackIdx];
    int creaturesKilled = 0;
    int damDone;
    this->DamageEnemy(primaryTarget, &damDone, (int *)&creaturesKilled, 0, 0);
    if(damDone > 0)
      totalDamage += damDone;
    totalCreaturesKilled += creaturesKilled;

    if(primaryTarget->creatureIdx == CREATURE_CYBER_SHADOW_ASSASSIN) { // astral dodge animations
      if(gIronfistExtra.combat.stack.abilityNowAnimating[primaryTarget][ASTRAL_DODGE]) {
        int dodgeAnimLen = 7;
        primaryTarget->frameInfo.animationLengths[ANIMATION_TYPE_WINCE] = dodgeAnimLen;
        for (int p = 0; p < dodgeAnimLen; p++) {
          primaryTarget->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_WINCE][p] = 34 + p;
        }
        gIronfistExtra.combat.stack.abilityNowAnimating[primaryTarget][ASTRAL_DODGE] = false;
      } else {
        // revert to usual animations after the first received attack
        int winceAnimLen = 1;
        primaryTarget->frameInfo.animationLengths[ANIMATION_TYPE_WINCE] = winceAnimLen;
        primaryTarget->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_WINCE][0] = 50;
      }
    }  
  }
  gChargePathDamage = false;

  // Battle message
  char *attackingCreature, *targetCreature;
  if (this->quantity <= 1)
    attackingCreature = GetCreatureName(this->creatureIdx);
  else
    attackingCreature = GetCreaturePluralName(this->creatureIdx);
  if(totalDamage > 0) {
    if (totalCreaturesKilled <= 0) {
      sprintf(gText, "%s %s %d damage.", attackingCreature, (this->quantity > 1) ? "do" : "does", totalDamage);
    } else {
      sprintf(
        gText,
        "%s %s %d damage.\n%d creatures %s.",
        attackingCreature,
        (this->quantity > 1) ? "do" : "does",
        totalDamage,
        totalCreaturesKilled,
        (totalCreaturesKilled > 1) ? "perish" : "perishes");
    }
    gText[0] = toupper(gText[0]);
    gpCombatManager->CombatMessage(gText, 1, 1, 0);
  }

  gpCombatManager->limitCreature[this->owningSide][this->stackIdx] = 1;

  if (this->facingRight != oldFacingRight) {
    if (!(this->creature.creature_flags & DEAD)) {
      this->facingRight = oldFacingRight;
      OccupyHexes(this);
    }
    // Kert: Not sure if this is needed
    /*for(auto targetHex : affectedHexes)
    {
      army *primaryTarget = &gpCombatManager->creatures[gpCombatManager->combatGrid[targetHex].unitOwner][gpCombatManager->combatGrid[targetHex].stackIdx];
      int targetOldFacingRight = primaryTarget->facingRight;
      if(!(primaryTarget->creature.creature_flags & DEAD))
      {
        if(primaryTarget->facingRight != targetOldFacingRight)
        {
          primaryTarget->facingRight = targetOldFacingRight;
          OccupyHexes(primaryTarget);
        }
      }
    }*/
  }
}

void army::DoAttack(int isRetaliation) {
  army* primaryTarget = &gpCombatManager->creatures[gpCombatManager->combatGrid[targetHex].unitOwner][gpCombatManager->combatGrid[targetHex].stackIdx];
  if (gpCombatManager->combatGrid[targetHex].unitOwner < 0 || gpCombatManager->combatGrid[targetHex].stackIdx < 0)
    primaryTarget = this;
  ScriptCallback("OnBattleMeleeAttack", deepbind<army*>(this), deepbind<army*>(primaryTarget), (bool)isRetaliation);

  if(isRetaliation)
    gCloseMove = true;

  primaryTarget = 0;
  this->field_6 = 3;
  int creaturesKilled = 0;
  army *secondHexTarget = nullptr;
  int oldFacingRight = this->facingRight;
  if (isRetaliation)
    gpCombatManager->currentActionSide = 1 - gpCombatManager->currentActionSide;
  if (this->creatureIdx == CREATURE_HYDRA) {
    this->DoHydraAttack(isRetaliation);
  } else {
    int tmpTargetNeighborIdx = this->targetNeighborIdx;
    int targetHex = this->occupiedHex;
    if (this->creature.creature_flags & TWO_HEXER
      && (!this->facingRight && this->targetNeighborIdx >= 3 || this->facingRight == 1 && (this->targetNeighborIdx <= 2 || this->targetNeighborIdx >= 6))) {
      if (oldFacingRight)
        targetHex = this->occupiedHex + 1;
      else
        targetHex = this->occupiedHex - 1;
    }
    targetHex = this->GetAdjacentCellIndex(targetHex, this->targetNeighborIdx);
    primaryTarget = &gpCombatManager->creatures[gpCombatManager->combatGrid[targetHex].unitOwner][gpCombatManager->combatGrid[targetHex].stackIdx];
    if (this->creature.creature_flags & TWO_HEX_ATTACKER) {
      int secondTargetHex = this->GetAdjacentCellIndex(targetHex, this->targetNeighborIdx);
      if (ValidHex(secondTargetHex)) {
        if (gpCombatManager->combatGrid[secondTargetHex].unitOwner >= 0
          && gpCombatManager->combatGrid[secondTargetHex].stackIdx >= 0
          && (gpCombatManager->combatGrid[secondTargetHex].unitOwner != primaryTarget->owningSide
            || gpCombatManager->combatGrid[secondTargetHex].stackIdx != primaryTarget->stackIdx))
          secondHexTarget = &gpCombatManager->creatures[gpCombatManager->combatGrid[secondTargetHex].unitOwner][gpCombatManager->combatGrid[secondTargetHex].stackIdx];
      }
    }

    gpCombatManager->ResetLimitCreature();
    int v2 = 80 * this->owningSide + 4 * this->stackIdx;
    ++*(signed int *)((char *)gpCombatManager->limitCreature[0] + v2);
    int v3 = 80 * primaryTarget->owningSide + 4 * primaryTarget->stackIdx;
    ++*(signed int *)((char *)gpCombatManager->limitCreature[0] + v3);
    if (secondHexTarget) {
      int v4 = 80 * secondHexTarget->owningSide + 4 * secondHexTarget->stackIdx;
      ++*(signed int *)((char *)gpCombatManager->limitCreature[0] + v4);
    }

    gpCombatManager->DrawFrame(0, 1, 0, 1, 75, 1, 1);
    int targetOldFacingRight = primaryTarget->facingRight;

    int shouldFaceRight;
    if (this->targetNeighborIdx > 2) {
      if (this->targetNeighborIdx > 5)
        shouldFaceRight = this->facingRight;
      else
        shouldFaceRight = 0;
    } else {
      shouldFaceRight = 1;
    }
    if (this->facingRight != shouldFaceRight) {
      this->facingRight = shouldFaceRight;
      if (this->creature.creature_flags & TWO_HEXER) {
        if (shouldFaceRight == 1)
          --this->occupiedHex;
        else
          ++this->occupiedHex;
      }
      primaryTarget->facingRight = 1 - this->facingRight;
      if (primaryTarget->facingRight != targetOldFacingRight)
        OccupyHexes(primaryTarget);
    }
    this->CheckLuck();
    this->mightBeIsAttacking = 1;
    if (this->targetNeighborIdx != 6 && this->targetNeighborIdx != 5 && this->targetNeighborIdx) {
      if (this->targetNeighborIdx != 1 && this->targetNeighborIdx != 4)
        this->mightBeAttackAnimIdx = 24;
      else
        this->mightBeAttackAnimIdx = 20;
    } else {
      this->mightBeAttackAnimIdx = 16;
    }
    if (secondHexTarget)
      this->mightBeAttackAnimIdx += 2;
    gpSoundManager->MemorySample(this->combatSounds[1]);

    int damDone;
    this->DamageEnemy(primaryTarget, &damDone, (int *)&creaturesKilled, 0, isRetaliation);
    int v13 = 0; // unused
    if (secondHexTarget)
      this->DamageEnemy(secondHexTarget, &v13, &v13, 0, isRetaliation);
    
    if(CreatureHasAttribute(this->creatureIdx, CHARGER))
      gCharging = false;

    DoAttackBattleMessage(this, primaryTarget, creaturesKilled, damDone);

    int enemyIncapacitated = 0;
    switch (this->creatureIdx) {
      case CREATURE_CYCLOPS:
        if (primaryTarget->quantity > 0 && (!secondHexTarget || secondHexTarget->quantity > 0)) {
          if (SRandom(1, 100) >= 20) {
            if (SRandom(1, 100) < 20 && secondHexTarget && secondHexTarget->SpellCastWorks(SPELL_PARALYZE))
              secondHexTarget->spellEnemyCreatureAbilityIsCasting = SPELL_PARALYZE;
          } else if (primaryTarget && primaryTarget->SpellCastWorks(SPELL_PARALYZE)) {
            primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_PARALYZE;
            enemyIncapacitated = 1;
          }
        }
        break;
      case CREATURE_UNICORN:
        if (SRandom(1, 100) < 20 && primaryTarget && primaryTarget->SpellCastWorks(SPELL_BLIND)) {
          primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_BLIND;
          enemyIncapacitated = 1;
        }
        break;
      case CREATURE_MEDUSA:
        if (SRandom(1, 100) < 20 && primaryTarget && primaryTarget->SpellCastWorks(SPELL_MEDUSA_PETRIFY)) {
          primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_MEDUSA_PETRIFY;
          enemyIncapacitated = 1;
        }
        break;
      case CREATURE_MUMMY: case CREATURE_ROYAL_MUMMY:
        int chance;
        if (this->creatureIdx == CREATURE_MUMMY)
          chance = 20;
        else
          chance = 30;
        if (SRandom(1, 100) < chance)
          if (primaryTarget && primaryTarget->SpellCastWorks(SPELL_CURSE))
            primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_CURSE;
        break;
      case CREATURE_ARCHMAGE:
        if (SRandom(1, 100) < 20 && primaryTarget && primaryTarget->SpellCastWorks(SPELL_ARCHMAGI_DISPEL))
          primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_ARCHMAGI_DISPEL;
        break;
      case CREATURE_GHOST:
        gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner] = creaturesKilled;
        break;
      case CREATURE_VAMPIRE_LORD:
        gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner] = creaturesKilled * primaryTarget->creature.hp;
        break;
    }
    if(CreatureHasAttribute(this->creatureIdx, SHADOW_MARK)) {
      if (primaryTarget->SpellCastWorks(SPELL_SHADOW_MARK)) {
        primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_SHADOW_MARK;
      }
    }

    if(primaryTarget->creatureIdx == CREATURE_CYBER_SHADOW_ASSASSIN) { // astral dodge animations
      if(gIronfistExtra.combat.stack.abilityNowAnimating[primaryTarget][ASTRAL_DODGE]) {
        int dodgeAnimLen = 7;
        primaryTarget->frameInfo.animationLengths[ANIMATION_TYPE_WINCE] = dodgeAnimLen;
        for (int p = 0; p < dodgeAnimLen; p++) {
          primaryTarget->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_WINCE][p] = 34 + p;
        }
        gIronfistExtra.combat.stack.abilityNowAnimating[primaryTarget][ASTRAL_DODGE] = false;
      } else {
        // revert to usual animations after the first received attack
        int winceAnimLen = 1;
        primaryTarget->frameInfo.animationLengths[ANIMATION_TYPE_WINCE] = winceAnimLen;
        primaryTarget->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_WINCE][0] = 50;
      }
    }

    if(gIronfistExtra.combat.stack.abilityNowAnimating[this][JUMPER]) {
      SetJumpingAnimation();
      gIronfistExtra.combat.stack.abilityNowAnimating[this][JUMPER] = false;
    } else {
      RevertJumpingAnimation();
    }
    this->PowEffect(-1, 0, -1, -1);
    
    gpCombatManager->limitCreature[this->owningSide][this->stackIdx] = 1;
    if (this->creatureIdx == CREATURE_GHOST)
      this->quantity += gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner];
    if (this->creatureIdx == CREATURE_VAMPIRE_LORD) {
      if (gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner] >= this->damage) {
        int v5 = gpCombatManager->combatGrid[this->occupiedHex].unitOwner;
        gpCombatManager->ghostAndVampireAbilityStrength[v5] -= this->damage;
        this->damage = 0;
        int v11 = gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner] / this->creature.hp;
        if (this->initialQuantity - this->quantity <= v11)
          this->quantity = this->initialQuantity;
        else
          this->quantity += v11;
      } else {
        this->damage -= gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner];
      }
    }
    if (primaryTarget
      && primaryTarget->quantity > 0
      && !primaryTarget->effectStrengths[EFFECT_PARALYZE]
      && !primaryTarget->effectStrengths[EFFECT_PETRIFY]
      && (primaryTarget->creatureIdx == CREATURE_GRIFFIN || !(primaryTarget->creature.creature_flags & RETALIATED))
      && this->creatureIdx != CREATURE_ROGUE
      && this->creatureIdx != CREATURE_SPRITE
      && this->creatureIdx != CREATURE_VAMPIRE
      && this->creatureIdx != CREATURE_VAMPIRE_LORD
      && !(CreatureHasAttribute(this->creatureIdx, TELEPORTER) && !gCloseMove)
      && !enemyIncapacitated
      && !isRetaliation) {
      DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 150.0));
      primaryTarget->targetNeighborIdx = OppositeDirection(this->targetNeighborIdx);
      if (primaryTarget->creature.creature_flags & TWO_HEXER) {
        if (this->occupiedHex == this->GetAdjacentCellIndex(primaryTarget->occupiedHex, (unsigned int)(primaryTarget->facingRight - 1) < 1 ? 0 : 5))
          primaryTarget->targetNeighborIdx = 6;
        if (this->occupiedHex == this->GetAdjacentCellIndex(primaryTarget->occupiedHex, 3 - ((unsigned int)(primaryTarget->facingRight - 1) < 1)))
          primaryTarget->targetNeighborIdx = 7;
      }
      primaryTarget->DoAttack(1);
      primaryTarget->creature.creature_flags |= RETALIATED;
      if (gbRemoteOn
        && gpCombatManager->involvedInBadMorale[0]
        && gpCombatManager->involvedInBadMorale[1]
        && primaryTarget->creatureIdx == CREATURE_GHOST)
        primaryTarget->quantity += gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[primaryTarget->occupiedHex].unitOwner];
    }
    if ((this->creatureIdx == CREATURE_WOLF
      || this->creatureIdx == CREATURE_PALADIN
      || this->creatureIdx == CREATURE_CRUSADER)
      && primaryTarget
      && primaryTarget->quantity > 0
      && !isRetaliation
      && !this->effectStrengths[EFFECT_PARALYZE]
      && !this->effectStrengths[EFFECT_PETRIFY]
      && !this->effectStrengths[EFFECT_BLIND]
      && this->quantity > 0) {
      DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 100.0));
      int v16 = this->targetNeighborIdx;
      this->targetNeighborIdx = tmpTargetNeighborIdx;
      this->DoAttack(1);
      this->targetNeighborIdx = v16;
    }
    if (this->facingRight != oldFacingRight) {
      if (!(this->creature.creature_flags & DEAD)) {
        this->facingRight = oldFacingRight;
        OccupyHexes(this);
      }
      if (!(primaryTarget->creature.creature_flags & DEAD)) {
        if (primaryTarget->facingRight != targetOldFacingRight) {
          primaryTarget->facingRight = targetOldFacingRight;
          OccupyHexes(primaryTarget);
        }
      }
    }
  }

  if (!isRetaliation && (this->effectStrengths[EFFECT_BERSERKER] || this->effectStrengths[EFFECT_HYPNOTIZE])) {
    this->CancelSpellType(1);
    gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
  }
  this->targetOwner = -1;
  if (isRetaliation)
    gpCombatManager->currentActionSide = 1 - gpCombatManager->currentActionSide;

  if (!isRetaliation) {
    ScriptCallback("OnBattleMeleeAttackComplete", deepbind<army*>(this), deepbind<army*>(primaryTarget));
  }

}

// Only combat message related code is changed here because of special condition when Astral Dodge happens
void army::DoHydraAttack(int isRetaliation) {
  int totalDamage, totalKilled;
  totalDamage = totalKilled = 0;

  gpCombatManager->ResetHitByCreature();

  __int16 attackMask;
  if(this->effectStrengths[EFFECT_BERSERKER])
    attackMask = this->GetAttackMask(this->occupiedHex, 2, -1);
  else
    attackMask = this->GetAttackMask(this->occupiedHex, 1, -1);

  this->CheckLuck();

  gpCombatManager->ResetLimitCreature();
  gpCombatManager->limitCreature[this->owningSide][this->stackIdx]++;

  for(int neighborIdx = 0; neighborIdx < 8; ++neighborIdx) {
    if(!(attackMask & (1 << neighborIdx))) {
      int attackFromHex = this->occupiedHex;
      if(this->creature.creature_flags & TWO_HEXER && (!this->facingRight && neighborIdx > 2 || this->facingRight == 1 && (neighborIdx < 3 || neighborIdx > 5))) {
        if(this->facingRight)
          attackFromHex = this->occupiedHex + 1;
        else
          attackFromHex = this->occupiedHex - 1;
      }
      int attackedToHex = this->GetAdjacentCellIndex(attackFromHex, neighborIdx);
      if(ValidHex(attackedToHex)) {
        int owner = gpCombatManager->combatGrid[attackedToHex].unitOwner;
        int stkIdx = gpCombatManager->combatGrid[attackedToHex].stackIdx;
        if(owner >= 0 && stkIdx >= 0) {
          ++gpCombatManager->limitCreature[owner][stkIdx];
          army *targ = &gpCombatManager->creatures[owner][stkIdx];
          if(!gpCombatManager->creatures[owner][stkIdx].hitByHydraAttack) {
            targ->hitByHydraAttack = true;
            int creaturesKilled, damageDone;
            this->DamageEnemy(targ, &damageDone, &creaturesKilled, 0, 0);
            // Don't add to total damage and show special messages
            if(damageDone < 0) {
              DoAttackBattleMessage(this, nullptr, creaturesKilled, damageDone);
            } else {
              totalDamage += damageDone;
              totalKilled += creaturesKilled;
            }
            ++gpCombatManager->limitCreature[owner][stkIdx];
          }
        }
      }
    }
  }

  gpCombatManager->DrawFrame(0, 1, 0, 1, 75, 1, 1);
  this->mightBeIsAttacking = 1;
  this->mightBeAttackAnimIdx = 20;
  gpSoundManager->MemorySample(this->combatSounds[1]);

  if(totalDamage > 0)
    DoAttackBattleMessage(this, nullptr, totalKilled, totalDamage);

  this->PowEffect(-1, 0, -1, -1);
  gpCombatManager->limitCreature[this->owningSide][this->stackIdx] = 1;
}

void army::Walk(signed int dir, int last, int notFirst) { 
  int targCell = this->GetAdjacentCellIndex(this->occupiedHex, dir);
  gCloseMove = IsCloseMove(targCell);
  
  // Bridge opening
  if (this->owningSide == 1
    && gpCombatManager->isCastleBattle
    && (targCell == 58 || targCell == 59 || targCell == 60 && this->owningSide == 1 && this->creature.creature_flags & TWO_HEXER)
    && gpCombatManager->drawBridgePosition == BRIDGE_CLOSED) {
    this->animationType = ANIMATION_TYPE_STANDING;
    this->animationFrame = 0;
    gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    gpCombatManager->LowerDoor();
    notFirst = 0;
  }
  
  giWalkingFrom = this->occupiedHex;
  giWalkingTo = targCell;
  if (this->creature.creature_flags & TWO_HEXER) {
    giWalkingFrom2 = this->occupiedHex + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
    giWalkingTo2 = targCell + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
  } else {
    giWalkingFrom2 = -1;
    giWalkingTo2 = -1;
  }
  giWalkingYMod = 0;
  
  BuildTempWalkSeq(&this->frameInfo, last, notFirst);
  this->field_8A = dir;
  if (!notFirst) {
    giMinExtentY = 640;
    giMinExtentX = 640;
    giMaxExtentY = 0;
    giMaxExtentX = 0;
    gpCombatManager->SetRenderExtentFlags(true);
    this->DrawToBuffer(gpCombatManager->combatGrid[this->occupiedHex].centerX, gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY, 0);
    gpCombatManager->SetRenderExtentFlags(false);
  }
  if (giMinExtentX < 0)
    giMinExtentX = 0;
  if (giMinExtentY < 0)
    giMinExtentY = 0;
  if (giMaxExtentX > 639)
    giMaxExtentX = 639;
  if (giMaxExtentY > 442)
    giMaxExtentY = 442;
  int offsetX = giMinExtentX;
  int offsetY = giMinExtentY;
  int v12 = giMaxExtentX;
  int v6 = giMaxExtentY;
  this->field_8E = 0;
  if (dir >= 3) {
    if (this->facingRight == 1) {
      this->field_8E = 1;
      this->facingRight = 1 - this->facingRight;
      if (this->creature.creature_flags & TWO_HEXER)
        ++this->occupiedHex;
    }
  } else if (!this->facingRight) {
    this->field_8E = 1;
    this->facingRight = 1 - this->facingRight;
    if (this->creature.creature_flags & TWO_HEXER)
      --this->occupiedHex;
  }
  if (!dir || dir == 5)
    this->field_6 = 0;
  if (dir == 2 || dir == 3)
    this->field_6 = 3;
  this->animationFrame = 0;
  this->animationType = ANIMATION_TYPE_WALKING;
  if (!gbNoShowCombat)
    gpSoundManager->MemorySample(this->combatSounds[0]);
  if (!notFirst) {
    gpCombatManager->combatGrid[this->occupiedHex].unitOwner = -1;
    gpCombatManager->DrawFrame(0, 0, 0, 0, 75, 1, 1);
    gpCombatManager->combatGrid[this->occupiedHex].unitOwner = gpCombatManager->otherCurrentSideThing;
    if (!gbNoShowCombat)
      gpWindowManager->screenBuffer->CopyTo(gpCombatManager->probablyBitmapForCombatScreen, 0, 0, 0, 0, 0x280u, 443);
    gpCombatManager->zeroedAfterAnimatingDeathAndHolySpells = 0;
  }
  if (!gbNoShowCombat) {
    for (int i = 0; this->frameInfo.animationLengths[6] > i; ++i) {
      this->animationFrame = i;
      if (notFirst || i) {
        gpCombatManager->probablyBitmapForCombatScreen->CopyTo(
          gpWindowManager->screenBuffer,
          giMinExtentX,
          giMinExtentY,
          giMinExtentX,
          giMinExtentY,
          giMaxExtentX - giMinExtentX + 1,
          giMaxExtentY - giMinExtentY + 1);
        if (giMinExtentX < 0)
          giMinExtentX = 0;
        if (giMinExtentY < 0)
          giMinExtentY = 0;
        if (giMaxExtentX > 639)
          giMaxExtentX = 639;
        if (giMaxExtentY > 442)
          giMaxExtentY = 442;
        offsetX = giMinExtentX;
        offsetY = giMinExtentY;
        v12 = giMaxExtentX;
        v6 = giMaxExtentY;
      }
      giMinExtentY = 640;
      giMinExtentX = 640;
      giMaxExtentY = 0;
      giMaxExtentX = 0;
      gpCombatManager->SetRenderExtentFlags(true);
      this->DrawToBuffer(
        gpCombatManager->combatGrid[this->occupiedHex].centerX,
        gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY,
        0);
      gpCombatManager->SetRenderExtentFlags(false);
      if (giMinExtentX < 0)
        giMinExtentX = 0;
      if (giMinExtentY < 0)
        giMinExtentY = 0;
      if (giMaxExtentX > 639)
        giMaxExtentX = 639;
      if (giMaxExtentY > 442)
        giMaxExtentY = 442;
      gbCurrArmyDrawn = 0;
      gbComputeExtent = 1;
      gbLimitToExtent = 1;
      this->field_11D = 0;
      gpCombatManager->DrawFrame(0, 0, 0, 0, 75, 0, 1);
      this->field_11D = 1;
      gbLimitToExtent = 0;
      gbComputeExtent = 0;
      gbCurrArmyDrawn = 1;
      if (giMinExtentX < offsetX)
        offsetX = giMinExtentX;
      if (offsetY > giMinExtentY)
        offsetY = giMinExtentY;
      if (giMaxExtentX > v12)
        v12 = giMaxExtentX;
      if (giMaxExtentY > v6)
        v6 = giMaxExtentY;
      DelayTil(&glTimers);
      glTimers = (signed __int64)((double)KBTickCount()
        + (double)this->frameInfo.stepTime
        * gfCombatSpeedMod[giCombatSpeed]
        / (double)this->frameInfo.animationLengths[6]);
      gpWindowManager->UpdateScreenRegion(offsetX, offsetY, v12 - offsetX + 1, v6 - offsetY + 1);
    }
  }
  int adjCell = this->GetAdjacentCellIndex(this->occupiedHex, dir);
  gpCombatManager->combatGrid[this->occupiedHex].stackIdx = -1;
  gpCombatManager->combatGrid[this->occupiedHex].unitOwner = -1;
  gpCombatManager->combatGrid[this->occupiedHex].occupiersOtherHexIsToLeft = -1;
  if (this->creature.creature_flags & TWO_HEXER) {
    int v4 = this->occupiedHex + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
    gpCombatManager->combatGrid[v4].stackIdx = -1;
    gpCombatManager->combatGrid[v4].unitOwner = -1;
    gpCombatManager->combatGrid[v4].occupiersOtherHexIsToLeft = -1;
  }
  gpCombatManager->combatGrid[adjCell].unitOwner = LOBYTE(this->owningSide);
  gpCombatManager->combatGrid[adjCell].stackIdx = LOBYTE(this->stackIdx);
  gpCombatManager->combatGrid[adjCell].occupiersOtherHexIsToLeft = -1;
  if (this->creature.creature_flags & TWO_HEXER) {
    int v7 = adjCell + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
    gpCombatManager->combatGrid[v7].unitOwner = LOBYTE(this->owningSide);
    gpCombatManager->combatGrid[v7].stackIdx = LOBYTE(this->stackIdx);
    gpCombatManager->combatGrid[v7].occupiersOtherHexIsToLeft = adjCell <= v7;
    gpCombatManager->combatGrid[adjCell].occupiersOtherHexIsToLeft = adjCell >= v7;
  }

  this->occupiedHex = adjCell;
  if (this->field_8E) {
    this->facingRight = 1 - this->facingRight;
    OccupyHexes(this);
    this->field_8E = 0;
  }

  giWalkingFrom = -1;
  giWalkingFrom2 = -1;
  giWalkingTo = -1;
  giWalkingTo2 = -1;
  this->field_6 = 1;
  if (last == 1) {
    this->animationType = ANIMATION_TYPE_STANDING;
    this->animationFrame = 0;
    gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 1, 1);
  }
  gpCombatManager->CheckBurnCreature(this);
}

int army::FindPath(int knownHex, int targHex, int speed, int flying, int flag) {
  int res;
  std::vector<int> obstacleHexes;

  if(!IsAICombatTurn() && CreatureHasAttribute(this->creatureIdx, JUMPER) && gIronfistExtra.combat.stack.abilityCounter[this][JUMPER]) {
    for (int i = 0; i < NUM_HEXES; i++) {
      if (gpCombatManager->combatGrid[i].isBlocked != 0 && !IsCastleWall(i)) {
        obstacleHexes.push_back(i);
        gpCombatManager->combatGrid[i].isBlocked = 0;
      }
    }
  }
  res = this->FindPath_orig(knownHex, targHex, speed, flying, flag);

  // pretending we don't see obstacles at all
  // this does nothing for creatures that don't ignore obstacles
  for (auto i : obstacleHexes)
    gpCombatManager->combatGrid[i].isBlocked = 1;

  return res;
}

int army::ValidPath(int hex, int flag) {
  if (ValidHex(hex)) {
    if (this->creature.creature_flags & FLYER) {
      return this->ValidFlight(hex, flag);
    } else if (this->FindPath(this->occupiedHex, hex, this->creature.speed, 0, flag)) {
      this->targetHex = hex;
      return 1;
    } else {
      return 0;
    }
  }
  return 0;
}

#pragma pack(push, 1)
struct PathfindingInfo {
  char field_0;
  char field_1;
  __int16 field_2;
  char field_4;
  int field_5;
};
#pragma pack(pop)

#pragma pack(push,1)
class searchArray {
public:
	int field_0;
	int field_4;
	int field_8;
	char _1[8];
	PathfindingInfo mainDataStructure[1024];
	PathfindingInfo *field_2414;
	int field_2418;
	int field_241C[63];
	searchArray();
  ~searchArray();
};
#pragma pack(pop)

void army::ArcJump(int fromHex, int toHex) {
  bool firingLeft = true;
  float fromX = gpCombatManager->combatGrid[fromHex].centerX;
  float fromY = gpCombatManager->combatGrid[fromHex].otherY2;
  float targX = gpCombatManager->combatGrid[toHex].centerX;
  float targY = gpCombatManager->combatGrid[toHex].otherY2;
  if(fromX > targX) {
    this->facingRight = false;
    firingLeft = false;
  } else {
    this->facingRight = true;
  }

  // remove from battlefield
  gpCombatManager->combatGrid[fromHex].stackIdx = -1;
  gpCombatManager->combatGrid[fromHex].unitOwner = -1;
  gpCombatManager->combatGrid[fromHex].occupiersOtherHexIsToLeft = -1;
  gpCombatManager->DrawFrame(0, 0, 0, 0, 75, 1, 1);

  // temporarily save the screen so we can clear it from the creature sprite later
  bitmap *savedscreen = new bitmap(0, INTERNAL_WINDOW_WIDTH, INTERNAL_WINDOW_HEIGHT);
  gpWindowManager->screenBuffer->CopyTo(savedscreen, 0, 0, 0, 0, INTERNAL_WINDOW_WIDTH, INTERNAL_WINDOW_HEIGHT);

  this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MOVE][0] = 31;
  this->animationFrame = 0;
  this->animationType = ANIMATION_TYPE_MOVE;
  
  std::vector<COORD> points;
  const int NUM_FRAMES = 24; // equals to the number of frames for the whole arc path
  points = MakeCatapultArc(NUM_FRAMES, firingLeft, fromX, fromY, targX, targY);
  for(int i = 0; i < (int)points.size(); i++) {
    if(i == 5) {
      this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MOVE][0] = 32;
    } else if(i == 12) {
      this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MOVE][0] = 33;
    }
    savedscreen->CopyTo(gpWindowManager->screenBuffer, 0, 0, 0, 0, INTERNAL_WINDOW_WIDTH, INTERNAL_WINDOW_HEIGHT); // clear the screen from the previous creature sprite
    this->DrawToBuffer(points[i].X, points[i].Y, 0);
    gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 0, 1);
    gpWindowManager->UpdateScreenRegion(0, 0, INTERNAL_WINDOW_WIDTH, INTERNAL_WINDOW_HEIGHT);
    glTimers = (signed __int64)((double)KBTickCount() + (double)40 * gfCombatSpeedMod[giCombatSpeed]);
    DelayTil(&glTimers);
  }
  
  // occupy new hex
  this->occupiedHex = toHex;
  gpCombatManager->combatGrid[this->occupiedHex].unitOwner = LOBYTE(this->owningSide);
  gpCombatManager->combatGrid[this->occupiedHex].stackIdx = LOBYTE(this->stackIdx);
  gpCombatManager->combatGrid[this->occupiedHex].occupiersOtherHexIsToLeft = -1;

  // reset renderer settings
  savedscreen->CopyTo(gpWindowManager->screenBuffer, 0, 0, 0, 0, INTERNAL_WINDOW_WIDTH, INTERNAL_WINDOW_HEIGHT); // clear the screen from the previous creature sprite
  giMinExtentY = giMinExtentX = giMaxExtentY = giMaxExtentX = 0;
  // reverting frame
  this->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_MOVE][0] = 1;

  delete savedscreen;
}

extern searchArray *gpSearchArray;

int army::WalkTo(int hex) {
  this->targetStackIdx = -1;
  this->targetOwner = this->targetStackIdx;
  if (gpCombatManager->hasMoat && this->creature.creature_flags & TWO_HEXER) {
    bool goingToMoat = false;
    int moatIdx = 0;
    for (int i = 0; i < 9; ++i) {
      if (moatCell[i] == hex) {
        goingToMoat = true;
        moatIdx = i;
      }
    }
    if (goingToMoat) {
      bool onEnemySideOfMoat = false;
      if (moatIdx == 4 && gpCombatManager->drawBridgePosition != 4)
        onEnemySideOfMoat = true;
      if (moatIdx > 0 && *(&giWalkingYMod + moatIdx + 3) == this->occupiedHex// moatCell[moatIdx-1]
        || moatIdx < 8 && moatCell[moatIdx + 1] == this->occupiedHex)
        onEnemySideOfMoat = true;
      for (int j = 0; j < 6; ++j) {
        if (moatCell[moatIdx] == army::GetAdjacentCellIndex(this->occupiedHex, j))
          onEnemySideOfMoat = true;
      }
      if (!this->owningSide && moatCell[this->occupiedHex / 13] < this->occupiedHex)
        onEnemySideOfMoat = true;
      if (this->owningSide == 1 && moatCell[this->occupiedHex / 13] > this->occupiedHex)
        onEnemySideOfMoat = true;
      if (!onEnemySideOfMoat) {
        if (this->facingRight == 1)
          --hex;
        else
          ++hex;
      }
    }
  }

  if(this->FindPath(this->occupiedHex, hex, this->creature.speed, 1, 0)) {
    int traveledHexes = 0;
    int initialHex = this->occupiedHex;
    for(int hexIdxb = gpSearchArray->field_8 - 1; hexIdxb >= 0; --hexIdxb) {
      int dir = *((BYTE *)&gpSearchArray->field_2418 + hexIdxb);
      int destHex = this->GetAdjacentCellIndex(this->occupiedHex, dir);
      if(this->creatureIdx == CREATURE_CYBER_PLASMA_BERSERKER && gIronfistExtra.combat.stack.abilityCounter[this][JUMPER]) {
        if(gMoveAttack && hexIdxb < 4) { // less than 4 hexes from enemy
          // find last hex
          for(int h = hexIdxb; h >= 0; --h) {
            dir = *((BYTE *)&gpSearchArray->field_2418 + h);
            destHex = this->GetAdjacentCellIndex(this->occupiedHex, dir);
            this->occupiedHex = destHex;
          }
          this->ArcJump(initialHex, destHex);
		      gIronfistExtra.combat.stack.abilityNowAnimating[this][JUMPER] = true;
		      this->CancelSpellType(0);
		      return 0;
        } else if(gpCombatManager->combatGrid[destHex].isBlocked) { // jumping over obstacle
          //finding where to land
          for(int landHex = hexIdxb - 1; landHex >= 0; --landHex) {
            dir = *((BYTE *)&gpSearchArray->field_2418 + landHex);
            this->occupiedHex = destHex;
            destHex = this->GetAdjacentCellIndex(this->occupiedHex, dir);
            if(!gpCombatManager->combatGrid[destHex].isBlocked) {
              traveledHexes += hexIdxb - landHex;
              hexIdxb = landHex;
              this->ArcJump(initialHex, destHex);
              break;
            }
          }
        } else {
          this->Walk(dir, 0, gpSearchArray->field_8 - 1 != hexIdxb);
          if(this->animationType == ANIMATION_TYPE_DYING)
            return 0;
        }
      } else {
        this->Walk(dir, 0, gpSearchArray->field_8 - 1 != hexIdxb);
        if(this->animationType == ANIMATION_TYPE_DYING)
          return 0;
      }
      traveledHexes++;
      if(traveledHexes >= this->creature.speed)
        hexIdxb = -1;
      initialHex = this->occupiedHex;
    }
    this->CancelSpellType(0);
    this->animationType = ANIMATION_TYPE_STANDING;
    this->animationFrame = 0;
    gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    gpCombatManager->TestRaiseDoor();
    return 0;
  } else {
    return 3;
  }
}

int army::AttackTo(int targetHex) {
  int result;

  if (this->creature.creature_flags & FLYER || (this->ValidPath(targetHex, 0) == 0 && CreatureHasAttribute(this->creatureIdx, CHARGER))) {
    if (this->occupiedHex != targetHex)
      this->FlyTo(targetHex);
    this->DoAttack(0);
    result = 0;
  } else if (this->creature.creature_flags & TWO_HEX_ATTACKER && this->occupiedHex == this->targetHex) {
    this->DoAttack(0);
    result = 0;
  } else if (this->FindPath(this->occupiedHex, targetHex, this->creature.speed, 1, 0)) {
    if (gpSearchArray->field_8 == 1) {
      this->targetNeighborIdx = LOBYTE(gpSearchArray->field_2418);
      gpCombatManager->TestRaiseDoor();
      this->DoAttack(0);
    } else {
      int traveledHexes = 0;
      int initialHex = this->occupiedHex;
      for (int i = gpSearchArray->field_8 - 1; i; --i) {
        int dir = *((BYTE *)&gpSearchArray->field_2418 + i);
        int destHex = this->GetAdjacentCellIndex(this->occupiedHex, dir);
        if(this->creatureIdx == CREATURE_CYBER_PLASMA_BERSERKER && gIronfistExtra.combat.stack.abilityCounter[this][JUMPER]) {
          if(gMoveAttack && i < 5) { // less than 4 hexes from enemy
            // find last hex
            for(int h = i; h >= 1; --h) {
              dir = *((BYTE *)&gpSearchArray->field_2418 + h);
              destHex = this->GetAdjacentCellIndex(this->occupiedHex, dir);
              this->occupiedHex = destHex;
            }
            this->ArcJump(initialHex, destHex);
            gIronfistExtra.combat.stack.abilityNowAnimating[this][JUMPER] = true;
            break;
          } else {
            this->Walk(dir, 0, gpSearchArray->field_8 - 1 != i);
            if(this->animationType == ANIMATION_TYPE_DYING)
              return 0;
          }
        } else { 
          this->Walk(dir, 0, gpSearchArray->field_8 - 1 != i);
          if(this->animationType == ANIMATION_TYPE_DYING)
            return 0;
        }
        ++traveledHexes;
        int a3 = i == 1 || this->creature.speed <= traveledHexes;
        if (this->creature.speed <= traveledHexes && i != 1)
          return 3;
        initialHex = this->occupiedHex;
      }
      this->CancelSpellType(0);
      this->targetNeighborIdx = LOBYTE(gpSearchArray->field_2418);
      gpCombatManager->TestRaiseDoor();
      this->DoAttack(0);
    }
    result = 0;
  } else {
    result = 3;
  }
  return result;
}

// ironfist function
bool army::IsCloseMove(int toHexIdx) {
  for (int j = 0; j < 6; j++) {
    if (this->creature.creature_flags & TWO_HEXER) {
      if (gpCombatManager->hexNeighbors[this->occupiedHex + 1][j] == toHexIdx)
        return true;
    }
    if (gpCombatManager->hexNeighbors[this->occupiedHex][j] == toHexIdx)
      return true;
  }
  return false;
}

int army::FlyTo(int hexIdx) {
  gCloseMove = IsCloseMove(hexIdx);

  if (ValidHex(hexIdx)) {
    int colDiff = hexIdx % 13 - this->occupiedHex % 13;
    this->field_8E = 0;
    if (colDiff <= 0 || this->facingRight) {
      if (colDiff < 0) {
        if (this->facingRight == 1) {
          this->field_8E = 1;
          this->facingRight = 1 - this->facingRight;
          if (this->creature.creature_flags & TWO_HEXER) {
            ++this->occupiedHex;
            ++hexIdx;
          }
        }
      }
    } else {
      this->field_8E = 1;
      this->facingRight = 1 - this->facingRight;
      if (this->creature.creature_flags & TWO_HEXER) {
        --this->occupiedHex;
        --hexIdx;
      }
    }
    if (this->field_8E)
      gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    int v19 = gpCombatManager->combatGrid[this->occupiedHex].centerX;
    int v14 = gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY;
    float currentDrawX = (double)v19;
    float currentDrawY = (double)v14;
    int deltaX = gpCombatManager->combatGrid[hexIdx].centerX - v19;
    int deltaY = gpCombatManager->combatGrid[hexIdx].occupyingCreatureBottomY - v14;
    int dist = (signed __int64)sqrt((double)(deltaY * deltaY + deltaX * deltaX));

    int numFrames = 0;
    if (this->frameInfo.flightSpeed > 0)
      numFrames = (dist + (this->frameInfo.flightSpeed >> 1)) / this->frameInfo.flightSpeed;
    if (numFrames <= 0)
      numFrames = 1;
    float stepX = (double)deltaX / (double)numFrames;
    float stepY = (double)deltaY / (double)numFrames;
    gpCombatManager->combatGrid[this->occupiedHex].stackIdx = -1;
    gpCombatManager->combatGrid[this->occupiedHex].unitOwner = -1;
    gpCombatManager->combatGrid[this->occupiedHex].occupiersOtherHexIsToLeft = -1;
    if (this->creature.creature_flags & TWO_HEXER) {
      int v3 = this->occupiedHex + (this->facingRight < 1u ? -1 : 1);
      gpCombatManager->combatGrid[v3].stackIdx = -1;
      gpCombatManager->combatGrid[v3].unitOwner = -1;
      gpCombatManager->combatGrid[v3].occupiersOtherHexIsToLeft = -1;
    }

    std::vector<int> chargeAffectedHexes;
    if (!gbNoShowCombat) {
      bool closeMove = IsCloseMove(hexIdx);
      bool teleporter = CreatureHasAttribute(this->creatureIdx, TELEPORTER);
      gpCombatManager->DrawFrame(0, 0, 0, 0, 75, 1, 1);
      gpWindowManager->screenBuffer->CopyTo(gpCombatManager->probablyBitmapForCombatScreen, 0, 0, 0, 0, 0x280u, 442);
      gpCombatManager->zeroedAfterAnimatingDeathAndHolySpells = 0;

      this->animationType = ANIMATION_TYPE_WALKING;
      for (int i = 0; numFrames > i; ++i) {
        if (teleporter) {
          BuildTeleporterTempWalkSeq(&this->frameInfo, i + 1 == numFrames, i > 0, closeMove);
        } else {
          BuildTempWalkSeq(&this->frameInfo, i + 1 == numFrames, i > 0);
          if(CreatureHasAttribute(this->creatureIdx, CHARGER)) {
            gCharging = true;
            CHARGING_DIRECTION chargeDir = CHARGING_FORWARD;
            double angle = (180.0 / 3.141592653589793238463) * atan2(deltaY, abs(deltaX));
            if(angle > 45)
              chargeDir = CHARGING_DOWN;
            else if(angle < -45)
              chargeDir = CHARGING_UP;
            SetChargingMoveAnimation(chargeDir);
          }
        }
        int startMoveLen = 0;
        int moveLen = 0;
        int moveAndSubEndMoveLen;
        if (numFrames) {
          if(i <= 0) {
            if(closeMove && teleporter)
              startMoveLen = 0;
            else
              startMoveLen = this->frameInfo.animationLengths[ANIMATION_TYPE_START_MOVE];
          } else
            startMoveLen = 0;
          moveAndSubEndMoveLen = this->frameInfo.animationLengths[ANIMATION_TYPE_MOVE];
          moveLen = this->frameInfo.animationLengths[ANIMATION_TYPE_MOVE];
          if (i + 1 < numFrames)
            moveAndSubEndMoveLen += this->frameInfo.animationLengths[ANIMATION_TYPE_SUB_END_MOVE];
        } else {
          moveAndSubEndMoveLen = this->frameInfo.animationLengths[ANIMATION_TYPE_WALKING];
          startMoveLen = 0;
        }
        for (this->animationFrame = 0; this->frameInfo.animationLengths[ANIMATION_TYPE_WALKING] > this->animationFrame; ++this->animationFrame) {
          if (this->animationFrame >= startMoveLen && startMoveLen + moveAndSubEndMoveLen > this->animationFrame) {
            if (teleporter && !closeMove) {
              currentDrawX = gpCombatManager->combatGrid[hexIdx].centerX;
              currentDrawY = gpCombatManager->combatGrid[hexIdx].occupyingCreatureBottomY;
            } else {
              currentDrawX += stepX / (double)moveAndSubEndMoveLen;
              currentDrawY += stepY / (double)moveAndSubEndMoveLen;
            }
          }
          if (this->animationFrame % this->frameInfo.animationLengths[ANIMATION_TYPE_WALKING] == 1) {
            if (this->creatureIdx != CREATURE_VAMPIRE && this->creatureIdx != CREATURE_VAMPIRE_LORD || i) {
              if (this->creatureIdx != CREATURE_VAMPIRE && this->creatureIdx != CREATURE_VAMPIRE_LORD || numFrames - 1 != i)
                gpSoundManager->MemorySample(this->combatSounds[0]);
              else
                gpSoundManager->MemorySample(this->combatSounds[6]);
            } else {
              gpSoundManager->MemorySample(this->combatSounds[5]);
              DelayMilli(100);
            }
          }
          int offsetX = 0;
          int offsetY = 0;
          int v10 = 639;
          int v6 = 442;
          if (i || this->animationFrame) {
            gpCombatManager->probablyBitmapForCombatScreen->CopyTo(
              gpWindowManager->screenBuffer,
              giMinExtentX,
              giMinExtentY,
              giMinExtentX,
              giMinExtentY,
              giMaxExtentX - giMinExtentX + 1,
              giMaxExtentY - giMinExtentY + 1);
            offsetX = giMinExtentX;
            offsetY = giMinExtentY;
            v10 = giMaxExtentX;
            v6 = giMaxExtentY;
          }
          giMinExtentY = 640;
          giMinExtentX = 640;
          giMaxExtentY = 0;
          giMaxExtentX = 0;
          gbComputeExtent = 1;
          gbSaveBiggestExtent = 1;
          this->DrawToBuffer((int)currentDrawX, (int)currentDrawY, 0);
          gbComputeExtent = 0;
          gbSaveBiggestExtent = 0;
          if (giMinExtentX < 0)
            giMinExtentX = 0;
          if (giMinExtentY < 0)
            giMinExtentY = 0;
          if (giMaxExtentX > 639)
            giMaxExtentX = 639;
          if (giMaxExtentY > 442)
            giMaxExtentY = 442;
          if (offsetX > giMinExtentX)
            offsetX = giMinExtentX;
          if (offsetY > giMinExtentY)
            offsetY = giMinExtentY;
          if (v10 < giMaxExtentX)
            v10 = giMaxExtentX;
          if (giMaxExtentY > v6)
            v6 = giMaxExtentY;
          DelayTil(&glTimers);
          if (this->animationFrame >= startMoveLen
            && (this->animationFrame + 1 < moveLen || this->creatureIdx != CREATURE_VAMPIRE && this->creatureIdx != CREATURE_VAMPIRE_LORD))
            glTimers = (signed __int64)((double)KBTickCount()
              + (double)this->frameInfo.stepTime * gfCombatSpeedMod[giCombatSpeed] / (double)moveAndSubEndMoveLen);
          else
            glTimers = (signed __int64)((double)KBTickCount()
              + (double)this->frameInfo.stepTime
              * gfCombatSpeedMod[giCombatSpeed]
              * 1.3
              / (double)moveAndSubEndMoveLen);
          gpWindowManager->UpdateScreenRegion(offsetX, offsetY, v10 - offsetX + 1, v6 - offsetY + 1);
          if (this->frameInfo.animationLengths[ANIMATION_TYPE_WALKING] - 1 == this->animationFrame) {
            currentDrawX = (double)(i + 1) * stepX + (double)v19;
            currentDrawY = (double)(i + 1) * stepY + (double)v14;
          }
          const int CHARGE_SPRITE_OFFSET = 10;
          int h = gpCombatManager->GetGridIndex(currentDrawX, currentDrawY - CHARGE_SPRITE_OFFSET);
          if(IsEnemyCreatureHex(h))
            chargeAffectedHexes.push_back(h);
        }
      }
    }
    this->CancelSpellType(0);
    gpCombatManager->combatGrid[hexIdx].unitOwner = LOBYTE(gpCombatManager->otherCurrentSideThing);
    gpCombatManager->combatGrid[hexIdx].stackIdx = LOBYTE(gpCombatManager->someSortOfStackIdx);
    gpCombatManager->combatGrid[hexIdx].occupiersOtherHexIsToLeft = -1;
    if (this->creature.creature_flags & TWO_HEXER) {
      int v5 = hexIdx + (this->facingRight < 1u ? -1 : 1);
      gpCombatManager->combatGrid[v5].unitOwner = LOBYTE(gpCombatManager->otherCurrentSideThing);
      gpCombatManager->combatGrid[v5].stackIdx = LOBYTE(gpCombatManager->someSortOfStackIdx);
      gpCombatManager->combatGrid[v5].occupiersOtherHexIsToLeft = v5 >= hexIdx;
      gpCombatManager->combatGrid[hexIdx].occupiersOtherHexIsToLeft = v5 <= hexIdx;
    }
    this->occupiedHex = hexIdx;
    this->animationType = ANIMATION_TYPE_STANDING;
    this->animationFrame = 0;
    if (this->field_8E) {
      this->facingRight = 1 - this->facingRight;
      OccupyHexes(this);
      this->field_8E = 0;
    }

    if(CreatureHasAttribute(this->creatureIdx, CHARGER)) {
      // remove duplicates
      std::set<int> s(chargeAffectedHexes.begin(), chargeAffectedHexes.end() );
      chargeAffectedHexes.assign(s.begin(),s.end());
      // don't damage target creature by "charge path damage"
      auto f = std::find(chargeAffectedHexes.begin(), chargeAffectedHexes.end(), giNextActionGridIndex);
      if(f != chargeAffectedHexes.end())
        chargeAffectedHexes.erase(f);
      ChargingDamage(chargeAffectedHexes);
    }
    gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    
    if(CreatureHasAttribute(this->creatureIdx, CHARGER))
        RevertChargingMoveAnimation();
    gpCombatManager->TestRaiseDoor();

    gpCombatManager->CheckBurnCreature(this);
    return 1;
  }
  return 0;
}

void SpecialAttackBattleMessage(army *attacker, army *target, int creaturesKilled, int damageDone) {
  char *attackingCreature;
  if (creaturesKilled <= 0) {
    if (attacker->quantity <= 1)
      attackingCreature = GetCreatureName(attacker->creatureIdx);
    else
      attackingCreature = GetCreaturePluralName(attacker->creatureIdx);
    sprintf(gText, "%s %s %d damage.", attackingCreature, (attacker->quantity > 1) ? "do" : "does", damageDone);
    gText[0] = toupper(gText[0]);
  } else {
    if (damageDone == -1) {
      sprintf(gText, "The mirror image is destroyed!");
    } else {
      char *targetCreature;
      if (creaturesKilled <= 1)
        targetCreature = GetCreatureName(target->creatureIdx);
      else
        targetCreature = GetCreaturePluralName(target->creatureIdx);
      if (attacker->quantity <= 1)
        attackingCreature = GetCreatureName(attacker->creatureIdx);
      else
        attackingCreature = GetCreaturePluralName(attacker->creatureIdx);
      sprintf(
        gText,
        "%s %s %d damage.\n%d %s %s.",
        attackingCreature,
        (attacker->quantity > 1) ? "do" : "does",
        damageDone,
        creaturesKilled,
        targetCreature,
        (creaturesKilled > 1) ? "perish" : "perishes");
      gText[0] = toupper(gText[0]);
    }
  }
  gpCombatManager->CombatMessage(gText, 1, 1, 0);
}

void ProcessSecondAttack(army *attacker, army *target) {
  if (!bSecondAttack && target->quantity > 0) {
    bSecondAttack = 1;
    attacker->SpecialAttack();
    bSecondAttack = 0;
  }
}

void SpecialAttackGraphics(army *attacker, army *target) {
  gpCombatManager->ResetLimitCreature();
  gpCombatManager->limitCreature[attacker->owningSide][attacker->stackIdx]++;
  gpCombatManager->DrawFrame(0, 1, 0, 1, 75, 1, 1);

  int targMidX, targMidY;
  int totXDiff, yDiff;
  char firingLeft;
  {
    targMidX = target->MidX();
    targMidY = target->MidY();
    if (attacker->creatureIdx == CREATURE_LICH || attacker->creatureIdx == CREATURE_POWER_LICH) {
      targMidX = gpCombatManager->combatGrid[target->occupiedHex].centerX;
      targMidY = gpCombatManager->combatGrid[target->occupiedHex].occupyingCreatureBottomY - 17;
    }
    int projStartX;
    if (attacker->facingRight == 1)
      projStartX = attacker->frameInfo.projectileStartOffset[1][0] + gpCombatManager->combatGrid[attacker->occupiedHex].centerX;
    else
      projStartX = gpCombatManager->combatGrid[attacker->occupiedHex].centerX - attacker->frameInfo.projectileStartOffset[1][0];
    int projStartY = attacker->frameInfo.projectileStartOffset[1][1] + gpCombatManager->combatGrid[attacker->occupiedHex].occupyingCreatureBottomY;
    totXDiff = targMidX - projStartX;
    firingLeft = 0;
    if (targMidX - projStartX < 0) {
      firingLeft = 1;
      totXDiff = -totXDiff;
    }
    yDiff = targMidY - projStartY;
  }

  float angleDeg;
  int spriteIdx;
  {
    if (totXDiff) {
      float slope = (double)-yDiff / (double)totXDiff;
      angleDeg = atan(slope) * 180.0 / 3.14159;
      int i;
      for (i = 1;  attacker->frameInfo.numMissileDirs > i &&
        (*(float *)((char *)&attacker->frameInfo.projectileStartOffset[i + 2] + 1) +
          attacker->frameInfo.projDirAngle[i]) / 2.0 >= angleDeg;  ++i)
        ;
      if (attacker->frameInfo.numMissileDirs <= i)
        spriteIdx = attacker->frameInfo.numMissileDirs - 1;
      else
        spriteIdx = i - 1;
    } else {
      
      if (yDiff <= 0)
        spriteIdx = 0;
      else
        spriteIdx = attacker->frameInfo.numMissileDirs - 1;
      angleDeg = (double)(yDiff <= 0 ? 90 : -90);
    }
  }

  int attackDirectionAnimationIdx;
  {
    if (angleDeg <= 25.0) {
      if (angleDeg <= -25.0) {
        attacker->animationType = ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS;
        attackDirectionAnimationIdx = 2;
      } else {
        attacker->animationType = ANIMATION_TYPE_RANGED_ATTACK_FORWARDS;
        attackDirectionAnimationIdx = 1;
      }
    } else {
      attacker->animationType = ANIMATION_TYPE_RANGED_ATTACK_UPWARDS;
      attackDirectionAnimationIdx = 0;
    }
  }

  DrawShootingAnimation: {
    for (attacker->animationFrame = 0;
         attacker->frameInfo.animationLengths[attacker->animationType] > attacker->animationFrame;
         ++attacker->animationFrame) {

      if (attacker->frameInfo.animationLengths[attacker->animationType] - 1 == attacker->animationFrame) {
        gpCombatManager->DrawFrame(0, 1, 0, 0, 75, 1, 1);
      } else {
        gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 1, 1);
      }

      glTimers = (signed __int64)((double)KBTickCount()
        + (double)attacker->frameInfo.shootingTime
        * gfCombatSpeedMod[giCombatSpeed]
        / (double)attacker->frameInfo.animationLengths[attacker->animationType]);
    }

    attacker->animationFrame = attacker->frameInfo.animationLengths[attacker->animationType] - 1;
  }


  int halfProjIconWidth = 100;
  int halfProjIconHeight = 100;
  int shotSpeed = 31; // in pixels/frame
  int v22 = 25;

  H2RECT bounds(top(INT_MAX), bottom(INT_MIN), left(INT_MAX), right(INT_MIN));

  int startX;
  if (attacker->facingRight == 1)
    startX = attacker->frameInfo.projectileStartOffset[attackDirectionAnimationIdx][0] + gpCombatManager->combatGrid[attacker->occupiedHex].centerX;
  else
    startX = gpCombatManager->combatGrid[attacker->occupiedHex].centerX - attacker->frameInfo.projectileStartOffset[attackDirectionAnimationIdx][0];

  int startY = attacker->frameInfo.projectileStartOffset[attackDirectionAnimationIdx][1] + gpCombatManager->combatGrid[attacker->occupiedHex].occupyingCreatureBottomY;

  int endX = target->MidX();
  int endY = target->MidY();
  int diffX = endX - startX;
  int diffY = endY - startY;
  int distance = (signed __int64)sqrt((double)(diffY * diffY + diffX * diffX));
  int numFrames = (distance + (shotSpeed / 2)) / shotSpeed;

  if (attacker->creatureIdx == CREATURE_MAGE || attacker->creatureIdx == CREATURE_ARCHMAGE) {
    gpWindowManager->UpdateScreenRegion(giMinExtentX, giMinExtentY, giMaxExtentX - giMinExtentX + 1, giMaxExtentY - giMinExtentY + 1);
    DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 115.0));
    gpCombatManager->DoBolt(1, startX, startY, endX, endY, 0, 0, 5, 4, 302, 0, 0, distance / 15 + 15, 1, 0, 10, 0);
  } else if (attacker->creatureIdx == CREATURE_CYBER_BEHEMOTH) {
    gpCombatManager->ArcShot(attacker->missileIcon, startX, startY, endX, endY);
  } else {
    int dx, dy;

    if (numFrames <= 1) {
      dx = diffX;
      dy = diffY;
    } else {
      dx = diffX / (numFrames - 1);
      dy = diffY / (numFrames - 1);
    }
    int centX = startX;
    int centY = startY;
    Point toDrawAt(0, 0);

    bitmap *from = new bitmap(33, 2 * halfProjIconWidth, 2 * halfProjIconHeight);
    from->GrabBitmapCareful(gpWindowManager->screenBuffer, centX - halfProjIconWidth, centY - halfProjIconHeight);
    int oldCentX = centX;
    int oldCentY = centY;

    for (int i = 0; i < numFrames; ++i) {
      bounds = bounds.unionWith(rectAroundPoint(Point(oldCentX, oldCentY),
                                                 halfProjIconWidth, halfProjIconHeight));

      bounds = bounds.clipToBounds(H2RECT(top(0), bottom(442), left(0), right(639)));

      if (i > 0) {
        from->DrawToBufferCareful(toDrawAt._x, toDrawAt._y);
      } else {
        // extent = extent.unionWidth(bounds);
        giMinExtentX = min(giMinExtentX, bounds._left);
        giMaxExtentX = max(giMaxExtentX, bounds._right);
        giMinExtentY = min(giMinExtentY, bounds._top);
        giMaxExtentY = max(giMaxExtentY, bounds._bottom);
      }

      toDrawAt = Point(centX - halfProjIconWidth, centY - halfProjIconHeight);
      toDrawAt = toDrawAt.clipToRect(H2RECT(top(0), bottom(442 - from->height), left(0), right(640 - from->width)));

      from->GrabBitmapCareful(gpWindowManager->screenBuffer, toDrawAt._x, toDrawAt._y);
      attacker->missileIcon->DrawToBuffer(centX, centY, spriteIdx, firingLeft);
      if (i == 0) {
        gpWindowManager->UpdateScreenRegion(giMinExtentX, giMinExtentY, giMaxExtentX - giMinExtentX + 1, giMaxExtentY - giMinExtentY + 1);
      } else {
        DelayTil(&glTimers);
        gpWindowManager->UpdateScreenRegion(bounds._left, bounds._top, bounds.getWidth(), bounds.getHeight());
      }

      glTimers = (signed __int64)((double)KBTickCount() + (double)v22 * gfCombatSpeedMod[giCombatSpeed]);
      oldCentX = centX;
      oldCentY = centY;
      centX += dx;
      centY += dy;

      bounds = rectAroundPoint(Point(centX, centY),
                                  halfProjIconWidth, halfProjIconHeight);
    }

    from->DrawToBuffer(toDrawAt._x, toDrawAt._y);
    gpWindowManager->UpdateScreenRegion(oldCentX - halfProjIconWidth, oldCentY - halfProjIconHeight, 2 * halfProjIconWidth, 2 * halfProjIconHeight);
    if (from)
      from->~bitmap();
  }
}

void army::SpecialAttack() {
  int damageDone = 0;
  int creaturesKilled = 0;
  this->field_125 = 0;
  army *target = &gpCombatManager->creatures[this->targetOwner][this->targetStackIdx];
  char targetColumnHex = target->occupiedHex % 13;
  char targetRowHex = target->occupiedHex / 13; // unused
  char sourceColumnHex = this->occupiedHex % 13;
  char sourceRowHex = this->occupiedHex / 13;
  int tmpFacingRight = this->facingRight;
  this->facingRight = targetColumnHex > sourceColumnHex || !(sourceRowHex & 1) && targetColumnHex == sourceColumnHex;

  if (this->facingRight != tmpFacingRight)
      OccupyHexes(this);

  gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);

  this->CheckLuck();
  gpSoundManager->MemorySample(this->combatSounds[3]);

  SpecialAttackGraphics(this, target);

  // Decrease the number of shots left
  if (!gpCombatManager->heroes[this->owningSide] || !gpCombatManager->heroes[this->owningSide]->HasArtifact(ARTIFACT_AMMO_CART))
    --this->creature.shots;

  int animIdx = -1;
  int a4 = -1;
  int a5 = -1;

  if (this->creatureIdx == CREATURE_LICH || this->creatureIdx == CREATURE_POWER_LICH) {
    int possibleTarget;
    gpCombatManager->ClearEffects();
    for (int i = 0; i < 7; ++i) {
      if (i >= 6)
        possibleTarget = target->occupiedHex;
      else
        possibleTarget = target->GetAdjacentCellIndex(target->occupiedHex, i);
      if (possibleTarget != -1) {
        hexcell *targetHex = &gpCombatManager->combatGrid[possibleTarget];
        if (targetHex->unitOwner != -1) {
          army *targ = &gpCombatManager->creatures[targetHex->unitOwner][targetHex->stackIdx];
          if (!gArmyEffected[targ->owningSide][targ->stackIdx]) {
            if (target != targ || i == 6) {
              gArmyEffected[targ->owningSide][targ->stackIdx] = 1;
              this->DamageEnemy(targ, &damageDone, &creaturesKilled, 1, 0);
            }
          }
        }
      }
    }
    this->field_FA = 0;
    animIdx = 20;
    a4 = gpCombatManager->combatGrid[possibleTarget].centerX;
    a5 = gpCombatManager->combatGrid[possibleTarget].occupyingCreatureBottomY - 17;
    gpSoundManager->MemorySample(combatSounds[5]);
  } else if (CreatureHasAttribute(this->creatureIdx, PLASMA_BLAST)) {

    int cyberBehemothAttackMask[] = {
      -27,-26,-25,
      -14,-13,-12,-11,
      -2,-1,1,2,
      12,13,14,15,
      25,26,27
    };

    gpCombatManager->ClearEffects();

    int possibleTarget;
    for (int j = 0; j < 18; j++) {
      possibleTarget = target->occupiedHex + cyberBehemothAttackMask[j];
      if (possibleTarget >= 0 && possibleTarget < 116) {
        hexcell *targetHex = &gpCombatManager->combatGrid[possibleTarget];
        if (targetHex->unitOwner != -1) {
          army *targ = &gpCombatManager->creatures[targetHex->unitOwner][targetHex->stackIdx];
          if (!gArmyEffected[targ->owningSide][targ->stackIdx]) {
            if (target != targ) {
              gArmyEffected[targ->owningSide][targ->stackIdx] = 1;
              this->DamageEnemy(targ, &damageDone, &creaturesKilled, 1, 0);
            }
          }
        }
      }
    }
    possibleTarget = target->occupiedHex;
    if (possibleTarget != -1) {
      hexcell *targetHex = &gpCombatManager->combatGrid[possibleTarget];
      if (targetHex->unitOwner != -1) {
        army *targ = &gpCombatManager->creatures[targetHex->unitOwner][targetHex->stackIdx];
        if (!gArmyEffected[targ->owningSide][targ->stackIdx]) {
          gArmyEffected[targ->owningSide][targ->stackIdx] = 1;
          this->DamageEnemy(targ, &damageDone, &creaturesKilled, 1, 0);
        }
      }
    }
    this->field_FA = 0;
    animIdx = 32;
    a4 = gpCombatManager->combatGrid[target->occupiedHex].centerX;
    a5 = gpCombatManager->combatGrid[target->occupiedHex].occupyingCreatureBottomY - 17;
    //gpSoundManager->MemorySample(combatSounds[5]);
  } else {
    this->DamageEnemy(target, &damageDone, &creaturesKilled, 1, 0);
  }

  SpecialAttackBattleMessage(this, target, creaturesKilled, damageDone);

  if (this->creatureIdx == CREATURE_ARCHMAGE) {
    if (SRandom(1, 100) < 20) {
      if (target) {
        if (target->SpellCastWorks(SPELL_ARCHMAGI_DISPEL))
          target->spellEnemyCreatureAbilityIsCasting = 102;
      }
    }
  }

  this->PowEffect(animIdx, 0, a4, a5);

  if (this->facingRight != tmpFacingRight) {
    OccupyHexes(this);
    this->facingRight = tmpFacingRight;
  }

  if (this->creatureIdx == CREATURE_ELF || this->creatureIdx == CREATURE_GRAND_ELF || this->creatureIdx == CREATURE_RANGER)
    ProcessSecondAttack(this, target);

  // Block mind spells
  if (this->effectStrengths[EFFECT_BERSERKER] || this->effectStrengths[EFFECT_HYPNOTIZE]) {
    this->CancelSpellType(1);
    gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
  }
}

void army::LoadResources() {
  if (!gbNoShowCombat) {
    int creatureID = this->creatureIdx;
    int formFileID = gpResourceManager->MakeId(cArmyFrameFileNames[creatureID], 1);
    gpResourceManager->PointToFile(formFileID);
    gpResourceManager->ReadBlock((signed char*)&this->frameInfo, 821u);
    ModifyFrameInfo(&this->frameInfo, (CREATURES)creatureID);
    this->field_B2 = this->frameInfo.stepTime;

    std::string shortName = this->creature.short_name;
    this->combatSounds[0] = gpResourceManager->GetSample(shortName + "move.82M");
    this->combatSounds[1] = gpResourceManager->GetSample(shortName + "attk.82M");
    this->combatSounds[2] = gpResourceManager->GetSample(shortName + "wnce.82M");
    this->combatSounds[4] = gpResourceManager->GetSample(shortName + "kill.82M");
    if (this->creature.creature_flags & SHOOTER) {
      this->combatSounds[3] = gpResourceManager->GetSample(shortName + "shot.82M");
    }
    switch (creatureID) {
      case CREATURE_VAMPIRE: case CREATURE_VAMPIRE_LORD:
      {
        this->combatSounds[5] = gpResourceManager->GetSample(shortName + "ext1.82M");
        this->combatSounds[6] = gpResourceManager->GetSample(shortName + "ext2.82M");
        break;
      }
      case CREATURE_LICH: case CREATURE_POWER_LICH:
      {
        this->combatSounds[5] = gpResourceManager->GetSample(shortName + "expl.82M");
      }
    }

    this->creatureIcon = gpResourceManager->GetIcon(cMonFilename[creatureID]);

    // Loading projectiles
    if (this->creature.creature_flags & SHOOTER) {
      if (!strlen(cArmyProjectileFileNames[creatureID]))
        this->missileIcon = gpResourceManager->GetIcon("elf__msl.icn");
      else
        this->missileIcon = gpResourceManager->GetIcon(cArmyProjectileFileNames[creatureID]);
    } else {
      this->combatSounds[3] = 0;
      this->missileIcon = 0;
    }

    for (int i = 0; i < 5; ++i) {
      if (this->combatSounds[i]) {
        this->combatSounds[i]->field_28 = 64;
        this->combatSounds[i]->codeThing = 3;
        this->combatSounds[i]->loopCount = 1;
      }
    }
  }
}

void army::PowEffect(int animIdx, int a3, int a4, int a5) {
  int specialCaseOverlapWeirdness = 1;
  if (this->creatureIdx == CREATURE_PALADIN || this->creatureIdx == CREATURE_CRUSADER)
    specialCaseOverlapWeirdness = 0;
  if (this->creatureIdx == CREATURE_DWARF || this->creatureIdx == CREATURE_BATTLE_DWARF)
    specialCaseOverlapWeirdness = 2;

  bool doCreatureEffect = false;

  if (a4 == -1) {
    if (animIdx != -1) {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; gpCombatManager->numCreatures[i] > j; j++) {
          if (gpCombatManager->creatures[i][j].probablyIsNeedDrawSpellEffect)
            doCreatureEffect = true;
        }
      }
    }
  } else {
    doCreatureEffect = true;
  }

  if (!gbNoShowCombat && animIdx != -1 && doCreatureEffect && animIdx != gCurLoadedSpellEffect) {
    gpResourceManager->Dispose((resource *)gCurLoadedSpellIcon);
    gCurLoadedSpellIcon = gpResourceManager->GetIcon(gCombatFxNames[animIdx]);
    gCurLoadedSpellEffect = animIdx;
  }

  int oneWayAnimLen = 0;
  int fromAnimLen = 0;
  int toAnimLen = 0;
  int maxOneWayAnimLen = 0;
  int maxFromAnimLen = 0;
  int maxToAnimLen = 0;
  int creatureEffectNumFrames = 0;
  if (doCreatureEffect)
    creatureEffectNumFrames = giNumPowFrames[gCurLoadedSpellEffect];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; gpCombatManager->numCreatures[i] > j; j++) {
      army *othstack = &gpCombatManager->creatures[i][j];
      if (othstack->mightBeIsAttacking) {
        toAnimLen = othstack->frameInfo.animationLengths[this->mightBeAttackAnimIdx];
        fromAnimLen = othstack->frameInfo.animationLengths[this->mightBeAttackAnimIdx + 1] + 1;
      } else if (othstack->dead) {
        oneWayAnimLen = othstack->frameInfo.animationLengths[ANIMATION_TYPE_DYING];
      } else if (othstack->damageTakenDuringSomeTimePeriod) {
        oneWayAnimLen = othstack->frameInfo.animationLengths[ANIMATION_TYPE_WINCE_RETURN] + othstack->frameInfo.animationLengths[ANIMATION_TYPE_WINCE] + 1;
      }
      if (maxToAnimLen <= toAnimLen)
        maxToAnimLen = toAnimLen;
      if (maxFromAnimLen <= fromAnimLen)
        maxFromAnimLen = fromAnimLen;
      if (maxOneWayAnimLen <= oneWayAnimLen)
        maxOneWayAnimLen = oneWayAnimLen;
    }
  }
  int maxAnyCreatureAnimLen = maxOneWayAnimLen + maxToAnimLen - specialCaseOverlapWeirdness;
  if (maxAnyCreatureAnimLen <= maxFromAnimLen + maxToAnimLen)
    maxAnyCreatureAnimLen = maxFromAnimLen + maxToAnimLen;

  int maxAnyCreatureAnimLena = maxOneWayAnimLen;
  if (maxAnyCreatureAnimLena <= maxAnyCreatureAnimLen)
    maxAnyCreatureAnimLena = maxAnyCreatureAnimLen;

  int maxAnimLen = creatureEffectNumFrames;
  if (maxAnimLen <= maxAnyCreatureAnimLena)
    maxAnimLen = maxAnyCreatureAnimLena;

  if (a3)
    gpCombatManager->ResetLimitCreature();

  for (int i = 0; i < 2; i++) {
    for (int j = 0; gpCombatManager->numCreatures[i] > j; j++) {
      army *creature = &gpCombatManager->creatures[i][j];
      int animType = creature->animationType;
      if (animType == ANIMATION_TYPE_RANGED_ATTACK_UPWARDS || animType == ANIMATION_TYPE_RANGED_ATTACK_FORWARDS || animType == ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS)
        creature->animatingRangedAttack = true;
      else
        creature->animatingRangedAttack = false;
      if ((creature->damageTakenDuringSomeTimePeriod || creature->mightBeIsAttacking || creature->animatingRangedAttack) && !gpCombatManager->limitCreature[i][j])
        gpCombatManager->limitCreature[i][j]++;
    }
  }
  gpCombatManager->DrawFrame(0, 1, 0, 1, 75, 1, 1);
  if (a4 != -1) {
    for (int i = 0; gCurLoadedSpellIcon->numSprites > i; i++) {
      IconEntry *animICNHeader = &gCurLoadedSpellIcon->headersAndImageData[i];
      giMinExtentX = a4 + animICNHeader->offsetX;
      if (giMinExtentX >= giMinExtentX)
        giMinExtentX = giMinExtentX;
      giMinExtentY = a5 + animICNHeader->offsetY;
      if (giMinExtentY >= giMinExtentY)
        giMinExtentY = giMinExtentY;
      giMaxExtentX = a4 + animICNHeader->offsetX + animICNHeader->width - 1;
      if (giMaxExtentX <= giMaxExtentX)
        giMaxExtentX = giMaxExtentX;
      giMaxExtentY = a5 + animICNHeader->height + animICNHeader->offsetY - 1;
      if (giMaxExtentY <= giMaxExtentY)
        giMaxExtentY = giMaxExtentY;
    }
    if (giMinExtentX <= 0)
      giMinExtentX = 0;
    if (giMinExtentY <= 0)
      giMinExtentY = 0;
    if (giMaxExtentX >= 639)
      giMaxExtentX = 639;
    if (giMaxExtentY >= 442)
      giMaxExtentY = 442;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; gpCombatManager->numCreatures[i] > j; j++) {
      army *creature = &gpCombatManager->creatures[i][j];
      creature->field_3 = -1;
      creature->field_4 = -1;
      //creature->effectStrengths[15] = 0;
      if (creature->damageTakenDuringSomeTimePeriod || creature->mightBeIsAttacking) {
        if (creature->mightBeIsAttacking) {
          creature->field_3 = this->mightBeAttackAnimIdx;
          creature->field_4 = this->mightBeAttackAnimIdx + 1;
        } else if (creature->dead) {
          creature->field_3 = ANIMATION_TYPE_DYING;
        } else {
          creature->field_3 = ANIMATION_TYPE_WINCE;
          creature->field_4 = ANIMATION_TYPE_WINCE_RETURN;
        }
        if (creature->field_3 == ANIMATION_TYPE_DYING)
          creature->field_5 = creature->frameInfo.animationLengths[ANIMATION_TYPE_DYING];
        else
          creature->field_5 = creature->frameInfo.animationLengths[creature->field_3]
          + creature->frameInfo.animationLengths[creature->field_3 + 1];
        if (creature->field_3 == creature->animationType)
          --creature->field_5;
        if (this->field_6 < 2)
          this->field_6 = 2;
      }
    }
  }
  for (int k = 0; maxAnimLen > k; k++) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; gpCombatManager->numCreatures[i] > j; j++) {
        army *creature = &gpCombatManager->creatures[i][j];

        if (creature->animatingRangedAttack) {
          if (creature->animationType != ANIMATION_TYPE_RANGED_ATTACK_UPWARDS
            && creature->animationType != ANIMATION_TYPE_RANGED_ATTACK_FORWARDS
            && creature->animationType != ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS) {
            if (creature->animationType != ANIMATION_TYPE_STANDING) {
              if (creature->frameInfo.animationLengths[creature->animationType] <= creature->animationFrame + 1) {
                creature->animationType = ANIMATION_TYPE_STANDING;
                creature->animationFrame = 0;
              } else {
                ++creature->animationFrame;
              }
            }
          } else {
            ++creature->animationType;
            creature->animationFrame = 0;
          }
        }
        if (creature->field_3 != -1
    //      && !creature->effectStrengths[15]
          && (creature->mightBeIsAttacking
            || creature->field_5 >= maxAnimLen - k - 1
            || maxToAnimLen && maxToAnimLen - 1 <= k
            || !maxToAnimLen
            && creature->animationType != ANIMATION_TYPE_WINCE_RETURN
            && (creature->animationType != ANIMATION_TYPE_WINCE
              || creature->frameInfo.animationLengths[creature->animationType] > creature->animationFrame + 1))) {
          if (creature->field_3 == creature->animationType || creature->field_4 == creature->animationType) {
            if (creature->frameInfo.animationLengths[creature->animationType] <= creature->animationFrame + 1) {
              if (creature->field_4 == creature->animationType || creature->field_4 == -1) {
                if (creature->animationType != ANIMATION_TYPE_STANDING && creature->animationType != ANIMATION_TYPE_DYING) {
                  creature->animationType = ANIMATION_TYPE_STANDING;
                  creature->animationFrame = 0;
                  creature->field_3 = -1;
                }
              } else {
                creature->animationType = creature->field_4;
                creature->animationFrame = 0;
              }
            } else {
              creature->animationFrame++;
            }
          } else {
            if (!gbNoShowCombat && creature->field_3 == ANIMATION_TYPE_WINCE)
              gpSoundManager->MemorySample(creature->combatSounds[2]);
            if (!gbNoShowCombat && creature->field_3 == ANIMATION_TYPE_DYING)
              gpSoundManager->MemorySample(creature->combatSounds[4]);
            creature->animationType = creature->field_3;
            creature->animationFrame = 0;
          }
        }
      }
    }
    glTimers = (signed __int64)((double)KBTickCount() + (double)120 * gfCombatSpeedMod[giCombatSpeed]);
    if (doCreatureEffect && giNumPowFrames[gCurLoadedSpellEffect] > k)
      gCurSpellEffectFrame = k;
    gpCombatManager->DrawFrame(0, 0, 0, 0, 75, 1, 1);
    if (a4 != -1 && giNumPowFrames[gCurLoadedSpellEffect] > k)
      gCurLoadedSpellIcon->CombatClipDrawToBuffer(a4, a5 + this->field_FA, gCurSpellEffectFrame, &this->effectAnimationBounds, 0, 0, 0, 0);
    gpWindowManager->UpdateScreenRegion(0, 0, INTERNAL_WINDOW_WIDTH, INTERNAL_WINDOW_HEIGHT);
    DelayTil(&glTimers);
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; gpCombatManager->numCreatures[i] > j; j++) {
      army *creature = &gpCombatManager->creatures[i][j];
      if (creature->damageTakenDuringSomeTimePeriod && creature->spellEnemyCreatureAbilityIsCasting != -1 && creature->spellEnemyCreatureAbilityIsCasting != 101) {
        gpCombatManager->CastSpell((Spell)creature->spellEnemyCreatureAbilityIsCasting, creature->occupiedHex, 1, -1);
        creature->spellEnemyCreatureAbilityIsCasting = -1;
      }
    }
  }

  bool v41 = true;
  while (v41) {
    v41 = false;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; gpCombatManager->numCreatures[i] > j; j++) {
        army *thisf = &gpCombatManager->creatures[i][j];
        int animType = thisf->animationType;
        if (animType != ANIMATION_TYPE_WINCE
          && animType != ANIMATION_TYPE_MELEE_ATTACK_UPWARDS
          && animType != ANIMATION_TYPE_MELEE_ATTACK_FORWARDS
          && animType != ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS
          && animType != ANIMATION_TYPE_TWO_HEX_ATTACK_UPWARDS
          && animType != ANIMATION_TYPE_TWO_HEX_ATTACK_FORWARDS
          && animType != ANIMATION_TYPE_TWO_HEX_ATTACK_DOWNWARDS
          && animType != ANIMATION_TYPE_RANGED_ATTACK_UPWARDS
          && animType != ANIMATION_TYPE_RANGED_ATTACK_FORWARDS
          && animType != ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS) {
          if (animType == ANIMATION_TYPE_DYING
            || animType == ANIMATION_TYPE_WINCE_RETURN
            || animType == ANIMATION_TYPE_MELEE_ATTACK_UPWARDS_RETURN
            || animType == ANIMATION_TYPE_MELEE_ATTACK_FORWARDS_RETURN
            || animType == ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS_RETURN
            || animType == ANIMATION_TYPE_TWO_HEX_ATTACK_UPWARDS_RETURN
            || animType == ANIMATION_TYPE_TWO_HEX_ATTACK_FORWARDS_RETURN
            || animType == ANIMATION_TYPE_TWO_HEX_ATTACK_DOWNWARDS_RETURN
            || animType == ANIMATION_TYPE_RANGED_ATTACK_UPWARDS_RETURN
            || animType == ANIMATION_TYPE_RANGED_ATTACK_FORWARDS_RETURN
            || animType == ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS_RETURN) {
            if (thisf->frameInfo.animationLengths[animType] <= thisf->animationFrame + 1) {
              if (animType != ANIMATION_TYPE_DYING) {
                thisf->animationType = ANIMATION_TYPE_STANDING;
                thisf->animationFrame = 0;
                v41 = true;
              }
            } else {
              thisf->animationFrame++;
              v41 = true;
            }
          }
        } else {
          thisf->animationType++;
          thisf->animationFrame = 0;
          v41 = true;
        }
      }
    }
    if (v41) {
      glTimers = (signed __int64)((double)KBTickCount() + (double)120 * gfCombatSpeedMod[giCombatSpeed]);
      gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 1, 1);
    }
  }
  if (a3)
    gpCombatManager->ResetLimitCreature();
  memset(gpCombatManager->shouldVanish, 0, 0x28u);
  gpCombatManager->anyStacksShouldVanish = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; gpCombatManager->numCreatures[i] > j; j++) {
      if (gpCombatManager->creatures[i][j].dead)
        gpCombatManager->creatures[i][j].ProcessDeath(0);
    }
  }
  if (gpCombatManager->anyStacksShouldVanish)
    gpCombatManager->MakeCreaturesVanish();
  for (int i = 0; i < 2; i++) {
    for (int j = 0; gpCombatManager->numCreatures[i] > j; j++) {
      army *creature = &gpCombatManager->creatures[i][j];
      if (creature->damageTakenDuringSomeTimePeriod && creature->spellEnemyCreatureAbilityIsCasting == 101) {
        gpCombatManager->CastSpell((Spell)creature->spellEnemyCreatureAbilityIsCasting, creature->occupiedHex, 1, -1);
        creature->spellEnemyCreatureAbilityIsCasting = -1;
      }
      creature->probablyIsNeedDrawSpellEffect = 0;
      creature->damageTakenDuringSomeTimePeriod = 0;
      creature->hasTakenLosses = 0;
      creature->field_6 = 1;
      creature->mightBeIsAttacking = 0;
      creature->previousQuantity = -1;
    }
  }
  gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
}

void army::DamageEnemy(army *targ, int *damageDone, int *creaturesKilled, int isRanged, int isRetaliation) {
  if (!targ)
    return;

  char attackerAtk = this->creature.attack;
  if(this->effectStrengths[EFFECT_DAZE] || this->effectStrengths[EFFECT_BURN])
    attackerAtk /= 2;
  char targetDef = targ->creature.defense;
  if(targ->effectStrengths[EFFECT_DAZE] || this->effectStrengths[EFFECT_BURN])
    targetDef /= 2;

  int attackDiff = attackerAtk - targetDef;

  if (this->effectStrengths[EFFECT_DRAGON_SLAYER]
    && (targ->creatureIdx == CREATURE_GREEN_DRAGON
      || targ->creatureIdx == CREATURE_RED_DRAGON
      || targ->creatureIdx == CREATURE_BLACK_DRAGON
      || targ->creatureIdx == CREATURE_BONE_DRAGON))
    attackDiff += 5;
  if (gpCombatManager->hasMoat) {
    int othHex = -1;
    if (targ->creature.creature_flags & TWO_HEXER)
      othHex = targ->occupiedHex + ((unsigned int)(targ->facingRight - 1) < 1 ? 1 : -1);
    for (int j = 0; j < 9; ++j) {
      if (moatCell[j] == targ->occupiedHex || moatCell[j] == othHex)
        attackDiff += 3;
    }
  }

  if (attackDiff > 20)
    attackDiff = 20;
  if (attackDiff < -20)
    attackDiff = -20;

  float damagePerUnit = 0.0;
  for (int i = 0; this->quantity > i; ++i) {
    if (this->effectStrengths[EFFECT_BLESS]) {
      damagePerUnit += (double)this->creature.max_damage;
    } else if (this->effectStrengths[EFFECT_CURSE]) {
      damagePerUnit += (double)this->creature.min_damage;
    } else {
      damagePerUnit += (double)SRandom(this->creature.min_damage, this->creature.max_damage);
    }
  }
  
  damagePerUnit *= gfBattleStat[attackDiff + 20];
  if (this->creatureIdx == CREATURE_CRUSADER && HIBYTE(targ->creature.creature_flags) & ATTR_UNDEAD
    || this->creatureIdx == CREATURE_EARTH_ELEMENTAL && targ->creatureIdx == CREATURE_AIR_ELEMENTAL
    || this->creatureIdx == CREATURE_AIR_ELEMENTAL && targ->creatureIdx == CREATURE_EARTH_ELEMENTAL
    || this->creatureIdx == CREATURE_WATER_ELEMENTAL && targ->creatureIdx == CREATURE_FIRE_ELEMENTAL
    || this->creatureIdx == CREATURE_FIRE_ELEMENTAL && targ->creatureIdx == CREATURE_WATER_ELEMENTAL)
    damagePerUnit *= 2.0;

  if (this->luckStatus > 0)
    damagePerUnit *= 2.0;
  if (this->luckStatus < 0)
    damagePerUnit /= 2.0;
  this->luckStatus = 0;

  if (isRanged && gpCombatManager->ShotIsThroughWall(this->owningSide, this->occupiedHex, targ->occupiedHex))
    damagePerUnit /= 2.0;

  hero *owningHero = gpCombatManager->heroes[this->owningSide];
  if (owningHero && isRanged)
    damagePerUnit *= gfSSArcheryMod[owningHero->secondarySkillLevel[1]];
  if (this->creature.creature_flags & SHOOTER
    && !isRanged
    && this->creatureIdx != CREATURE_TITAN
    && this->creatureIdx != CREATURE_MAGE
    && this->creatureIdx != CREATURE_ARCHMAGE
    && this->creatureIdx != CREATURE_CYBER_BEHEMOTH)
    damagePerUnit /= 2.0;
  if (isRanged && targ->effectStrengths[EFFECT_SHIELD])
    damagePerUnit /= 2.0;
  if (this->otherBadLuckThing == 2)
    damagePerUnit /= 2.0;
  this->otherBadLuckThing = 0;
  if (targ->effectStrengths[EFFECT_PETRIFY])
    damagePerUnit /= 2.0;
  if (targ->effectStrengths[EFFECT_SHADOW_MARK])
	  damagePerUnit *= 1.5;

  if (CreatureHasAttribute(this->creatureIdx, JUMPER) && !isRetaliation && gIronfistExtra.combat.stack.abilityCounter[this][JUMPER] && gIronfistExtra.combat.stack.abilityNowAnimating[this][JUMPER]) {
    gIronfistExtra.combat.stack.abilityCounter[this][JUMPER] = 0;
    damagePerUnit *= SRandom(125, 150) * 0.01;
  }

  if(CreatureHasAttribute(this->creatureIdx, CHARGER)) {
    if(gCharging) {
      if(gChargePathDamage)
        damagePerUnit *= 0.5;
      else
        damagePerUnit *= 1.25;
    }
  }

  int baseDam;
  if(!gCloseMove && CreatureHasAttribute(this->creatureIdx, TELEPORTER)) {
    baseDam = (signed __int64)(damagePerUnit * 1.25 + 0.5);
  } else {
    baseDam = (signed __int64)(damagePerUnit + 0.5);
  }

  gbGenieHalf = 0;
  if (this->creatureIdx == CREATURE_GENIE) {
    if (SRandom(1, 5) == 2) {
      int tmp = targ->creature.hp * ((targ->quantity + 1) / 2);
      if (baseDam < tmp) {
        gbGenieHalf = 1;
        baseDam = tmp;
      }
    }
  }
  if (baseDam <= 0)
    baseDam = 1;
  if (HIBYTE(targ->creature.creature_flags) & ATTR_MIRROR_IMAGE)
    baseDam = -1;
  if(!isRanged && !isRetaliation) {
    if(CreatureHasAttribute(targ->creatureIdx, ASTRAL_DODGE) && gIronfistExtra.combat.stack.abilityCounter[targ][ASTRAL_DODGE]) {
        gIronfistExtra.combat.stack.abilityNowAnimating[targ][ASTRAL_DODGE] = true;
        gIronfistExtra.combat.stack.abilityCounter[targ][ASTRAL_DODGE] = 0;
        baseDam = -2;
    }
  }
  
  *damageDone = baseDam;
  if(baseDam < 0)
    *creaturesKilled = targ->Damage(0, SPELL_NONE);
  else {
    int forceShieldHP = gIronfistExtra.combat.stack.forceShieldHP[targ];
    if(forceShieldHP > 0) {
      int afterDmg = forceShieldHP - baseDam;
      if(afterDmg <= 0) {
        targ->CancelIndividualSpell(EFFECT_FORCE_SHIELD);
        baseDam = -1 * afterDmg;
      } else {
        gIronfistExtra.combat.stack.forceShieldHP[targ] -= baseDam;
        baseDam = 0;
      } 
    }
    *creaturesKilled = targ->Damage(baseDam, SPELL_NONE);
  }
}

void army::MoveTo(int hexIdx) {
  if (this->creature.creature_flags & FLYER) {
    this->targetHex = hexIdx;
    if (ValidFlight(this->targetHex, 0))
      FlyTo(this->targetHex);
  } else {
    WalkTo(hexIdx);
  }
}

bool army::TargetOnStraightLine(int targHex) {
  int deltaY = gpCombatManager->combatGrid[targHex].occupyingCreatureBottomY - gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY;
  int deltaX = gpCombatManager->combatGrid[targHex].centerX - gpCombatManager->combatGrid[this->occupiedHex].centerX;
  double angle = abs((180.0 / 3.141592653589793238463) * atan2(deltaY, abs(deltaX)));
  return angle == 0 || angle == 62.354024636261322;
}

int army::GetStraightLineDirection(int targHex) {
  int deltaY = gpCombatManager->combatGrid[targHex].occupyingCreatureBottomY - gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY;
  int deltaX = gpCombatManager->combatGrid[targHex].centerX - gpCombatManager->combatGrid[this->occupiedHex].centerX;
  double angle = (180.0 / 3.141592653589793238463) * atan2(deltaY, deltaX);
  if(angle >= -62.4 && angle <= -62.3)
    return 0;
  if(angle == 0)
    return 1;
  if(angle >= 62.3 && angle <= 62.4)
    return 2;
  if(angle >= 117.6 && angle <= 117.7)
    return 3;
  if(angle == 180)
    return 4;
  if(angle >= -117.7 && angle <= -117.6)
    return 5;
  return -1;
}

void army::MoveAttackNonFlyer(int startHex, int attackMask) {
  int attackMask2;
  if(this->effectStrengths[5])
    attackMask2 = GetAttackMask(this->occupiedHex, 2, -1);
  else
    attackMask2 = GetAttackMask(this->occupiedHex, 1, -1);
  if(attackMask2 != 0xFF || this->creature.shots <= 0) {
    if(attackMask == 0xFF) {
      AttackTo();
    } else {
      for(int i = 0; i < 8; ++i) {
        if(i < 6 || this->creature.creature_flags & TWO_HEXER) {
          int knownHex = this->occupiedHex;
          if(this->creature.creature_flags & TWO_HEXER && this->facingRight == 1 && i >= 0 && i <= 2)
            ++knownHex;
          if(this->creature.creature_flags & TWO_HEXER && !this->facingRight && i >= 3 && i <= 5)
            --knownHex;
          if(i >= 6) {
            if(this->facingRight == 1)
              ++knownHex;
            else
              --knownHex;
          }
          int adjCell = GetAdjacentCellIndex(knownHex, i);
          if(ValidHex(adjCell)
            && gpCombatManager->combatGrid[adjCell].unitOwner == this->targetOwner
            && gpCombatManager->combatGrid[adjCell].stackIdx == this->targetStackIdx)
            this->targetNeighborIdx = i;
        }
      }
      DoAttack(0);
    }
  } else {
    SpecialAttack();
  }

  if (!(this->creature.creature_flags & DEAD) &&
    CreatureHasAttribute(this->creatureIdx, STRIKE_AND_RETURN)) {
    MoveTo(startHex);
  }
}

void army::MoveAttack(int targHex, int x) {
  char targetOwner = gpCombatManager->combatGrid[targHex].unitOwner;
  char targetStack = gpCombatManager->combatGrid[targHex].stackIdx;
  gMoveAttack = false;
  // when "x" is 1 - moveattack, when "x" is 0 - just move. It doesn't apply to AI moves!
  if(x == 1 || (!x && targetOwner != -1))
    gMoveAttack = true;
  int startHex = this->occupiedHex;
  
  while(1) {
    gpCombatManager->field_F2B7 = 0;
    this->targetOwner = -1;
    this->targetStackIdx = -1;
    if(!ValidHex(targHex))
      break;
    if(targetOwner == -1 ||
      targetOwner == gpCombatManager->otherCurrentSideThing && targetStack == gpCombatManager->someSortOfStackIdx) {
      if(this->creature.creature_flags & FLYER || (CreatureHasAttribute(this->creatureIdx, CHARGER) && gMoveAttack && TargetOnStraightLine(giNextActionGridIndex) && TargetOnStraightLine(targHex))) {
        this->targetHex = targHex;
        if(!ValidFlight(this->targetHex, 0))
          return;
        FlyTo(this->targetHex);
      } else {
        WalkTo(targHex);
      }
      gpCombatManager->field_F2B7 = 1;
      return;
    }
    if(x)
      return;
    this->targetOwner = targetOwner;
    this->targetStackIdx = targetStack;
    this->targetHex = targHex;
    int attackMask = GetAttackMask(this->occupiedHex, 0, -1);
    if(!(this->creature.creature_flags & FLYER || (CreatureHasAttribute(this->creatureIdx, CHARGER) && TargetOnStraightLine(targHex))) || attackMask != 255) {
      MoveAttackNonFlyer(startHex, attackMask);
      gpCombatManager->field_F2B7 = 1;
      return;
    }
    if(this->occupiedHex != this->targetHex && !ValidFlight(this->targetHex, 0))
      return;
    if(CreatureHasAttribute(this->creatureIdx, CHARGER)) {
      if(TargetOnStraightLine(this->targetHex)) {
        FlyTo(this->targetHex);
      } else {
        MoveAttackNonFlyer(startHex, attackMask);
        gpCombatManager->field_F2B7 = 1;
        return;
      }
    } else {    
      FlyTo(this->targetHex);
    }
  }
}

void army::DecrementSpellRounds() {
  for (int effect = 0; effect < NUM_SPELL_EFFECTS; ++effect) {
    if (this->effectStrengths[effect]) {
      if(effect == EFFECT_FORCE_SHIELD)
        continue;
      if(effect == EFFECT_BURN)
        gpCombatManager->BurnCreature(this);
      if (this->effectStrengths[effect] == 1)
        this->CancelIndividualSpell(effect);
      else
        this->effectStrengths[effect]--;
    }
  }
  if (this->lifespan > 0)
    this->lifespan--;
}

int army::AddActiveEffect(int effectType, int strength) {
  ++this->numActiveEffects;
  this->effectStrengths[effectType] = strength;
  return 1;
}

signed int army::SetSpellInfluence(int effectType, signed int strength) {
  signed int result;
  int effect;

  if (this->effectStrengths[effectType]) {
    if (this->effectStrengths[effectType] < strength)
      this->effectStrengths[effectType] = strength;
    return 0;
  } else {
    switch (effectType) {
    case EFFECT_HASTE:
      this->CancelIndividualSpell(EFFECT_SLOW);
      this->creature.speed += 2;
      this->frameInfo.stepTime = (signed __int64)((double)this->frameInfo.stepTime * 0.65);
      break;
    case EFFECT_SLOW:
      this->CancelIndividualSpell(EFFECT_HASTE);
      this->creature.speed = (this->creature.speed + 1) / 2;
      if (this->creature.creature_flags & FLYER)
        this->creature.creature_flags -= FLYER;
      this->frameInfo.stepTime = (signed __int64)((double)this->frameInfo.stepTime * 1.5);
      break;
    case EFFECT_BLESS:
      this->CancelIndividualSpell(EFFECT_CURSE);
      break;
    case EFFECT_CURSE:
      this->CancelIndividualSpell(EFFECT_BLESS);
      break;
    case EFFECT_BERSERKER:
      this->CancelIndividualSpell(EFFECT_HYPNOTIZE);
      break;
    case EFFECT_HYPNOTIZE:
      this->CancelIndividualSpell(EFFECT_BERSERKER);
      break;
    case EFFECT_BLOOD_LUST:
      this->creature.attack += 3;
      break;
    case EFFECT_ANTI_MAGIC:
      for (effect = 0; (signed int)effect < 15; ++effect)
        this->CancelIndividualSpell(effect);
      break;
    case EFFECT_STONESKIN:
      if (this->effectStrengths[EFFECT_STEELSKIN]) {
        return 0;
      } else {
        this->creature.defense += 3;
        break;
      }
    case EFFECT_STEELSKIN:
      this->CancelIndividualSpell(EFFECT_STONESKIN);
      this->creature.defense += 5;
      break;
    case EFFECT_BLIND:
    case EFFECT_PARALYZE:
    case EFFECT_DRAGON_SLAYER:
    case EFFECT_SHIELD:
    case EFFECT_PETRIFY:
      break;
    case EFFECT_SHADOW_MARK:
    case EFFECT_DAZE:
    case EFFECT_BURN:
      break;
    case EFFECT_FORCE_SHIELD:
      gIronfistExtra.combat.stack.forceShieldHP[this] = gMonsterDatabase[this->creatureIdx].hp;
      break;
    }
    return this->AddActiveEffect(effectType, strength);
  }
}

void army::CancelIndividualSpell(int effect) {
  if (this->effectStrengths[effect]) {
    --this->numActiveEffects;
    this->effectStrengths[effect] = 0;
    switch (effect) {
    case EFFECT_HASTE:
    case EFFECT_SLOW:
      this->creature.speed = LOBYTE(this->speed);
      this->frameInfo.stepTime = this->field_B2;
      this->creature.creature_flags |= gMonsterDatabase[this->creatureIdx].creature_flags & FLYER;
      break;
    case EFFECT_BLOOD_LUST:
      this->creature.attack -= 3;
      break;
    case EFFECT_STONESKIN:
      this->creature.defense -= 3;
      break;
    case EFFECT_STEELSKIN:
      this->creature.defense -= 5;
      break;
    case EFFECT_SHADOW_MARK:
    case EFFECT_DAZE:
    case EFFECT_BURN:
      break;
    case EFFECT_FORCE_SHIELD:
      gIronfistExtra.combat.stack.forceShieldHP[this] = 0;
      break;
    case EFFECT_BLIND:
    case EFFECT_BLESS:
    case EFFECT_CURSE:
    case EFFECT_BERSERKER:
    case EFFECT_PARALYZE:
    case EFFECT_HYPNOTIZE:
    case EFFECT_DRAGON_SLAYER:
    case EFFECT_SHIELD:
    case EFFECT_PETRIFY:
    case EFFECT_ANTI_MAGIC:
      return;
    }
  }
}

extern std::vector<std::string> ironfistAttributeNames;
void army::Init(int creatureIdx, int quantity, int owner, int stackIdx, int startHex, int armyIdx) {
    Init_orig(creatureIdx, quantity, owner, stackIdx, startHex, armyIdx);
    for(auto &i : ironfistAttributeNames) {
      if(CreatureHasAttribute(this->creatureIdx, i))
        gIronfistExtra.combat.stack.abilityCounter[this][i] = 1;
    }
}

void army::InitClean() {
  for (int i = 0; i < 7; ++i)
    this->combatSounds[i] = 0;
  this->lifespan = -1;
  this->numActiveEffects = 0;
  for(int i = 0; i <  NUM_SPELL_EFFECTS; i++) {
    this->effectStrengths[i] = 0;
  }
  this->baseFidgetTime = KBTickCount();
  this->field_11D = 1;
  this->creatureIcon = 0;
  this->probablyIsNeedDrawSpellEffect = 0;
  this->spellEnemyCreatureAbilityIsCasting = -1;
  this->mirroredIdx = -1;
  this->mirrorIdx = -1;
  this->armyIdx = -1;
  this->previousQuantity = -1;
  for(auto &i : ironfistAttributeNames) {
      if(CreatureHasAttribute(this->creatureIdx, i))
        gIronfistExtra.combat.stack.abilityCounter[this][i] = 1;
    }
}

bool army::FlightThroughObstacles(int toHex) {
  double x1, x2, y1, y2, dx, dy;
  x1 = this->MidX();
  y1 = this->MidY();
  x2 = gpCombatManager->combatGrid[toHex].centerX;
  y2 = gpCombatManager->combatGrid[toHex].occupyingCreatureBottomY;
  dx = x2 - x1;
  dy = y2 - y1;
  int x = x1;
  int endX = x2;
  if(x1 > x2) {
    x = x2;
    endX = x1;
  }
  while(x < endX) {
    int y = y1 + dy * (x - x1) / dx;
    int cellIndex = gpCombatManager->GetGridIndex(x, y);
    if(gpCombatManager->combatGrid[cellIndex].isBlocked)
      return true;
    x++;
  }
  return false;
}

bool army::IsEnemyCreatureHex(int hex) {
  return (gpCombatManager->combatGrid[hex].stackIdx != -1) &&
    (gpCombatManager->combatGrid[hex].unitOwner != this->owningSide);
}

int army::GetStraightLineDistanceToHex(int hex) {
  int dir = this->GetStraightLineDirection(hex);
  if(dir == -1)
    return 999;
  int tempHex = this->occupiedHex;
  int distance = 0;
  while(tempHex != hex) {
    tempHex = this->GetAdjacentCellIndex(tempHex, dir);
    distance++;
    if(tempHex > 113 || tempHex < 0) {
      return 999;
    }
  }
  return distance;
}

void army::DrawToBuffer(int centX, int standingBotY, int a4) {
  if(!(!gpCombatManager->field_F357 && !gbNoShowCombat))
    return;

  int x = this->xDrawOffset + centX;
  int y = this->yDrawOffset + standingBotY;
  if(this->animationType == ANIMATION_TYPE_WALKING && !(this->creature.creature_flags & FLYER)) {
    int walkLen = this->frameInfo.animationLengths[this->animationType];
    int offsetYExtra = 42 * this->animationFrame / walkLen;
    int offsetXExtra = 22 * this->animationFrame / walkLen;
    if(!this->field_8A || this->field_8A == 5) {
      y -= offsetYExtra;
      giWalkingYMod = -offsetYExtra;
    }
    if(this->field_8A == 2 || this->field_8A == 3) {
      y += offsetYExtra;
      giWalkingYMod = offsetYExtra;
    }
    if(!this->field_8A || this->field_8A == 2)
      x -= offsetXExtra;
    if(this->field_8A == 5 || this->field_8A == 3)
      x += offsetXExtra;
  }

  bool isIdle = false;
  if(this->animationType == ANIMATION_TYPE_STANDING || this->animationType >= ANIMATION_TYPE_FIDGET_1 && this->animationType <= ANIMATION_TYPE_FIDGET_5)
    isIdle = true;

  int unknown = 0;
  if(!giSpellEffectShowType && isIdle && this->numActiveEffects > 0)
    unknown = 237;
  if(this->occupiedHex == gpCombatManager->field_F2BB && gpCombatManager->field_F2B7 == 1)
    unknown = 236;

  unsigned char *paletteSubstitution = nullptr;
  if(this->effectStrengths[EFFECT_PETRIFY])
    paletteSubstitution = gColorTableGray;
  else if(HIBYTE(this->creature.creature_flags) & ATTR_BLOODLUST_RED)
    paletteSubstitution = gColorTableRed;
  else if(HIBYTE(this->creature.creature_flags) & ATTR_BROWN)
    paletteSubstitution = gColorTableDarkBrown;
  else if(HIBYTE(this->creature.creature_flags) & ATTR_PETRIFY_GRAY)
    paletteSubstitution = gColorTableGray;
  else if(HIBYTE(this->creature.creature_flags) & ATTR_MIRROR_IMAGE)
    paletteSubstitution = gColorTableLighten;

  if(!a4)
    this->creatureIcon->CombatClipDrawToBuffer(
      x,
      y,
      this->frameInfo.animationFrameToImgIdx[this->animationType][this->animationFrame],
      &this->bounds,
      this->facingRight < 1,
      unknown,
      paletteSubstitution,
      (signed char*)this->field_125);

  if(isIdle && gpCombatManager->field_F2BF && this->field_4E) {
    int hexInFront;
    int stackNumXOffset;
    if(this->creature.creature_flags & TWO_HEXER) {
      if(this->facingRight == 1) {
        stackNumXOffset = x + 53;
        hexInFront = this->occupiedHex + 2;
      } else {
        stackNumXOffset = x - 73;
        hexInFront = this->occupiedHex - 2;
      }
    } else if(this->facingRight == 1) {
      stackNumXOffset = x + 9;
      hexInFront = this->occupiedHex + 1;
    } else {
      stackNumXOffset = x - 29;
      hexInFront = this->occupiedHex - 1;
    }
    bool hexInFrontClear = gpCombatManager->combatGrid[hexInFront].unitOwner != -1;
    int creatureStackNumXOffset = this->frameInfo.stackNumDispXShift[1 - this->facingRight];
    if(hexInFrontClear && creatureStackNumXOffset > 0)
      creatureStackNumXOffset = 0;
    if(this->facingRight == 1)
      stackNumXOffset += creatureStackNumXOffset;
    else
      stackNumXOffset -= creatureStackNumXOffset;

    int offsetY;
    if(this->facingRight == 1)
      offsetY = y - 11;
    else
      offsetY = y - 23;
    int numPosEffects = 0;
    int numNegEffects = 0;
    for(int i = 0; i < NUM_SPELL_EFFECTS; i++) {
      if(this->effectStrengths[i]) {
        switch(i) {
          case EFFECT_HASTE:
          case EFFECT_BLESS:
          case EFFECT_DRAGON_SLAYER:
          case EFFECT_BLOOD_LUST:
          case EFFECT_SHIELD:
          case EFFECT_ANTI_MAGIC:
          case EFFECT_STONESKIN:
          case EFFECT_STEELSKIN:
          case EFFECT_FORCE_SHIELD:
            ++numPosEffects;
            break;
          default:
            ++numNegEffects;
            break;
        }
      }
    }

    int inRedrawZone;
    if(giSpellEffectShowType && isIdle && this->numActiveEffects > 0) {
      if(giSpellEffectShowType == 1) {
        inRedrawZone = gpCombatManager->combatScreenIcons[COMBAT_ICON_IDX_TEXTBAR]->CombatClipDrawToBuffer(stackNumXOffset, offsetY, 11, &this->stackSizeDispBounds, 0, 237, 0, 0);
      } else {
        int numImageIdx = 12;
        if(numPosEffects <= 0 || numNegEffects <= 0) {
          if(numNegEffects > 0)
            numImageIdx = 14;
        } else {
          numImageIdx = 13;
        }
        inRedrawZone = gpCombatManager->combatScreenIcons[COMBAT_ICON_IDX_TEXTBAR]->CombatClipDrawToBuffer(stackNumXOffset, offsetY, numImageIdx, &this->stackSizeDispBounds, 0, 0, 0, 0);
      }
    } else {
      inRedrawZone = gpCombatManager->combatScreenIcons[COMBAT_ICON_IDX_TEXTBAR]->CombatClipDrawToBuffer(stackNumXOffset, offsetY, 10, &this->stackSizeDispBounds, 0, 0, 0, 0);
    }
    if(gIronfistExtra.combat.stack.forceShieldHP[this] > 0) {
      const int FORCE_SHIELD_ICON_X_OFFSET = 2;
      const int FORCE_SHIELD_ICON_Y_OFFSET = -28;
      const int FORCE_SHIELD_HP_BOX_Y_OFFSET = -24;

      icon* shieldIcon = gpResourceManager->GetIcon("SPELLINF.ICN");
      shieldIcon->CombatClipDrawToBuffer(stackNumXOffset + FORCE_SHIELD_ICON_X_OFFSET, offsetY + FORCE_SHIELD_ICON_Y_OFFSET, 10, &this->stackSizeDispBounds, 0, 0, gColorTableRed, 0);

      std::string str = std::to_string(gIronfistExtra.combat.stack.forceShieldHP[this]);
      smallFont->DrawBoundedString((char*)str.c_str(), stackNumXOffset, offsetY + FORCE_SHIELD_HP_BOX_Y_OFFSET + 2, 20, 12, 1, 1);
    }

    if(inRedrawZone) {
      int quantity;
      if(this->previousQuantity == -1)
        quantity = this->quantity;
      else
        quantity = this->previousQuantity;
      std::string str = std::to_string(quantity);
      smallFont->DrawBoundedString((char*)str.c_str(), stackNumXOffset, offsetY + 2, 20, 12, 1, 1);
    }
  }

  if(this->probablyIsNeedDrawSpellEffect && !a4) {
    int offsetX = x;
    if(this->animationType == ANIMATION_TYPE_WINCE || this->animationType == ANIMATION_TYPE_WINCE_RETURN) {
      if(this->facingRight == 1)
        offsetX -= 4;
      else
        offsetX += 4;
    }
    if(this->creature.creature_flags & TWO_HEXER) {
      if(this->facingRight == 1)
        offsetX += 22;
      else
        offsetX -= 22;
    }
    if(gCurLoadedSpellEffect == ANIM_SHIELD_IDX) {
      if(this->facingRight == 1)
        offsetX = this->RightX();
      else
        offsetX = this->LeftX();
    }

    int spellOffsetYExtra = this->GetPowBaseY();
    if(gCurLoadedSpellEffect == ANIM_BLIND_IDX) {
       if(this->facingRight == 1)
          offsetX = x + this->frameInfo.offsetForBlind[0];
       else
          offsetX = x + this->frameInfo.offsetForBlind[0] * -1;
      spellOffsetYExtra = y + this->frameInfo.offsetForBlind[1];
    }
    gCurLoadedSpellIcon->CombatClipDrawToBuffer(offsetX, spellOffsetYExtra + this->field_FA, gCurSpellEffectFrame, &this->effectAnimationBounds, 1 - this->facingRight, 0, 0, 0);
  }
}
