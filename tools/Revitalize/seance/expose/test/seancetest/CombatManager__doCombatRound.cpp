signed int __thiscall CombatManager::doCombatRound(CombatManager *this, int a2)
{
  CombatManager *thisa; // [sp+Ch] [bp-24h]@1
  int side; // [sp+10h] [bp-20h]@2
  signed int j; // [sp+18h] [bp-18h]@4
  signed int k; // [sp+18h] [bp-18h]@38
  int stackIdx; // [sp+1Ch] [bp-14h]@6
  int stackIdxa; // [sp+1Ch] [bp-14h]@40
  signed int v9; // [sp+24h] [bp-Ch]@2
  signed int v10; // [sp+28h] [bp-8h]@8
  signed int i; // [sp+2Ch] [bp-4h]@2

  thisa = this;
  while ( 1 )
  {
    v9 = 0;
    side = thisa->otherCurrentSideThing;
    thisa->field_F2AB = 14;
    for ( i = 0; i < 15; ++i )
    {
      for ( j = 0; j < 2; ++j )
      {
        side ^= 1u;
        for ( stackIdx = 0; ; ++stackIdx )
        {
          if ( thisa->numCreatures[side] > stackIdx )
          {
            v10 = 0;
            if ( thisa->creatures[side][stackIdx].creature.creature_flags & (MAYBE_NOT_LOST_TURN|DEAD)
              || thisa->creatures[side][stackIdx].effectStrengths[6]
              || thisa->creatures[side][stackIdx].effectStrengths[11]
              || thisa->creatures[side][stackIdx].effectStrengths[2]
              || thisa->creatures[side][stackIdx].creature.speed != thisa->field_F2AB
              && !(thisa->creatures[side][stackIdx].creature.creature_flags & HAS_GOOD_MORALE) )
              v10 = 1;
            if ( !v10 && !i && !(thisa->creatures[side][stackIdx].creature.creature_flags & HAS_GOOD_MORALE) )
              v10 = 1;
            if ( HIBYTE(thisa->creatures[side][stackIdx].creature.creature_flags) & 0x10 )
            {
              v10 = 1;
              v9 = 1;
            }
            if ( !v10 && a2 && CombatManager::handleBadMorale(thisa, side, stackIdx) )
              v10 = 1;
            if ( v10 )
              continue;
          }
          break;
        }
        if ( thisa->numCreatures[side] != stackIdx )
        {
          thisa->otherCurrentSideThing = side;
          thisa->someSortOfStackIdx = stackIdx;
          if ( thisa->creatures[side][stackIdx].effectStrengths[7] )
            thisa->currentActionSide = 1 - side;
          else
            thisa->currentActionSide = side;
          sub_440D40(thisa);
          return 1;
        }
      }
      if ( i )
      {
        --thisa->field_F2AB;
        if ( !thisa->field_F2AB )
          thisa->field_F2AB = 15;
      }
    }
    if ( !v9 )
      break;
    a2 = 0;
    for ( k = 0; k < 2; ++k )
    {
      for ( stackIdxa = 0; thisa->numCreatures[k] > stackIdxa; ++stackIdxa )
        *(_DWORD *)&thisa->creatures[k][stackIdxa].creature.creature_flags &= 0xFFFFEFFFu;
    }
  }
  CombatManager::handleGarrisonAndCatapult(thisa);
  thisa->currentActionSide = 1 - thisa->currentActionSide;
  CombatManager::handleGarrisonAndCatapult(thisa);
  thisa->currentActionSide = 1 - thisa->currentActionSide;
  return 0;
}
