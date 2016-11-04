{
  int v1; // [sp+0h] [bp-18h]@0
  __int16 v2; // [sp+4h] [bp-14h]@0
  int v3; // [sp+8h] [bp-10h]@0
  SoundManager *thisa; // [sp+Ch] [bp-Ch]@1
  HSAMPLE a2; // [sp+10h] [bp-8h]@6
  int i; // [sp+14h] [bp-4h]@4

  thisa = this;
  if ( !soundDisabled && this->hdidriver && this->field_688 )
  {
    for ( i = 1; thisa->numSamplesAllocated > i; ++i )
    {
      a2 = thisa->hsamples[i];
      if ( *(_DWORD *)&soundVolume )
      {
        if ( SoundManager::sampleStillPlaying(thisa, a2, 4) )
          sub_4037F0(thisa, a2, 100, word_522B30[i], v1, v2, v3);
      }
      else
      {
        sub_4037F0(thisa, a2, 1, 0, v1, v2, v3);
      }
    }
  }
}
