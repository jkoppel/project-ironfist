LPVOID __cdecl _heap_alloc(DWORD dwBytes)
{
  return HeapAlloc(hHeap, 0, dwBytes);
}
