{
  __int32 v1; // edi@3
  void *v2; // eax@4
  unsigned __int32 v3; // edi@5
  signed int result; // eax@8

  if ( (a1 == 1 || a1 == 2) && (v1 = _get_osfhandle(2), v1 == _get_osfhandle(1))
    || (v2 = (void *)_get_osfhandle(a1), CloseHandle(v2)) )
    v3 = 0;
  else
    v3 = GetLastError();
  _free_osfhnd(a1);
  if ( v3 )
  {
    _dosmaperr(v3);
    result = -1;
  }
  else
  {
    *(_BYTE *)(*(int *)((char *)&dword_538E20 + ((a1 & 0xFFFFFFE7) >> 3)) + 36 * (a1 & 0x1F) + 4) = 0;
    result = 0;
  }
  return result;
}
