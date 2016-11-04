{
  signed __int32 v7; // eax@11
  signed __int32 v8; // eax@14
  signed int v9; // [sp+14h] [bp-Ch]@5
  int i; // [sp+18h] [bp-8h]@5

  if ( !soundDisabled && this->hdidriver && this->field_688 && *(_DWORD *)&this->_0[0] )
  {
    v9 = -1;
    for ( i = 0; this->numSamplesAllocated > i; ++i )
    {
      if ( this->hsamples[i] == a2 )
        v9 = i;
    }
    switch ( a3 )
    {
      case 1:
      case 100:
        v7 = computeAILVolume(a4, 100);
        AIL_set_sample_volume(a2, v7);
        if ( v9 >= 0 )
          word_522B30[v9] = a4;
        break;
      case 101:
        assertTrue(*(_DWORD *)&useCDMusic < 1u, "F:\\h2xsrc\\Base\\Soundmgr.cpp", word_4ED28C + 27);
        v8 = computeAILVolume(a4, 101);
        AIL_set_sample_volume(a2, v8);
        if ( v9 >= 0 )
          word_522B30[v9] = a4;
        break;
      case 5:
        AIL_start_sample(a2);
        break;
      default:
        break;
    }
    passOnMessages();
  }
}
