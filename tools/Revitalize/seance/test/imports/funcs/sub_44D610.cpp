{
  signed int result; // eax@10
  void *v2; // [sp+Ch] [bp-18h]@1
  int v3; // [sp+14h] [bp-10h]@8
  int v4; // [sp+1Ch] [bp-8h]@5
  signed int i; // [sp+20h] [bp-4h]@2

  v2 = this;
  if ( dword_50EAA0 )
  {
    for ( i = 0; i < 12; ++i )
    {
      if ( *(_DWORD *)((char *)v2 + 4 * i + 58) )
      {
        GUIWindow::removeComponent(
          *(GUIWindow **)((char *)v2 + 154),
          *(AbstractGUIComponent **)((char *)v2 + 4 * i + 58));
        v4 = *(_DWORD *)((char *)v2 + 4 * i + 58);
        if ( v4 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
      }
      if ( *(_DWORD *)((char *)v2 + 4 * i + 106) )
      {
        GUIWindow::removeComponent(
          *(GUIWindow **)((char *)v2 + 154),
          *(AbstractGUIComponent **)((char *)v2 + 4 * i + 106));
        v3 = *(_DWORD *)((char *)v2 + 4 * i + 106);
        if ( v3 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(v3);
      }
      *(_DWORD *)((char *)v2 + 4 * i + 58) = 0;
      result = i;
      *(_DWORD *)((char *)v2 + 4 * i + 106) = 0;
    }
    dword_50EAA4 = -1;
    dword_50EAA0 = 0;
    dword_524CB0 = -1;
  }
  return result;
}
