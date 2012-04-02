BOOL __cdecl sub_49CD80()
{
  BOOL result; // eax@2

  if ( (unsigned int)DDRAW_LIBRARY >= 0x20 )
    result = FreeLibrary(DDRAW_LIBRARY);
  return result;
}
