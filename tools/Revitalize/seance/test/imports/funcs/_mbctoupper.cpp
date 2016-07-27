{
  int result; // eax@3
  const CHAR MultiByteStr; // [sp+6h] [bp-6h]@2
  char v3; // [sp+7h] [bp-5h]@2
  WCHAR DestStr; // [sp+8h] [bp-4h]@4

  if ( (unsigned int)a1 <= 0xFF )
  {
    if ( a1 < 97 || a1 > 122 )
      result = a1;
    else
      result = a1 - 32;
  }
  else
  {
    MultiByteStr = BYTE1(a1);
    v3 = a1;
    if ( byte_521581[BYTE1(a1)] & 4 )
    {
      if ( __crtLCMapStringA(dword_521688, 0x200u, &MultiByteStr, 2, (CHAR *)&DestStr, 2, dword_521684) )
        result = HIBYTE(DestStr) + ((unsigned __int8)DestStr << 8);
      else
        result = a1;
    }
    else
    {
      result = a1;
    }
  }
  return result;
}
