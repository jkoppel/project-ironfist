{
  BOOL result; // eax@2

  if ( (unsigned int)hDDrawLibrary >= 0x20 )
    result = FreeLibrary(hDDrawLibrary);
  return result;
}