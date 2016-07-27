{
  char *result; // eax@2

  if ( *(_DWORD *)(this + 4) >= 4 )
    result = (&off_51A8C8)[4 * *(_DWORD *)(this + 4)];
  else
    result = off_51A8D8[0];
  return result;
}
