DWORD __cdecl _msize(LPCVOID lpMem)
{
  return HeapSize(hHeap, 0, lpMem);
}
