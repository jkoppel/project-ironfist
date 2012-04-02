BOOL __cdecl free(BOOL lpMem)
{
  BOOL result; // eax@1

  result = lpMem;
  if ( lpMem )
    result = HeapFree(hHeap, 0, (LPVOID)lpMem);
  return result;
}
