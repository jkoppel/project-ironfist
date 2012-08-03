{
  int v3; // eax@1
  signed int v4; // eax@2
  char v5; // zf@4
  int result; // eax@4

  v3 = *(_DWORD *)(a2 + 4) - 1;
  *(_DWORD *)(a2 + 4) = v3;
  if ( v3 < 0 )
  {
    v4 = _flsbuf(a1, a2);
  }
  else
  {
    **(_BYTE **)a2 = a1;
    v4 = *(_BYTE *)(*(_DWORD *)a2)++;
  }
  v5 = v4 == -1;
  result = a3;
  if ( v5 )
    *(_DWORD *)a3 = -1;
  else
    ++*(_DWORD *)a3;
  return result;
}