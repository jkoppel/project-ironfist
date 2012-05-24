{
  SoundManager *thisa;
  signed int i;

  this->field_6A6 = 0;
  LODWORD(this->field_6AA) = 0;
  this->field_69E = 0;
  this->usingRedbookRelated = 0;
  memset(&byte_523020, 0, 0x3Cu);
  memset(byte_524060, 0, 0x3Cu);
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
    byte_524060[i] = 1;
  if ( (unsigned __int16)GetAsyncKeyState(VK_F6) >> 8 )
  {
    *(_DWORD *)&useCDMusic = 0;
    propagateSettingChanges();
  }
  if ( (unsigned __int16)GetAsyncKeyState(VK_F7) >> 8 )
  {
    *(_DWORD *)&useCDMusic = 1;
    propagateSettingChanges();
  }
  this->currentTrack = -1;
  if ( !soundDisabled )
  {
    this->_4[0] = 0;
    this->_4[1] = this->_4[0];
    this->_4[2] = this->_4[1];
    AIL_startup();
    if ( *(_DWORD *)&useCDMusic )
    {
      SoundManager::initializeRedbook(this);
      if ( !this->field_69E )
      {
        SoundManager::readyMidiOutput(this);
        if ( this->usingRedbookRelated )
        {
          *(_DWORD *)&useCDMusic = 0;
          propagateSettingChanges();
        }
        else
        {
          *(_DWORD *)&musicVolume = 0;
          propagateSettingChanges();
        }
      }
    }
    else
    {
      SoundManager::readyMidiOutput(this);
      if ( !this->usingRedbookRelated )
      {
        SoundManager::initializeRedbook(this);
        if ( this->field_69E )
        {
          *(_DWORD *)&useCDMusic = 1;
          propagateSettingChanges();
        }
        else
        {
          *(_DWORD *)&musicVolume = 0;
          propagateSettingChanges();
        }
      }
    }
    this->field_688 = 1;
    memset(this->_0, 0, 0xAEu);
    if ( !disableSound && !this->hdidriver )
      this->hdidriver = initializeWaveOutput(0x5622u, 8, 1u, 0);
    if ( !this->hdidriver )
    {
      *(_DWORD *)&soundVolume = 0;
      propagateSettingChanges();
    }
    SoundManager::allocateSamples(this);
    *(_DWORD *)&this->_0[0] = 1;
    *(_DWORD *)&this->_0[18] = 0;
    memset(&this->_4[23], 0, 0xF0u);
    *(_DWORD *)&this->_4[263] = 1;
  }
  this->type = 16;
  this->idx = -1;
  this->ready = 1;
  strcpy(this->name, "soundManager");
  return 0;
}
