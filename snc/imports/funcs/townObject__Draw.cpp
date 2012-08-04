{
  BuildingDisplay *thisa; // [sp+Ch] [bp-8h]@1
  int spriteIdx; // [sp+10h] [bp-4h]@48

  thisa = this;
  if ( this->built
    && this->buildingCode != BUILDING_TENT
    && (this->buildingCode != BUILDING_EXT_1
     || gpTownManager->castle->factionID
     || gpTownManager->castle->buildingsBuiltFlags & 4
     && (gpTownManager->castle->buildingsBuiltFlags & 1
      || BYTE3(gpTownManager->castle->buildingsBuiltFlags) & 1
      || BYTE3(gpTownManager->castle->buildingsBuiltFlags) & 0x20))
    && (this->buildingCode != BUILDING_EXT_2
     || gpTownManager->castle->factionID
     || gpTownManager->castle->buildingsBuiltFlags & 1
     && (BYTE3(gpTownManager->castle->buildingsBuiltFlags) & 1
      || BYTE3(gpTownManager->castle->buildingsBuiltFlags) & 0x20))
    && (this->buildingCode != BUILDING_EXT_2
     || gpTownManager->castle->factionID != 1
     || gpTownManager->castle->buildingsBuiltFlags & 1 && BYTE1(gpTownManager->castle->buildingsBuiltFlags) & 0x20)
    && (this->buildingCode != BUILDING_EXT_3
     || gpTownManager->castle->factionID != 1
     || gpTownManager->castle->buildingsBuiltFlags & 2 && BYTE2(gpTownManager->castle->buildingsBuiltFlags) & 0x20)
    && (gpTownManager->castle->factionID != 2
     || this->buildingCode != BUILDING_EXT_1
     || gpTownManager->castle->buildingsBuiltFlags & 0x80 && BYTE1(gpTownManager->castle->buildingsBuiltFlags) & 8)
    && (gpTownManager->castle->factionID != 2
     || this->buildingCode != BUILDING_STATUE && this->buildingCode != BUILDING_SPECIAL_GROWTH
     || !(gpTownManager->castle->buildingsBuiltFlags & 0x80)
     || !(BYTE1(gpTownManager->castle->buildingsBuiltFlags) & 8))
    && (this->buildingCode != BUILDING_EXT_0
     || gpTownManager->castle->factionID != 5
     && gpTownManager->castle->factionID != 3
     && gpTownManager->castle->factionID != 2
     && gpTownManager->castle->factionID
     || !(BYTE1(gpTownManager->castle->buildingsBuiltFlags) & 0x40) && !(gpTownManager->castle->buildingsBuiltFlags & 8))
    && (this->buildingCode != 3 || !(BYTE1(gpTownManager->castle->buildingsBuiltFlags) & 0x40)) )
  {
    if ( this->buildingCode )
    {
      icon::DrawToBuffer(this->icon, 0, 0, 0, 0);
      if ( thisa->animationLength )
      {
        icon::DrawToBuffer(thisa->icon, 0, 0, thisa->animationIdx + 1, 0);
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
      if ( gpTownManager->castle->factionID == FACTION_NECROMANCER )
        spriteIdx = 2 * (3 * gpTownManager->castle->mageGuildLevel - 3);
      else
        spriteIdx = gpTownManager->castle->mageGuildLevel - 1;
      icon::DrawToBuffer(this->icon, 0, 0, spriteIdx, 0);
      if ( thisa->animationLength
        && (gpTownManager->castle->factionID != FACTION_BARBARIAN || gpTownManager->castle->mageGuildLevel >= 5) )
      {
        icon::DrawToBuffer(thisa->icon, 0, 0, spriteIdx + thisa->animationIdx + 1, 0);
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