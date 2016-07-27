{
  int v2; // esi@1
  int result; // eax@2
  signed int v4; // eax@5
  int v5; // ecx@5
  unsigned int v6; // edi@5
  signed int v7; // ecx@5

  v2 = low;
  if ( high == low )
  {
    result = high;
  }
  else
  {
    if ( high >= low )
    {
      v4 = 0;
      v5 = ((((13 * (_BYTE)high + -3 * (_BYTE)low + -96 * (_BYTE)high + (_BYTE)randomSeed) & 0x3F) << 8)
          + (13 * (_WORD)high & 0xFF)
          + 13233 * (13 * (_WORD)low & 0xFF)
          + 32 * (13 * (_WORD)high & 0xFF)
          + (_WORD)randomSeed) & 0xFFF;
      randomSeed = v5;
      v6 = ((7 * (_WORD)v5 & 0xFF0u) >> 4) + 7 * v5;
      v7 = 31;
      do
      {
        if ( v6 & (1 << v7) )
          v4 |= 1 << v7;
        --v7;
      }
      while ( v7 >= 0 );
      randomSeed = v2 + v6 + 8 * high;
      result = v2 + v4 % (high - v2 + 1);
    }
    else
    {
      result = low;
    }
  }
  return result;
}
