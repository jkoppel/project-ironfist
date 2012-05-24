signed int __thiscall AdvManager__handleInput(AdvManager *this, InputEvent *evt)
{
  int v2; // edx@1
  signed int result; // eax@5
  int v4; // edx@6
  int v5; // eax@166
  int v6; // [sp+14h] [bp-40h]@22
  INPUT_EVENT_CODE v7; // [sp+18h] [bp-3Ch]@21
  signed int a8; // [sp+20h] [bp-34h]@175
  int a6; // [sp+24h] [bp-30h]@175
  Hero *v11; // [sp+28h] [bp-2Ch]@83
  int v12; // [sp+2Ch] [bp-28h]@27
  Hero *hero; // [sp+30h] [bp-24h]@46
  int a2; // [sp+34h] [bp-20h]@45
  MapTile *loc; // [sp+38h] [bp-1Ch]@20
  int v16; // [sp+3Ch] [bp-18h]@156
  int i; // [sp+40h] [bp-14h]@66
  int v18; // [sp+4Ch] [bp-8h]@20
  int a3; // [sp+50h] [bp-4h]@20

  if ( getTickCount() > animationFrameSwitchTime && sub_452F20(this, 1) )
    sub_447A00(this, 1, 0);
  if ( dword_4EF268 )
  {
    evt->eventCode = 16384;
    evt->xCoordOrKeycode = 1;
    return 2;
  }
  sub_455D20(this, v2);
  if ( !dword_523ED4 )
    return sub_455F30(this, (int)evt, 0);
  if ( !dword_524810[curPlayerIdx] )
  {
    sub_4AC3C0((void *)unknownGlobalObject4, curPlayerIdx);
    GameInfo::endTurn(gameObject);
    return 1;
  }
  if ( dword_4F19A4 && dword_4F0A10 )
    sub_455590(this);
  if ( !soundDisabled && *(_DWORD *)&musicVolume && dword_4F747C > 0 && getTickCount() - dword_4F747C > 6000 )
  {
    dword_4F747C = -1;
    if ( soundManager->currentTrack == 21 )
      SoundManager::playCDTrack(soundManager, (unsigned __int8)terrainTrackNumbers[this->currentTerrain]);
    sub_452F60(this, this->viewX + 7, this->viewY + 7, 1);
  }
  v18 = 1;
  a3 = 0;
  loc = 0;
  if ( evt->eventCode )
  {
    v7 = evt->eventCode;
    if ( v7 == INPUT_KEYDOWN_EVENT_CODE )
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
            v11 = 0;
            if ( curPlayer->_1[0] != -1 )
              v11 = &gameObject->heroes[curPlayer->_1[0]];
            dword_50ECB0 = 10 * dword_50ECB0 % 10000000 + i;
            if ( !dword_4F7494 )
            {
              if ( dword_50ECB0 % 100000 == 32167 && v11 )
              {
                gameObject->_10[32] = 1;
                if ( loadOrNewGameSelected )
                  gameObject->_1[204] = 1;
                addCreaturesToArmy(&v11->army, 37, 5, -1);
                sub_44D440(this, 1, 1, 1);
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
              sub_44AA80((int)this, 1, 0);
              sub_448110(this, 0);
              sub_447A00(this, 0, 0);
            }
            if ( dword_50ECB0 % 1000 == 411 )
            {
              sprintf(globBuf, "Coordinates at top left corner of view:\n\n  X: %d\n  Y: %d", this->viewX, this->viewY);
              display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
            }
            break;
          case 72:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0(this, 0, 0);
            else
              a2 = 0;
            break;
          case 73:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0(this, 1, 0);
            else
              a2 = 1;
            break;
          case 77:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0(this, 2, 0);
            else
              a2 = 2;
            break;
          case 81:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0(this, 3, 0);
            else
              a2 = 3;
            break;
          case 80:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0(this, 4, 0);
            else
              a2 = 4;
            break;
          case 79:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0(this, 5, 0);
            else
              a2 = 5;
            break;
          case 75:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0(this, 6, 0);
            else
              a2 = 6;
            break;
          case 71:
            if ( evt->inputTypeBitmask & 0xC )
              sub_4553E0(this, 7, 0);
            else
              a2 = 7;
            break;
          case 46:
            AdvManager::castAdventureSpell(this);
            break;
          case 32:
            AdvManager::digForArtifact(this, -1i64);
            break;
          case 25:
            sub_456C40(this);
            break;
          case 47:
            sub_498F20(this, v4, 53, 0, 0);
            break;
          case 49:
            i = 101;
            strcpy((int)globBuf);
            goto LABEL_143;
          case 38:
            i = 102;
            strcpy((int)globBuf);
            goto LABEL_143;
          case 16:
            i = 105;
            strcpy((int)globBuf);
LABEL_143:
            a3 = 1;
            display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
            if ( HeroWindowManager::instance->buttonPressedCode == 30726 )
              a3 = 0;
            else
              dword_523408 = i;
            break;
          case 31:
            sub_451750();
            break;
          case 23:
            if ( loadOrNewGameSelected )
            {
              sub_452F60(this, -1, -1, 1);
              sub_4A8140(gameObject, 1, 0);
              sub_452F60(this, this->viewX + 7, this->viewY + 7, 1);
              sub_4506B0(this, 1, 0);
              SoundManager::playCDTrack(soundManager, (unsigned __int8)terrainTrackNumbers[this->currentTerrain]);
            }
            else
            {
              if ( byte_5304A0 )
              {
                sub_452F60(this, -1, -1, 1);
                sub_470DF0((int)&unk_530450, 1, 0);
                sub_452F60(this, this->viewX + 7, this->viewY + 7, 1);
                sub_4506B0(this, 1, 0);
                SoundManager::playCDTrack(soundManager, (unsigned __int8)terrainTrackNumbers[this->currentTerrain]);
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
                v16 = curPlayer->castlesOwned[0];
              }
              else
              {
                v16 = 0;
                for ( i = 0; curPlayer->numCastles > i; ++i )
                {
                  if ( curPlayer->castlesOwned[i] == LOBYTE(curPlayer->field_45) )
                  {
                    if ( curPlayer->numCastles - 1 == i )
                      v16 = curPlayer->castlesOwned[0];
                    else
                      v16 = curPlayer->castlesOwned[i + 1];
                  }
                }
              }
              sub_4509F0(this, v16);
            }
            break;
          case 35:
            v5 = sub_418CE0(curPlayer, 0);
            sub_450C10(this, v5, 0);
            break;
          case 28:
            if ( LOBYTE(curPlayer->field_45) == -1 )
            {
              if ( curPlayer->_1[0] != -1 )
              {
                this->field_36 = 2;
                sub_443E90(this);
              }
            }
            else
            {
              this->field_36 = 3;
              sub_443E90(this);
            }
            break;
          case 66:
          case 1:
            break;
        }
        if ( curPlayer->_1[0] != -1 && a2 >= 0 )
        {
          sub_455030(this, 1, 1, 1);
          MouseManager::disableCursor(mouseManager);
          loc = sub_4C08F0(this, a2, 1, &qword_50EA98, &qword_50EA98 + 1, (int)&a6, 0, (signed int)&a8, 0);
          AdvManager::involvesSettingPointBars(this, -1, 1, 1);
          while ( mouseManager->cursorDisabled )
            MouseManager::enableCursor(mouseManager);
          SoundManager::playCDTrack(soundManager, (unsigned __int8)terrainTrackNumbers[this->currentTerrain]);
          if ( loc )
          {
            sub_4BFAC0(this, 1);
            AdvManager::visitLocation(this, loc, *(__int64 *)&qword_50EA98);
            loc = 0;
          }
          sub_4456D0(0, 0);
          sub_455380(this);
          sub_44D440(this, 1, 1, 1);
          sub_455140(this);
        }
      }
      goto LABEL_185;
    }
    if ( v7 == 4 )
    {
      v18 = sub_446FB0(this, evt->altXCoord, evt->altYCoord);
    }
    else
    {
      if ( v7 == 512 )
      {
        v6 = evt->xCoordOrKeycode;
        if ( v6 == 12 )
          goto LABEL_194;
        if ( v6 == 13 )
        {
          if ( !(BYTE1(evt->inputTypeBitmask) & 2) )
            v18 = sub_446570(this, (GUIMessage *)evt, (int)&a3, (int)&loc);
          goto LABEL_185;
        }
        if ( v6 == 14 )
        {
          if ( !(BYTE1(evt->inputTypeBitmask) & 2) )
            goto LABEL_195;
LABEL_194:
          v12 = -1;
          switch ( evt->yCoord )
          {
            case 1:
              v12 = 0;
              break;
            case 2:
              v12 = 1;
              break;
            case 3:
              v12 = 2;
              break;
            case 4:
              v12 = 3;
              break;
            case 5:
              v12 = 4;
              break;
            case 6:
              v12 = 5;
              break;
            case 7:
              v12 = 6;
              break;
            case 8:
              v12 = 7;
              break;
            default:
              break;
          }
          if ( v12 >= 0 )
            display_message_window(adventureMapLocationMessages[v12 + 122], 4, -1, -1, -1, 0, -1, 0, -1, 0);
          else
LABEL_195:
            v18 = sub_445700((int)this, (int)evt, (int)&loc);
        }
      }
    }
  }
LABEL_185:
  if ( loc )
    AdvManager::visitLocation(this, loc, *(__int64 *)&qword_50EA98);
  if ( dword_4EF268 || a3 == 1 || dword_4F19A8 != -1 )
  {
    evt->eventCode = 16384;
    evt->xCoordOrKeycode = 1;
    result = 2;
  }
  else
  {
    result = v18;
  }
  return result;
}
