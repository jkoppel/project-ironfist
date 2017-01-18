#include "artifacts.h"
#include "combat/army.h"
#include "combat/combat.h"
#include "resource/resourceManager.h"
#include "scripting/callback.h"
#include "sound/sound.h"
#include "spells.h"

extern char *cMonFilename[]; // it's inside creature.cpp
extern char *cArmyFrameFileNames[]; // it's inside creature.cpp
extern char *cArmyProjectileFileNames[]; // it's inside creature.cpp
extern icon *gCurLoadedSpellIcon;
extern int gCurLoadedSpellEffect;
extern int gCurSpellEffectFrame;

extern bool gCloseMove;

char *gCombatFxNames[33] =
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
  "plasmblast.icn"
};

unsigned __int8 giNumPowFrames[33] =
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
  7u
};

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

extern int gbGenieHalf;
extern int gbRemoteOn;

void DoAttackBattleMessage(army *attacker, army *target, int creaturesKilled, int damageDone) {
  char *attackingCreature;
  if (attacker->quantity <= 1)
    attackingCreature = GetCreatureName(attacker->creatureIdx);
  else
    attackingCreature = GetCreaturePluralName(attacker->creatureIdx);

  if (damageDone == -1) {
    sprintf(gText, "The mirror image is destroyed!");
  } else if (gbGenieHalf) {
    sprintf(gText, "%s %s half the enemy troops!", attackingCreature, (attacker->quantity > 1) ? "damage" : "damages");
  } else if (creaturesKilled <= 0) {
    sprintf(gText, "%s %s %d damage.", attackingCreature, (attacker->quantity > 1) ? "do" : "does", damageDone);
    gText[0] = toupper(gText[0]);
  } else {
    char *targetCreature;
    if (creaturesKilled <= 1)
      targetCreature = GetCreatureName(target->creatureIdx);
    else
      targetCreature = GetCreaturePluralName(target->creatureIdx);
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
    int v18 = this->targetNeighborIdx;
    int targetHex = this->occupiedHex;
    if (this->creature.creature_flags & TWO_HEXER
      && (!this->facingRight && this->targetNeighborIdx >= 3
        || this->facingRight == 1 && (this->targetNeighborIdx <= 2 || this->targetNeighborIdx >= 6))) {
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
      if (primaryTarget->facingRight != targetOldFacingRight && primaryTarget->creature.creature_flags & TWO_HEXER) {
        if (primaryTarget->facingRight == 1)
          --primaryTarget->occupiedHex;
        else
          ++primaryTarget->occupiedHex;
      }
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
    int damageDone = 0;
    this->DamageEnemy(primaryTarget, &damDone, (int *)&creaturesKilled, 0, 0);
    int v13 = 0; // unused
    if (secondHexTarget)
      this->DamageEnemy(secondHexTarget, &damageDone, &v13, 0, 0);

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
      case CREATURE_MUMMY:
        if (SRandom(1, 100) < 20)
          goto LABEL_97;
        break;
      case CREATURE_ROYAL_MUMMY:
        if (SRandom(1, 100) < 30) {
        LABEL_97:
          if (primaryTarget && primaryTarget->SpellCastWorks(SPELL_CURSE))
            primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_CURSE;
        }
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
      case CREATURE_SPRITE:
      case CREATURE_DWARF:
      case CREATURE_BATTLE_DWARF:
      case CREATURE_ELF:
      case CREATURE_GRAND_ELF:
      case CREATURE_DRUID:
      case CREATURE_GREATER_DRUID:
      case CREATURE_PHOENIX:
      case CREATURE_CENTAUR:
      case CREATURE_GARGOYLE:
      case CREATURE_GRIFFIN:
      case CREATURE_MINOTAUR:
      case CREATURE_MINOTAUR_KING:
      case CREATURE_HYDRA:
      case CREATURE_GREEN_DRAGON:
      case CREATURE_RED_DRAGON:
      case CREATURE_BLACK_DRAGON:
      case CREATURE_HALFLING:
      case CREATURE_BOAR:
      case CREATURE_IRON_GOLEM:
      case CREATURE_STEEL_GOLEM:
      case CREATURE_ROC:
      case CREATURE_MAGE:
      case CREATURE_GIANT:
      case CREATURE_TITAN:
      case CREATURE_SKELETON:
      case CREATURE_ZOMBIE:
      case CREATURE_MUTANT_ZOMBIE:
      case CREATURE_VAMPIRE:
      case CREATURE_LICH:
      case CREATURE_POWER_LICH:
      case CREATURE_BONE_DRAGON:
      case CREATURE_ROGUE:
      case CREATURE_NOMAD:
      case CREATURE_GENIE:
        break;
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
      && !primaryTarget->effectStrengths[6]
      && !primaryTarget->effectStrengths[11]
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
      && !this->effectStrengths[6]
      && !this->effectStrengths[11]
      && !this->effectStrengths[2]
      && this->quantity > 0) {
      DelayMilli((signed __int64)(gfCombatSpeedMod[giCombatSpeed] * 100.0));
      int v16 = this->targetNeighborIdx;
      this->targetNeighborIdx = v18;
      this->DoAttack(1);
      this->targetNeighborIdx = v16;
    }
    if (this->facingRight != oldFacingRight) {
      if (!(this->creature.creature_flags & DEAD)) {
        this->facingRight = oldFacingRight;
        if (this->creature.creature_flags & TWO_HEXER) {
          if (oldFacingRight == 1)
            --this->occupiedHex;
          else
            ++this->occupiedHex;
        }
      }
      if (!(primaryTarget->creature.creature_flags & DEAD)) {
        if (primaryTarget->facingRight != targetOldFacingRight) {
          primaryTarget->facingRight = targetOldFacingRight;
          if (primaryTarget->creature.creature_flags & TWO_HEXER) {
            if (primaryTarget->facingRight == 1)
              --primaryTarget->occupiedHex;
            else
              ++primaryTarget->occupiedHex;
          }
        }
      }
    }
  }
  if (!isRetaliation && (this->effectStrengths[5] || this->effectStrengths[7])) {
    this->CancelSpellType(1);
    gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
  }
  this->targetOwner = -1;
  if (isRetaliation)
    gpCombatManager->currentActionSide = 1 - gpCombatManager->currentActionSide;
}

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

void army::Walk(signed int dir, int last, int notFirst) { 
  int v4; // ST3C_4@78
  int v6; // [sp+1Ch] [bp-24h]@26
  int v7; // [sp+20h] [bp-20h]@80
  int i; // [sp+24h] [bp-1Ch]@47
  int v9; // [sp+28h] [bp-18h]@77
  signed int targCell; // [sp+30h] [bp-10h]@1
  int offsetY; // [sp+34h] [bp-Ch]@26
  int v12; // [sp+38h] [bp-8h]@26
  int offsetX; // [sp+3Ch] [bp-4h]@26

  targCell = this->GetAdjacentCellIndex(this->occupiedHex, dir);
  gCloseMove = IsCloseMove(targCell);
  if (this->owningSide == 1
    && gpCombatManager->isCastleBattle
    && (targCell == 58 || targCell == 59 || targCell == 60 && this->owningSide == 1 && this->creature.creature_flags & 1)
    && gpCombatManager->drawBridgePosition == BRIDGE_CLOSED) {
    this->animationType = ANIMATION_TYPE_STANDING;
    this->animationFrame = 0;
    gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    gpCombatManager->LowerDoor();
    notFirst = 0;
  }
  giWalkingFrom = this->occupiedHex;
  if (this->creature.creature_flags & 1)
    giWalkingFrom2 = this->occupiedHex + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
  else
    giWalkingFrom2 = -1;
  giWalkingTo = targCell;
  if (this->creature.creature_flags & 1)
    giWalkingTo2 = targCell + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
  else
    giWalkingTo2 = -1;
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
  offsetX = giMinExtentX;
  offsetY = giMinExtentY;
  v12 = giMaxExtentX;
  v6 = giMaxExtentY;
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
  this->animationType = 6;
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
    for (i = 0; this->frameInfo.animationLengths[6] > i; ++i) {
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
  v9 = this->GetAdjacentCellIndex(this->occupiedHex, dir);
  gpCombatManager->combatGrid[this->occupiedHex].stackIdx = -1;
  gpCombatManager->combatGrid[this->occupiedHex].unitOwner = -1;
  gpCombatManager->combatGrid[this->occupiedHex].occupiersOtherHexIsToLeft = -1;
  if (this->creature.creature_flags & 1) {
    v4 = this->occupiedHex + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
    gpCombatManager->combatGrid[v4].stackIdx = -1;
    gpCombatManager->combatGrid[v4].unitOwner = -1;
    gpCombatManager->combatGrid[v4].occupiersOtherHexIsToLeft = -1;
  }
  gpCombatManager->combatGrid[v9].unitOwner = LOBYTE(this->owningSide);
  gpCombatManager->combatGrid[v9].stackIdx = LOBYTE(this->stackIdx);
  gpCombatManager->combatGrid[v9].occupiersOtherHexIsToLeft = -1;
  if (this->creature.creature_flags & 1) {
    v7 = v9 + ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
    gpCombatManager->combatGrid[v7].unitOwner = LOBYTE(this->owningSide);
    gpCombatManager->combatGrid[v7].stackIdx = LOBYTE(this->stackIdx);
    gpCombatManager->combatGrid[v7].occupiersOtherHexIsToLeft = v9 <= v7;
    gpCombatManager->combatGrid[v9].occupiersOtherHexIsToLeft = v9 >= v7;
  }
  this->occupiedHex = v9;
  if (this->field_8E) {
    this->facingRight = 1 - this->facingRight;
    if (this->creature.creature_flags & TWO_HEXER) {
      if (this->facingRight)
        --this->occupiedHex;
      else
        ++this->occupiedHex;
    }
    this->field_8E = 0;
  }
  giWalkingFrom = -1;
  giWalkingFrom2 = -1;
  giWalkingTo = -1;
  giWalkingTo2 = -1;
  this->field_6 = 1;
  if (last == 1) {
    this->animationType = 7;
    this->animationFrame = 0;
    gpCombatManager->DrawFrame(1, 1, 0, 0, 75, 1, 1);
  }
}


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
  signed int result; // eax@2
  int v3; // ST98_4@19
  signed int v5; // [sp+64h] [bp-70h]@76
  signed int v6; // [sp+68h] [bp-6Ch]@47
  int v7; // [sp+6Ch] [bp-68h]@21
  int v8; // [sp+70h] [bp-64h]@24
  int offsetY; // [sp+74h] [bp-60h]@47
  signed int v10; // [sp+78h] [bp-5Ch]@47
  int offsetX; // [sp+7Ch] [bp-58h]@47
  signed int v12; // [sp+80h] [bp-54h]@24
  int dist; // [sp+8Ch] [bp-48h]@14
  signed int v14; // [sp+90h] [bp-44h]@14
  int deltaY; // [sp+94h] [bp-40h]@14
  float v16; // [sp+98h] [bp-3Ch]@18
  int i; // [sp+A0h] [bp-34h]@21
  int colDiff; // [sp+A4h] [bp-30h]@3
  signed int v19; // [sp+A8h] [bp-2Ch]@14
  int deltaX; // [sp+ACh] [bp-28h]@14
  int numFrames; // [sp+BCh] [bp-18h]@14
  float v22; // [sp+C4h] [bp-10h]@14
  float v23; // [sp+CCh] [bp-8h]@14
  float v24; // [sp+D0h] [bp-4h]@18

  if (ValidHex(hexIdx)) {
    colDiff = hexIdx % 13 - this->occupiedHex % 13;
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
    v19 = gpCombatManager->combatGrid[this->occupiedHex].centerX;
    v14 = gpCombatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY;
    v23 = (double)v19;
    v22 = (double)v14;
    deltaX = gpCombatManager->combatGrid[hexIdx].centerX - v19;
    deltaY = gpCombatManager->combatGrid[hexIdx].occupyingCreatureBottomY - v14;
    dist = (signed __int64)sqrt((double)(deltaY * deltaY + deltaX * deltaX));
    numFrames = 0;
    if (this->frameInfo.flightSpeed > 0)
      numFrames = (dist + (this->frameInfo.flightSpeed >> 1)) / this->frameInfo.flightSpeed;
    if (numFrames <= 0)
      numFrames = 1;
    v16 = (double)deltaX / (double)numFrames;
    v24 = (double)deltaY / (double)numFrames;
    gpCombatManager->combatGrid[this->occupiedHex].stackIdx = -1;
    gpCombatManager->combatGrid[this->occupiedHex].unitOwner = -1;
    gpCombatManager->combatGrid[this->occupiedHex].occupiersOtherHexIsToLeft = -1;
    if (this->creature.creature_flags & TWO_HEXER) {
      v3 = this->occupiedHex + (this->facingRight < 1u ? -1 : 1);
      gpCombatManager->combatGrid[v3].stackIdx = -1;
      gpCombatManager->combatGrid[v3].unitOwner = -1;
      gpCombatManager->combatGrid[v3].occupiersOtherHexIsToLeft = -1;
    }

    if (!gbNoShowCombat) {
      bool closeMove = IsCloseMove(hexIdx);
      bool teleporter = CreatureHasAttribute(this->creatureIdx, TELEPORTER);
      v7 = 0;
      gpCombatManager->DrawFrame(0, 0, 0, 0, 75, 1, 1);
      gpWindowManager->screenBuffer->CopyTo(gpCombatManager->probablyBitmapForCombatScreen, 0, 0, 0, 0, 0x280u, 442);
      gpCombatManager->zeroedAfterAnimatingDeathAndHolySpells = 0;

      this->animationType = ANIMATION_TYPE_WALKING;
      for (i = 0; numFrames > i; ++i) {
        if (teleporter) {
          BuildTeleporterTempWalkSeq(&this->frameInfo, i + 1 == numFrames, i > 0, closeMove);
        } else
          BuildTempWalkSeq(&this->frameInfo, i + 1 == numFrames, i > 0);

        if (numFrames) {
          if (i <= 0 && (!closeMove && teleporter))
            v8 = this->frameInfo.animationLengths[ANIMATION_TYPE_START_MOVE];
          else
            v8 = 0;
          v12 = this->frameInfo.animationLengths[ANIMATION_TYPE_MOVE];
          v7 = this->frameInfo.animationLengths[ANIMATION_TYPE_MOVE];
          if (i + 1 < numFrames)
            v12 += this->frameInfo.animationLengths[ANIMATION_TYPE_SUB_END_MOVE];
        } else {
          v12 = this->frameInfo.animationLengths[ANIMATION_TYPE_WALKING];
          v8 = 0;
        }
        for (this->animationFrame = 0; this->frameInfo.animationLengths[ANIMATION_TYPE_WALKING] > this->animationFrame; ++this->animationFrame) {
          if (this->animationFrame >= v8 && v8 + v12 > this->animationFrame) {
            if (teleporter && !closeMove) {
              v23 = gpCombatManager->combatGrid[hexIdx].centerX;
              v22 = gpCombatManager->combatGrid[hexIdx].occupyingCreatureBottomY;
            } else {
              v23 = v16 / (double)v12 + v23;
              v22 = v24 / (double)v12 + v22;
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
          } else {
            offsetX = 0;
            offsetY = 0;
            v10 = 639;
            v6 = 442;
          }
          giMinExtentY = 640;
          giMinExtentX = 640;
          giMaxExtentY = 0;
          giMaxExtentX = 0;
          gbComputeExtent = 1;
          gbSaveBiggestExtent = 1;
          this->DrawToBuffer((signed __int64)v23, (signed __int64)v22, 0);
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
          if (this->animationFrame >= v8
            && (this->animationFrame + 1 < v7 || this->creatureIdx != CREATURE_VAMPIRE && this->creatureIdx != CREATURE_VAMPIRE_LORD))
            glTimers = (signed __int64)((double)KBTickCount()
              + (double)this->frameInfo.stepTime * gfCombatSpeedMod[giCombatSpeed] / (double)v12);
          else
            glTimers = (signed __int64)((double)KBTickCount()
              + (double)this->frameInfo.stepTime
              * gfCombatSpeedMod[giCombatSpeed]
              * 1.3
              / (double)v12);
          gpWindowManager->UpdateScreenRegion(offsetX, offsetY, v10 - offsetX + 1, v6 - offsetY + 1);
          if (this->frameInfo.animationLengths[ANIMATION_TYPE_WALKING] - 1 == this->animationFrame) {
            v23 = (double)(i + 1) * v16 + (double)v19;
            v22 = (double)(i + 1) * v24 + (double)v14;
          }
        }
      }
    }
    this->CancelSpellType(0);
    gpCombatManager->combatGrid[hexIdx].unitOwner = LOBYTE(gpCombatManager->otherCurrentSideThing);
    gpCombatManager->combatGrid[hexIdx].stackIdx = LOBYTE(gpCombatManager->someSortOfStackIdx);
    gpCombatManager->combatGrid[hexIdx].occupiersOtherHexIsToLeft = -1;
    if (this->creature.creature_flags & TWO_HEXER) {
      v5 = hexIdx + (this->facingRight < 1u ? -1 : 1);
      gpCombatManager->combatGrid[v5].unitOwner = LOBYTE(gpCombatManager->otherCurrentSideThing);
      gpCombatManager->combatGrid[v5].stackIdx = LOBYTE(gpCombatManager->someSortOfStackIdx);
      gpCombatManager->combatGrid[v5].occupiersOtherHexIsToLeft = v5 >= hexIdx;
      gpCombatManager->combatGrid[hexIdx].occupiersOtherHexIsToLeft = v5 <= hexIdx;
    }
    this->occupiedHex = hexIdx;
    this->animationType = 7;
    this->animationFrame = 0;
    if (this->field_8E) {
      this->facingRight = 1 - this->facingRight;
      if (this->creature.creature_flags & TWO_HEXER) {
        if (this->facingRight)
          --this->occupiedHex;
        else
          ++this->occupiedHex;
      }
      this->field_8E = 0;
    }
    gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
    gpCombatManager->TestRaiseDoor();
    result = 1;
  } else {
    result = 0;
  }
  return result;
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

void OccupyHexes(army *a) {
  if (a->facingRight == 1)
    a->occupiedHex--;
  else
    a->occupiedHex++;
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
  int v27 = 25;
  int v18 = 25;
  int v35 = 31;
  int v22 = 25;
  if (attacker->creatureIdx == CREATURE_LICH || attacker->creatureIdx == CREATURE_POWER_LICH) {
    v35 = 26;
    v22 = 7;
    v27 = 10;
    v18 = 10;
  }
  if (attacker->creatureIdx == CREATURE_CYBER_BEHEMOTH) {
    v27 = 100;
    v18 = 100;
    v35 = 31;
    v22 = 25;
  }
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
    from = new bitmap(33, 2 * v27, 2 * v18);
    from->GrabBitmapCareful(gpWindowManager->screenBuffer, v44 - v27, v38 - v18);
    int v59 = v44;
    int v53 = v38;
    int x = 0;
    int y = 0;
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
      offsetX = v44 - v27;
      v20 = v27 + v44;
      offsetY = v38 - v18;
      v15 = v18 + v38;
    }
    from->DrawToBuffer(x, y);
    gpWindowManager->UpdateScreenRegion(v59 - v27, v53 - v18, 2 * v27, 2 * v18);
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

  if (this->facingRight != tmpFacingRight) {
    if (this->creature.creature_flags & TWO_HEXER) {
      OccupyHexes(this);
    }
    gpCombatManager->DrawFrame(1, 0, 0, 0, 75, 1, 1);
  }

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
    if (this->creature.creature_flags & TWO_HEXER) {
      OccupyHexes(this);
    }
    this->facingRight = tmpFacingRight;
  }

  if (this->creatureIdx == CREATURE_ELF || this->creatureIdx == CREATURE_GRAND_ELF || this->creatureIdx == CREATURE_RANGER)
    ProcessSecondAttack(this, target);

  // Block mind spells
  if (this->effectStrengths[5] || this->effectStrengths[7]) {
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
        oneWayAnimLen = othstack->frameInfo.animationLengths[13];
      } else if (othstack->damageTakenDuringSomeTimePeriod) {
        oneWayAnimLen = othstack->frameInfo.animationLengths[15] + othstack->frameInfo.animationLengths[14] + 1;
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
        if (creature->field_3 == 13)
          creature->field_5 = creature->frameInfo.animationLengths[13];
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
            if (!gbNoShowCombat && creature->field_3 == 14)
              gpSoundManager->MemorySample(creature->combatSounds[2]);
            if (!gbNoShowCombat && creature->field_3 == 13)
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

extern unsigned __int8 moatCell[];
extern float gfBattleStat[];
extern float gfSSArcheryMod[];

void army::DamageEnemy(army *targ, int *damageDone, int *creaturesKilled, int isRanged, int a6) {
  int v7; // [sp+1Ch] [bp-24h]@65
  int othHex; // [sp+20h] [bp-20h]@17
  hero *owningHero; // [sp+24h] [bp-1Ch]@47
  float damagePerUnit; // [sp+2Ch] [bp-14h]@2
  float damagePerUnita; // [sp+2Ch] [bp-14h]@29
  int i; // [sp+30h] [bp-10h]@2
  signed int j; // [sp+30h] [bp-10h]@19
  int baseDam; // [sp+34h] [bp-Ch]@63
  int attackDiff; // [sp+3Ch] [bp-4h]@10

  if (targ) {
    damagePerUnit = 0.0;
    gbGenieHalf = 0;
    for (i = 0; this->quantity > i; ++i) {
      if (this->effectStrengths[3]) {
        damagePerUnit = (double)this->creature.max_damage + damagePerUnit;
      } else if (this->effectStrengths[4]) {
        damagePerUnit = (double)this->creature.min_damage + damagePerUnit;
      } else {
        damagePerUnit = (double)SRandom(this->creature.min_damage, this->creature.max_damage) + damagePerUnit;
      }
    }
    attackDiff = this->creature.attack - (a6 + targ->creature.defense);
    if (this->effectStrengths[8]
      && (targ->creatureIdx == CREATURE_GREEN_DRAGON
        || targ->creatureIdx == CREATURE_RED_DRAGON
        || targ->creatureIdx == CREATURE_BLACK_DRAGON
        || targ->creatureIdx == CREATURE_BONE_DRAGON))
      attackDiff += 5;
    if (gpCombatManager->hasMoat) {
      othHex = -1;
      if (targ->creature.creature_flags & TWO_HEXER)
        othHex = targ->occupiedHex + ((unsigned int)(targ->facingRight - 1) < 1 ? 1 : -1);
      for (j = 0; j < 9; ++j) {
        if (moatCell[j] == targ->occupiedHex || moatCell[j] == othHex)
          attackDiff += 3;
      }
    }
    if (attackDiff > 20)
      attackDiff = 20;
    if (attackDiff < -20)
      attackDiff = -20;
    damagePerUnita = gfBattleStat[attackDiff + 20] * damagePerUnit;
    if (this->creatureIdx == CREATURE_CRUSADER && HIBYTE(targ->creature.creature_flags) & ATTR_UNDEAD
      || this->creatureIdx == CREATURE_EARTH_ELEMENTAL && targ->creatureIdx == CREATURE_AIR_ELEMENTAL
      || this->creatureIdx == CREATURE_AIR_ELEMENTAL && targ->creatureIdx == CREATURE_EARTH_ELEMENTAL
      || this->creatureIdx == CREATURE_WATER_ELEMENTAL && targ->creatureIdx == CREATURE_FIRE_ELEMENTAL
      || this->creatureIdx == CREATURE_FIRE_ELEMENTAL && targ->creatureIdx == CREATURE_WATER_ELEMENTAL)
      damagePerUnita = damagePerUnita * 2.0;
    if (this->luckStatus > 0)
      damagePerUnita = damagePerUnita * 2.0;
    if (this->luckStatus < 0)
      damagePerUnita = damagePerUnita / 2.0;
    this->luckStatus = 0;
    if (isRanged
      && gpCombatManager->ShotIsThroughWall(this->owningSide, this->occupiedHex, targ->occupiedHex))
      damagePerUnita = damagePerUnita / 2.0;
    owningHero = gpCombatManager->heroes[this->owningSide];
    if (owningHero && isRanged)
      damagePerUnita = gfSSArcheryMod[owningHero->secondarySkillLevel[1]] * damagePerUnita;
    if (this->creature.creature_flags & SHOOTER
      && !isRanged
      && this->creatureIdx != CREATURE_TITAN
      && this->creatureIdx != CREATURE_MAGE
      && this->creatureIdx != CREATURE_ARCHMAGE)
      damagePerUnita = damagePerUnita / 2.0;
    if (isRanged && targ->effectStrengths[10])
      damagePerUnita = damagePerUnita / 2.0;
    if (this->otherBadLuckThing == 2)
      damagePerUnita = damagePerUnita / 2.0;
    this->otherBadLuckThing = 0;
    if (targ->effectStrengths[11])
      damagePerUnita = damagePerUnita / 2.0;
    if(!gCloseMove && CreatureHasAttribute(this->creatureIdx, TELEPORTER)) {
      baseDam = (signed __int64)(damagePerUnita * 1.25 + 0.5);
    } else {
      baseDam = (signed __int64)(damagePerUnita + 0.5);
    }
    if (this->creatureIdx == CREATURE_GENIE) {
      if (SRandom(1, 5) == 2) {
        v7 = targ->creature.hp * ((targ->quantity + 1) / 2);
        if (baseDam < v7) {
          gbGenieHalf = 1;
          baseDam = v7;
        }
      }
    }
    if (baseDam <= 0)
      baseDam = 1;
    if (HIBYTE(targ->creature.creature_flags) & ATTR_MIRROR_IMAGE)
      baseDam = -1;
    *damageDone = baseDam;
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

void army::MoveAttack(int targHex, int x) {
  int startHex = this->occupiedHex;
  this->MoveAttack_orig(targHex, x);

  if (!(this->creature.creature_flags & DEAD) &&
    CreatureHasAttribute(this->creatureIdx, STRIKE_AND_RETURN)) {
    MoveTo(startHex);
  }
}