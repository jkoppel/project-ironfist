{
  signed int result; // eax@26
  int v2; // ST48_4@29
  int v3; // [sp+0h] [bp-30h]@0
  int v4; // [sp+Ch] [bp-24h]@27
  void *evt; // [sp+18h] [bp-18h]@1
  signed int v6; // [sp+1Ch] [bp-14h]@40
  signed int v7; // [sp+20h] [bp-10h]@4
  signed int v8; // [sp+24h] [bp-Ch]@1
  signed int highID; // [sp+2Ch] [bp-4h]@32
  signed int highIDa; // [sp+2Ch] [bp-4h]@40

  evt = this;
  v8 = 0;
  yieldToGlobalUpdater();
  if ( *((_BYTE *)evt + 13) & 2 )
  {
    if ( *((_DWORD *)evt + 1) == 12 || *((_DWORD *)evt + 1) == 14 )
    {
      v7 = -1;
      switch ( *((_DWORD *)evt + 2) )
      {
        case 0x65:
          v7 = 0;
          break;
        case 0x66:
          v7 = 1;
          break;
        case 0x67:
          v7 = 2;
          break;
        case 0x68:
          v7 = 3;
          break;
        case 0x69:
          v7 = 4;
          break;
        default:
          break;
      }
      if ( v7 >= 0 )
        display_message_window(adventureMapLocationMessages[v7 + 116], 4, -1, -1, -1, 0, -1, 0, -1, 0);
    }
  }
  else
  {
    switch ( *(_DWORD *)evt )
    {
      case 1:
        switch ( *((_DWORD *)evt + 1) )
        {
          case 0x31:
            HeroWindowManager::instance->buttonPressedCode = 101;
            v8 = 1;
            break;
          case 0x26:
            HeroWindowManager::instance->buttonPressedCode = 102;
            v8 = 1;
            break;
          case 0x2E:
            HeroWindowManager::instance->buttonPressedCode = 104;
            v8 = 1;
            break;
          case 0x23:
            HeroWindowManager::instance->buttonPressedCode = 103;
            v8 = 1;
            break;
          case 0x10:
            HeroWindowManager::instance->buttonPressedCode = 105;
            v8 = 1;
            break;
          default:
            goto LABEL_54;
        }
        break;
      case 0x200:
        if ( *((_DWORD *)evt + 2) < 101 || *((_DWORD *)evt + 2) > 107 )
          return 0;
        v4 = *((_DWORD *)evt + 1);
        if ( v4 == 12 )
        {
          if ( *((_DWORD *)evt + 2) != 107 )
          {
            v2 = *((_DWORD *)evt + 2) - 101;
            *(_DWORD *)evt = 512;
            *((_DWORD *)evt + 2) = v2 + 11;
            *((_DWORD *)evt + 1) = 4;
            *((_DWORD *)evt + 6) = 4 * v2 + 3;
            GUIWindow::processMessage(dword_4F4BC8, (Event *)evt);
            GUIWindow::repaintComponentsInRange(dword_4F4BC8, 0, v2 + 11, v2 + 11);
            HeroWindowManager::redrawRectangle(
              HeroWindowManager::instance,
              (unsigned __int16)word_50CFE8[4 * v2],
              (unsigned __int16)word_50CFEA[4 * v2],
              (unsigned __int16)word_50CFEC[4 * v2],
              (unsigned __int16)word_50CFEE[4 * v2]);
          }
        }
        else
        {
          if ( v4 == 13 )
          {
            if ( *((_DWORD *)evt + 2) == 107 )
            {
              sub_45A2A0(38);
              ResourceManager::dumpImageToScreen(
                resourceManager,
                "heroes.icn",
                HeroWindowManager::instance->screenBuffer,
                1);
              GUIWindow::repaint(dword_4F4BC8, 0);
              HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 0x280u, 480);
              SoundManager::otherPlayTrack(soundManager, 42, 0, -1, v3);
            }
            else
            {
              HeroWindowManager::instance->buttonPressedCode = *((_DWORD *)evt + 2);
              for ( highID = 11; highID <= 15; ++highID )
              {
                *(_DWORD *)evt = 512;
                *((_DWORD *)evt + 2) = highID;
                *((_DWORD *)evt + 1) = 4;
                *((_DWORD *)evt + 6) = 4 * highID - 44;
                GUIWindow::processMessage(dword_4F4BC8, (Event *)evt);
              }
              GUIWindow::repaintComponentsInRange(dword_4F4BC8, 0, 11, 15);
              HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 105, 0x235u, 375);
              v8 = 1;
            }
          }
        }
        break;
      case 4:
        v6 = -1;
        for ( highIDa = 0; highIDa < 5; ++highIDa )
        {
          if ( (signed int)(unsigned __int16)word_50CFE8[4 * highIDa] <= *((_DWORD *)evt + 4)
            && (signed int)(unsigned __int16)word_50CFEA[4 * highIDa] <= *((_DWORD *)evt + 5)
            && (unsigned __int16)word_50CFE8[4 * highIDa] + (unsigned __int16)word_50CFEC[4 * highIDa] > *((_DWORD *)evt + 4)
            && (unsigned __int16)word_50CFEE[4 * highIDa] + (unsigned __int16)word_50CFEA[4 * highIDa] > *((_DWORD *)evt + 5) )
            v6 = highIDa;
        }
        if ( v6 != dword_50D010 )
        {
          if ( dword_50D010 != -1 )
          {
            *(_DWORD *)evt = 512;
            *((_DWORD *)evt + 2) = dword_50D010 + 11;
            *((_DWORD *)evt + 1) = 4;
            *((_DWORD *)evt + 6) = 4 * dword_50D010 + 1;
            GUIWindow::processMessage(dword_4F4BC8, (Event *)evt);
            GUIWindow::repaintComponentsInRange(dword_4F4BC8, 0, dword_50D010 + 11, dword_50D010 + 11);
            HeroWindowManager::redrawRectangle(
              HeroWindowManager::instance,
              (unsigned __int16)word_50CFE8[4 * dword_50D010],
              (unsigned __int16)word_50CFEA[4 * dword_50D010],
              (unsigned __int16)word_50CFEC[4 * dword_50D010],
              (unsigned __int16)word_50CFEE[4 * dword_50D010]);
          }
          if ( v6 != -1 )
          {
            *(_DWORD *)evt = 512;
            *((_DWORD *)evt + 2) = v6 + 11;
            *((_DWORD *)evt + 1) = 4;
            *((_DWORD *)evt + 6) = 4 * v6 + 2;
            GUIWindow::processMessage(dword_4F4BC8, (Event *)evt);
            GUIWindow::repaintComponentsInRange(dword_4F4BC8, 0, v6 + 11, v6 + 11);
            HeroWindowManager::redrawRectangle(
              HeroWindowManager::instance,
              (unsigned __int16)word_50CFE8[4 * v6],
              (unsigned __int16)word_50CFEA[4 * v6],
              (unsigned __int16)word_50CFEC[4 * v6],
              (unsigned __int16)word_50CFEE[4 * v6]);
          }
          dword_50D010 = v6;
        }
        break;
    }
  }
LABEL_54:
  if ( v8 || dword_4F19A8 != -1 )
  {
    *(_DWORD *)evt = 512;
    *((_DWORD *)evt + 2) = 10;
    *((_DWORD *)evt + 1) = *((_DWORD *)evt + 2);
    result = 2;
  }
  else
  {
    sub_4398D0();
    result = 1;
  }
  return result;
}
