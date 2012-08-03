{
  __int16 v3; // fps@1
  unsigned __int8 v4; // c0@1
  unsigned __int8 v5; // c3@1
  int result; // eax@2
  __int16 v7; // fps@24
  unsigned __int8 v8; // c0@24
  unsigned __int8 v9; // c3@24
  float v10; // STA0_4@31
  __int16 v11; // fps@62
  unsigned __int8 v12; // c0@62
  unsigned __int8 v13; // c3@62
  combatManager *thisa; // [sp+64h] [bp-58h]@1
  float v15; // [sp+68h] [bp-54h]@30
  signed int numDragons; // [sp+70h] [bp-4Ch]@42
  signed int numShooters; // [sp+78h] [bp-44h]@55
  signed int v18; // [sp+7Ch] [bp-40h]@42
  signed int v19; // [sp+80h] [bp-3Ch]@28
  int v19a; // [sp+80h] [bp-3Ch]@67
  int speedWithEffect; // [sp+88h] [bp-34h]@4
  float chance; // [sp+90h] [bp-2Ch]@1
  int i; // [sp+9Ch] [bp-20h]@42
  int j; // [sp+9Ch] [bp-20h]@55
  int fightValue; // [sp+A0h] [bp-1Ch]@3
  int hexXCoord; // [sp+A4h] [bp-18h]@14
  float avgDamage; // [sp+A8h] [bp-14h]@29
  float currentTurnsToOtherSide; // [sp+ACh] [bp-10h]@22
  float v29; // [sp+B0h] [bp-Ch]@52
  float v30; // [sp+B0h] [bp-Ch]@60
  int distFromOptimalColumn; // [sp+B4h] [bp-8h]@15
  int adjustedDistFromOtherSide; // [sp+B4h] [bp-8h]@19
  float turnsToOtherSideAfterCast; // [sp+B8h] [bp-4h]@24

  thisa = this;
  UNDEF(v3);
  chance = army::SpellCastWorkChance(stack, (Spell)giSpellInfluenceToSpell[eff]);
  if ( v4 | v5 )
  {
    result = 0;
  }
  else
  {
    fightValue = stack->quantity * stack->creature.fight_value;
    switch ( eff )
    {
      case EFFECT_SLOW:
        speedWithEffect = (stack->creature.speed + 1) >> 1;
        goto LABEL_7;
      case EFFECT_HASTE:
        speedWithEffect = stack->creature.speed + 2;
        if ( stack->creature.creature_flags & FLYER )
        {
          result = 0;
        }
        else
        {
LABEL_7:
          if ( thisa->isCastleBattle && stack->owningSide == 1 )
          {
            result = 0;
          }
          else if ( stack->creature.creature_flags & SHOOTER )
          {
            result = 0;
          }
          else if ( army::GetAttackMask(stack, stack->occupiedHex, 1, -1) == 255 )
          {
            hexXCoord = stack->occupiedHex % 13;
            if ( thisa->currentActionSide )
              distFromOptimalColumn = 10 - hexXCoord;
            else
              distFromOptimalColumn = hexXCoord - 2;
            if ( distFromOptimalColumn < 0 )
              distFromOptimalColumn = 0;
            adjustedDistFromOtherSide = distFromOptimalColumn + 2;
            if ( thisa->isCastleBattle )
              adjustedDistFromOtherSide += 3;
            if ( stack->creature.creature_flags & FLYER )
              currentTurnsToOtherSide = 1.0;
            else
              currentTurnsToOtherSide = (double)adjustedDistFromOtherSide / (double)stack->creature.speed;
            UNDEF(v7);
            turnsToOtherSideAfterCast = (double)adjustedDistFromOtherSide / (double)speedWithEffect;
            if ( !(v8 | v9) )
              turnsToOtherSideAfterCast = 7.0;
            if ( currentTurnsToOtherSide > 7.0 )
              currentTurnsToOtherSide = 7.0;
            v19 = (signed __int64)((currentTurnsToOtherSide - turnsToOtherSideAfterCast) / 10.0 * (double)fightValue);
LABEL_67:
            v19a = (signed __int64)((double)v19 * chance);
            if ( stack->effectStrengths[5] || stack->effectStrengths[7] )
            {
              if ( eff != EFFECT_ANTI_MAGIC )
                v19a = 0;
            }
            result = v19a;
          }
          else
          {
            result = 0;
          }
        }
        break;
      case EFFECT_BLESS:
      case EFFECT_CURSE:
        avgDamage = ((double)stack->creature.min_damage + (double)stack->creature.max_damage) * 0.5;
        if ( eff == EFFECT_BLESS )
        {
          v15 = ((double)stack->creature.max_damage - avgDamage) / avgDamage * (double)fightValue * 0.45;
        }
        else
        {
          v10 = ((double)stack->creature.max_damage - avgDamage) / avgDamage * (double)fightValue * 0.45;
          v15 = -v10;
        }
        v19 = (signed __int64)v15;
        goto LABEL_67;
      case EFFECT_BLIND:
        v19 = (signed __int64)((double)fightValue * 0.40000001);
        goto LABEL_67;
      case EFFECT_BERSERKER:
        v19 = (signed __int64)((double)fightValue * 0.55000001);
        goto LABEL_67;
      case EFFECT_PARALYZE:
        v19 = (signed __int64)((double)fightValue * 0.5);
        goto LABEL_67;
      case EFFECT_HYPNOTIZE:
        v19 = (signed __int64)((double)fightValue * 0.64999998);
        goto LABEL_67;
      case EFFECT_BLOOD_LUST:
        v19 = (signed __int64)((double)fightValue * 0.14);
        goto LABEL_67;
      case EFFECT_PETRIFY:
        v19 = (signed __int64)((double)fightValue * 0.25);
        goto LABEL_67;
      case EFFECT_STONESKIN:
        v19 = (signed __int64)((double)fightValue * 0.16);
        goto LABEL_67;
      case EFFECT_STEELSKIN:
        v19 = (signed __int64)((double)fightValue * 0.28);
        goto LABEL_67;
      case EFFECT_ANTI_MAGIC:
        v19 = (signed __int64)((double)fightValue * 0.2);
        goto LABEL_67;
      case EFFECT_DRAGON_SLAYER:
        v18 = 0;
        numDragons = 0;
        for ( i = 0; thisa->numCreatures[1 - stack->owningSide] > i; ++i )
        {
          if ( thisa->creatures[stack->owningSide][i].creatureIdx == CREATURE_GREEN_DRAGON
            || thisa->creatures[stack->owningSide][i].creatureIdx == CREATURE_RED_DRAGON
            || thisa->creatures[stack->owningSide][i].creatureIdx == CREATURE_BLACK_DRAGON
            || thisa->creatures[stack->owningSide][i].creatureIdx == CREATURE_BONE_DRAGON )
          {
            ++numDragons;
            if ( army::OtherArmyAdjacent(
                   stack,
                   thisa->creatures[stack->owningSide][i].owningSide,
                   thisa->creatures[stack->owningSide][i].stackIdx) )
              v18 = 1;
          }
        }
        if ( v18 )
          v29 = 1.0;
        else
          v29 = (double)(numDragons / thisa->numCreatures[1 - stack->owningSide]);
        v19 = (signed __int64)(0.28 * v29);
        goto LABEL_67;
      case EFFECT_SHIELD:
        numShooters = 0;
        for ( j = 0; thisa->numCreatures[1 - stack->owningSide] > j; ++j )
        {
          if ( thisa->creatures[stack->owningSide][j].creature.creature_flags & SHOOTER )
            ++numShooters;
        }
        v30 = (double)(numShooters / thisa->numCreatures[1 - stack->owningSide]);
        if ( !stack->owningSide )
        {
          if ( thisa->isCastleBattle )
          {
            UNDEF(v11);
            v30 = v30 + 0.3;
            if ( !(v12 | v13) )
              v30 = 1.0;
          }
        }
        v19 = (signed __int64)(0.44999999 * v30);
        goto LABEL_67;
      default:
        v19 = 0;
        goto LABEL_67;
    }
  }
  return result;
}
/* Orphan comments:
if(turnsToOtherSideAfterCast > 7.0)
*/