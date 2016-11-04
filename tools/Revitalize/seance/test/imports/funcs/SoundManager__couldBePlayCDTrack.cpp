{
  int v2; // [sp+0h] [bp-10h]@0
  SoundManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( !soundDisabled && this->field_688 )
  {
    if ( *(_DWORD *)&musicVolume )
    {
      if ( SoundManager::songPlaying(this) )
      {
        if ( thisa->currentTrack != track )
        {
          if ( (passOnMessages(), thisa->volRelated) && thisa->_5 != track
            || !thisa->volRelated && thisa->currentTrack != track )
          {
            if ( thisa->volRelated <= 10 )
            {
              thisa->volRelated = 11;
              dword_524BF8 = getTickCount() + 900;
            }
            thisa->_5 = track;
            sub_403E60(thisa);
          }
        }
      }
      else
      {
        SoundManager::otherPlayTrack(thisa, track, 0, -1, v2);
      }
    }
    else
    {
      this->currentTrack = track;
    }
  }
}
