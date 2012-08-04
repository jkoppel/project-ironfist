{
  army *creature; // ST38_4@17
  int v8; // edx@20
  combatManager *thisa; // [sp+Ch] [bp-14h]@1
  int newStackIDx; // [sp+10h] [bp-10h]@1
  spellpower_offset i; // [sp+14h] [bp-Ch]@1
  signed int replacingStack; // [sp+18h] [bp-8h]@1

  thisa = this;
  newStackIDx = -1;
  replacingStack = 0;
  for ( i = 0; i < MAX_STACKS; ++i )
  {
    if ( this->creatures[side][i].creatureIdx == -1 )
    {
      newStackIDx = i;
      break;
    }
    if ( !this->creatures[side][i].quantity
      && this->creatures[side][i].creature.creature_flags & DEAD
      && (HIBYTE(this->creatures[side][i].creature.creature_flags) & ATTR_MIRROR_IMAGE
       || this->creatures[side][i].creatureIdx == CREATURE_EARTH_ELEMENTAL
       || this->creatures[side][i].creatureIdx == CREATURE_AIR_ELEMENTAL
       || this->creatures[side][i].creatureIdx == CREATURE_FIRE_ELEMENTAL
       || this->creatures[side][i].creatureIdx == CREATURE_WATER_ELEMENTAL) )
    {
      newStackIDx = i;
      replacingStack = 1;
      break;
    }
  }
  if ( newStackIDx != -1 && this->combatGrid[hex].unitOwner == -1 )
  {
    creature = &this->creatures[side][newStackIDx];
    army::Init(&this->creatures[side][newStackIDx], creatureID, num, side, newStackIDx, hex, -1);
    army::LoadResources(creature);
    *(_DWORD *)&creature->creature.creature_flags |= attrs;
    if ( !replacingStack )
      ++thisa->numCreatures[side];
    if ( a7 )
    {
      combatManager::ResetLimitCreature(thisa);
      ++thisa->stuffHappenedToCreature[side][newStackIDx];
      combatManager::DrawFrame(gpCombatManager, 0, 1, 0, 1, 75, 1, 1);
      heroWindowManager::SaveFizzleSource(
        gpWindowManager,
        giMinExtentX,
        giMinExtentY,
        giMaxExtentX - giMinExtentX + 1,
        giMaxExtentY - giMinExtentY + 1);
      combatManager::UpdateGrid(thisa, v8, 0, 1);
      combatManager::DrawFrame(thisa, 0, 0, 0, 0, 75, 1, 1);
      heroWindowManager::FizzleForward(
        gpWindowManager,
        giMinExtentX,
        giMinExtentY,
        giMaxExtentX - giMinExtentX + 1,
        giMaxExtentY - giMinExtentY + 1,
        75,
        0,
        0);
    }
  }
}