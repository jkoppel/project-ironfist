{
  int v2; // esi@1
  HMODULE v3; // eax@2
  HMODULE v4; // ebx@2
  void *v6; // [sp+Ch] [bp+0h]@10

  v2 = 0;
  if ( !dword_5224D0 )
  {
    v3 = LoadLibraryA("user32.dll");
    v4 = v3;
    if ( !v3 )
      return 0;
    dword_5224D0 = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))GetProcAddress(v3, "MessageBoxA");
    if ( !dword_5224D0 )
      return 0;
    dword_5224D4 = GetProcAddress(v4, "GetActiveWindow");
    dword_5224D8 = (int (__cdecl *)(_DWORD))GetProcAddress(v4, "GetLastActivePopup");
  }
  if ( dword_5224D4 )
    v2 = dword_5224D4();
  if ( v2 )
  {
    if ( dword_5224D8 )
      v2 = dword_5224D8(v2);
  }
  return dword_5224D0(v2, v6, a1, a2);
}
