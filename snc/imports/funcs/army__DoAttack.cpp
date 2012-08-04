{
  int v2; // eax@21
  int v3; // eax@21
  int v4; // eax@22
  int v5; // ecx@114
  army *this; // [sp+10h] [bp-120h]@1
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
  army *primaryTarget; // [sp+54h] [bp-DCh]@1
  int oldFacingRight; // [sp+58h] [bp-D8h]@1
  int enemyIncapacitated; // [sp+5Ch] [bp-D4h]@1
  int targetOldFacingRight; // [sp+60h] [bp-D0h]@23
  army *secondHexTarget; // [sp+64h] [bp-CCh]@1
  char a1; // [sp+68h] [bp-C8h]@69

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
    gpCombatManager->currentActionSide = 1 - gpCombatManager->currentActionSide;
  if ( ecx0->creatureIdx == CREATURE_HYDRA )
  {
    army::DoHydraAttack(ecx0, isRetaliationOrSecondAttack);
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
    targetHex = army::GetAdjacentCellIndex(ecx0, targetHex, ecx0->targetNeighborIdx);
    primaryTarget = &gpCombatManager->creatures[gpCombatManager->combatGrid[targetHex].unitOwner][gpCombatManager->combatGrid[targetHex].stackIdx];
    if ( this->creature.creature_flags & TWO_HEX_ATTACKER )
    {
      secondTargetHex = army::GetAdjacentCellIndex(this, targetHex, this->targetNeighborIdx);
      if ( ValidHex(secondTargetHex) )
      {
        if ( gpCombatManager->combatGrid[secondTargetHex].unitOwner >= 0
          && gpCombatManager->combatGrid[secondTargetHex].stackIdx >= 0
          && (gpCombatManager->combatGrid[secondTargetHex].unitOwner != primaryTarget->owningSide
           || gpCombatManager->combatGrid[secondTargetHex].stackIdx != primaryTarget->stackIdx) )
          secondHexTarget = &gpCombatManager->creatures[gpCombatManager->combatGrid[secondTargetHex].unitOwner][gpCombatManager->combatGrid[secondTargetHex].stackIdx];
      }
    }
    combatManager::ResetLimitCreature(gpCombatManager);
    v2 = 80 * this->owningSide + 4 * this->stackIdx;
    ++*(signed int *)((char *)gpCombatManager->stuffHappenedToCreature[0] + v2);
    v3 = 80 * primaryTarget->owningSide + 4 * primaryTarget->stackIdx;
    ++*(signed int *)((char *)gpCombatManager->stuffHappenedToCreature[0] + v3);
    if ( secondHexTarget )
    {
      v4 = 80 * secondHexTarget->owningSide + 4 * secondHexTarget->stackIdx;
      ++*(signed int *)((char *)gpCombatManager->stuffHappenedToCreature[0] + v4);
    }
    combatManager::DrawFrame(gpCombatManager, 0, 1, 0, 1, 75, 1, 1);
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
    army::CheckLuck(this);
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
    soundManager::MemorySample(gpSoundManager, this->combatSounds[1]);
    army::DamageEnemy(this, primaryTarget, &damDone, (int *)&creaturesKilled, 0, 0);
    if ( secondHexTarget )
      army::DamageEnemy(this, secondHexTarget, &damageDone, &v13, 0, 0);
    if ( damDone == -1 )
    {
      sprintf(gText, "The mirror image is destroyed!");
    }
    else if ( gbGenieHalf )
    {
      if ( this->quantity <= 1 )
        v10 = gArmyNames[this->creatureIdx];
      else
        v10 = gArmyNamesPlural[this->creatureIdx];
      sprintf(
        gText,
        "%s %s half the enemy troops!",
        v10,
        &aDestroy[("destroys" - "destroy") & ((this->quantity > 1) - 1)]);
      gText[0] -= 32;
    }
    else if ( SLODWORD(creaturesKilled) <= 0 )
    {
      if ( this->quantity <= 1 )
        v7 = gArmyNames[this->creatureIdx];
      else
        v7 = gArmyNamesPlural[this->creatureIdx];
      sprintf(gText, "%s %s %d %s.", v7, &aDo_4[("does" - "do") & ((this->quantity > 1) - 1)], damDone, "damage");
      gText[0] -= 32;
    }
    else
    {
      if ( SLODWORD(creaturesKilled) <= 1 )
        v9 = gArmyNames[primaryTarget->creatureIdx];
      else
        v9 = gArmyNamesPlural[primaryTarget->creatureIdx];
      if ( this->quantity <= 1 )
        v8 = gArmyNames[this->creatureIdx];
      else
        v8 = gArmyNamesPlural[this->creatureIdx];
      sprintf(
        gText,
        "%s %s %d %s.\n%d %s %s.",
        v8,
        &aDo_3[("does" - "do") & ((this->quantity > 1) - 1)],
        damDone,
        "damage",
        LODWORD(creaturesKilled),
        v9,
        &aPerish_2[("perishes" - "perish") & ((SLODWORD(creaturesKilled) > 1) - 1)]);
      gText[0] -= 32;
    }
    strcpy(&a1, gText);
    switch ( this->creatureIdx )
    {
      case CREATURE_CYCLOPS:
        if ( primaryTarget->quantity > 0 && (!secondHexTarget || secondHexTarget->quantity > 0) )
        {
          if ( SRandom(1, 100) >= 20 )
          {
            if ( SRandom(1, 100) < 20 && secondHexTarget && army::SpellCastWorks(secondHexTarget, SPELL_PARALYZE) )
              secondHexTarget->spellEnemyCreatureAbilityIsCasting = SPELL_PARALYZE;
          }
          else if ( primaryTarget && army::SpellCastWorks(primaryTarget, SPELL_PARALYZE) )
          {
            primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_PARALYZE;
            enemyIncapacitated = 1;
          }
        }
        break;
      case CREATURE_UNICORN:
        if ( SRandom(1, 100) < 20 && primaryTarget && army::SpellCastWorks(primaryTarget, SPELL_BLIND) )
        {
          primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_BLIND;
          enemyIncapacitated = 1;
        }
        break;
      case CREATURE_MEDUSA:
        if ( SRandom(1, 100) < 20 && primaryTarget && army::SpellCastWorks(primaryTarget, SPELL_MEDUSA_PETRIFY) )
        {
          primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_MEDUSA_PETRIFY;
          enemyIncapacitated = 1;
        }
        break;
      case CREATURE_MUMMY:
        if ( SRandom(1, 100) < 20 )
          goto LABEL_97;
        break;
      case CREATURE_ROYAL_MUMMY:
        if ( SRandom(1, 100) < 30 )
        {
LABEL_97:
          if ( primaryTarget && army::SpellCastWorks(primaryTarget, SPELL_CURSE) )
            primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_CURSE;
        }
        break;
      case CREATURE_ARCHMAGE:
        if ( SRandom(1, 100) < 20 && primaryTarget && army::SpellCastWorks(primaryTarget, SPELL_ARCHMAGI_DISPEL) )
          primaryTarget->spellEnemyCreatureAbilityIsCasting = SPELL_ARCHMAGI_DISPEL;
        break;
      case CREATURE_GHOST:
        gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner] = creaturesKilled;
        break;
      case CREATURE_VAMPIRE_LORD:
        LODWORD(gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner]) = LODWORD(creaturesKilled) * primaryTarget->creature.hp;
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
    army::PowEffect(this, -1, 0, -1, -1);
    combatManager::CombatMessage(gpCombatManager, &a1, 1, 1, 0);
    gpCombatManager->stuffHappenedToCreature[this->owningSide][this->stackIdx] = 1;
    if ( this->creatureIdx == CREATURE_GHOST )
      this->quantity += LODWORD(gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner]);
    if ( this->creatureIdx == CREATURE_VAMPIRE_LORD )
    {
      if ( SLODWORD(gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner]) >= this->damage )
      {
        v5 = gpCombatManager->combatGrid[this->occupiedHex].unitOwner;
        LODWORD(gpCombatManager->ghostAndVampireAbilityStrength[v5]) -= this->damage;
        this->damage = 0;
        v11 = SLODWORD(gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner])
            / this->creature.hp;
        if ( this->initialQuantity - this->quantity <= v11 )
          this->quantity = this->initialQuantity;
        else
          this->quantity += v11;
      }
      else
      {
        this->damage -= LODWORD(gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[this->occupiedHex].unitOwner]);
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
      DelayMilli((signed __int64)(gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 150.0));
      primaryTarget->targetNeighborIdx = OppositeDirection(this->targetNeighborIdx);
      if ( primaryTarget->creature.creature_flags & TWO_HEXER )
      {
        if ( this->occupiedHex == army::GetAdjacentCellIndex(
                                    this,
                                    primaryTarget->occupiedHex,
                                    (unsigned int)(primaryTarget->facingRight - 1) < 1 ? 0 : 5) )
          primaryTarget->targetNeighborIdx = 6;
        if ( this->occupiedHex == army::GetAdjacentCellIndex(
                                    this,
                                    primaryTarget->occupiedHex,
                                    3 - ((unsigned int)(primaryTarget->facingRight - 1) < 1)) )
          primaryTarget->targetNeighborIdx = 7;
      }
      army::DoAttack(primaryTarget, 1);
      *(_DWORD *)&primaryTarget->creature.creature_flags |= RETALIATED;
      if ( gbRemoteOn
        && gpCombatManager->involvedInBadMorale[0]
        && gpCombatManager->involvedInBadMorale[1]
        && primaryTarget->creatureIdx == CREATURE_GHOST )
        primaryTarget->quantity += LODWORD(gpCombatManager->ghostAndVampireAbilityStrength[gpCombatManager->combatGrid[primaryTarget->occupiedHex].unitOwner]);
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
      DelayMilli((signed __int64)(gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 100.0));
      v16 = this->targetNeighborIdx;
      this->targetNeighborIdx = v18;
      army::DoAttack(this, 1);
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
    army::CancelSpellType(this, CREATURE_TOOK_TURN_EVENT_CODE);
    combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
  }
  targetHex = -1;
  this->targetOwner = -1;
  if ( isRetaliationOrSecondAttack )
    gpCombatManager->currentActionSide = 1 - gpCombatManager->currentActionSide;
}