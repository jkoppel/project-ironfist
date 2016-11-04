{
  CreatureStack *thisa; // [sp+Ch] [bp-1Ch]@1
  int knownHex; // [sp+10h] [bp-18h]@24
  int v5; // [sp+14h] [bp-14h]@13
  int v6; // [sp+18h] [bp-10h]@7
  signed int hexIdxa; // [sp+20h] [bp-8h]@20
  int v8; // [sp+24h] [bp-4h]@38

  for ( thisa = this; ; sub_401700(thisa, thisa->targetHex) )
  {
    combatManager->field_F2B7 = 0;
    thisa->targetOwner = -1;
    thisa->targetStackIdx = -1;
    if ( !checkHexGridIdxBounds(hexIdx) )
      break;
    if ( combatManager->combatGrid[hexIdx].unitOwner == -1
      || combatManager->combatGrid[hexIdx].unitOwner == combatManager->otherCurrentSideThing
      && combatManager->combatGrid[hexIdx].stackIdx == combatManager->someSortOfStackIdx )
    {
      if ( thisa->creature.creature_flags & FLYER )
      {
        thisa->targetHex = hexIdx;
        if ( !sub_4012C0(thisa, thisa->targetHex, 0) )
          return;
        sub_401700(thisa, thisa->targetHex);
      }
      else
      {
        CreatureStack::walkTo(thisa, hexIdx);
      }
      goto LABEL_49;
    }
    if ( a3 )
      return;
    thisa->targetOwner = combatManager->combatGrid[hexIdx].unitOwner;
    thisa->targetStackIdx = combatManager->combatGrid[hexIdx].stackIdx;
    thisa->targetHex = hexIdx;
    v6 = CreatureStack::getFreeNeighborBitmask(thisa, thisa->occupiedHex, 0, -1);
    if ( !(thisa->creature.creature_flags & FLYER) || v6 != 255 )
    {
      if ( thisa->effectStrengths[5] )
        v5 = CreatureStack::getFreeNeighborBitmask(thisa, thisa->occupiedHex, 2, -1);
      else
        v5 = CreatureStack::getFreeNeighborBitmask(thisa, thisa->occupiedHex, 1, -1);
      if ( v5 != 255 || thisa->creature.shots <= 0 )
      {
        if ( v6 == 255 )
        {
          sub_47FDE0(thisa);
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
              v8 = CreatureStack::getHexNeighbor(thisa, knownHex, hexIdxa);
              if ( checkHexGridIdxBounds(v8)
                && combatManager->combatGrid[v8].unitOwner == thisa->targetOwner
                && combatManager->combatGrid[v8].stackIdx == thisa->targetStackIdx )
                thisa->targetNeighborIdx = hexIdxa;
            }
          }
          CreatureStack::performMeleeAttack(thisa, 0);
        }
      }
      else
      {
        CreatureStack::fireShot(thisa);
      }
LABEL_49:
      combatManager->field_F2B7 = 1;
      return;
    }
    if ( thisa->occupiedHex != thisa->targetHex && !sub_4012C0(thisa, thisa->targetHex, 0) )
      return;
  }
}
