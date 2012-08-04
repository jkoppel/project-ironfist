{
  UINT v0; // ST1C_4@3
  signed int result; // eax@4
  HDC hDC; // [sp+Ch] [bp-8h]@1

  hDC = GetDC(hwndApp);
  if ( hpalApp )
    SelectPalette(hDC, hpalApp, 0);
  v0 = RealizePalette(hDC);
  ReleaseDC(hwndApp, hDC);
  if ( (signed int)v0 <= 0 )
  {
    result = 0;
  }
  else
  {
    InvalidateRect(hwndApp, 0, 1);
    result = 1;
  }
  return result;
}