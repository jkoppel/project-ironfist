void __cdecl sub_49CD00()
{
  DDRAW_LIBRARY = LoadLibraryA("DDRAW.DLL");
  if ( (unsigned int)DDRAW_LIBRARY >= 0x20 )
    DirectDrawCreate = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))GetProcAddress(DDRAW_LIBRARY, "DirectDrawCreate");
  if ( DirectDrawCreate )
  {
    dword_5192EC = 1;
  }
  else
  {
    *(&mainWindows + 7 * gameOrEditorIdx + 5) = 0;
    sub_485B30(1);
  }
}
