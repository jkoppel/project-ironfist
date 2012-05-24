void __thiscall CreatureStack::die(CreatureStack *this, int a2)
{
  char *v2; // eax@29
  CreatureStack *thisa; // [sp+Ch] [bp-18h]@1
  CombatHexTile *hexTile; // [sp+18h] [bp-Ch]@6
  CombatHexTile *secondHexTile; // [sp+1Ch] [bp-8h]@7
  int v6; // [sp+20h] [bp-4h]@6

  thisa = this;
  if ( !(this->creature.creature_flags & 0x10) )
  {
    if ( unseededNextRand(0, 100) >= 60 )
    {
      if ( unseededNextRand(0, 100) < 80 )
        combatManager->field_339F[1 - thisa->owningSide] = 1;
    }
    else
    {
      combatManager->field_339D[thisa->owningSide] = 1;
    }
    *(_DWORD *)&thisa->creature.creature_flags |= 0x10u;
    thisa->dead = 0;
    hexTile = &combatManager->combatGrid[thisa->occupiedHex];
    v6 = 0;
    if ( thisa->creature.creature_flags & TWO_HEXER )
    {
      v6 = thisa->occupiedHex + ((unsigned int)(thisa->facingRight - 1) < 1 ? 1 : -1);
      secondHexTile = &combatManager->combatGrid[v6];
    }
    else
    {
      secondHexTile = 0;
    }
    if ( CreatureStack::isElementalOrMirrorImage(thisa) )
    {
      if ( a2
        || thisa->creatureIdx != CREATURE_AIR_ELEMENTAL
        && thisa->creatureIdx != CREATURE_FIRE_ELEMENTAL
        && thisa->creatureIdx != CREATURE_WATER_ELEMENTAL
        && thisa->creatureIdx != CREATURE_EARTH_ELEMENTAL )
      {
        combatManager->field_F577[thisa->owningSide][thisa->stackIdx] = 1;
        combatManager->field_F59F = 1;
      }
      else
      {
        hexTile->unitOwner = -1;
        hexTile->stackIdx = -1;
      }
    }
    if ( hexTile->numCorpses < 14
      && !CreatureStack::isElementalOrMirrorImage(thisa)
      && (!secondHexTile || secondHexTile->numCorpses < 14) )
    {
      hexTile->corpseOwners[hexTile->numCorpses] = combatManager->combatGrid[thisa->occupiedHex].unitOwner;
      hexTile->corpseStackIndices[hexTile->numCorpses] = combatManager->combatGrid[thisa->occupiedHex].stackIdx;
      hexTile->field_33[hexTile->numCorpses++] = combatManager->combatGrid[thisa->occupiedHex].isOccupierNonPrimaryHex;
      if ( secondHexTile )
      {
        secondHexTile->corpseOwners[secondHexTile->numCorpses] = combatManager->combatGrid[v6].unitOwner;
        secondHexTile->corpseStackIndices[secondHexTile->numCorpses] = combatManager->combatGrid[v6].stackIdx;
        secondHexTile->field_33[secondHexTile->numCorpses++] = combatManager->combatGrid[v6].isOccupierNonPrimaryHex;
      }
    }
    if ( !CreatureStack::isElementalOrMirrorImage(thisa) )
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
      combatManager->creatures[thisa->owningSide][thisa->mirroredIdx].mirrorIdx = -1;
    if ( thisa->mirrorIdx != -1 )
    {
      v2 = (char *)combatManager + 24234 * thisa->owningSide + 1154 * thisa->mirrorIdx;
      *(_DWORD *)(v2 + 13797) = 0;
      CreatureStack::die((CreatureStack *)(v2 + 13647), 0);
    }
  }
}
