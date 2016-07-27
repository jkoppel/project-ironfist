{
  int result; // eax@3

  if ( a1 )
  {
    if ( *(_BYTE *)(a2 + 13) & 0x10 )
    {
      result = _flush(a2);
      *(_DWORD *)(a2 + 12) &= 0xFFFFEEFFu;
      *(_DWORD *)(a2 + 24) = 0;
      *(_DWORD *)a2 = 0;
      *(_DWORD *)(a2 + 8) = 0;
    }
  }
  return result;
}
