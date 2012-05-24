{
  SoundManager *thisa; // [sp+Ch] [bp-8h]@1
  unsigned __int32 v2; // [sp+10h] [bp-4h]@6

  thisa = this;
  if ( !soundDisabled && this->field_69E )
  {
    if ( dword_4ED0AC )
    {
      if ( this->currentTrack >= 0 )
      {
        if ( sub_4023E0(this) )
        {
          v2 = AIL_redbook_position(redbook);
          if ( *((_DWORD *)ptr + thisa->currentTrack) <= v2 )
          {
            if ( *((_DWORD *)dword_4ED0B4 + thisa->currentTrack) >= v2 )
              *((_DWORD *)dword_4ED0B8 + thisa->currentTrack) = v2;
          }
        }
      }
    }
    thisa->redbookStatus = AIL_redbook_stop(redbook);
    if ( thisa->redbookStatus != 3 )
    {
      sleep(100);
      thisa->redbookStatus = AIL_redbook_status(redbook);
      if ( thisa->redbookStatus != 3 )
        thisa->redbookStatus = AIL_redbook_stop(redbook);
    }
    dword_4ED0AC = 0;
  }
}
