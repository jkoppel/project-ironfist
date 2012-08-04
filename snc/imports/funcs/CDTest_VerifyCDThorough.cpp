{
  signed int i; // [sp+Ch] [bp-4h]@1

  for ( i = 1; i <= 43; ++i )
  {
    if ( !CDTest_VerifyTrack(i) )
      return 0;
  }
  return 1;
}