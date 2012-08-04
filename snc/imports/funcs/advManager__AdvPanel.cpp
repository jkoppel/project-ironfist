{
  int v1; // edx@8
  void *thisa; // [sp+10h] [bp-34h]@1
  heroWindow *thisb; // [sp+1Ch] [bp-28h]@1
  int v4; // [sp+20h] [bp-24h]@1
  int evt; // [sp+24h] [bp-20h]@7
  int v6; // [sp+28h] [bp-1Ch]@7
  int v7; // [sp+2Ch] [bp-18h]@7
  int v8; // [sp+3Ch] [bp-8h]@7
  int window; // [sp+40h] [bp-4h]@2

  thisa = this;
  advManager::TrimLoopingSounds((advManager *)this, 4);
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  v4 = *(_DWORD *)((char *)thisa + 678);
  advManager::DemobilizeCurrHero((advManager *)thisa);
  thisb = (heroWindow *)operator new(68);
  if ( thisb )
    window = (int)heroWindow::heroWindow(thisb, 144, 40, "apanel.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  if ( gpCurPlayer->curHeroIdx == -1 )
  {
    evt = 512;
    v7 = 4;
    v6 = 6;
    v8 = 2;
    heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
    v7 = 4;
    v6 = 5;
    v8 = 4096;
    heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
  }
  heroWindowManager::DoDialog(
    gpWindowManager,
    (heroWindow *)window,
    (int (__fastcall *)(tag_message *))APanelHandler,
    0);
  operator delete((void *)window);
  switch ( gpWindowManager->buttonPressedCode )
  {
    case 3:
      if ( gbInCampaign )
      {
        advManager::SetEnvironmentOrigin((advManager *)thisa, -1, -1, 1);
        game::ShowCampaignInfo(gpGame, 1, 0);
        advManager::SetEnvironmentOrigin(
          (advManager *)thisa,
          *(_DWORD *)((char *)thisa + 470) + 7,
          *(_DWORD *)((char *)thisa + 474) + 7,
          1);
        advManager::RedrawAdvScreen(thisa, 1, 0);
        soundManager::SwitchAmbientMusic(
          gpSoundManager,
          (unsigned __int8)giTerrainToMusicTrack[*(_DWORD *)((char *)thisa + 166)]);
      }
      else if ( xIsPlayingExpansionCampaign )
      {
        advManager::SetEnvironmentOrigin((advManager *)thisa, -1, -1, 1);
        ExpCampaign::ShowInfo((int)&xCampaign, 1, 0);
        advManager::SetEnvironmentOrigin(
          (advManager *)thisa,
          *(_DWORD *)((char *)thisa + 470) + 7,
          *(_DWORD *)((char *)thisa + 474) + 7,
          1);
        advManager::RedrawAdvScreen(thisa, 1, 0);
        soundManager::SwitchAmbientMusic(
          gpSoundManager,
          (unsigned __int8)giTerrainToMusicTrack[*(_DWORD *)((char *)thisa + 166)]);
      }
      else
      {
        game::ShowScenInfo(gpGame);
      }
      break;
    case 4:
      advManager::ProcessSearch((advManager *)thisa, -1i64);
      break;
    case 1:
      advManager::ViewWorld((advManager *)thisa, v1, 53, 0, 0);
      break;
    case 2:
      advManager::ViewPuzzle((advManager *)thisa);
      break;
    default:
      break;
  }
  if ( v4 )
    advManager::MobilizeCurrHero((advManager *)thisa, 0);
}