void __thiscall SoundManager::otherPlayTrack(SoundManager *this, int track, int a3, int a4, int a5)
{
  SoundManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( !soundDisabled && this->field_688 && *(_DWORD *)&this->_0[0] && this->currentTrack != track )
  {
    if ( *(_DWORD *)&musicVolume )
    {
      if ( *(_DWORD *)&useCDMusic )
        sub_402950(this, track, a3, -1, 0);
      else
        SoundManager::playMidiSong(this, track);
      thisa->currentTrack = track;
    }
    else
    {
      this->currentTrack = track;
    }
  }
}
