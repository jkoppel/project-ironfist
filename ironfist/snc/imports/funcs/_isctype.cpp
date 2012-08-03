{
  int result; // eax@2
  int v3; // eax@4
  __int16 CharType; // [sp+6h] [bp-6h]@6
  __int16 MultiByteStr; // [sp+8h] [bp-4h]@4
  char v6; // [sp+Ah] [bp-2h]@4

  if ( (unsigned int)(a1 + 1) > 0x100 )
  {
    if ( HIBYTE(_pctype[BYTE1(a1)]) & 0x80 )
    {
      v3 = 2;
      LOBYTE(MultiByteStr) = BYTE1(a1);
      v6 = 0;
      HIBYTE(MultiByteStr) = a1;
    }
    else
    {
      v3 = 1;
      MultiByteStr = (unsigned __int8)a1;
    }
    if ( __crtGetStringTypeA(1u, (LPCSTR)&MultiByteStr, v3, (LPWORD)&CharType, 0, 0) )
      result = (unsigned __int16)(a2 & CharType);
    else
      result = 0;
  }
  else
  {
    result = (unsigned __int16)(a2 & _pctype[a1]);
  }
  return result;
}