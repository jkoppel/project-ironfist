{
  SoundManager *thisa; // [sp+Ch] [bp-E0h]@1
  signed int j; // [sp+10h] [bp-DCh]@14
  signed int k; // [sp+14h] [bp-D8h]@18
  __int16 i; // [sp+18h] [bp-D4h]@4

  thisa = this;
  if ( !soundDisabled && this->hdidriver && this->field_688 )
  {
    for ( i = 0; thisa->numSamplesAllocated > i; ++i )
    {
      if ( AIL_sample_status(thisa->hsamples[i]) == 4 )
        AIL_end_sample(thisa->hsamples[i]);
    }
    thisa->volRelated = 0;
    if ( a2 )
    {
      if ( *(_DWORD *)&useCDMusic )
        sub_4022B0(thisa);
      else
        sub_4CBA70((int)thisa);
    }
    if ( !dword_50FED8 )
    {
      AIL_digital_handle_release(thisa->hdidriver);
      for ( j = 0; ; ++j )
      {
        if ( j < 20 )
        {
          sleep(5);
          if ( !AIL_digital_handle_reacquire(thisa->hdidriver) )
            continue;
        }
        break;
      }
    }
    for ( k = 0; k < 10; ++k )
      sleep(2);
  }
}
