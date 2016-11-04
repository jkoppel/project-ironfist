{
  int v3; // [sp+14h] [bp-8h]@2
  char v4; // [sp+18h] [bp-4h]@1

  v4 = *(_BYTE *)(*(_DWORD *)a2 + a1);
  if ( v4 & 0x40 )
  {
    v3 = *(_WORD *)(*(_DWORD *)a2 + a1 + 1) | ((v4 & 0x3F) << 16);
    *(_DWORD *)a2 += 3;
  }
  else
  {
    if ( v4 & 0x20 )
    {
      v3 = *(_BYTE *)(*(_DWORD *)a2 + a1 + 1) | ((v4 & 0x1F) << 8);
      *(_DWORD *)a2 += 2;
    }
    else
    {
      v3 = v4 & 0x1F;
      ++*(_DWORD *)a2;
    }
  }
  return v3;
}
