{
  BuildingDisplay *thisa; // [sp+Ch] [bp-8h]@1
  int spriteIdx; // [sp+10h] [bp-4h]@48

  thisa = this;
  if ( this->built
    && this->buildingCode != BUILDING_TENT
    && (this->buildingCode != BUILDING_EXT_1
     || townManager->castle->factionID
     || townManager->castle->buildingsBuiltFlags & 4
     && (townManager->castle->buildingsBuiltFlags & 1
      || BYTE3(townManager->castle->buildingsBuiltFlags) & 1
      || BYTE3(townManager->castle->buildingsBuiltFlags) & 0x20))
    && (this->buildingCode != BUILDING_EXT_2
     || townManager->castle->factionID
     || townManager->castle->buildingsBuiltFlags & 1
     && (BYTE3(townManager->castle->buildingsBuiltFlags) & 1 || BYTE3(townManager->castle->buildingsBuiltFlags) & 0x20))
    && (this->buildingCode != BUILDING_EXT_2
     || townManager->castle->factionID != 1
     || townManager->castle->buildingsBuiltFlags & 1 && BYTE1(townManager->castle->buildingsBuiltFlags) & 0x20)
    && (this->buildingCode != BUILDING_EXT_3
     || townManager->castle->factionID != 1
     || townManager->castle->buildingsBuiltFlags & 2 && BYTE2(townManager->castle->buildingsBuiltFlags) & 0x20)
    && (townManager->castle->factionID != 2
     || this->buildingCode != BUILDING_EXT_1
     || townManager->castle->buildingsBuiltFlags & 0x80 && BYTE1(townManager->castle->buildingsBuiltFlags) & 8)
    && (townManager->castle->factionID != 2
     || this->buildingCode != BUILDING_STATUE && this->buildingCode != BUILDING_SPECIAL_GROWTH
     || !(townManager->castle->buildingsBuiltFlags & 0x80)
     || !(BYTE1(townManager->castle->buildingsBuiltFlags) & 8))
    && (this->buildingCode != BUILDING_EXT_0
     || townManager->castle->factionID != 5
     && townManager->castle->factionID != 3
     && townManager->castle->factionID != 2
     && townManager->castle->factionID
     || !(BYTE1(townManager->castle->buildingsBuiltFlags) & 0x40) && !(townManager->castle->buildingsBuiltFlags & 8))
    && (this->buildingCode != 3 || !(BYTE1(townManager->castle->buildingsBuiltFlags) & 0x40)) )
  {
    if ( this->buildingCode )
    {
      Icon::drawToScreen(this->icon, 0, 0, 0, 0);
      if ( thisa->animationLength )
      {
        Icon::drawToScreen(thisa->icon, 0, 0, thisa->animationIdx + 1, 0);
        if ( advanceAnimations == 1 )
        {
          ++thisa->animationIdx;
          if ( thisa->animationIdx == thisa->animationLength )
            thisa->animationIdx = 0;
        }
      }
    }
    else
    {
      if ( townManager->castle->factionID == FACTION_NECROMANCER )
        spriteIdx = 2 * (3 * townManager->castle->mageGuildLevel - 3);
      else
        spriteIdx = townManager->castle->mageGuildLevel - 1;
      Icon::drawToScreen(this->icon, 0, 0, spriteIdx, 0);
      if ( thisa->animationLength
        && (townManager->castle->factionID != FACTION_BARBARIAN || townManager->castle->mageGuildLevel >= 5) )
      {
        Icon::drawToScreen(thisa->icon, 0, 0, spriteIdx + thisa->animationIdx + 1, 0);
        if ( advanceAnimations == 1 )
        {
          ++thisa->animationIdx;
          if ( thisa->animationIdx == thisa->animationLength )
            thisa->animationIdx = 0;
        }
      }
    }
  }
}
