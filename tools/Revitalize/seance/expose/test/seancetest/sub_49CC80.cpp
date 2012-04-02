void __cdecl sub_49CC80()
{
  HGDIOBJ v0; // ST14_4@2

  if ( dword_519DB8 )
  {
    v0 = SelectObject(dword_519DB8, dword_519DBC);
    DeleteObject(v0);
    DeleteDC(dword_519DB8);
    dword_519DB8 = 0;
  }
  if ( logicalPaletteHandle )
  {
    DeleteObject(logicalPaletteHandle);
    logicalPaletteHandle = 0;
  }
}
