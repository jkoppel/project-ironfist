{
  int v2; // [sp+Ch] [bp-11Ch]@1
  int v3; // [sp+10h] [bp-118h]@15
  int v4; // [sp+10h] [bp-118h]@16
  int v5; // [sp+14h] [bp-114h]@7
  signed int j; // [sp+18h] [bp-110h]@29
  int v7; // [sp+1Ch] [bp-10Ch]@1
  signed int i; // [sp+20h] [bp-108h]@4
  int v9; // [sp+24h] [bp-104h]@1
  char v10[256]; // [sp+28h] [bp-100h]@6

  v2 = this;
  v7 = 100000 * blockSize100k;
  v9 = getInt32(this);
  if ( v9 >= 0 )
    origPtr = v9 - 1;
  else
    origPtr = -v9 - 1;
  initModels();
  for ( i = 0; i <= 255; ++i )
    v10[i] = i;
  last = -1;
  v5 = getMTFVal(v2);
  while ( v5 != 259 )
  {
    if ( v5 != 257 && v5 != 258 )
    {
      if ( v5 < 1 || v5 > 255 )
      {
        sprintf(gText, "bad MTF value %d\n", v5);
        LogStr(gText);
        panic();
        return 1;
      }
      ++last;
      if ( last >= v7 )
        blockOverrun();
      *((_BYTE *)ll + last) = v10[v5];
      for ( j = v5; j > 3; j -= 4 )
      {
        v10[j] = *((_BYTE *)&v9 + j + 3);
        *((_BYTE *)&v9 + j + 3) = *((_BYTE *)&v9 + j + 2);
        *((_BYTE *)&v9 + j + 2) = *((_BYTE *)&v9 + j + 1);
        *((_BYTE *)&v9 + j + 1) = *((_BYTE *)&v9 + j);
      }
      while ( j > 0 )
      {
        v10[j] = *((_BYTE *)&v9 + j + 3);
        --j;
      }
      v10[0] = *((_BYTE *)ll + last);
      v5 = getMTFVal(v2);
    }
    else
    {
      v3 = 0;
      do
      {
        v4 = 2 * v3;
        if ( v5 == 257 )
          v4 |= 1u;
        v3 = v4 + 1;
        v5 = getMTFVal(v2);
      }
      while ( v5 == 257 || v5 == 258 );
      while ( v3 > 0 )
      {
        ++last;
        if ( last >= v7 )
          blockOverrun();
        *((_BYTE *)ll + last) = v10[0];
        --v3;
      }
    }
  }
  return v9 < 0;
}