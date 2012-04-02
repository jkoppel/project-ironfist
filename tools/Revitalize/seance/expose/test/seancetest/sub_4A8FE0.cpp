signed int __thiscall sub_4A8FE0(void *this)
{
  signed int v2; // [sp+Ch] [bp-1Ch]@28
  int v3; // [sp+14h] [bp-14h]@8
  void *v4; // [sp+18h] [bp-10h]@1
  char v5; // [sp+1Ch] [bp-Ch]@19
  char v6; // [sp+20h] [bp-8h]@14
  int v7; // [sp+24h] [bp-4h]@10
  signed int i; // [sp+24h] [bp-4h]@33

  v4 = this;
  if ( !SoundManager::songPlaying(soundManager) && advManager->ready == 1 )
    SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[advManager->field_A6]);
  if ( dword_4F1CB4 && getTickCount() > dword_4F1CB4 )
  {
    *(_DWORD *)v4 = 512;
    HeroWindowManager::instance->buttonPressedCode = *((_DWORD *)v4 + 2);
    *((_DWORD *)v4 + 2) = 10;
    *((_DWORD *)v4 + 1) = *((_DWORD *)v4 + 2);
    dword_4F1CB4 = 0;
    return 2;
  }
  if ( *(_DWORD *)v4 != 512 )
    return 1;
  v3 = *((_DWORD *)v4 + 1);
  if ( v3 == 12 )
    goto LABEL_54;
  if ( v3 == 13 )
  {
    v2 = *((_DWORD *)v4 + 2);
    if ( v2 > 30721 )
    {
      if ( v2 != 30722 )
        return 1;
      if ( !dword_5304D4 )
      {
        if ( !*(&gameObject->_1[12 * dword_5304D8 + 157] + dword_5304DC) )
        {
          display_message_window(
            "The currently selected map is not a valid choice for your next scenario.",
            1,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
          return 1;
        }
        if ( dword_5304DC == 11 )
        {
          gameObject->field_4 = 4;
          gameObject->field_2 = 1 - gameObject->field_2;
          *(&gameObject->_1[12 * gameObject->field_4 + 157] + gameObject->field_2) = 1;
          *((_WORD *)&gameObject->_1[24 * gameObject->field_2 + 24] + gameObject->field_4) = *(_WORD *)&gameObject->_1[181];
          *(&gameObject->_1[12 * gameObject->field_2 + 133] + gameObject->field_4) = gameObject->_1[12 * (1 - gameObject->field_2) + 144];
          for ( i = 0; i < 12; ++i )
            gameObject->_1[i + 121] = 0;
        }
        else
        {
          gameObject->field_4 = dword_5304DC;
          gameObject->field_2 = dword_5304D8;
        }
      }
    }
    else
    {
      if ( v2 != 30721 && v2 != 901 )
      {
        if ( v2 == 902 )
        {
          sub_4A7DF0((int)gameObject, dword_5304D8, dword_5304DC);
          GUIWindow::repaintAndUpdateScreen(dword_51D158);
        }
        return 1;
      }
    }
    HeroWindowManager::instance->buttonPressedCode = *((_DWORD *)v4 + 2);
    *((_DWORD *)v4 + 2) = 10;
    *((_DWORD *)v4 + 1) = *((_DWORD *)v4 + 2);
    dword_4F1CB4 = 0;
    return 2;
  }
  if ( v3 == 14 )
  {
LABEL_54:
    switch ( *((_DWORD *)v4 + 2) )
    {
      case 0x352:
      case 0x353:
      case 0x354:
      case 0x355:
      case 0x356:
      case 0x357:
      case 0x358:
      case 0x359:
      case 0x35A:
      case 0x35B:
      case 0x35C:
      case 0x35D:
        v7 = *((_DWORD *)v4 + 2) - 850;
        if ( debugLogLevel >= 1
          || *(&gameObject->_1[12 * dword_5304D8 + 157] + v7)
          || v7 < 11
          && (v7 < 4 ? (v6 = gameObject->field_3) : (v6 = gameObject->field_2),
              *(&gameObject->_1[12 * (unsigned __int8)v6] + v7)) )
        {
          dword_5304DC = *((_DWORD *)v4 + 2) - 850;
          if ( v7 < 4 )
            v5 = gameObject->field_3;
          else
            v5 = gameObject->field_2;
          dword_5304D8 = (unsigned __int8)v5;
          sub_4A85D0(gameObject, 1);
        }
        break;
      case 0x32A:
      case 0x32B:
      case 0x32C:
        if ( !dword_5304D4 && *(&gameObject->_1[12 * dword_5304D8 + 157] + dword_5304DC) )
        {
          *(&gameObject->_1[12 * dword_5304D8 + 133] + dword_5304DC) = *((_BYTE *)v4 + 8) - 42;
          sub_4A85D0(gameObject, 1);
        }
        break;
      default:
        return 1;
    }
  }
  return 1;
}
