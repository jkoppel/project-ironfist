{
  const char *v1; // eax@1
  ArmyInfo *v2; // ST14_4@46
  int v3; // ST10_4@46
  int v4; // eax@46
  ArmyInfo *visitorArmy; // ST14_4@52
  int v6; // eax@52
  int v7; // ST20_4@61
  int v8; // eax@61
  int v9; // eax@67
  TownManager *thisa; // [sp+Ch] [bp-58h]@1
  ArmyDisplay *v11; // [sp+10h] [bp-54h]@66
  ArmyDisplay *v12; // [sp+14h] [bp-50h]@60
  ArmyDisplay *v13; // [sp+18h] [bp-4Ch]@51
  ArmyDisplay *ecx0; // [sp+1Ch] [bp-48h]@45
  ArmyDisplay *v15; // [sp+24h] [bp-40h]@39
  ArmyDisplay *v16; // [sp+2Ch] [bp-38h]@36
  BuildingDisplay *v17; // [sp+30h] [bp-34h]@14
  Bankbox *thisb; // [sp+34h] [bp-30h]@6
  int v19; // [sp+38h] [bp-2Ch]@28
  int buildingCode; // [sp+3Ch] [bp-28h]@13
  GUIMessage evt; // [sp+40h] [bp-24h]@1
  int i; // [sp+5Ch] [bp-8h]@11
  int v23; // [sp+60h] [bp-4h]@42

  thisa = this;
  v1 = getCastleName(this->castle->idx);
  sprintf(globBuf, v1);
  evt.eventCode = 512;
  evt.messageType = GUI_MESSAGE_SET_CONTENTS;
  evt.fieldID = 137;
  evt.payload = globBuf;
  GUIWindow::processMessage(thisa->townScreen, (Event *)&evt);
  strcpy(globBuf, "Town Screen");
  evt.fieldID = 902;
  evt.payload = globBuf;
  GUIWindow::processMessage(thisa->townScreen, (Event *)&evt);
  GUIWindow::repaintComponentsInRange(thisa->townScreen, 0, 800, 801);
  if ( curPlayer->numCastles == 1 )
  {
    evt.messageType = GUI_MESSAGE_ADD_FLAGS;
    evt.payload = (void *)4096;
    evt.fieldID = 903;
    GUIWindow::processMessage(thisa->townScreen, (Event *)&evt);
    evt.fieldID = 904;
    GUIWindow::processMessage(thisa->townScreen, (Event *)&evt);
    evt.messageType = 6;
    evt.payload = (void *)2;
    evt.fieldID = 903;
    GUIWindow::processMessage(thisa->townScreen, (Event *)&evt);
    evt.fieldID = 904;
    GUIWindow::processMessage(thisa->townScreen, (Event *)&evt);
  }
  if ( thisa->castle->factionID == thisa->factionID )
  {
    thisa->curBuilding = 0;
    for ( i = 0; i < 32; ++i )
    {
      v19 = byte_4EA068[thisa->castle->factionID][i];
      if ( v19 != -1 )
      {
        if ( thisa->buildingDisplays[thisa->curBuilding]->guiElement )
        {
          if ( (1 << v19) & thisa->castle->buildingsBuiltFlags )
          {
            thisa->buildingDisplays[thisa->curBuilding]->guiElement->flagsRelatedToShouldDisplayAndPerhapsMouseCode |= 2u;
            thisa->buildingDisplays[thisa->curBuilding]->built = 1;
          }
          else
          {
            thisa->buildingDisplays[thisa->curBuilding]->guiElement->flagsRelatedToShouldDisplayAndPerhapsMouseCode &= 0xFFFDu;
            thisa->buildingDisplays[thisa->curBuilding]->built = 0;
          }
        }
        ++thisa->curBuilding;
      }
    }
    if ( thisa->visitingArmyDisplay )
    {
      v16 = thisa->visitingArmyDisplay;
      if ( v16 )
      {
        ArmyDisplay::cleanUp(v16);
        operator delete(v16);
      }
    }
    thisa->visitingArmyDisplay = 0;
    if ( thisa->garrisonDisplay )
    {
      v15 = thisa->garrisonDisplay;
      if ( v15 )
      {
        ArmyDisplay::cleanUp(v15);
        operator delete(v15);
      }
    }
    thisa->garrisonDisplay = 0;
  }
  else
  {
    if ( thisa->factionID != -1 )
      TownManager::reset(thisa);
    thisb = (Bankbox *)operator new(0xCu);
    if ( thisb )
      thisa->bankbox = Bankbox_constructor(thisb, 546, 256, curPlayer);
    else
      thisa->bankbox = 0;
    if ( !thisa->bankbox )
      fatalOutOfMemoryError();
    sprintf(globBuf, "townbkg%d.icn", thisa->castle->factionID);
    thisa->couldBeBackground = ResourceManager::getIconByFilename(resourceManager, globBuf);
    thisa->curBuilding = 0;
    for ( i = 0; i < 32; ++i )
    {
      buildingCode = byte_4EA068[thisa->castle->factionID][i];
      if ( buildingCode != -1 )
      {
        sprintf(globBuf, "%s%s", townShortNames[thisa->castle->factionID], buildingShortNames[buildingCode]);
        v17 = (BuildingDisplay *)operator new(0x18u);
        if ( v17 )
          thisa->buildingDisplays[thisa->curBuilding] = BuildingDisplay_constructor(
                                                          v17,
                                                          thisa->castle->factionID,
                                                          buildingCode,
                                                          globBuf);
        else
          thisa->buildingDisplays[thisa->curBuilding] = 0;
        if ( !thisa->buildingDisplays[thisa->curBuilding] )
          fatalOutOfMemoryError();
        if ( thisa->buildingDisplays[thisa->curBuilding]->guiElement )
        {
          if ( !((1 << buildingCode) & thisa->castle->buildingsBuiltFlags) )
          {
            thisa->buildingDisplays[thisa->curBuilding]->guiElement->flagsRelatedToShouldDisplayAndPerhapsMouseCode &= 0xFFFDu;
            thisa->buildingDisplays[thisa->curBuilding]->built = 0;
          }
          GUIWindow::insertElement(
            thisa->townScreen,
            (AbstractGUIComponent *)thisa->buildingDisplays[thisa->curBuilding]->guiElement,
            -1);
        }
        ++thisa->curBuilding;
      }
    }
    HeroWindowManager::addWindow(HeroWindowManager::instance, thisa->townScreen, 0, 1);
  }
  v23 = curPlayer->color;
  if ( thisa->castle->visitingHeroIdx == -1 )
  {
    v23 += 16;
  }
  else
  {
    v23 *= 4;
    v23 += gameObject->heroes[thisa->castle->visitingHeroIdx].factionID;
  }
  ecx0 = (ArmyDisplay *)operator new(0x84u);
  if ( ecx0 )
  {
    v2 = &thisa->castle->garrison;
    v3 = curPlayer->color;
    v4 = ResourceManager::setResource(resourceManager, "crest.icn", 1);
    thisa->garrisonDisplay = ArmyDisplay::constructor(
                               ecx0,
                               0,
                               256,
                               (unsigned int)(thisa->castle->visitingHeroIdx + 1) < 1 ? 4 : 1,
                               v4,
                               v3,
                               v2,
                               116,
                               0,
                               -1);
  }
  else
  {
    thisa->garrisonDisplay = 0;
  }
  if ( !thisa->garrisonDisplay )
    fatalOutOfMemoryError();
  if ( thisa->castle->visitingHeroIdx == -1 )
  {
    if ( BYTE1(thisa->castle->buildingsBuiltFlags) & 0x80 )
    {
      sprintf(globBuf, "port%04d.icn", thisa->castle->factionID + 90);
      v12 = (ArmyDisplay *)operator new(0x84u);
      if ( v12 )
      {
        v7 = curPlayer->color;
        v8 = ResourceManager::setResource(resourceManager, globBuf, 1);
        thisa->visitingArmyDisplay = ArmyDisplay::constructor(v12, 0, 355, 3, v8, 0, 0, -1, 0, v7);
      }
      else
      {
        thisa->visitingArmyDisplay = 0;
      }
      if ( !thisa->visitingArmyDisplay )
        fatalOutOfMemoryError();
    }
    else
    {
      v11 = (ArmyDisplay *)operator new(0x84u);
      if ( v11 )
      {
        v9 = ResourceManager::setResource(resourceManager, "strip.icn", 1);
        thisa->visitingArmyDisplay = ArmyDisplay::constructor(v11, 0, 355, 3, v9, 3, 0, -1, 0, -1);
      }
      else
      {
        thisa->visitingArmyDisplay = 0;
      }
      if ( !thisa->visitingArmyDisplay )
        fatalOutOfMemoryError();
    }
  }
  else
  {
    sprintf(globBuf, "port%04d.icn", gameObject->heroes[thisa->castle->visitingHeroIdx].heroID);
    v13 = (ArmyDisplay *)operator new(132u);
    if ( v13 )
    {
      visitorArmy = &gameObject->heroes[thisa->castle->visitingHeroIdx].army;
      v6 = ResourceManager::setResource(resourceManager, globBuf, 1);
      thisa->visitingArmyDisplay = ArmyDisplay::constructor(v13, 0, 355, 3, v6, 0, visitorArmy, 122, 0, -1);
    }
    else
    {
      thisa->visitingArmyDisplay = 0;
    }
    if ( !thisa->visitingArmyDisplay )
      fatalOutOfMemoryError();
    if ( thisa->castle->buildingsBuiltFlags & 1 )
      Castle::grantHeroSpellsFromMageGuild(thisa->castle, 0);
  }
  thisa->factionID = thisa->castle->factionID;
  thisa->field_E6 = 0;
  thisa->field_DE = thisa->field_E6;
  thisa->field_D6 = thisa->field_DE;
  thisa->field_EA = -1;
  thisa->field_E2 = thisa->field_EA;
  thisa->field_DA = thisa->field_E2;
  TownManager::paintTown(thisa, 0, 0);
  HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 0x280u, 480);
}
