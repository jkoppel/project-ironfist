{
  int v2; // esi@2
  signed int v3; // eax@6
  double result; // st7@16
  double v5; // [sp+8h] [bp-8h]@2

  if ( LODWORD(a1) | HIDWORD(a1) & 0x7FFFFFFF )
  {
    if ( !(WORD3(a1) & 0x7FF0) && (HIDWORD(a1) & 0xFFFFF || LODWORD(a1)) )
    {
      v2 = -1021;
      v3 = 1;
      if ( a1 >= 0.0 )
        v3 = 0;
      for ( ; !(BYTE6(a1) & 0x10); LODWORD(a1) *= 2 )
      {
        HIDWORD(a1) *= 2;
        if ( LODWORD(a1) & 0x80000000 )
          HIDWORD(a1) |= 1u;
        --v2;
      }
      WORD3(a1) &= 0xFFEFu;
      if ( v3 )
        BYTE7(a1) |= 0x80u;
      v5 = _set_exp(a1, 0);
    }
    else
    {
      v2 = ((unsigned __int16)(WORD3(a1) & 0x7FF0) >> 4) - 1022;
      v5 = _set_exp(a1, 0);
    }
  }
  else
  {
    v2 = 0;
    v5 = 0.0;
  }
  result = v5;
  *(_DWORD *)a2 = v2;
  return result;
}
