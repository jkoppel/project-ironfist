{
  soundManager *thisa; // [sp+Ch] [bp-8h]@1
  unsigned __int32 v2; // [sp+10h] [bp-4h]@6

  thisa = this;
  if ( !gbNoSound && this->field_69E )
  {
    if ( CDPlaying )
    {
      if ( this->currentTrack >= 0 )
      {
        if ( soundManager::CDIsPlaying(this) )
        {
          v2 = AIL_redbook_position(aStatusCdPositi);
          if ( *((_DWORD *)ptr + thisa->currentTrack) <= v2 )
          {
            if ( *((_DWORD *)dword_4ED0B4 + thisa->currentTrack) >= v2 )
              *((_DWORD *)dword_4ED0B8 + thisa->currentTrack) = v2;
          }
        }
      }
    }
    thisa->redbookStatus = AIL_redbook_stop(aStatusCdPositi);
    if ( thisa->redbookStatus != 3 )
    {
      DelayMilli(100);
      thisa->redbookStatus = AIL_redbook_status(aStatusCdPositi);
      if ( thisa->redbookStatus != 3 )
        thisa->redbookStatus = AIL_redbook_stop(aStatusCdPositi);
    }
    CDPlaying = 0;
  }
}