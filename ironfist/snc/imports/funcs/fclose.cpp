{
  signed int result; // eax@2
  signed int v2; // edi@3

  if ( *(_BYTE *)(a1 + 12) & 0x40 )
  {
    *(_DWORD *)(a1 + 12) = 0;
    result = -1;
  }
  else
  {
    _lock_file(a1);
    v2 = _fclose_lk(a1);
    _unlock_file(a1);
    result = v2;
  }
  return result;
}