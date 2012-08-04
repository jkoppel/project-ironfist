{
  int v2; // [sp+Ch] [bp-28h]@1
  int v3; // [sp+10h] [bp-24h]@1
  signed int i; // [sp+14h] [bp-20h]@11
  signed int v5; // [sp+1Ch] [bp-18h]@4
  int v6; // [sp+20h] [bp-14h]@4
  signed int v7; // [sp+24h] [bp-10h]@6
  int v8; // [sp+28h] [bp-Ch]@4
  signed int v9; // [sp+2Ch] [bp-8h]@4
  int v10; // [sp+30h] [bp-4h]@2

  v2 = a2;
  v3 = (int)a1;
  if ( a2 )
    v10 = last - 1;
  else
    v10 = last;
  v9 = 0;
  v6 = 0;
  v5 = 256;
  v8 = getGlobalCRC();
  while ( v6 <= v10 )
  {
    v7 = v5;
    v5 = *((_BYTE *)block + v6++);
    if ( putc(v5, v3) == -1 )
      ioError();
    v8 = (v8 << 8) ^ crc32Table[((unsigned int)v8 >> 24) ^ (unsigned __int8)v5];
    if ( v5 == v7 )
    {
      ++v9;
      if ( v9 >= 4 )
      {
        for ( i = 0; *((_BYTE *)block + v6) > i; ++i )
        {
          if ( putc(v5, v3) == -1 )
            ioError();
          v8 = (v8 << 8) ^ crc32Table[((unsigned int)v8 >> 24) ^ (unsigned __int8)v5];
        }
        ++v6;
        v9 = 0;
      }
    }
    else
    {
      v9 = 1;
    }
  }
  setGlobalCRC((void *)v8);
  if ( v2 && *((_BYTE *)block + last) != 42 )
    unblockError();
}