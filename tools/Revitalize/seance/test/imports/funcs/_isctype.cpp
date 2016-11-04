{
  int result; // eax@2
  int v3; // eax@4
  __int16 CharType; // [sp+6h] [bp-6h]@6
  __int16 v5; // [sp+8h] [bp-4h]@4

  if ( (unsigned int)(a1 + 1) > 0x100 )
  {
    if ( *((_BYTE *)off_520FE0 + 2 * BYTE1(a1) + 1) & 0x80 )
    {
      v3 = 2;
      LOBYTE(v5) = BYTE1(a1);
      *(__int16 *)((char *)&v5 + 1) = (unsigned __int8)a1;
    }
    else
    {
      v3 = 1;
      v5 = (unsigned __int8)a1;
    }
    if ( __crtGetStringTypeA(1u, (LPCSTR)&v5, v3, (LPWORD)&CharType, 0, 0) )
      result = (unsigned __int16)(a2 & CharType);
    else
      result = 0;
  }
  else
  {
    result = (unsigned __int16)(a2 & *((_WORD *)off_520FE0 + a1));
  }
  return result;
}
