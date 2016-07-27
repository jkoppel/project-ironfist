{
  signed int i; // [sp+14h] [bp-4h]@1

  for ( i = 65; i >= 0; --i )
  {
    if ( a2 && a2 != 2 )
    {
      if ( word_4F2C28[2 * i] <= a1 )
        return word_4F2C2A[2 * i];
    }
    else
    {
      if ( word_4F2D30[2 * i] >= a1 )
        return word_4F2D32[2 * i];
    }
  }
  return word_4F2C2A[0];
}
