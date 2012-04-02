{
  signed int result; // eax@5
  int v3; // eax@166
  int v4; // [sp+14h] [bp-40h]@22
  INPUT_EVENT_CODE v5; // [sp+18h] [bp-3Ch]@21
  AdvManager *thisa; // [sp+1Ch] [bp-38h]@1
  signed int a8; // [sp+20h] [bp-34h]@175
  int a6; // [sp+24h] [bp-30h]@175
  Hero *v9; // [sp+28h] [bp-2Ch]@83
  int v10; // [sp+2Ch] [bp-28h]@27
  Hero *hero; // [sp+30h] [bp-24h]@46
  int a2; // [sp+34h] [bp-20h]@45
  int loc; // [sp+38h] [bp-1Ch]@20
  int v14; // [sp+3Ch] [bp-18h]@156
  int i; // [sp+40h] [bp-14h]@66
  int v16; // [sp+4Ch] [bp-8h]@20
  int v17; // [sp+50h] [bp-4h]@20

  thisa = this;
  if ( getTickCount() > animationFrameSwitchTime && sub_452F20(thisa, 1) )
    sub_447A00(thisa, 1, 0);
  if ( dword_4EF268 )
  {
    evt->eventCode = 16384;
    evt->xCoordOrKeycode = 1;
    return 2;
  }
  sub_455D20(thisa);
  if ( !dword_523ED4 )
    return sub_455F30(thisa, (int)evt, 0);
  if ( !dword_524810[curPlayerIdx] )
  {
    sub_4AC3C0((void *)unknownGlobalObject4, curPlayerIdx);
    GameInfo::endTurn(gameObject);
    return 1;
  }
  if ( dword_4F19A4 && dword_4F0A10 )
    sub_455590(thisa);
  if ( !soundDisabled && *(_DWORD *)&musicVolume && dword_4F747C > 0 && getTickCount() - dword_4F747C > 6000 )
  {
    dword_4F747C = -1;
    if ( soundManager->currentTrack == 21 )
      SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[thisa->field_A6]);
    sub_452F60(thisa, thisa->viewX + 7, thisa->viewY + 7, 1);
  }
  v16 = 1;
  v17 = 0;
  loc = 0;
  if ( evt->eventCode )
  {
    v5 = evt->eventCode;
    if ( v5 == INPUT_KEYDOWN_EVENT_CODE )
    {
      a2 = -1;
      if ( curPlayer->_1[0] == -1 )
        hero = 0;
      else
        hero = &gameObject->heroes[curPlayer->_1[0]];
      if ( debugLogLevel >= 1
        || evt->xCoordOrKeycode != 61
        && evt->xCoordOrKeycode != 62
        && evt->xCoordOrKeycode != 63
        && evt->xCoordOrKeycode != 64
        && evt->xCoordOrKeycode != 65
        && evt->xCoordOrKeycode != 66
        && evt->xCoordOrKeycode != 67
        && evt->xCoordOrKeycode != 68
        && evt->xCoordOrKeycode != 87
        && evt->xCoordOrKeycode != 88 )
      {
        switch ( evt->xCoordOrKeycode )
        {
          case 60:
            nullsub_1();
            sub_435F20(0, (void *)0xFFFFFFFF);
            break;
          case 64:
            GameInfo::fixSeveralInvariants(gameObject);
            break;
          case 65:
            curPlayer->_3[0] += 12;
            if ( hero )
              giveXPToHero(hero, 3000, 1);
            break;
          case 67:
            for ( i = 0; i < 7; ++i )
            {
              if ( i == 6 )
                curPlayer->resources[6] += 1000;
              else
                curPlayer->resources[i] += 10;
            }
            break;
          case 11:
            i = 0;
            goto LABEL_83;
          case 2:
            i = 1;
            goto LABEL_83;
          case 3:
            i = 2;
            goto LABEL_83;
          case 4:
            i = 3;
            goto LABEL_83;
          case 5:
            i = 4;
            goto LABEL_83;
          case 6:
            i = 5;
            goto LABEL_83;
          case 7:
            i = 6;
            goto LABEL_83;
          case 8:
            i = 7;
            goto LABEL_83;
          case 9:
            i = 8;
            goto LABEL_83;
          case 10:
            i = 9;
LABEL_83:
            v9 = 0;
            if ( curPlayer->_1[0] != -1 )
              v9 = &gameObject->heroes[curPlayer->_1[0]];
            dword_50ECB0 = 10 * dword_50ECB0 % 10000000 + i;
            if ( !dword_4F7494 )
            {
              if ( dword_50ECB0 % 100000 == 32167 && v9 )
              {
                gameObject->_10[32] = 1;
                if ( loadOrNewGameSelected )
                  gameObject->_1[204] = 1;
                addCreaturesToArmy(&v9->army, 37, 5, -1);
                sub_44D440(thisa, 1, 1, 1);
              }
              if ( dword_50ECB0 % 1000 == 911 )
              {
                gameObject->_10[32] = 1;
                if ( loadOrNewGameSelected )
                  gameObject->_1[204] = 1;
                checkGameEnd(1, 0);
              }
              if ( dword_50ECB0 % 10000 == 1313 )
              {
                gameObject->_10[32] = 1;
                checkGameEnd(2, 0);
              }
            }
            if ( dword_50ECB0 % 10000000 == 8675309 )
            {
              gameObject->_10[32] = 1;
              if ( loadOrNewGameSelected )
                gameObject->_1[204] = 1;
              explore(30, 30, 0, 180);
              explore(30, 30, 1, 180);
              explore(30, 30, 2, 180);
              explore(30, 30, 3, 180);
              explore(30, 30, 4, 180);
              explore(30, 30, 5, 180);
              sub_4456D0(0, 0);
              sub_44AA80((int)thisa, 1, 0);
              sub_448110(thisa, 0);
              sub_447A00(thisa, 0, 0);
            }
            if ( dword_50ECB0 % 1000 == 411 )
            {
              sprintf(
                globBuf,
                "Coordinates at top left corner of view:\n\n  X: %d\n  Y: %d",
                thisa->viewX,
                thisa->viewY);
              display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
            }
            break;
          case 72:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0((int)thisa, 0, 0);
            else
              a2 = 0;
            break;
          case 73:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0((int)thisa, 1, 0);
            else
              a2 = 1;
            break;
          case 77:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0((int)thisa, 2, 0);
            else
              a2 = 2;
            break;
          case 81:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0((int)thisa, 3, 0);
            else
              a2 = 3;
            break;
          case 80:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0((int)thisa, 4, 0);
            else
              a2 = 4;
            break;
          case 79:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0((int)thisa, 5, 0);
            else
              a2 = 5;
            break;
          case 75:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0((int)thisa, 6, 0);
            else
              a2 = 6;
            break;
          case 71:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0((int)thisa, 7, 0);
            else
              a2 = 7;
            break;
          case 46:
            sub_4519A0((int)thisa);
            break;
          case 32:
            sub_4469E0(thisa, -1i64);
            break;
          case 25:
            sub_456C40(thisa);
            break;
          case 47:
            sub_498F20(thisa, 53, 0, 0);
            break;
          case 49:
            i = 101;
            strcpy(globBuf, "Are you sure you want to restart?  (Your current game will be lost)");
            goto LABEL_143;
          case 38:
            i = 102;
            strcpy(globBuf, "Are you sure you want to load a new game?  (Your current game will be lost)");
            goto LABEL_143;
          case 16:
            i = 105;
            strcpy(globBuf, "Are you sure you want to quit?");
LABEL_143:
            v17 = 1;
            display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
            if ( HeroWindowManager::instance->buttonPressedCode == 30726 )
              v17 = 0;
            else
              dword_523408 = i;
            break;
          case 31:
            sub_451750();
            break;
          case 23:
            if ( loadOrNewGameSelected )
            {
              sub_452F60(thisa, -1, -1, 1);
              sub_4A8140(gameObject, 1, 0);
              sub_452F60(thisa, thisa->viewX + 7, thisa->viewY + 7, 1);
              sub_4506B0(thisa, 1, 0);
              SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[thisa->field_A6]);
            }
            else
            {
              if ( byte_5304A0 )
              {
                sub_452F60(thisa, -1, -1, 1);
                sub_470DF0((int)&unk_530450, 1, 0);
                sub_452F60(thisa, thisa->viewX + 7, thisa->viewY + 7, 1);
                sub_4506B0(thisa, 1, 0);
                SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[thisa->field_A6]);
              }
              else
              {
                sub_45DC50(gameObject);
              }
            }
            break;
          case 20:
            if ( curPlayer->numCastles >= 0 )
            {
              if ( LOBYTE(curPlayer->field_45) == -1 )
              {
                v14 = curPlayer->castlesOwned[0];
              }
              else
              {
                v14 = 0;
                for ( i = 0; curPlayer->numCastles > i; ++i )
                {
                  if ( curPlayer->castlesOwned[i] == LOBYTE(curPlayer->field_45) )
                  {
                    if ( curPlayer->numCastles - 1 == i )
                      v14 = curPlayer->castlesOwned[0];
                    else
                      v14 = curPlayer->castlesOwned[i + 1];
                  }
                }
              }
              sub_4509F0(thisa, v14);
            }
            break;
          case 35:
            v3 = sub_418CE0(curPlayer, 0);
            sub_450C10(thisa, v3, 0);
            break;
          case 28:
            if ( LOBYTE(curPlayer->field_45) == -1 )
            {
              if ( curPlayer->_1[0] != -1 )
              {
                thisa->field_36 = 2;
                sub_443E90((int)thisa);
              }
            }
            else
            {
              thisa->field_36 = 3;
              sub_443E90((int)thisa);
            }
            break;
          case 66:
          case 1:
            break;
        }
        if ( curPlayer->_1[0] != -1 && a2 >= 0 )
        {
          sub_455030(thisa, 1, 1, 1);
          MouseManager::disableCursor(mouseManager);
          loc = sub_4C08F0(thisa, a2, 1, &qword_50EA98, &qword_50EA98 + 1, (int)&a6, 0, (signed int)&a8, 0);
          AdvManager::involvesSettingPointBars(thisa, -1, 1, 1);
          while ( mouseManager->cursorDisabled )
            MouseManager::enableCursor(mouseManager);
          SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[thisa->field_A6]);
          if ( loc )
          {
            sub_4BFAC0(thisa, 1);
            AdvManager::visitLocation(thisa, (MapTile *)loc, *(__int64 *)&qword_50EA98);
            loc = 0;
          }
          sub_4456D0(0, 0);
          sub_455380(thisa);
          sub_44D440(thisa, 1, 1, 1);
          sub_455140(thisa);
        }
      }
      goto LABEL_185;
    }
    if ( v5 == 4 )
    {
      v16 = sub_446FB0(thisa, evt->altXCoord, evt->altYCoord);
    }
    else
    {
      if ( v5 == 512 )
      {
        v4 = evt->xCoordOrKeycode;
        if ( v4 == 12 )
          goto LABEL_194;
        if ( v4 == 13 )
        {
          if ( !(BYTE1(evt->inputTypeBitmask) & 2) )
            v16 = sub_446570((int)thisa, (int)evt, (int)&v17, (int)&loc);
          goto LABEL_185;
        }
        if ( v4 == 14 )
        {
          if ( !(BYTE1(evt->inputTypeBitmask) & 2) )
            goto LABEL_195;
LABEL_194:
          v10 = -1;
          switch ( evt->yCoord )
          {
            case 1:
              v10 = 0;
              break;
            case 2:
              v10 = 1;
              break;
            case 3:
              v10 = 2;
              break;
            case 4:
              v10 = 3;
              break;
            case 5:
              v10 = 4;
              break;
            case 6:
              v10 = 5;
              break;
            case 7:
              v10 = 6;
              break;
            case 8:
              v10 = 7;
              break;
            default:
              break;
          }
          if ( v10 >= 0 )
            display_message_window(adventureMapLocationMessages[v10 + 122], 4, -1, -1, -1, 0, -1, 0, -1, 0);
          else
LABEL_195:
            v16 = sub_445700((int)thisa, (int)evt, (int)&loc);
        }
      }
    }
  }
LABEL_185:
  if ( loc )
    AdvManager::visitLocation(thisa, (MapTile *)loc, *(__int64 *)&qword_50EA98);
  if ( dword_4EF268 || v17 == 1 || dword_4F19A8 != -1 )
  {
    evt->eventCode = 16384;
    evt->xCoordOrKeycode = 1;
    result = 2;
  }
  else
  {
    result = v16;
  }
  return result;
}
