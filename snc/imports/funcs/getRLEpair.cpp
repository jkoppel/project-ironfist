{
  int result; // eax@4
  int v2; // [sp+Ch] [bp-14h]@1
  signed int i; // [sp+10h] [bp-10h]@16
  signed int v4; // [sp+14h] [bp-Ch]@5
  signed int v5; // [sp+18h] [bp-8h]@1
  int v6; // [sp+1Ch] [bp-4h]@6

  v2 = (int)this;
  v5 = getc((int)this);
  if ( v5 == -1 )
  {
    if ( *_errno() )
      ioError();
    result = 65793;
  }
  else
  {
    v4 = 0;
    do
    {
      v6 = getc(v2);
      ++v4;
      ++bytesIn;
    }
    while ( v6 == v5 && v4 < 255 );
    if ( v6 == -1 )
    {
      if ( *_errno() )
        ioError();
    }
    else if ( ungetc(v6, v2) == -1 )
    {
      panic();
    }
    if ( v4 == 1 )
    {
      globalCrc = (globalCrc << 8) ^ crc32Table[((unsigned int)globalCrc >> 24) ^ (unsigned __int8)v5];
      result = v5 | 0x10000;
    }
    else
    {
      for ( i = 1; i <= v4; ++i )
        globalCrc = (globalCrc << 8) ^ crc32Table[((unsigned int)globalCrc >> 24) ^ (unsigned __int8)v5];
      result = v5 | (v4 << 16);
    }
  }
  return result;
}