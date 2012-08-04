{
  int v4; // eax@20
  int v5; // eax@26
  signed int v8; // [sp+14h] [bp-4h]@23

  switch ( evt->fieldID )
  {
    case 0x17:
      if ( (signed int)HIBYTE(gpCurPlayer->field_45) > 0 )
      {
        --HIBYTE(gpCurPlayer->field_45);
        advManager::UpdateTownLocators(this, 1, 1);
      }
      break;
    case 0x18:
      if ( HIBYTE(gpCurPlayer->field_45) + 4 < gpCurPlayer->numCastles )
      {
        ++HIBYTE(gpCurPlayer->field_45);
        advManager::UpdateTownLocators(this, 1, 1);
      }
      break;
    case 0x14:
      if ( gpCurPlayer->field_3 > 0 )
      {
        --gpCurPlayer->field_3;
        advManager::UpdateHeroLocators(this, 1, 1);
      }
      break;
    case 0x15:
      if ( gpCurPlayer->field_3 + 4 < gpCurPlayer->numHeroes )
      {
        ++gpCurPlayer->field_3;
        advManager::UpdateHeroLocators(this, 1, 1);
      }
      break;
    case 2:
      this->field_36 = 7;
      *(_DWORD *)a4 = advManager::DoAdvCommand(this);
      break;
    case 5:
      advManager::AdvPanel(this);
      break;
    case 6:
      *(_DWORD *)a3 = advManager::ControlPanel(this);
      break;
    case 4:
      if ( !playerData::HasMobileHero(gpCurPlayer)
        || (NormalDialog(
              "One or more heroes may still move, are you sure you want to end your turn?",
              2,
              -1,
              -1,
              -1,
              0,
              -1,
              0,
              -1,
              0),
            gpWindowManager->buttonPressedCode != 30726) )
        game::NextPlayer(gpGame);
      break;
    case 1:
      advManager::HideRoute(this, 1, 0, 1);
      v4 = playerData::NextHero(gpCurPlayer, 1);
      advManager::SetHeroContext(this, v4, 0);
      break;
    case 3:
      if ( gbLowMemory )
        advManager::SetEnvironmentOrigin(this, -1, -1, 1);
      advManager::TrimLoopingSounds(this, 0);
      game::Overview(gpGame);
      v8 = 1;
      if ( giOverviewReturnAction == 1 )
      {
        mouseManager::SetPointer(gpMouseManager, 0);
        if ( gbLowMemory )
          advManager::SetEnvironmentOrigin(this, -1, -1, 1);
        advManager::TrimLoopingSounds(this, 0);
        v5 = (int)hero::GetOccupiedTown(&gpGame->heroes[giOverviewReturnAction]);
        HeroView(giOverviewReturnActionExtra, v5, 1);
        if ( gbLowMemory )
          advManager::SetEnvironmentOrigin(this, this->viewX + 7, this->viewY + 7, 1);
      }
      else if ( giOverviewReturnAction == 2 )
      {
        advManager::DemobilizeCurrHero(this);
        mouseManager::SetPointer(gpMouseManager, 0);
        town::View(&gpGame->castles[giOverviewReturnActionExtra], 1);
        v8 = 0;
      }
      else if ( gbLowMemory )
      {
        advManager::SetEnvironmentOrigin(this, this->viewX + 7, this->viewY + 7, 1);
      }
      advManager::RedrawAdvScreen(this, 1, 0);
      if ( v8 )
        heroWindowManager::FadeScreen(gpWindowManager, 0, 8, 0);
      break;
    case 8:
      advManager::CheckCastSpell();
      break;
    case 7:
      advManager::SystemOptions(this);
      break;
    default:
      break;
  }
  if ( evt->fieldID >= 2000 && evt->fieldID <= 2200 )
  {
    if ( giBottomViewOverride == 2 )
    {
      giBottomViewOverride = 1;
    }
    else if ( giBottomViewOverride )
    {
      giBottomViewOverride = 0;
    }
    else if ( iCurBottomView == 2 )
    {
      giBottomViewOverride = 1;
    }
    else
    {
      giBottomViewOverride = 2;
    }
    giBottomViewOverrideEndTime = KBTickCount() + 3000;
    advManager::UpdBottomView(this, 1, 1, 1);
  }
  return 1;
}