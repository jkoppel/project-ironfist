{
  bool result; // eax@2
  combatManager *thisb; // [sp+10h] [bp-10h]@1
  army *stack; // [sp+1Ch] [bp-4h]@1

  thisb = this;
  stack = 0;
  if ( ValidHex(hexIdx) )
  {
    if ( spell                                  // a2 != SPELL_FIREBALL
      && spell != SPELL_FIREBLAST
      && spell != SPELL_METEOR_SHOWER
      && spell != SPELL_COLD_RING
      && spell != SPELL_RESURRECT
      && spell != SPELL_RESURRECT_TRUE
      && spell != SPELL_ANIMATE_DEAD
      && thisb->combatGrid[hexIdx].unitOwner != -1
      && ((stack = &thisb->creatures[thisb->combatGrid[hexIdx].unitOwner][thisb->combatGrid[hexIdx].stackIdx],
           thisb->creatures[thisb->combatGrid[hexIdx].unitOwner][thisb->combatGrid[hexIdx].stackIdx].effectStrengths[12])
       || thisb->creatures[thisb->combatGrid[hexIdx].unitOwner][thisb->combatGrid[hexIdx].stackIdx].creatureIdx == CREATURE_GREEN_DRAGON) )
    {
      result = 0;
    }
    else if ( stack && army::SpellCastWorkChance(stack, spell) <= 0.0 )
    {
      result = 0;
    }
    else
    {
      switch ( spell )
      {
        case SPELL_HOLY_WORD:
        case SPELL_HOLY_SHOUT:
        case SPELL_DISPEL_MAGIC:
        case SPELL_MASS_DISPEL:
        case SPELL_ARMAGEDDON:
        case SPELL_ELEMENTAL_STORM:
        case SPELL_DEATH_RIPPLE:
        case SPELL_DEATH_WAVE:
          if ( thisb->combatGrid[hexIdx].unitOwner != -1 )
            goto LABEL_48;
          result = 0;
          break;
        case SPELL_RESURRECT:
        case SPELL_RESURRECT_TRUE:
        case SPELL_ANIMATE_DEAD:
          result = combatManager::FindResurrectArmyIndex(thisb, thisb->currentActionSide, spell, hexIdx) != -1;
          break;
        case SPELL_CURE:
        case SPELL_MASS_CURE:
        case SPELL_HASTE:
        case SPELL_MASS_HASTE:
        case SPELL_BLESS:
        case SPELL_MASS_BLESS:
        case SPELL_STONESKIN:
        case SPELL_STEELSKIN:
        case SPELL_ANTI_MAGIC:
        case SPELL_DRAGON_SLAYER:
        case SPELL_BLOOD_LUST:
        case SPELL_SHIELD:
        case SPELL_MASS_SHIELD:
          if ( thisb->combatGrid[hexIdx].unitOwner == thisb->currentActionSide )
            goto LABEL_48;
          result = 0;
          break;
        case SPELL_MIRROR_IMAGE:
          if ( thisb->combatGrid[hexIdx].unitOwner == thisb->currentActionSide )
          {
            if ( thisb->creatures[thisb->combatGrid[hexIdx].unitOwner][thisb->combatGrid[hexIdx].stackIdx].mirrorIdx == -1
              && thisb->creatures[thisb->combatGrid[hexIdx].unitOwner][thisb->combatGrid[hexIdx].stackIdx].mirroredIdx == -1 )
              goto LABEL_48;
            result = 0;
          }
          else
          {
            result = 0;
          }
          break;
        case SPELL_LIGHTNING_BOLT:
        case SPELL_CHAIN_LIGHTNING:
        case SPELL_SLOW:
        case SPELL_MASS_SLOW:
        case SPELL_BLIND:
        case SPELL_CURSE:
        case SPELL_MASS_CURSE:
        case SPELL_MAGIC_ARROW:
        case SPELL_BERZERKER:
        case SPELL_PARALYZE:
        case SPELL_HYPNOTIZE:
        case SPELL_COLD_RAY:
        case SPELL_DISRUPTING_RAY:
          if ( thisb->combatGrid[hexIdx].unitOwner == 1 - thisb->currentActionSide )
            goto LABEL_48;
          result = 0;
          break;
        case SPELL_TELEPORT:
          if ( bInTeleportGetDest )
          {
            if ( hexIdx != giNextActionGridIndex
              && army::CanFit(
                   &thisb->creatures[gpCombatManager->combatGrid[giNextActionGridIndex].unitOwner][gpCombatManager->combatGrid[giNextActionGridIndex].stackIdx],
                   hexIdx,
                   0,
                   0) )
              goto LABEL_48;
            result = 0;
          }
          else
          {
            if ( thisb->combatGrid[hexIdx].unitOwner == thisb->currentActionSide )
              goto LABEL_48;
            result = 0;
          }
          break;
        case SPELL_FIREBALL:
        case SPELL_FIREBLAST:
        case SPELL_METEOR_SHOWER:
        case SPELL_COLD_RING:
          if ( hexIdx != -1 && hexIdx % 13 && hexIdx % 13 != 12 )
            goto LABEL_48;
          result = 0;
          break;
        default:
LABEL_48:
          result = 1;
          break;
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}