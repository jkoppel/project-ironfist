{
  TownManager *thisa; // [sp+Ch] [bp-8h]@1
  GUIWindow *window; // [sp+10h] [bp-4h]@4

  thisa = this;
  GameInfo::fixSeveralInvariants(gameObject);
  if ( *(_DWORD *)&useOpera || !*(_DWORD *)&useCDMusic )
    SoundManager::couldBePlayCDTrack(soundManager, factionTrackNumbers[thisa->castle->factionID]);
  yieldToGlobalUpdater();
  window = (GUIWindow *)operator new(0x44u);
  if ( window )
    thisa->townScreen = GUIWindow_constructorFromFile(window, 0, 0, "townwind.bin");
  else
    thisa->townScreen = 0;
  if ( !thisa->townScreen )
    fatalOutOfMemoryError();
  animationFrameSwitchTime = getTickCount() + 150;
  thisa->factionID = -2;
  thisa->field_15A = 0;
  thisa->field_14E = 0;
  thisa->field_142 = -1;
  thisa->field_146 = 0;
  thisa->curBuilding = 0;
  thisa->field_C6 = 0;
  thisa->garrisonDisplay = 0;
  thisa->visitingArmyDisplay = 0;
  thisa->field_D6 = 0;
  thisa->field_DE = 0;
  thisa->field_E6 = 0;
  thisa->bankbox = 0;
  thisa->couldBeBackground = 0;
  TownManager::buildCosmeticBuildings(thisa);
  TownManager::refreshFromCastle(thisa);
  changeMenu(townMenu);
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  thisa->type = 2048;
  thisa->idx = idx;
  thisa->ready = 1;
  strcpy(thisa->name, "townManager");
  sub_4C7C60(HeroWindowManager::instance, 0, 8, 0);
  return 0;
}
