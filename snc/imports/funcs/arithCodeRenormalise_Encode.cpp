{
  int result; // eax@3
  int v2; // [sp+Ch] [bp-4h]@1

  v2 = (int)this;
  while ( (unsigned int)bigR <= 0x1000000 )
  {
    result = bigL + bigR;
    if ( (unsigned int)(bigL + bigR) > 0x2000000 )
    {
      if ( (unsigned int)bigL < 0x2000000 )
      {
        ++bitsOutstanding;
        bigL -= 16777216;
      }
      else
      {
        result = arithCodeBitPlusFollow(v2, 1);
        bigL -= 33554432;
      }
    }
    else
    {
      result = arithCodeBitPlusFollow(v2, 0);
    }
    bigL *= 2;
    bigR *= 2;
  }
  return result;
}