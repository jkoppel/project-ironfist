{
  int v2; // [sp+0h] [bp-10h]@0
  soundManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( !gbNoSound && this->aiMusicOff )
  {
    if ( *(_DWORD *)&Data )
    {
      if ( soundManager::MusicPlaying(this) )
      {
        if ( thisa->currentTrack != track )
        {
          if ( (Process1WindowsMessage(), thisa->volRelated) && thisa->_5 != track
            || !thisa->volRelated && thisa->currentTrack != track )
          {
            if ( thisa->volRelated <= 10 )
            {
              thisa->volRelated = 11;
              dword_524BF8 = KBTickCount() + 900;
            }
            thisa->_5 = track;
            soundManager::PollSound(thisa);
          }
        }
      }
      else
      {
        soundManager::PlayAmbientMusic(thisa, track, 0, -1, v2);
      }
    }
    else
    {
      this->currentTrack = track;
    }
  }
}