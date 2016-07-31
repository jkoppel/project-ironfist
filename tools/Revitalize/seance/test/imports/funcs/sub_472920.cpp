{
  char *result; // eax@2

  if ( *(_DWORD *)(this + 4) >= 4 )
    result = off_51A8E0[*(_DWORD *)(this + 4)];
  else
    result = off_51A8F0[0];
  return result;
}
