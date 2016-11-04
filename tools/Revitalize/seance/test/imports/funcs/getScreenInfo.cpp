{
  HDC hDC; // [sp+Ch] [bp-4h]@1

  hDC = GetDC(0);
  if ( hDC )
  {
    bitspixel = GetDeviceCaps(hDC, BITSPIXEL);
    horizontalResolution = GetDeviceCaps(hDC, HORZRES);
    verticalResolution = GetDeviceCaps(hDC, VERTRES);
    ReleaseDC(0, hDC);
    if ( bitspixel < 8 )
      terminate("Heroes II requires 256 color mode or higher.\n\nTo change color mode, right click in an open area on the Windows 95 background, choose 'Properties', then the 'Settings' tab, then change the entry in the 'Color Palette Box'.");
  }
}
