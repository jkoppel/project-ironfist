{
  signed int v2; // [sp+Ch] [bp-10h]@1
  signed int v3; // [sp+Ch] [bp-10h]@4
  void *v4; // [sp+10h] [bp-Ch]@1
  unsigned int v5; // [sp+14h] [bp-8h]@2
  int v6; // [sp+18h] [bp-4h]@2

  v2 = a2;
  v4 = a1;
  if ( a2 )
  {
    v5 = 0;
    v6 = 0;
    while ( v2 )
    {
      ++v6;
      v5 *= 2;
      v3 = v2 - 1;
      if ( v3 & 1 )
        v5 |= 1u;
      v2 = v3 >> 1;
    }
    while ( v6 > 0 )
    {
      if ( v5 & 1 )
        sendMTFVal(v4, 257);
      else
        sendMTFVal(v4, 258);
      v5 >>= 1;
      --v6;
    }
  }
}