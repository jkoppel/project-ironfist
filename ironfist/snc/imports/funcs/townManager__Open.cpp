{
  townManager *thisa; // [sp+Ch] [bp-8h]@1
  heroWindow *window; // [sp+10h] [bp-4h]@4

  thisa = this;
  game::CheckHeroConsistency(gpGame);
  if ( *(_DWORD *)&useOpera || !*(_DWORD *)&useCDMusic )
    soundManager::SwitchAmbientMusic(gpSoundManager, townTheme[thisa->castle->factionID]);
  PollSound();
  window = (heroWindow *)operator new(68);
  if ( window )
    thisa->townScreen = heroWindow::heroWindow(window, 0, 0, "townwind.bin");
  else
    thisa->townScreen = 0;
  if ( !thisa->townScreen )
    MemError();
  glTimers = KBTickCount() + 150;
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
  townManager::SetupExtraStuff(thisa);
  townManager::SetupTown(thisa);
  KBChangeMenu(hmnuTown);
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  thisa->type = 2048;
  thisa->idx = idx;
  thisa->ready = 1;
  strcpy(thisa->name, "townManager");
  heroWindowManager::FadeScreen(gpWindowManager, 0, 8, 0);
  return 0;
}