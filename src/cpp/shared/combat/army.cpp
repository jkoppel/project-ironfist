#include "artifacts.h"
#include "combat/army.h"
#include "combat/combat.h"
#include "resource/resourceManager.h"
#include "scripting/callback.h"
#include "sound/sound.h"
#include "spell/spells.h"
#include "expansions.h"

extern ironfistExtra gIronfistExtra;

extern char *cMonFilename[]; // it's inside creature.cpp
extern char *cArmyFrameFileNames[]; // it's inside creature.cpp
extern char *cArmyProjectileFileNames[]; // it's inside creature.cpp
extern icon *gCurLoadedSpellIcon;
extern int gCurLoadedSpellEffect;
extern int gCurSpellEffectFrame;
extern int gbGenieHalf;
extern int gbRemoteOn;
extern int giWalkingFrom;
extern int giWalkingFrom2;
extern int giWalkingTo;
extern int giWalkingTo2;
extern int giWalkingYMod;
extern int gbComputeExtent;
extern int gbSaveBiggestExtent;
extern int gbReturnAfterComputeExtent;
extern int gbCurrArmyDrawn;
extern int gbLimitToExtent;
extern unsigned __int8 moatCell[];
extern float gfBattleStat[];
extern float gfSSArcheryMod[];

bool gCloseMove; // ironfist var to differentiate between close/from a distance attack

char *gCombatFxNames[34] =
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
  "shdwmark.icn"
};

unsigned __int8 giNumPowFrames[34] =
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
  if (creaturesKilled <= 1)
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

void army::DoAttack(int isRetaliation) {
  army* primaryTarget = &gpCombatManager->creatures[gpCombatManager->combatGrid[targetHex].unitOwner][gpCombatManager->combatGrid[targetHex].stackIdx];
  if (gpCombatManager->combatGrid[targetHex].unitOwner < 0 || gpCombatManager->combatGrid[targetHex].stackIdx < 0)
    primaryTarget = this;
  ScriptCallback("OnBattleMeleeAttack", this, primaryTarget, isRetaliation);

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

    if(gIronfistExtra.combat.stack.abilityNowAnimating[primaryTarget]) {
        if(primaryTarget->creatureIdx == CREATURE_CYBER_SHADOW_ASSASSIN) { // astral dodge animations
            int dodgeAnimLen = 7;
            primaryTarget->frameInfo.animationLengths[ANIMATION_TYPE_WINCE] = dodgeAnimLen;
            for (int p = 0; p < dodgeAnimLen; p++) {
              primaryTarget->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_WINCE][p] = 34 + p;
            }

            this->PowEffect(-1, 0, -1, -1);

            // revert to usual animations after the first received attack
            int winceAnimLen = 1;
            primaryTarget->frameInfo.animationLengths[ANIMATION_TYPE_WINCE] = winceAnimLen;
            primaryTarget->frameInfo.animationFrameToImgIdx[ANIMATION_TYPE_WINCE][0] = 50;            
            gIronfistExtra.combat.stack.abilityNowAnimating[primaryTarget] = false;
        }
    } else {
      this->PowEffect(-1, 0, -1, -1);
    }
    
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
    gbComputeExtent = 1;
    gbSaveBiggestExtent = 1;
    gbReturnAfterComputeExtent = 1;
    this->DrawToBuffer(gpCombatManager->combatGrid[this->occupiedHex].centerX, gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY, 0);
    gbReturnAfterComputeExtent = 0;
    gbSaveBiggestExtent = 0;
    gbComputeExtent = 0;
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
      gbComputeExtent = 1;
      gbSaveBiggestExtent = 1;
      gbReturnAfterComputeExtent = 1;
      this->DrawToBuffer(
        gpCombatManager->combatGrid[this->occupiedHex].centerX,
        gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY,
        0);
      gbReturnAfterComputeExtent = 0;
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
        } else
          BuildTempWalkSeq(&this->frameInfo, i + 1 == numFrames, i > 0);

        int startMoveLen = 0;
        int moveLen = 0;
        int moveAndSubEndMoveLen;
        if (numFrames) {
          if (i <= 0 && (!closeMove && teleporter))
            startMoveLen = this->frameInfo.animationLengths[ANIMATION_TYPE_START_MOVE];
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
    gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    gpCombatManager->TestRaiseDoor();
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

  int targMidX = target->MidX();
  int targMidY = target->MidY();
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
  int totXDiff = targMidX - projStartX;
  char firingLeft = 0;
  if (targMidX - projStartX < 0) {
    firingLeft = 1;
    totXDiff = -totXDiff;
  }
  int yDiff = targMidY - projStartY;

  float angleDeg;
  int spriteIdx;
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

  int attackDirectionAnimationIdx;
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
  for (attacker->animationFrame = 0;
    attacker->frameInfo.animationLengths[attacker->animationType] > attacker->animationFrame;
    ++attacker->animationFrame) {
    if (attacker->frameInfo.animationLengths[attacker->animationType] - 1 == attacker->animationFrame)
      gpCombatManager->DrawFrame(0, 1, 0, 0, 75, 1, 1);
    else
      gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 1, 1);
    glTimers = (signed __int64)((double)KBTickCount()
      + (double)attacker->frameInfo.shootingTime
      * gfCombatSpeedMod[giCombatSpeed]
      / (double)attacker->frameInfo.animationLengths[attacker->animationType]);
  }
  attacker->animationFrame = attacker->frameInfo.animationLengths[attacker->animationType] - 1;
  int projIconWidth = 100;
  int projIconHeight = 100;
  int v35 = 31;
  int v22 = 25;

  int v20 = 0;
  int offsetX = 639;
  int v15 = 0;
  int offsetY = 479;
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
  int v52 = (distance + (v35 / 2)) / v35;

  if (attacker->creatureIdx == CREATURE_MAGE || attacker->creatureIdx == CREATURE_ARCHMAGE) {
    gpWindowManager->UpdateScreenRegion(giMinExtentX, giMinExtentY, giMaxExtentX - giMinExtentX + 1, giMaxExtentY - giMinExtentY + 1);
    DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 115.0));
    gpCombatManager->DoBolt(1, startX, startY, endX, endY, 0, 0, 5, 4, 302, 0, 0, distance / 15 + 15, 1, 0, 10, 0);
  } else if (attacker->creatureIdx == CREATURE_CYBER_BEHEMOTH) {
    gpCombatManager->ArcShot(attacker->missileIcon, startX, startY, endX, endY);
  } else {
    int v37;
    int v43;
    if (v52 <= 1) {
      v43 = diffX;
      v37 = diffY;
    } else {
      v43 = diffX / (v52 - 1);
      v37 = diffY / (v52 - 1);
    }
    int v44 = startX;
    int v38 = startY;
    //from = (bitmap *)operator new(26);
    bitmap *from = nullptr;
    from = new bitmap(33, 2 * projIconWidth, 2 * projIconHeight);
    from->GrabBitmapCareful(gpWindowManager->screenBuffer, v44 - projIconWidth, v38 - projIconHeight);
    int v59 = v44;
    int v53 = v38;
    int x = 0;
    int y = 0;
    for (int i = 0; i < v52; ++i) {
      if (v59 - projIconWidth < offsetX)
        offsetX = v59 - projIconWidth;
      if (offsetX < 0)
        offsetX = 0;
      if (projIconWidth + v59 > v20)
        v20 = projIconWidth + v59;
      if (v20 > 639)
        v20 = 639;
      if (v53 - projIconHeight < offsetY)
        offsetY = v53 - projIconHeight;
      if (offsetY < 0)
        offsetY = 0;
      if (projIconHeight + v53 > v15)
        v15 = projIconHeight + v53;
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
      x = v44 - projIconWidth;
      if (v44 - projIconWidth < 0)
        x = 0;
      if (x + (signed int)from->width > 640)
        x = 640 - from->width;
      y = v38 - projIconHeight;
      if (v38 - projIconHeight < 0)
        y = 0;
      if (y + (signed int)from->height > 640)
        y = 640 - from->height;
      from->GrabBitmapCareful(gpWindowManager->screenBuffer, x, y);
      attacker->missileIcon->DrawToBuffer(v44, v38, spriteIdx, firingLeft);
      if (i) {
        DelayTil(&glTimers);
        gpWindowManager->UpdateScreenRegion(offsetX, offsetY, v20 - offsetX + 1, v15 - offsetY + 1);
      } else {
        gpWindowManager->UpdateScreenRegion(giMinExtentX, giMinExtentY, giMaxExtentX - giMinExtentX + 1, giMaxExtentY - giMinExtentY + 1);
      }

      glTimers = (signed __int64)((double)KBTickCount() + (double)v22 * gfCombatSpeedMod[giCombatSpeed]);
      v59 = v44;
      v53 = v38;
      v44 += v43;
      v38 += v37;
      offsetX = v44 - projIconWidth;
      v20 = projIconWidth + v44;
      offsetY = v38 - projIconHeight;
      v15 = projIconHeight + v38;
    }
    from->DrawToBuffer(x, y);
    gpWindowManager->UpdateScreenRegion(v59 - projIconWidth, v53 - projIconHeight, 2 * projIconWidth, 2 * projIconHeight);
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
      creature->effectStrengths[15] = 0;
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
          && !creature->effectStrengths[15]
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
                  creature->effectStrengths[15] = 1;
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

  int attackDiff = this->creature.attack - targ->creature.defense;
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
    if(CreatureHasAttribute(targ->creatureIdx, ASTRAL_DODGE) && gIronfistExtra.combat.stack.abilityCounter[targ]) {
        gIronfistExtra.combat.stack.abilityNowAnimating[targ] = true;
        gIronfistExtra.combat.stack.abilityCounter[targ] = 0;
        baseDam = -2;
    }
  }
  
  *damageDone = baseDam;
  *creaturesKilled = targ->Damage(baseDam, SPELL_NONE);
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

void army::MoveAttack(int targHex, int x) {
  int startHex = this->occupiedHex;
  this->MoveAttack_orig(targHex, x);

  if (!(this->creature.creature_flags & DEAD) &&
    CreatureHasAttribute(this->creatureIdx, STRIKE_AND_RETURN)) {
    MoveTo(startHex);
  }
}

void army::DecrementSpellRounds() {
  for (int effect = 0; effect < NUM_SPELL_EFFECTS; ++effect) {
    if (this->effectStrengths[effect]) {
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
  __int64 v4;
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
      this->CancelIndividualSpell(0);
      v4 = (signed int)this->creature.speed + 1;
      this->creature.speed = ((signed int)v4 - v4) >> 1;
      if (this->creature.creature_flags & 2)
        this->creature.creature_flags -= 2;
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

void army::Init(int creatureIdx, int quantity, int owner, int stackIdx, int startHex, int armyIdx) {
    Init_orig(creatureIdx, quantity, owner, stackIdx, startHex, armyIdx);
    if(CreatureHasAttribute(this->creatureIdx, ASTRAL_DODGE))
        gIronfistExtra.combat.stack.abilityCounter[this] = 1;
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
  if(CreatureHasAttribute(this->creatureIdx, ASTRAL_DODGE))
    gIronfistExtra.combat.stack.abilityCounter[this] = 1;
}