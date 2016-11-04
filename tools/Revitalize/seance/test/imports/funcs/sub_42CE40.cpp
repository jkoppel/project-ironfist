{
  signed int v4; // ecx@2
  int result; // eax@2
  char v6; // [sp+1Ch] [bp-4h]@1

  v6 = a1 << 7;
  if ( a2 <= 8191 )
  {
    if ( a2 <= 31 )
    {
      *(_BYTE *)(*(_DWORD *)a4 + a3) = a2 | v6;
      result = a4;
      ++*(_DWORD *)result;
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)a4 + a3) = BYTE1(a2) & 0x1F | v6 | 0x20;
      *(_BYTE *)(*(_DWORD *)a4 + a3 + 1) = a2;
      result = a4;
      *(_DWORD *)result += 2;
    }
  }
  else
  {
    v4 = a2;
    *(_BYTE *)(*(_DWORD *)a4 + a3) = ((v4 & 0x2F0000u) >> 16) | v6 | 0x40;
    *(_WORD *)(*(_DWORD *)a4 + a3 + 1) = a2;
    result = a4;
    *(_DWORD *)result += 3;
  }
  return result;
}
