{
  SoundManager *thisa; // [sp+Ch] [bp-8h]@1
  int i; // [sp+10h] [bp-4h]@3

  thisa = this;
  if ( !soundDisabled && this->hdidriver )
  {
    for ( i = 0; ; ++i )
    {
      if ( i < 14 )
      {
        thisa->hsamples[i] = AIL_allocate_sample_handle(thisa->hdidriver);
        if ( thisa->hsamples[i] )
          continue;
      }
      break;
    }
    thisa->numSamplesAllocated = i;
  }
}
