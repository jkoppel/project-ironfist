{
  hDDrawLibrary = LoadLibraryA("DDRAW.DLL");
  if ( (unsigned int)hDDrawLibrary >= 0x20 )
    lpDirectDrawCreate = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))GetProcAddress(hDDrawLibrary, "DirectDrawCreate");
  if ( lpDirectDrawCreate )
  {
    gbDDrawAttached = 1;
  }
  else
  {
    *(&bMenu + 7 * giCurExe + 5) = 0;
    SetMenuStatus(1);
  }
}