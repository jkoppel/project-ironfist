signed int __cdecl _read(UINT fd, void *buf, DWORD nbytes)
{
  signed int v3; // edi@3
  signed int result; // eax@3

  if ( fd < uNumber
    && *(_BYTE *)(*(int *)((char *)&dword_538E20 + ((signed int)(fd & 0xFFFFFFE7) >> 3)) + 36 * (fd & 0x1F) + 4) & 1 )
  {
    _lock_fhandle(fd);
    v3 = _read_lk(fd, buf, nbytes);
    _unlock_fhandle(fd);
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
