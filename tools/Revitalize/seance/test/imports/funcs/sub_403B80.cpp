{
  if ( !soundDisabled && *(_DWORD *)(this + 1672) && (signed int)*(_BYTE *)(this + 1404) >= 0 )
  {
    if ( *(_DWORD *)&musicVolume )
    {
      if ( *(_DWORD *)&useCDMusic )
        SoundManager::setCDMusicVolume((SoundManager *)this, -1, 0);
      else
        SoundManager::resetMidiVolume((SoundManager *)this);
    }
    else
    {
      if ( *(_DWORD *)&useCDMusic )
        SoundManager::setCDMusicVolume((SoundManager *)this, -1, 0);
      else
        SoundManager::resetMidiVolume((SoundManager *)this);
    }
  }
}
