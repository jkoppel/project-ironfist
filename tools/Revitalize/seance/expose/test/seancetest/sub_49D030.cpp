void __thiscall sub_49D030(void *this)
{
  void *v1; // [sp+Ch] [bp-4h]@1

  v1 = this;
  if ( !dword_4F3088 && (void *)*(&mainWindows + 7 * gameOrEditorIdx + 5) != this )
  {
    if ( graphicsLibraryToUse == 1 )
    {
      if ( !dword_5192EC )
        return;
      *(&mainWindows + 7 * gameOrEditorIdx + 5) = 1;
      if ( sub_49D160((void *)2) )
        sub_49C1E0(v1);
    }
    else
    {
      if ( this )
      {
        sub_49C1E0(this);
      }
      else
      {
        if ( dword_5192E8 )
          sub_49D160((void *)1);
      }
    }
    if ( v1 )
      sub_4D1480(0, 0, 1);
  }
}
