{
  signed int v3; // [sp+10h] [bp-1Ch]@1
  int v4; // [sp+14h] [bp-18h]@94
  int level; // [sp+1Ch] [bp-10h]@85
  signed int v6; // [sp+20h] [bp-Ch]@1
  int spell; // [sp+24h] [bp-8h]@55
  signed int spella; // [sp+24h] [bp-8h]@62
  signed int spellb; // [sp+24h] [bp-8h]@89
  signed int spellc; // [sp+24h] [bp-8h]@92
  char *this; // [sp+28h] [bp-4h]@1

  v3 = a1;
  v6 = 0;
  this = 0;
  if ( gpCurPlayer && gpCurPlayer->curHeroIdx != -1 )
    this = (char *)&gpGame->heroes[gpCurPlayer->curHeroIdx];
  switch ( a1 )
  {
    case 40102:
    case 40104:
    case 40105:
    case 40106:
    case 40107:
    case 40110:
    case 40111:
    case 40112:
    case 40114:
    case 40115:
    case 40117:
    case 40118:
    case 40120:
    case 40121:
      strcpy(gText, "Are you sure you want to restart?  (Your current game will be lost)");
      goto LABEL_7;
    case 40123:
    case 40124:
    case 40127:
    case 40128:
    case 40129:
    case 40131:
    case 40132:
    case 40134:
    case 40135:
    case 40137:
    case 40138:
      strcpy(gText, "Are you sure you want to load a new game?  (Your current game will be lost)");
LABEL_7:
      if ( gpAdvManager->ready != 1
        || (NormalDialog(gText, 2, -1, -1, -1, 0, -1, 0, -1, 0), gpWindowManager->buttonPressedCode == 30725) )
        giMenuCommand = v3;
      goto LABEL_100;
    case 40139:
      SaveGame();
      goto LABEL_100;
    case 40140:
      PostMessageA(hwndApp, 0x10u, 0, 0);
      goto LABEL_100;
    case 40016:
      *(_DWORD *)&Data = 0;
      goto LABEL_23;
    case 40017:
      *(_DWORD *)&Data = 1;
      goto LABEL_23;
    case 40018:
      *(_DWORD *)&Data = 2;
      goto LABEL_23;
    case 40019:
      *(_DWORD *)&Data = 3;
      goto LABEL_23;
    case 40020:
      *(_DWORD *)&Data = 4;
      goto LABEL_23;
    case 40021:
      *(_DWORD *)&Data = 5;
      goto LABEL_23;
    case 40022:
      *(_DWORD *)&Data = 6;
      goto LABEL_23;
    case 40023:
      *(_DWORD *)&Data = 7;
      goto LABEL_23;
    case 40024:
      *(_DWORD *)&Data = 8;
      goto LABEL_23;
    case 40025:
      *(_DWORD *)&Data = 9;
      goto LABEL_23;
    case 40026:
      *(_DWORD *)&Data = 10;
LABEL_23:
      soundManager::AdjustMusicVolumes((int)gpSoundManager);
      v6 = 1;
      goto LABEL_100;
    case 40028:
      *(_DWORD *)&soundVolume = 0;
      goto LABEL_35;
    case 40029:
      *(_DWORD *)&soundVolume = 1;
      goto LABEL_35;
    case 40030:
      *(_DWORD *)&soundVolume = 2;
      goto LABEL_35;
    case 40031:
      *(_DWORD *)&soundVolume = 3;
      goto LABEL_35;
    case 40032:
      *(_DWORD *)&soundVolume = 4;
      goto LABEL_35;
    case 40033:
      *(_DWORD *)&soundVolume = 5;
      goto LABEL_35;
    case 40034:
      *(_DWORD *)&soundVolume = 6;
      goto LABEL_35;
    case 40035:
      *(_DWORD *)&soundVolume = 7;
      goto LABEL_35;
    case 40036:
      *(_DWORD *)&soundVolume = 8;
      goto LABEL_35;
    case 40037:
      *(_DWORD *)&soundVolume = 9;
      goto LABEL_35;
    case 40038:
      *(_DWORD *)&soundVolume = 10;
LABEL_35:
      soundManager::AdjustSoundVolumes(gpSoundManager);
      v6 = 1;
      goto LABEL_100;
    case 40046:
      *(_DWORD *)&showRoute = 1 - *(_DWORD *)&showRoute;
      v6 = 1;
      goto LABEL_100;
    case 40047:
      *(_DWORD *)&blackoutComputer = 1 - *(_DWORD *)&blackoutComputer;
      v6 = 1;
      goto LABEL_100;
    case 40012:
      advManager::ViewWorld(gpAdvManager, a2, 53, 0, 0);
      goto LABEL_100;
    case 40013:
      advManager::ViewPuzzle(gpAdvManager);
      goto LABEL_100;
    case 40014:
      advManager::CheckCastSpell();
      goto LABEL_100;
    case 40015:
      advManager::ProcessSearch(gpAdvManager, -1i64);
      goto LABEL_100;
    case 40141:
      gpGame->_10[32] = 1;
      if ( gbInCampaign )
        gpGame->_1[204] = 1;
      game::SetVisibility(30, 30, giCurPlayer, 180);
      if ( this )
        advManager::Reseed(0, 0);
      advManager::UpdateRadar((int)gpAdvManager, 1, 0);
      advManager::CompleteDraw(gpAdvManager, 0);
      advManager::UpdateScreen(gpAdvManager, 0, 0);
      goto LABEL_100;
    case 40142:
      gpGame->_10[32] = 1;
      if ( gbInCampaign )
        gpGame->_1[204] = 1;
      if ( this )
        *(_DWORD *)(this + 53) = 299999;
      goto LABEL_100;
    case 40143:
      gpGame->_10[32] = 1;
      if ( gbInCampaign )
        gpGame->_1[204] = 1;
      if ( this )
      {
        for ( spell = 0; spell < 65; ++spell )
          hero::AddSpell((hero *)this, spell, 10);
        *(_WORD *)this = 999;
      }
      goto LABEL_100;
    case 40144:
      gpGame->_10[32] = 1;
      if ( gbInCampaign )
        gpGame->_1[204] = 1;
      for ( spella = 0; spella < 7; ++spella )
      {
        if ( spella == 6 )
          gpCurPlayer->resources[6] += 1000;
        else
          gpCurPlayer->resources[spella] += 10;
      }
      advManager::UpdBottomView(gpAdvManager, 1, 1, 1);
      goto LABEL_100;
    default:
      if ( a1 >= 43000 && a1 < 43101 )
      {
        gpGame->_10[32] = 1;
        if ( gbInCampaign )
          gpGame->_1[204] = 1;
        giDebugBuildingToBuild = a1 - 43000;
LABEL_100:
        if ( v6 )
          WritePrefs();
        return 0;
      }
      if ( a1 >= 41000 && a1 < 41066 )
      {
        gpGame->_10[32] = 1;
        if ( gbInCampaign )
          gpGame->_1[204] = 1;
        if ( gpCurPlayer->curHeroIdx != -1 )
        {
          game::GiveArmy(&gpGame->heroes[gpCurPlayer->curHeroIdx].army, a1 - 41000, 5, -1);
          advManager::UpdBottomView(gpAdvManager, 1, 1, 1);
        }
        goto LABEL_100;
      }
      if ( a1 >= 42000 && a1 < 42056 )
      {
        gpGame->_10[32] = 1;
        if ( gbInCampaign )
          gpGame->_1[204] = 1;
        level = (((unsigned __int64)(a1 - 42000) >> 32) ^ abs(a1 - 16) & 3) - ((unsigned __int64)(a1 - 42000) >> 32);
        if ( this )
          hero::SetSS((hero *)this, (a1 - 42000) / 4, level);
      }
      if ( v3 >= 44000 && v3 < 44200 )
      {
        gpCombatManager->combatFieldCoverID = v3 - 44000;
        gpCombatManager->zeroedAfterAnimatingDeathAndHolySpells = 0;
        for ( spellb = 0; spellb < 117; ++spellb )
        {
          gpCombatManager->combatGrid[spellb].isBlocked = 0;
          gpCombatManager->combatGrid[spellb].combatObjIdx = -1;
        }
        for ( spellc = 0; spellc < 15; ++spellc )
        {
          v4 = *(&byte_4F529A[17 * gpCombatManager->combatFieldCoverID] + spellc);
          if ( v4 != -1 )
            gpCombatManager->combatGrid[v4].isBlocked = 1;
        }
        combatManager::SetupGridForArmy(
          gpCombatManager,
          &gpCombatManager->creatures[gpCombatManager->otherCurrentSideThing][gpCombatManager->someSortOfStackIdx]);
        combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 0, 1, 1);
      }
      return 1;
  }
}