{
  int result; // eax@2

  if ( _flush(a1) )
  {
    result = -1;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 13) & 0x40 )
      result = ((unsigned int)_commit(*(_DWORD *)(a1 + 16)) < 1) - 1;
    else
      result = 0;
  }
  return result;
}
