{
  char result; // al@2

  if ( *(_BYTE *)(*(_DWORD *)(this + 8) + this + 19) )
    result = 1;
  else
    result = *(_DWORD *)this == 3 && *(_BYTE *)(this + 22);
  return result;
}
