{
  LeaveCriticalSection((LPCRITICAL_SECTION)(36 * (a1 & 0x1F)
                                          + *(int *)((char *)__pioinfo + ((a1 & 0xFFFFFFE7) >> 3))
                                          + 12));
}