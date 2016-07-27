{
  signed int v2; // [sp+10h] [bp-1Ch]@1
  int v3; // [sp+14h] [bp-18h]@94
  int level; // [sp+1Ch] [bp-10h]@85
  signed int v5; // [sp+20h] [bp-Ch]@1
  int spell; // [sp+24h] [bp-8h]@55
  signed int spella; // [sp+24h] [bp-8h]@62
  signed int spellb; // [sp+24h] [bp-8h]@89
  signed int spellc; // [sp+24h] [bp-8h]@92
  char *this; // [sp+28h] [bp-4h]@1

  v2 = a1;
  v5 = 0;
  this = 0;
  if ( curPlayer && curPlayer->_1[0] != -1 )
    this = (char *)&gameObject->heroes[curPlayer->_1[0]];
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
      strcpy(globBuf, "Are you sure you want to restart?  (Your current game will be lost)");
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
      strcpy(globBuf, "Are you sure you want to load a new game?  (Your current game will be lost)");
LABEL_7:
      if ( advManager->ready != 1
        || (display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0),
            HeroWindowManager::instance->buttonPressedCode == 30725) )
        dword_4F19A8 = v2;
      goto LABEL_100;
    case 40139:
      sub_451750();
      goto LABEL_100;
    case 40140:
      PostMessageA(windowHandle, 0x10u, 0, 0);
      goto LABEL_100;
    case 40016:
      *(_DWORD *)&musicVolume = 0;
      goto LABEL_23;
    case 40017:
      *(_DWORD *)&musicVolume = 1;
      goto LABEL_23;
    case 40018:
      *(_DWORD *)&musicVolume = 2;
      goto LABEL_23;
    case 40019:
      *(_DWORD *)&musicVolume = 3;
      goto LABEL_23;
    case 40020:
      *(_DWORD *)&musicVolume = 4;
      goto LABEL_23;
    case 40021:
      *(_DWORD *)&musicVolume = 5;
      goto LABEL_23;
    case 40022:
      *(_DWORD *)&musicVolume = 6;
      goto LABEL_23;
    case 40023:
      *(_DWORD *)&musicVolume = 7;
      goto LABEL_23;
    case 40024:
      *(_DWORD *)&musicVolume = 8;
      goto LABEL_23;
    case 40025:
      *(_DWORD *)&musicVolume = 9;
      goto LABEL_23;
    case 40026:
      *(_DWORD *)&musicVolume = 10;
LABEL_23:
      sub_403B80((int)soundManager);
      v5 = 1;
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
      sub_403AA0(soundManager);
      v5 = 1;
      goto LABEL_100;
    case 40046:
      *(_DWORD *)&showRoute = 1 - *(_DWORD *)&showRoute;
      v5 = 1;
      goto LABEL_100;
    case 40047:
      *(_DWORD *)&blackoutComputer = 1 - *(_DWORD *)&blackoutComputer;
      v5 = 1;
      goto LABEL_100;
    case 40012:
      sub_498F20(advManager, 53, 0, 0);
      goto LABEL_100;
    case 40013:
      sub_456C40(advManager);
      goto LABEL_100;
    case 40014:
      sub_4519A0((int)advManager);
      goto LABEL_100;
    case 40015:
      sub_4469E0(advManager, -1i64);
      goto LABEL_100;
    case 40141:
      gameObject->_10[32] = 1;
      if ( loadOrNewGameSelected )
        gameObject->_1[204] = 1;
      explore(30, 30, curPlayerIdx, 180);
      if ( this )
        sub_4456D0(0, 0);
      sub_44AA80((int)advManager, 1, 0);
      sub_448110(advManager, 0);
      sub_447A00(advManager, 0, 0);
      goto LABEL_100;
    case 40142:
      gameObject->_10[32] = 1;
      if ( loadOrNewGameSelected )
        gameObject->_1[204] = 1;
      if ( this )
        *(_DWORD *)(this + 53) = 299999;
      goto LABEL_100;
    case 40143:
      gameObject->_10[32] = 1;
      if ( loadOrNewGameSelected )
        gameObject->_1[204] = 1;
      if ( this )
      {
        for ( spell = 0; spell < 65; ++spell )
          Hero::learnSpell((Hero *)this, spell, 10);
        *(_WORD *)this = 999;
      }
      goto LABEL_100;
    case 40144:
      gameObject->_10[32] = 1;
      if ( loadOrNewGameSelected )
        gameObject->_1[204] = 1;
      for ( spella = 0; spella < 7; ++spella )
      {
        if ( spella == 6 )
          curPlayer->resources[6] += 1000;
        else
          curPlayer->resources[spella] += 10;
      }
      sub_44D440(advManager, 1, 1, 1);
      goto LABEL_100;
    default:
      if ( a1 >= 43000 && a1 < 43101 )
      {
        gameObject->_10[32] = 1;
        if ( loadOrNewGameSelected )
          gameObject->_1[204] = 1;
        dword_4F4B88 = a1 - 43000;
LABEL_100:
        if ( v5 )
          propagateSettingChanges();
        return 0;
      }
      if ( a1 >= 41000 && a1 < 41066 )
      {
        gameObject->_10[32] = 1;
        if ( loadOrNewGameSelected )
          gameObject->_1[204] = 1;
        if ( curPlayer->_1[0] != -1 )
        {
          addCreaturesToArmy(&gameObject->heroes[curPlayer->_1[0]].army, a1 - 41000, 5, -1);
          sub_44D440(advManager, 1, 1, 1);
        }
        goto LABEL_100;
      }
      if ( a1 >= 42000 && a1 < 42056 )
      {
        gameObject->_10[32] = 1;
        if ( loadOrNewGameSelected )
          gameObject->_1[204] = 1;
        level = (((unsigned __int64)(a1 - 42000) >> 32) ^ abs(a1 - 16) & 3) - ((unsigned __int64)(a1 - 42000) >> 32);
        if ( this )
          Hero::setSecondarySkillLevel((Hero *)this, (a1 - 42000) / 4, level);
      }
      if ( v2 >= 44000 && v2 < 44200 )
      {
        combatManager->combatFieldCoverID = v2 - 44000;
        combatManager->zeroedAfterAnimatingDeathAndHolySpells = 0;
        for ( spellb = 0; spellb < 117; ++spellb )
        {
          combatManager->combatGrid[spellb].probablyIsBlocked = 0;
          combatManager->combatGrid[spellb].combatObjIdx = -1;
        }
        for ( spellc = 0; spellc < 15; ++spellc )
        {
          v3 = *(&byte_4F529A[17 * combatManager->combatFieldCoverID] + spellc);
          if ( v3 != -1 )
            combatManager->combatGrid[v3].probablyIsBlocked = 1;
        }
        sub_4C3DD0(
          combatManager,
          &combatManager->creatures[combatManager->otherCurrentSideThing][combatManager->someSortOfStackIdx]);
        CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 0, 1, 1);
      }
      return 1;
  }
}
