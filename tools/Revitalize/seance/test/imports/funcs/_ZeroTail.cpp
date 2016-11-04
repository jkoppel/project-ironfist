{
  signed int result; // eax@2
  int v3; // edi@3
  int v4; // eax@4

  if ( ~(-1 << (31 - ((((unsigned __int64)a2 >> 32) ^ abs(a2) & 0x1F) - ((unsigned __int64)a2 >> 32)))) & *(_DWORD *)(a1 + 4 * (a2 / 32)) )
  {
    result = 0;
  }
  else
  {
    v3 = a2 / 32 + 1;
    if ( v3 >= 3 )
    {
LABEL_7:
      result = 1;
    }
    else
    {
      v4 = a1 + 4 * v3;
      while ( !*(_DWORD *)v4 )
      {
        v4 += 4;
        ++v3;
        if ( v3 >= 3 )
          goto LABEL_7;
      }
      result = 0;
    }
  }
  return result;
}
