void __cdecl _unlock_fhandle(int a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)(36 * (a1 & 0x1F)
                                          + *(int *)((char *)dword_538E20 + ((a1 & 0xFFFFFFE7) >> 3))
                                          + 12));
}
