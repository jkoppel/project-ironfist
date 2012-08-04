{
  BOOL result; // eax@1

  result = lpMem;
  if ( lpMem )
    result = HeapFree(_crtheap, 0, (LPVOID)lpMem);
  return result;
}