int __cdecl realloc(BOOL lpMem, DWORD dwBytes)
{
  int result; // eax@2
  HANDLE v3; // eax@5
  char v4; // zf@11

  if ( lpMem )
  {
    if ( dwBytes )
    {
      v3 = hHeap;
      while ( 1 )
      {
        result = (int)(dwBytes <= 0xFFFFFFE0 ? HeapReAlloc(v3, 0, (LPVOID)lpMem, dwBytes) : 0);
        if ( result || !dword_521828 )
          break;
        v4 = _callnewh(dwBytes) == 0;
        v3 = hHeap;
        if ( v4 )
          return 0;
      }
    }
    else
    {
      free(lpMem);
      result = 0;
    }
  }
  else
  {
    result = malloc(dwBytes);
  }
  return result;
}
