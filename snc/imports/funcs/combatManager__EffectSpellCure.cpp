{
  double v5; // st7@24
  int v6; // edx@24
  double v7; // st7@27
  int v8; // edx@27
  double v9; // st7@30
  int v10; // edx@30
  combatManager *thisa; // [sp+38h] [bp-30h]@1
  int dam; // [sp+40h] [bp-28h]@14
  int curSide; // [sp+44h] [bp-24h]@2
  STACK_MODIFYING_EFFECT eff; // [sp+48h] [bp-20h]@19
  army *stack; // [sp+4Ch] [bp-1Ch]@13
  signed int i; // [sp+50h] [bp-18h]@5
  signed int removingPosEffectVal; // [sp+58h] [bp-10h]@5
  signed int done; // [sp+5Ch] [bp-Ch]@1
  int removingNegEffectVal; // [sp+60h] [bp-8h]@5
  bool lostTurn; // [sp+64h] [bp-4h]@17

  thisa = this;
  *val = 0;
  done = 0;
  if ( side == 2 )
    curSide = this->currentActionSide;
  else
    curSide = side;
  while ( !done )
  {
    removingPosEffectVal = 0;
    removingNegEffectVal = 0;
    for ( i = 0; i < 20; ++i )
    {
      if ( (hex == -1 || i == hex)
        && thisa->creatures[curSide][i].creatureIdx >= 0
        && thisa->creatures[curSide][i].quantity > 0 )
      {
        stack = &thisa->creatures[curSide][i];
        if ( isCure == 1 )
        {
          dam = 5 * thisa->heroSpellpowers[thisa->currentActionSide];
          if ( thisa->creatures[curSide][i].damage < dam )
            dam = thisa->creatures[curSide][i].damage;
          removingPosEffectVal = (signed __int64)((double)gMonsterDatabase[thisa->creatures[curSide][i].creatureIdx].fight_value
                                                * (double)dam
                                                * 0.75
                                                / (double)thisa->creatures[curSide][i].creature.hp
                                                + (double)removingPosEffectVal);
        }
        lostTurn = (thisa->creatures[curSide][i].creature.creature_flags & MAYBE_NOT_LOST_TURN) != 0;
        if ( HIBYTE(thisa->creatures[curSide][i].creature.creature_flags) & ATTR_MIRROR_IMAGE )
        {
          removingNegEffectVal = thisa->creatures[curSide][i].quantity
                               * gMonsterDatabase[thisa->creatures[curSide][i].creatureIdx].fight_value;
        }
        else
        {
          for ( eff = 0; (signed int)eff < 15; ++eff )
          {
            if ( stack->effectStrengths[eff] )
            {
              switch ( eff )
              {
                case EFFECT_HASTE:
                case EFFECT_BLESS:
                case EFFECT_DRAGON_SLAYER:
                case EFFECT_BLOOD_LUST:
                case EFFECT_SHIELD:
                case EFFECT_STONESKIN:
                case EFFECT_STEELSKIN:
                  v5 = (double)combatManager::RawEffectSpellInfluence(thisa, stack, eff);
                  v6 = lostTurn + stack->effectStrengths[eff];
                  if ( v6 >= 10 )
                    v6 = 10;
                  removingPosEffectVal = (signed __int64)(v5 * heuristicModifierForDuration[v6]
                                                        + (double)removingPosEffectVal);
                  break;
                case EFFECT_SLOW:
                case EFFECT_CURSE:
                  v7 = (double)combatManager::RawEffectSpellInfluence(thisa, stack, eff);
                  v8 = lostTurn + stack->effectStrengths[eff];
                  if ( v8 >= 10 )
                    v8 = 10;
                  removingNegEffectVal = (signed __int64)(v7 * heuristicModifierForDuration[v8]
                                                        + (double)removingNegEffectVal);
                  break;
                case EFFECT_BLIND:
                case EFFECT_BERSERKER:
                case EFFECT_PARALYZE:
                case EFFECT_HYPNOTIZE:
                case EFFECT_PETRIFY:
                  v9 = (double)combatManager::RawEffectSpellInfluence(thisa, stack, eff);
                  v10 = lostTurn + stack->effectStrengths[eff];
                  if ( v10 >= 10 )
                    v10 = 10;
                  removingNegEffectVal = (signed __int64)((double)removingNegEffectVal
                                                        - v9 * heuristicModifierForDuration[v10]);
                  break;
                case EFFECT_ANTI_MAGIC:
                  continue;
              }
            }
          }
        }
      }
    }
    if ( isCure == 1 )
      removingPosEffectVal = 0;
    if ( thisa->currentActionSide == curSide )
      *val += -removingNegEffectVal - removingPosEffectVal;
    else
      *val += removingNegEffectVal + removingPosEffectVal;
    if ( side != 2 || thisa->currentActionSide != curSide )
      done = 1;
    else
      curSide = 1 - thisa->currentActionSide;
  }
}