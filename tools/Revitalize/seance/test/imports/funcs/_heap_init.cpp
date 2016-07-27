{
  HANDLE result; // eax@1

  result = HeapCreate(0, 0x1000u, 0);
  hHeap = result;
  return result;
}
