{
  char result; // al@2

  if ( *(_BYTE *)(*(_DWORD *)(this + 4) + this + 20) )
    result = 1;
  else
    result = 0;
  return result;
}
