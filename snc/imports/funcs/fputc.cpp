{
  int v2; // eax@1
  signed int v3; // ebx@2

  _lock_file(a2);
  v2 = *(_DWORD *)(a2 + 4) - 1;
  *(_DWORD *)(a2 + 4) = v2;
  if ( v2 < 0 )
  {
    v3 = _flsbuf(a1, a2);
  }
  else
  {
    **(_BYTE **)a2 = a1;
    v3 = *(_BYTE *)(*(_DWORD *)a2)++;
  }
  _unlock_file(a2);
  return v3;
}