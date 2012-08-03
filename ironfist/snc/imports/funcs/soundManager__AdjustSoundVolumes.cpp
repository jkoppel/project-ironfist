{
  int v1; // [sp+0h] [bp-18h]@0
  __int16 v2; // [sp+4h] [bp-14h]@0
  int v3; // [sp+8h] [bp-10h]@0
  soundManager *thisa; // [sp+Ch] [bp-Ch]@1
  HSAMPLE samp; // [sp+10h] [bp-8h]@6
  int i; // [sp+14h] [bp-4h]@4

  thisa = this;
  if ( !gbNoSound && this->hdidriver && this->aiMusicOff )
  {
    for ( i = 1; thisa->numSamplesAllocated > i; ++i )
    {
      samp = thisa->hsamples[i];
      if ( *(_DWORD *)&soundVolume )
      {
        if ( soundManager::DigitalReport(thisa, samp, 4) )
          soundManager::ModifySample(thisa, samp, 100, iLastVolume[i], v1, v2, v3);
      }
      else
      {
        soundManager::ModifySample(thisa, samp, 1, 0, v1, v2, v3);
      }
    }
  }
}