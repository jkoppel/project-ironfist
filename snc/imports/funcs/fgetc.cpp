{
  int v1; // eax@1
  signed int v2; // ebx@2

  _lock_file(a1);
  v1 = *(_DWORD *)(a1 + 4) - 1;
  *(_DWORD *)(a1 + 4) = v1;
  if ( v1 < 0 )
    v2 = _filbuf(a1);
  else
    v2 = *(_BYTE *)(*(_DWORD *)a1)++;
  _unlock_file(a1);
  return v2;
}