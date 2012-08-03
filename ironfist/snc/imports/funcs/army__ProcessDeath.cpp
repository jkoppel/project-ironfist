{
  char *v2; // eax@29
  army *thisa; // [sp+Ch] [bp-18h]@1
  hexcell *hexTile; // [sp+18h] [bp-Ch]@6
  hexcell *secondHexTile; // [sp+1Ch] [bp-8h]@7
  int v6; // [sp+20h] [bp-4h]@6

  thisa = this;
  if ( !(this->creature.creature_flags & 0x10) )
  {
    if ( Random(0, 100) >= 60 )
    {
      if ( Random(0, 100) < 80 )
        gpCombatManager->field_339F[1 - thisa->owningSide] = 1;
    }
    else
    {
      gpCombatManager->field_339D[thisa->owningSide] = 1;
    }
    *(_DWORD *)&thisa->creature.creature_flags |= 0x10u;
    thisa->dead = 0;
    hexTile = &gpCombatManager->combatGrid[thisa->occupiedHex];
    v6 = 0;
    if ( thisa->creature.creature_flags & TWO_HEXER )
    {
      v6 = thisa->occupiedHex + ((unsigned int)(thisa->facingRight - 1) < 1 ? 1 : -1);
      secondHexTile = &gpCombatManager->combatGrid[v6];
    }
    else
    {
      secondHexTile = 0;
    }
    if ( army::LeaveNoBody(thisa) )
    {
      if ( a2
        || thisa->creatureIdx != CREATURE_AIR_ELEMENTAL
        && thisa->creatureIdx != CREATURE_FIRE_ELEMENTAL
        && thisa->creatureIdx != CREATURE_WATER_ELEMENTAL
        && thisa->creatureIdx != CREATURE_EARTH_ELEMENTAL )
      {
        gpCombatManager->field_F577[thisa->owningSide][thisa->stackIdx] = 1;
        gpCombatManager->field_F59F = 1;
      }
      else
      {
        hexTile->unitOwner = -1;
        hexTile->stackIdx = -1;
      }
    }
    if ( hexTile->numCorpses < 14 && !army::LeaveNoBody(thisa) && (!secondHexTile || secondHexTile->numCorpses < 14) )
    {
      hexTile->corpseOwners[hexTile->numCorpses] = gpCombatManager->combatGrid[thisa->occupiedHex].unitOwner;
      hexTile->corpseStackIndices[hexTile->numCorpses] = gpCombatManager->combatGrid[thisa->occupiedHex].stackIdx;
      hexTile->field_33[hexTile->numCorpses++] = gpCombatManager->combatGrid[thisa->occupiedHex].isOccupierNonPrimaryHex;
      if ( secondHexTile )
      {
        secondHexTile->corpseOwners[secondHexTile->numCorpses] = gpCombatManager->combatGrid[v6].unitOwner;
        secondHexTile->corpseStackIndices[secondHexTile->numCorpses] = gpCombatManager->combatGrid[v6].stackIdx;
        secondHexTile->field_33[secondHexTile->numCorpses++] = gpCombatManager->combatGrid[v6].isOccupierNonPrimaryHex;
      }
    }
    if ( !army::LeaveNoBody(thisa) )
    {
      hexTile->unitOwner = -1;
      hexTile->stackIdx = -1;
      if ( secondHexTile )
      {
        secondHexTile->unitOwner = -1;
        secondHexTile->stackIdx = -1;
      }
    }
    if ( thisa->mirroredIdx != -1 )
      gpCombatManager->creatures[thisa->owningSide][thisa->mirroredIdx].mirrorIdx = -1;
    if ( thisa->mirrorIdx != -1 )
    {
      v2 = (char *)gpCombatManager + 24234 * thisa->owningSide + 1154 * thisa->mirrorIdx;
      *(_DWORD *)(v2 + 13797) = 0;
      army::ProcessDeath((army *)(v2 + 13647), 0);
    }
  }
}