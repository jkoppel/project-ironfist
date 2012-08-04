{
  void *result; // eax@3

  __onexitbegin = malloc(0x80u);
  if ( !__onexitbegin )
    _amsg_exit(24);
  *(_DWORD *)__onexitbegin = 0;
  result = __onexitbegin;
  __onexitend = (int)__onexitbegin;
  return result;
}