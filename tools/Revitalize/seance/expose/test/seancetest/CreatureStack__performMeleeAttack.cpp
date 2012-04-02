void __thiscall CreatureStack::performMeleeAttack(CreatureStack *ecx0, int isRetaliationOrSecondAttack)
{
  int v2; // eax@21
  int v3; // eax@21
  int v4; // eax@22
  int v5; // ecx@114
  CreatureStack *this; // [sp+10h] [bp-120h]@1
  char *v7; // [sp+14h] [bp-11Ch]@66
  char *v8; // [sp+18h] [bp-118h]@62
  char *v9; // [sp+1Ch] [bp-114h]@59
  char *v10; // [sp+20h] [bp-110h]@54
  int v11; // [sp+28h] [bp-108h]@114
  int secondTargetHex; // [sp+2Ch] [bp-104h]@15
  int v13; // [sp+30h] [bp-100h]@1
  int shouldFaceRight; // [sp+34h] [bp-FCh]@24
  int targetHex; // [sp+38h] [bp-F8h]@5
  int v16; // [sp+3Ch] [bp-F4h]@150
  int damDone; // [sp+40h] [bp-F0h]@1
  int v18; // [sp+44h] [bp-ECh]@5
  int damageDone; // [sp+48h] [bp-E8h]@1
  float creaturesKilled; // [sp+4Ch] [bp-E4h]@1
  CreatureStack *primaryTarget; // [sp+54h] [bp-DCh]@1
  int oldFacingRight; // [sp+58h] [bp-D8h]@1
  int enemyIncapacitated; // [sp+5Ch] [bp-D4h]@1
  int targetOldFacingRight; // [sp+60h] [bp-D0h]@23
  CreatureStack *secondHexTarget; // [sp+64h] [bp-CCh]@1
  char message; // [sp+68h] [bp-C8h]@69

  this = ecx0;
  ecx0->field_6 = 3;
  damDone = 0;
  creaturesKilled = 0.0;
  damageDone = 0;
  v13 = 0;
  enemyIncapacitated = 0;
  primaryTarget = 0;
  secondHexTarget = 0;
  oldFacingRight = ecx0->facingRight;
  if ( isRetaliationOrSecondAttack )
    combatManager->currentActionSide = 1 - combatManager->currentActionSide;
  if ( ecx0->creatureIdx == CREATURE_HYDRA )
  {
    CreatureStack::doHydraAttack(ecx0, isRetaliationOrSecondAttack);
  }
  else
  {
    v18 = ecx0->targetNeighborIdx;
    targetHex = ecx0->occupiedHex;
    if ( ecx0->creature.creature_flags & TWO_HEXER
      && (!ecx0->facingRight && ecx0->targetNeighborIdx >= 3
       || ecx0->facingRight == 1 && (ecx0->targetNeighborIdx <= 2 || ecx0->targetNeighborIdx >= 6)) )
    {
      if ( oldFacingRight )
        targetHex = ecx0->occupiedHex + 1;
      else
        targetHex = ecx0->occupiedHex - 1;
    }
    targetHex = CreatureStack::getHexNeighbor(ecx0, targetHex, ecx0->targetNeighborIdx);
    primaryTarget = &combatManager->creatures[combatManager->combatGrid[targetHex].unitOwner][combatManager->combatGrid[targetHex].stackIdx];
    if ( this->creature.creature_flags & TWO_HEX_ATTACKER )
    {
      secondTargetHex = CreatureStack::getHexNeighbor(this, targetHex, this->targetNeighborIdx);
      if ( checkHexGridIdxBounds(secondTargetHex) )
      {
        if ( combatManager->combatGrid[secondTargetHex].unitOwner >= 0
          && combatManager->combatGrid[secondTargetHex].stackIdx >= 0
          && (combatManager->combatGrid[secondTargetHex].unitOwner != primaryTarget->owningSide
           || combatManager->combatGrid[secondTargetHex].stackIdx != primaryTarget->stackIdx) )
          secondHexTarget = &combatManager->creatures[combatManager->combatGrid[secondTargetHex].unitOwner][combatManager->combatGrid[secondTargetHex].stackIdx];
      }
    }
    CombatManager::resetStuffHapenedToCreature(combatManager);
    v2 = 80 * this->owningSide + 4 * this->stackIdx;
    ++*(signed int *)((char *)combatManager->stuffHappenedToCreature[0] + v2);
    v3 = 80 * primaryTarget->owningSide + 4 * primaryTarget->stackIdx;
    ++*(signed int *)((char *)combatManager->stuffHappenedToCreature[0] + v3);
    if ( secondHexTarget )
    {
      v4 = 80 * secondHexTarget->owningSide + 4 * secondHexTarget->stackIdx;
      ++*(signed int *)((char *)combatManager->stuffHappenedToCreature[0] + v4);
    }
    CombatManager::drawBattlefield(combatManager, 0, 1, 0, 1, 75, 1, 1);
    targetOldFacingRight = primaryTarget->facingRight;
    if ( this->targetNeighborIdx > 2 )
    {
      if ( this->targetNeighborIdx > 5 )
        shouldFaceRight = this->facingRight;
      else
        shouldFaceRight = 0;
    }
    else
    {
      shouldFaceRight = 1;
    }
    if ( this->facingRight != shouldFaceRight )
    {
      this->facingRight = shouldFaceRight;
      if ( this->creature.creature_flags & TWO_HEXER )
      {
        if ( shouldFaceRight == 1 )
          --this->occupiedHex;
        else
          ++this->occupiedHex;
      }
      primaryTarget->facingRight = 1 - this->facingRight;
      if ( primaryTarget->facingRight != targetOldFacingRight && primaryTarget->creature.creature_flags & 1 )
      {
        if ( primaryTarget->facingRight == 1 )
          --primaryTarget->occupiedHex;
        else
          ++primaryTarget->occupiedHex;
      }
    }
    CreatureStack::rollAndHandleLuck(this);
    this->mightBeIsAttacking = 1;
    if ( this->targetNeighborIdx != 6 && this->targetNeighborIdx != 5 && this->targetNeighborIdx )
    {
      if ( this->targetNeighborIdx != 1 && this->targetNeighborIdx != 4 )
        this->mightBeAttackAnimIdx = 24;
      else
        this->mightBeAttackAnimIdx = 20;
    }
    else
    {
      this->mightBeAttackAnimIdx = 16;
    }
    if ( secondHexTarget )
      this->mightBeAttackAnimIdx += 2;
    SoundManager::playSample(soundManager, this->combatSounds[1]);
    CreatureStack::dealDamage(this, primaryTarget, &damDone, (int *)&creaturesKilled, 0, 0);
    if ( secondHexTarget )
      CreatureStack::dealDamage(this, secondHexTarget, &damageDone, &v13, 0, 0);
    if ( damDone == -1 )
    {
      sprintf(globBuf, "The mirror image is destroyed!");
    }
    else
    {
      if ( genieIsHalving )
      {
        if ( this->quantity <= 1 )
          v10 = creatureSingularNames[this->creatureIdx];
        else
          v10 = creaturePluralNames[this->creatureIdx];
        sprintf(
          globBuf,
          "%s %s half the enemy troops!",
          v10,
          &aDestroy[("destroys" - "destroy") & ((this->quantity > 1) - 1)]);
        globBuf[0] -= 32;
      }
      else
      {
        if ( SLODWORD(creaturesKilled) <= 0 )
        {
          if ( this->quantity <= 1 )
            v7 = creatureSingularNames[this->creatureIdx];
          else
            v7 = creaturePluralNames[this->creatureIdx];
          sprintf(globBuf, "%s %s %d %s.", v7, &aDo_4[("does" - "do") & ((this->quantity > 1) - 1)], damDone, "damage");
          globBuf[0] -= 32;
        }
        else
        {
          if ( SLODWORD(creaturesKilled) <= 1 )
            v9 = creatureSingularNames[primaryTarget->creatureIdx];
          else
            v9 = creaturePluralNames[primaryTarget->creatureIdx];
          if ( this->quantity <= 1 )
            v8 = creatureSingularNames[this->creatureIdx];
          else
            v8 = creaturePluralNames[this->creatureIdx];
          sprintf(
            globBuf,
            "%s %s %d %s.\n%d %s %s.",
            v8,
            &aDo_3[("does" - "do") & ((this->quantity > 1) - 1)],
            damDone,
            "damage",
            LODWORD(creaturesKilled),
            v9,
            &aPerish_2[("perishes" - "perish") & ((SLODWORD(creaturesKilled) > 1) - 1)]);
          globBuf[0] -= 32;
        }
      }
    }
    strcpy(&message, globBuf);
    switch ( this->creatureIdx )
    {
      case CREATURE_CYCLOPS:
        if ( primaryTarget->quantity > 0 && (!secondHexTarget || secondHexTarget->quantity > 0) )
        {
          if ( nextRandomInt(1, 100) >= 20 )
          {
            if ( nextRandomInt(1, 100) < 20
              && secondHexTarget
              && CreatureStack::rollSpellSucceeds(secondHexTarget, SPELL_PARALYZE) )
              secondHexTarget->spellEnemyCreatureAbilityIsCasting = SPELL_PARALYZE;
          }
          else
          {
            if ( primaryTarget && CreatureStack::rollSpellSucceeds(primaryTarget, SPELL_PARALYZE) )
            {
              primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_PARALYZE;
              enemyIncapacitated = 1;
            }
          }
        }
        break;
      case CREATURE_UNICORN:
        if ( nextRandomInt(1, 100) < 20 && primaryTarget && CreatureStack::rollSpellSucceeds(primaryTarget, SPELL_BLIND) )
        {
          primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_BLIND;
          enemyIncapacitated = 1;
        }
        break;
      case CREATURE_MEDUSA:
        if ( nextRandomInt(1, 100) < 20
          && primaryTarget
          && CreatureStack::rollSpellSucceeds(primaryTarget, SPELL_MEDUSA_PETRIFY) )
        {
          primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_MEDUSA_PETRIFY;
          enemyIncapacitated = 1;
        }
        break;
      case CREATURE_MUMMY:
        if ( nextRandomInt(1, 100) < 20 )
          goto LABEL_97;
        break;
      case CREATURE_ROYAL_MUMMY:
        if ( nextRandomInt(1, 100) < 30 )
        {
LABEL_97:
          if ( primaryTarget && CreatureStack::rollSpellSucceeds(primaryTarget, SPELL_CURSE) )
            primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_CURSE;
        }
        break;
      case CREATURE_ARCHMAGE:
        if ( nextRandomInt(1, 100) < 20
          && primaryTarget
          && CreatureStack::rollSpellSucceeds(primaryTarget, SPELL_ARCHMAGI_DISPEL) )
          primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_ARCHMAGI_DISPEL;
        break;
      case CREATURE_GHOST:
        combatManager->ghostAndVampireAbilityStrength[combatManager->combatGrid[this->occupiedHex].unitOwner] = creaturesKilled;
        break;
      case CREATURE_VAMPIRE_LORD:
        LODWORD(combatManager->ghostAndVampireAbilityStrength[combatManager->combatGrid[this->occupiedHex].unitOwner]) = LODWORD(creaturesKilled) * primaryTarget->creature.hp;
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
    CreatureStack::doAttackAndDamageTakenAnimations(this, -1, 0, -1, -1);
    CombatManager::displayCombatMessage(combatManager, &message, 1, 1, 0);
    combatManager->stuffHappenedToCreature[this->owningSide][this->stackIdx] = 1;
    if ( this->creatureIdx == CREATURE_GHOST )
      this->quantity += LODWORD(combatManager->ghostAndVampireAbilityStrength[combatManager->combatGrid[this->occupiedHex].unitOwner]);
    if ( this->creatureIdx == CREATURE_VAMPIRE_LORD )
    {
      if ( SLODWORD(combatManager->ghostAndVampireAbilityStrength[combatManager->combatGrid[this->occupiedHex].unitOwner]) >= this->damage )
      {
        v5 = combatManager->combatGrid[this->occupiedHex].unitOwner;
        LODWORD(combatManager->ghostAndVampireAbilityStrength[v5]) -= this->damage;
        this->damage = 0;
        v11 = SLODWORD(combatManager->ghostAndVampireAbilityStrength[combatManager->combatGrid[this->occupiedHex].unitOwner])
            / this->creature.hp;
        if ( this->initialQuantity - this->quantity <= v11 )
          this->quantity = this->initialQuantity;
        else
          this->quantity += v11;
      }
      else
      {
        this->damage -= LODWORD(combatManager->ghostAndVampireAbilityStrength[combatManager->combatGrid[this->occupiedHex].unitOwner]);
      }
    }
    if ( primaryTarget
      && primaryTarget->quantity > 0
      && !primaryTarget->effectStrengths[6]
      && !primaryTarget->effectStrengths[11]
      && (primaryTarget->creatureIdx == CREATURE_GRIFFIN || !(primaryTarget->creature.creature_flags & RETALIATED))
      && this->creatureIdx != CREATURE_ROGUE
      && this->creatureIdx != CREATURE_SPRITE
      && this->creatureIdx != CREATURE_VAMPIRE
      && this->creatureIdx != CREATURE_VAMPIRE_LORD
      && !enemyIncapacitated
      && !isRetaliationOrSecondAttack )
    {
      sleep((signed __int64)(combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 150.0));
      primaryTarget->targetNeighborIdx = mirrorNeighborIdx(this->targetNeighborIdx);
      if ( primaryTarget->creature.creature_flags & TWO_HEXER )
      {
        if ( this->occupiedHex == CreatureStack::getHexNeighbor(
                                    this,
                                    primaryTarget->occupiedHex,
                                    (((unsigned int)(primaryTarget->facingRight - 1) < 1) - 1) & 5) )
          primaryTarget->targetNeighborIdx = 6;
        if ( this->occupiedHex == CreatureStack::getHexNeighbor(
                                    this,
                                    primaryTarget->occupiedHex,
                                    3 - ((unsigned int)(primaryTarget->facingRight - 1) < 1)) )
          primaryTarget->targetNeighborIdx = 7;
      }
      CreatureStack::performMeleeAttack(primaryTarget, 1);
      *(_DWORD *)&primaryTarget->creature.creature_flags |= RETALIATED;
      if ( dword_4F7494
        && combatManager->involvedInBadMorale[0]
        && combatManager->involvedInBadMorale[1]
        && primaryTarget->creatureIdx == CREATURE_GHOST )
        primaryTarget->quantity += LODWORD(combatManager->ghostAndVampireAbilityStrength[combatManager->combatGrid[primaryTarget->occupiedHex].unitOwner]);
    }
    if ( (this->creatureIdx == CREATURE_WOLF
       || this->creatureIdx == CREATURE_PALADIN
       || this->creatureIdx == CREATURE_CRUSADER)
      && primaryTarget
      && primaryTarget->quantity > 0
      && !isRetaliationOrSecondAttack
      && !this->effectStrengths[6]
      && !this->effectStrengths[11]
      && !this->effectStrengths[2]
      && this->quantity > 0 )
    {
      sleep((signed __int64)(combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 100.0));
      v16 = this->targetNeighborIdx;
      this->targetNeighborIdx = v18;
      CreatureStack::performMeleeAttack(this, 1);
      this->targetNeighborIdx = v16;
    }
    if ( this->facingRight != oldFacingRight )
    {
      if ( !(this->creature.creature_flags & DEAD) )
      {
        this->facingRight = oldFacingRight;
        if ( this->creature.creature_flags & TWO_HEXER )
        {
          if ( oldFacingRight == 1 )
            --this->occupiedHex;
          else
            ++this->occupiedHex;
        }
      }
      if ( !(primaryTarget->creature.creature_flags & DEAD) )
      {
        if ( primaryTarget->facingRight != targetOldFacingRight )
        {
          primaryTarget->facingRight = targetOldFacingRight;
          if ( primaryTarget->creature.creature_flags & TWO_HEXER )
          {
            if ( primaryTarget->facingRight == 1 )
              --primaryTarget->occupiedHex;
            else
              ++primaryTarget->occupiedHex;
          }
        }
      }
    }
  }
  if ( !isRetaliationOrSecondAttack && (this->effectStrengths[5] || this->effectStrengths[7]) )
  {
    CreatureStack::handleCreatureEvent(this, CREATURE_TOOK_TURN_EVENT_CODE);
    CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
  }
  targetHex = -1;
  this->targetOwner = -1;
  if ( isRetaliationOrSecondAttack )
    combatManager->currentActionSide = 1 - combatManager->currentActionSide;
}
