{
  DWORD v2; // edi@1
  HANDLE v3; // eax@3
  LPVOID result; // eax@5
  char v5; // zf@9

  v2 = a1 * a2;
  if ( !(a1 * a2) )
    v2 = 1;
  v3 = _crtheap;
  while ( 1 )
  {
    result = v2 <= 0xFFFFFFE0 ? HeapAlloc(v3, 8u, v2) : 0;
    if ( result || !_newmode )
      break;
    v5 = _callnewh(v2) == 0;
    v3 = _crtheap;
    if ( v5 )
      return 0;
  }
  return result;
}