{
  int v1; // eax@6

  _lock_fhandle(2);
  if ( lpBuffer && *(_BYTE *)lpBuffer )
  {
    _write_lk(2, lpBuffer, strlen((const char *)lpBuffer));
    _write_lk(2, &_string_, 2u);
  }
  if ( *_errno() < 0 || *_errno() >= _sys_nerr )
    v1 = _sys_nerr;
  else
    v1 = *_errno();
  _write_lk(2, *(&::lpBuffer + v1), strlen((const char *)*(&::lpBuffer + v1)));
  _write_lk(2, &_string_, 1u);
  _unlock_fhandle(2);
}