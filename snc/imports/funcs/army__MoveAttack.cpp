{
  army *thisa; // [sp+Ch] [bp-1Ch]@1
  int knownHex; // [sp+10h] [bp-18h]@24
  int v5; // [sp+14h] [bp-14h]@13
  int v6; // [sp+18h] [bp-10h]@7
  signed int hexIdxa; // [sp+20h] [bp-8h]@20
  int v8; // [sp+24h] [bp-4h]@38

  for ( thisa = this; ; army::FlyTo(thisa, thisa->targetHex) )
  {
    gpCombatManager->field_F2B7 = 0;
    thisa->targetOwner = -1;
    thisa->targetStackIdx = -1;
    if ( !ValidHex(hexIdx) )
      break;
    if ( gpCombatManager->combatGrid[hexIdx].unitOwner == -1
      || gpCombatManager->combatGrid[hexIdx].unitOwner == gpCombatManager->otherCurrentSideThing
      && gpCombatManager->combatGrid[hexIdx].stackIdx == gpCombatManager->someSortOfStackIdx )
    {
      if ( thisa->creature.creature_flags & FLYER )
      {
        thisa->targetHex = hexIdx;
        if ( !army::ValidFlight(thisa, thisa->targetHex, 0) )
          return;
        army::FlyTo(thisa, thisa->targetHex);
      }
      else
      {
        army::WalkTo(thisa, hexIdx);
      }
      goto LABEL_49;
    }
    if ( a3 )
      return;
    thisa->targetOwner = gpCombatManager->combatGrid[hexIdx].unitOwner;
    thisa->targetStackIdx = gpCombatManager->combatGrid[hexIdx].stackIdx;
    thisa->targetHex = hexIdx;
    v6 = army::GetAttackMask(thisa, thisa->occupiedHex, 0, -1);
    if ( !(thisa->creature.creature_flags & FLYER) || v6 != 255 )
    {
      if ( thisa->effectStrengths[5] )
        v5 = army::GetAttackMask(thisa, thisa->occupiedHex, 2, -1);
      else
        v5 = army::GetAttackMask(thisa, thisa->occupiedHex, 1, -1);
      if ( v5 != 255 || thisa->creature.shots <= 0 )
      {
        if ( v6 == 255 )
        {
          army::AttackTo(thisa);
        }
        else
        {
          for ( hexIdxa = 0; hexIdxa < 8; ++hexIdxa )
          {
            if ( hexIdxa < 6 || thisa->creature.creature_flags & TWO_HEXER )
            {
              knownHex = thisa->occupiedHex;
              if ( thisa->creature.creature_flags & TWO_HEXER && thisa->facingRight == 1 && hexIdxa >= 0 && hexIdxa <= 2 )
                ++knownHex;
              if ( thisa->creature.creature_flags & TWO_HEXER && !thisa->facingRight && hexIdxa >= 3 && hexIdxa <= 5 )
                --knownHex;
              if ( hexIdxa >= 6 )
              {
                if ( thisa->facingRight == 1 )
                  ++knownHex;
                else
                  --knownHex;
              }
              v8 = army::GetAdjacentCellIndex(thisa, knownHex, hexIdxa);
              if ( ValidHex(v8)
                && gpCombatManager->combatGrid[v8].unitOwner == thisa->targetOwner
                && gpCombatManager->combatGrid[v8].stackIdx == thisa->targetStackIdx )
                thisa->targetNeighborIdx = hexIdxa;
            }
          }
          army::DoAttack(thisa, 0);
        }
      }
      else
      {
        army::SpecialAttack(thisa);
      }
LABEL_49:
      gpCombatManager->field_F2B7 = 1;
      return;
    }
    if ( thisa->occupiedHex != thisa->targetHex && !army::ValidFlight(thisa, thisa->targetHex, 0) )
      return;
  }
}