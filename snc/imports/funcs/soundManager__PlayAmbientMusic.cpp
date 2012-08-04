{
  soundManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( !gbNoSound && this->aiMusicOff && *(_DWORD *)&this->_0[0] && this->currentTrack != track )
  {
    if ( *(_DWORD *)&Data )
    {
      if ( *(_DWORD *)&useCDMusic )
        soundManager::CDPlay(this, track, a3, -1, 0);
      else
        soundManager::MIDIPlay(this, track);
      thisa->currentTrack = track;
    }
    else
    {
      this->currentTrack = track;
    }
  }
}