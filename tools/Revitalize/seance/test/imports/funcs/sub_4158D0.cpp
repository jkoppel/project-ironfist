{
  TownManager *thisa; // [sp+Ch] [bp-30h]@1
  int imageIdx; // [sp+18h] [bp-24h]@20
  signed int buildingDispForNewBuildingIdx; // [sp+1Ch] [bp-20h]@13
  H2RECT rect; // [sp+20h] [bp-1Ch]@22
  int i; // [sp+30h] [bp-Ch]@7
  sample_resource res; // [sp+34h] [bp-8h]@27

  thisa = this;
  if ( (!((1 << buildingCode) & this->castle->buildingsBuiltFlags) || !buildingCode && this->castle->mageGuildLevel != 5)
    && (buildingCode != BUILDING_DOCK || Castle::adjacentToWater(this->castle)) )
  {
    TownManager::paintTown(thisa, 1, 1);
    Castle::buildBuilding(thisa->castle, buildingCode);
    for ( i = 0; thisa->curBuilding > i; ++i )
    {
      if ( (1 << LOBYTE(thisa->buildingDisplays[i]->buildingCode)) & thisa->castle->buildingsBuiltFlags )
      {
        thisa->buildingDisplays[i]->built = 1;
        thisa->buildingDisplays[i]->guiElement->flagsRelatedToShouldDisplayAndPerhapsMouseCode |= 2u;
      }
      else
      {
        thisa->buildingDisplays[i]->built = 0;
        thisa->buildingDisplays[i]->guiElement->flagsRelatedToShouldDisplayAndPerhapsMouseCode &= 0xFFFDu;
      }
    }
    buildingDispForNewBuildingIdx = -1;
    for ( i = 0; thisa->curBuilding > i; ++i )
    {
      if ( thisa->buildingDisplays[i]->buildingCode == buildingCode )
        buildingDispForNewBuildingIdx = i;
    }
    combatScreenRedrawRectBot = 0;
    combatScreenRedrawRectRight = 0;
    combatScreenRedrawRectLeft = 639;
    combatScreenRedrawRectTop = 255;
    dword_4F7480 = 1;
    dword_4F7484 = 1;
    dword_4F1998 = 1;
    if ( buildingCode )
    {
      Icon::drawToScreenAndSetRectBounds(
        thisa->buildingDisplays[buildingDispForNewBuildingIdx]->icon,
        0,
        0,
        0,
        &rect,
        0,
        0,
        0,
        0);
      if ( thisa->buildingDisplays[buildingDispForNewBuildingIdx]->animationLength )
        Icon::drawToScreenAndSetRectBounds(
          thisa->buildingDisplays[buildingDispForNewBuildingIdx]->icon,
          0,
          0,
          1,
          &rect,
          0,
          0,
          0,
          0);
    }
    else
    {
      if ( townManager->castle->factionID == FACTION_NECROMANCER )
        imageIdx = 2 * (3 * townManager->castle->mageGuildLevel - 3);
      else
        imageIdx = townManager->castle->mageGuildLevel - 1;
      Icon::drawToScreenAndSetRectBounds(
        thisa->buildingDisplays[buildingDispForNewBuildingIdx]->icon,
        0,
        0,
        imageIdx,
        &rect,
        0,
        0,
        0,
        0);
      if ( thisa->buildingDisplays[buildingDispForNewBuildingIdx]->animationLength )
        Icon::drawToScreenAndSetRectBounds(
          thisa->buildingDisplays[buildingDispForNewBuildingIdx]->icon,
          0,
          0,
          imageIdx + 1,
          &rect,
          0,
          0,
          0,
          0);
    }
    dword_4F7480 = 0;
    dword_4F7484 = 0;
    dword_4F1998 = 0;
    HeroWindowManager::resetSomeBMP(
      HeroWindowManager::instance,
      combatScreenRedrawRectLeft,
      combatScreenRedrawRectTop,
      combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
      combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
    TownManager::paintTown(thisa, 0, 1);
    res = stru_5230F8;
    res = playSample("buildtwn.82M");
    sub_4C7E00(
      HeroWindowManager::instance,
      combatScreenRedrawRectLeft,
      combatScreenRedrawRectTop,
      combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
      combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1,
      -1,
      0,
      0);
    waitForSampleToFinish(-1, res);
    yieldToGlobalUpdater();
    thisa->field_15E = -1;
    HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 6, 30720, 16392);
    TownManager::paint(thisa);
  }
}
