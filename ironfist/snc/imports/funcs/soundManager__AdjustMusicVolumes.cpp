{
  if ( !gbNoSound && *(_DWORD *)(this + 1672) && (signed int)*(_BYTE *)(this + 1404) >= 0 )
  {
    if ( *(_DWORD *)&Data )
    {
      if ( *(_DWORD *)&useCDMusic )
        soundManager::CDSetVolume((soundManager *)this, -1, 0);
      else
        soundManager::MIDISetVolume((soundManager *)this);
    }
    else if ( *(_DWORD *)&useCDMusic )
    {
      soundManager::CDSetVolume((soundManager *)this, -1, 0);
    }
    else
    {
      soundManager::MIDISetVolume((soundManager *)this);
    }
  }
}