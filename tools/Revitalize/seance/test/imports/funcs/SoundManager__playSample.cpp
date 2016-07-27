{
  signed __int32 v3; // ST08_4@23
  SoundManager *v4; // [sp+Ch] [bp-14h]@1
  char *v5; // [sp+10h] [bp-10h]@12
  struct _SAMPLE *S; // [sp+14h] [bp-Ch]@22
  __int16 i; // [sp+18h] [bp-8h]@12

  v4 = this;
  if ( soundDisabled )
    return 0;
  if ( !this->hdidriver )
    return 0;
  if ( !this->field_688 )
    return 0;
  if ( !*(_DWORD *)&soundVolume )
    return 0;
  if ( !*(_DWORD *)&this->_0[0] || !a2->field_28 )
    return 0;
  v5 = (char *)&unk_4ED078 + 12 * a2->codeThing;
  for ( i = *(_DWORD *)v5; *((_DWORD *)v5 + 1) > (signed int)i && AIL_sample_status(v4->hsamples[i]) != 2; ++i )
    ;
  if ( *((_DWORD *)v5 + 1) == i )
  {
    if ( a2->codeThing == 4 )
      return 0;
    i = (*((_DWORD *)v5 + 2))++;
    if ( *((_DWORD *)v5 + 1) <= *((_DWORD *)v5 + 2) )
    {
      *((_DWORD *)v5 + 2) = *(_DWORD *)v5;
      i = *((_DWORD *)v5 + 2);
    }
    sub_403760((int)v4, (int)v4->hsamples[i]);
  }
  S = v4->hsamples[i];
  v4->_1[i + 64] = LOBYTE(a2->field_28);
  word_522B30[i] = a2->field_28;
  AIL_init_sample(S);
  AIL_set_sample_type(S, a2->sampleType, 0);
  AIL_set_sample_playback_rate(S, a2->playbackRate);
  AIL_set_sample_loop_count(S, a2->loopCount);
  AIL_set_sample_address(S, a2->contents, a2->nbytes);
  if ( *(_DWORD *)&soundVolume )
  {
    v3 = computeAILVolume(a2->field_28, 100);
    AIL_set_sample_volume(S, v3);
  }
  else
  {
    AIL_set_sample_volume(S, 0);
  }
  AIL_start_sample(S);
  a2->field_10 = (int)S;
  *(_DWORD *)&v4->_2[4 * i] = S;
  *(_DWORD *)&v4->_2[4 * i + 64] = a2->contents;
  *(_DWORD *)&v4->_2[4 * i + 128] = a2->nbytes;
  return S;
}
