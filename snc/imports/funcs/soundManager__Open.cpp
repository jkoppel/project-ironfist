{
  soundManager *thisa; // [sp+Ch] [bp-Ch]@1
  signed int i; // [sp+14h] [bp-4h]@1

  thisa = this;
  this->field_6A6 = 0;
  LODWORD(this->field_6AA) = 0;
  this->field_69E = 0;
  this->usingRedbookRelated = 0;
  memset(&bSaveMusicPosition, 0, 0x3Cu);
  memset(bMusicIsLooping, 0, 0x3Cu);
  byte_523030 = 1;
  byte_523032 = 1;
  byte_52302E = 1;
  byte_52302F = 1;
  byte_52302B = 1;
  byte_52302D = 1;
  byte_523031 = 1;
  byte_52302C = 1;
  byte_52303C = 1;
  byte_52304A = 1;
  byte_524070 = 1;
  byte_524072 = 1;
  byte_52406E = 1;
  byte_52406F = 1;
  byte_52406B = 1;
  byte_52406D = 1;
  byte_524071 = 1;
  byte_52406C = 1;
  byte_524068 = 1;
  byte_524069 = 1;
  byte_524065 = 1;
  byte_524066 = 1;
  byte_52406A = 1;
  byte_524067 = 1;
  byte_52408A = 1;
  byte_52407C = 1;
  byte_52408B = 1;
  byte_524076 = 1;
  byte_524078 = 1;
  for ( i = 2; i <= 4; ++i )
    bMusicIsLooping[i] = 1;
  if ( (unsigned __int16)GetAsyncKeyState(VK_F6) >> 8 )
  {
    *(_DWORD *)&useCDMusic = 0;
    WritePrefs();
  }
  if ( (unsigned __int16)GetAsyncKeyState(VK_F7) >> 8 )
  {
    *(_DWORD *)&useCDMusic = 1;
    WritePrefs();
  }
  thisa->currentTrack = -1;
  if ( !gbNoSound )
  {
    thisa->_4[0] = 0;
    thisa->_4[1] = thisa->_4[0];
    thisa->_4[2] = thisa->_4[1];
    AIL_startup();
    if ( *(_DWORD *)&useCDMusic )
    {
      soundManager::CDStartup(thisa);
      if ( !thisa->field_69E )
      {
        soundManager::MIDIStartup(thisa);
        if ( thisa->usingRedbookRelated )
        {
          *(_DWORD *)&useCDMusic = 0;
          WritePrefs();
        }
        else
        {
          *(_DWORD *)&Data = 0;
          WritePrefs();
        }
      }
    }
    else
    {
      soundManager::MIDIStartup(thisa);
      if ( !thisa->usingRedbookRelated )
      {
        soundManager::CDStartup(thisa);
        if ( thisa->field_69E )
        {
          *(_DWORD *)&useCDMusic = 1;
          WritePrefs();
        }
        else
        {
          *(_DWORD *)&Data = 0;
          WritePrefs();
        }
      }
    }
    thisa->aiMusicOff = 1;
    memset(thisa->_0, 0, 0xAEu);
    if ( !gbDontTryDigital && !thisa->hdidriver )
      thisa->hdidriver = WAVE_init_driver(0x5622u, 8, 1u, 0);
    if ( !thisa->hdidriver )
    {
      *(_DWORD *)&soundVolume = 0;
      WritePrefs();
    }
    soundManager::AllocateSampleHandles(thisa);
    *(_DWORD *)&thisa->_0[0] = 1;
    *(_DWORD *)&thisa->_0[18] = 0;
    memset(&thisa->_4[23], 0, 0xF0u);
    *(_DWORD *)&thisa->_4[263] = 1;
  }
  thisa->type = 16;
  thisa->idx = -1;
  thisa->ready = 1;
  strcpy(thisa->name, "soundManager");
  return 0;
}