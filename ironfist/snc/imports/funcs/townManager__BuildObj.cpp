{
  townManager *thisa; // [sp+Ch] [bp-30h]@1
  int imageIdx; // [sp+18h] [bp-24h]@20
  signed int buildingDispForNewBuildingIdx; // [sp+1Ch] [bp-20h]@13
  H2RECT rect; // [sp+20h] [bp-1Ch]@22
  int i; // [sp+30h] [bp-Ch]@7
  sample_resource res; // [sp+34h] [bp-8h]@27

  thisa = this;
  if ( (!((1 << buildingCode) & this->castle->buildingsBuiltFlags) || !buildingCode && this->castle->mageGuildLevel != 5)
    && (buildingCode != BUILDING_DOCK || town::CanBuildDock(this->castle)) )
  {
    townManager::DrawTown(thisa, 1, 1);
    town::BuildBuilding(thisa->castle, buildingCode);
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
    giMaxExtentY = 0;
    giMaxExtentX = 0;
    giMinExtentX = 639;
    giMinExtentY = 255;
    gbComputeExtent = 1;
    gbSaveBiggestExtent = 1;
    gbReturnAfterComputeExtent = 1;
    if ( buildingCode )
    {
      icon::CombatClipDrawToBuffer(
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
        icon::CombatClipDrawToBuffer(
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
      if ( gpTownManager->castle->factionID == FACTION_NECROMANCER )
        imageIdx = 2 * (3 * gpTownManager->castle->mageGuildLevel - 3);
      else
        imageIdx = gpTownManager->castle->mageGuildLevel - 1;
      icon::CombatClipDrawToBuffer(
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
        icon::CombatClipDrawToBuffer(
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
    gbComputeExtent = 0;
    gbSaveBiggestExtent = 0;
    gbReturnAfterComputeExtent = 0;
    heroWindowManager::SaveFizzleSource(
      gpWindowManager,
      giMinExtentX,
      giMinExtentY,
      giMaxExtentX - giMinExtentX + 1,
      giMaxExtentY - giMinExtentY + 1);
    townManager::DrawTown(thisa, 0, 1);
    res = NULL_SAMPLE2;
    res = LoadPlaySample("buildtwn.82M");
    heroWindowManager::FizzleForward(
      gpWindowManager,
      giMinExtentX,
      giMinExtentY,
      giMaxExtentX - giMinExtentX + 1,
      giMaxExtentY - giMinExtentY + 1,
      -1,
      0,
      0);
    WaitEndSample(-1, res);
    PollSound();
    thisa->field_15E = -1;
    heroWindowManager::BroadcastMessage(gpWindowManager, INPUT_GUI_MESSAGE_CODE, 6, 30720, 16392);
    townManager::RedrawTownScreen(thisa);
  }
}