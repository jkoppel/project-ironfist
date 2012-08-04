{
  int v1; // ebx@1
  int result; // eax@5
  int v3; // eax@8
  unsigned __int16 v4; // ax@9
  int v5; // eax@13
  int v6; // eax@15
  WCHAR DestStr; // [sp+4h] [bp-8h]@15
  __int16 MultiByteStr; // [sp+8h] [bp-4h]@13
  char v9; // [sp+Ah] [bp-2h]@13

  v1 = a1;
  if ( Locale )
  {
    if ( a1 >= 256 || (__mb_cur_max <= 1 ? (v4 = _pctype[a1], v3 = v4 & 2) : (v3 = _isctype(a1, 2)), v3) )
    {
      if ( HIBYTE(_pctype[BYTE1(v1)]) & 0x80 )
      {
        v5 = 2;
        LOBYTE(MultiByteStr) = BYTE1(v1);
        v9 = 0;
        HIBYTE(MultiByteStr) = a1;
      }
      else
      {
        v5 = 1;
        MultiByteStr = (unsigned __int8)a1;
      }
      v6 = __crtLCMapStringA(Locale, 0x200u, (LPCSTR)&MultiByteStr, v5, (CHAR *)&DestStr, 3, 0);
      if ( v6 )
      {
        if ( v6 == 1 )
          result = (unsigned __int8)DestStr;
        else
          result = (unsigned __int8)DestStr | (HIBYTE(DestStr) << 8);
      }
      else
      {
        result = a1;
      }
    }
    else
    {
      result = a1;
    }
  }
  else
  {
    if ( a1 >= 97 )
    {
      if ( a1 <= 122 )
        v1 = a1 - 32;
    }
    result = v1;
  }
  return result;
}