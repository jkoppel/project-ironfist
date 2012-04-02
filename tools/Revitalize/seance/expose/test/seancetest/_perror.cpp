int __cdecl perror(LPCVOID lpBuffer)
{
  int v1; // eax@6

  _lock_fhandle(2);
  if ( lpBuffer && *(_BYTE *)lpBuffer )
  {
    _write_lk(2, lpBuffer, strlen((const char *)lpBuffer));
    _write_lk(2, &unk_4EB030, 2u);
  }
  if ( *_errno() < 0 || *_errno() >= dword_5212B0 )
    v1 = dword_5212B0;
  else
    v1 = *_errno();
  _write_lk(2, *(&::lpBuffer + v1), strlen((const char *)*(&::lpBuffer + v1)));
  _write_lk(2, &unk_4EB02C, 1u);
  return _unlock_fhandle(2);
}
