{
  signed int result; // eax@9
  void *v3; // [sp+Ch] [bp-18h]@1
  int v4; // [sp+14h] [bp-10h]@7
  int v5; // [sp+1Ch] [bp-8h]@4
  signed int i; // [sp+20h] [bp-4h]@1

  v3 = this;
  for ( i = 0; i < 25; ++i )
  {
    if ( *(_DWORD *)((char *)v3 + 4 * i + 62515) )
    {
      GUIWindow::removeComponent((GUIWindow *)a2, *(AbstractGUIComponent **)((char *)v3 + 4 * i + 62515));
      v5 = *(_DWORD *)((char *)v3 + 4 * i + 62515);
      if ( v5 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(v5);
    }
    if ( *(_DWORD *)((char *)v3 + 4 * i + 62615) )
    {
      GUIWindow::removeComponent((GUIWindow *)a2, *(AbstractGUIComponent **)((char *)v3 + 4 * i + 62615));
      v4 = *(_DWORD *)((char *)v3 + 4 * i + 62615);
      if ( v4 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
    }
    *(_DWORD *)((char *)v3 + 4 * i + 62515) = 0;
    result = i;
    *(_DWORD *)((char *)v3 + 4 * i + 62615) = 0;
  }
  return result;
}
