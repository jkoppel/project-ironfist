{
  signed int result; // eax@71
  int v2; // [sp+14h] [bp-90h]@22
  int v3; // [sp+18h] [bp-8Ch]@5
  void *v4; // [sp+1Ch] [bp-88h]@1
  signed int v5; // [sp+20h] [bp-84h]@5
  signed int v6; // [sp+9Ch] [bp-8h]@1
  signed int v7; // [sp+A0h] [bp-4h]@1

  v4 = this;
  v6 = 0;
  v7 = 0;
  if ( *(_DWORD *)this == 512 )
  {
    if ( *((_BYTE *)this + 13) & 2 )
    {
      if ( *((_DWORD *)this + 1) == 12 || *((_DWORD *)this + 1) == 14 )
      {
        v5 = -1;
        v3 = *((_DWORD *)this + 2);
        if ( v3 <= 30720 )
        {
          if ( v3 == 30720 )
          {
            v5 = 0;
          }
          else
          {
            switch ( v3 )
            {
              case 10:
                v5 = 1;
                break;
              case 11:
                v5 = 2;
                break;
              case 12:
                v5 = 3;
                break;
              case 13:
                v5 = 4;
                break;
              case 14:
                v5 = 5;
                break;
              case 15:
                v5 = 6;
                break;
              case 16:
                v5 = 7;
                break;
              case 17:
                v5 = 8;
                break;
              case 18:
                v5 = 9;
                break;
              default:
                break;
            }
          }
        }
        if ( v5 >= 0 )
          NormalDialog((&gSPanelHelp)[4 * v5], 4, -1, -1, -1, 0, -1, 0, -1, 0);
      }
    }
    else
    {
      v2 = *((_DWORD *)this + 1);
      if ( v2 == 12 )
      {
        switch ( *((_DWORD *)this + 2) )
        {
          case 0xA:
            if ( *(_DWORD *)&Data || gpSoundManager->field_69E || gpSoundManager->usingRedbookRelated )
            {
              *(_DWORD *)&Data = (*(_DWORD *)&Data + 1) % 11;
              soundManager::AdjustMusicVolumes((int)gpSoundManager);
              v6 = 1;
              bPrefsChanged = 1;
            }
            else
            {
              NormalDialog(
                "Neither MIDI nor Redbook music is currently available on this system.",
                1,
                -1,
                -1,
                -1,
                0,
                -1,
                0,
                -1,
                0);
            }
            break;
          case 0xB:
            if ( *(_DWORD *)&soundVolume || gpSoundManager->hdidriver )
            {
              *(_DWORD *)&soundVolume = (*(_DWORD *)&soundVolume + 1) % 11;
              soundManager::AdjustSoundVolumes(gpSoundManager);
              v6 = 1;
              bPrefsChanged = 1;
            }
            else
            {
              NormalDialog("Digital sound is not currently available on this system.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
            }
            break;
          case 0xC:
            ++*(_DWORD *)&walkSpeed;
            *(_DWORD *)&walkSpeed %= 5;
            v6 = 1;
            bPrefsChanged = 1;
            break;
          case 0xF:
            if ( *(_DWORD *)&blackoutComputer )
            {
              *(_DWORD *)&blackoutComputer = 0;
              *(_DWORD *)&gConfig = 2;
            }
            else if ( *(_DWORD *)&gConfig >= 4 )
            {
              *(_DWORD *)&blackoutComputer = 1;
            }
            else
            {
              ++*(_DWORD *)&gConfig;
            }
            v6 = 1;
            bPrefsChanged = 1;
            break;
          case 0xD:
            if ( *(_DWORD *)&useCDMusic )
            {
              if ( *(_DWORD *)&useOpera )
              {
                if ( !LODWORD(gpSoundManager->field_6AA) )
                  soundManager::MIDIStartup(gpSoundManager);
                if ( gpSoundManager->usingRedbookRelated )
                  soundManager::SetMusicQuality((int)gpSoundManager, 0);
                else
                  *(_DWORD *)&useOpera = 1 - *(_DWORD *)&useOpera;
              }
              else
              {
                *(_DWORD *)&useOpera = 1;
              }
            }
            else
            {
              if ( !gpSoundManager->field_6A6 )
                soundManager::CDStartup(gpSoundManager);
              if ( !gpSoundManager->field_69E )
              {
                NormalDialog(
                  "Unable to set up CD stereo music.  Your CD player might be in use by another program, or your sound driver might not support CD stereo.",
                  1,
                  -1,
                  -1,
                  -1,
                  0,
                  -1,
                  0,
                  -1,
                  0);
                break;
              }
              soundManager::SetMusicQuality((int)gpSoundManager, 1);
              *(_DWORD *)&useOpera = 0;
            }
            v6 = 1;
            bPrefsChanged = 1;
            break;
          case 0xE:
            *(_DWORD *)&showRoute = 1 - *(_DWORD *)&showRoute;
            v6 = 1;
            bPrefsChanged = 1;
            break;
          case 0x10:
            *(_DWORD *)&evilInterfaceUsage = (*(_DWORD *)&evilInterfaceUsage + 1) % 3;
            v6 = 1;
            bPrefsChanged = 1;
            break;
          case 0x11:
            if ( gbLowMemory )
            {
              NormalDialog("You don't have enough memory for non-interlaced video.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
            }
            else
            {
              *(_DWORD *)&slowVideo = *(_DWORD *)&slowVideo == 0;
              v6 = 1;
              bPrefsChanged = 1;
            }
            break;
          case 0x12:
            *(&bMenu + 6) = 1 - *(&bMenu + 6);
            v6 = 1;
            bPrefsChanged = 1;
            mouseManager::SetColorMice(gpMouseManager, *(&bMenu + 6));
            break;
          default:
            break;
        }
      }
      else if ( v2 == 13 && *((_DWORD *)this + 2) == 30720 )
      {
        v7 = 1;
      }
    }
  }
  if ( v6 )
    UpdateSystemOptions(0);
  if ( v7 )
  {
    gpWindowManager->buttonPressedCode = *((_DWORD *)v4 + 2);
    *((_DWORD *)v4 + 2) = 10;
    *((_DWORD *)v4 + 1) = *((_DWORD *)v4 + 2);
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}