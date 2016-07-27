{
  int result; // eax@1
  int v3; // esi@1
  int v4; // edi@2
  int v5; // ST08_4@4
  int v6; // eax@4

  result = __addl(
             *(_DWORD *)(a1 + 4 * (a2 / 32)),
             1 << (31 - ((((unsigned __int64)a2 >> 32) ^ abs(a2) & 0x1F) - ((unsigned __int64)a2 >> 32))),
             a1 + 4 * (a2 / 32));
  v3 = a2 / 32 - 1;
  if ( v3 >= 0 )
  {
    v4 = a1 + 4 * v3;
    do
    {
      if ( !result )
        break;
      v5 = v4;
      v6 = *(_DWORD *)v4;
      v4 -= 4;
      result = __addl(v6, 1, v5);
      --v3;
    }
    while ( v3 >= 0 );
  }
  return result;
}
