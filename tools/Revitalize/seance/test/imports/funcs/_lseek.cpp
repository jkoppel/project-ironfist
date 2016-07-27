{
  int v3; // edi@3
  signed int result; // eax@3

  if ( uNumber > a1 && *(_BYTE *)(*(int *)((char *)&dword_538E20 + ((a1 & 0xFFFFFFE7) >> 3)) + 36 * (a1 & 0x1F) + 4) & 1 )
  {
    _lock_fhandle(a1);
    v3 = _lseek_lk(a1, lDistanceToMove, dwMoveMethod);
    _unlock_fhandle(a1);
    result = v3;
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    result = -1;
  }
  return result;
}
