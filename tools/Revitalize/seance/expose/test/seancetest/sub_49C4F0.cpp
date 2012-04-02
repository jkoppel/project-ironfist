signed int __cdecl sub_49C4F0()
{
  UINT v0; // ST1C_4@3
  signed int result; // eax@4
  HDC hDC; // [sp+Ch] [bp-8h]@1

  hDC = GetDC(windowHandle);
  if ( logicalPaletteHandle )
    SelectPalette(hDC, logicalPaletteHandle, 0);
  v0 = RealizePalette(hDC);
  ReleaseDC(windowHandle, hDC);
  if ( (signed int)v0 <= 0 )
  {
    result = 0;
  }
  else
  {
    InvalidateRect(windowHandle, 0, 1);
    result = 1;
  }
  return result;
}
