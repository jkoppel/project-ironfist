{
  HDC hDC; // [sp+Ch] [bp-4h]@1

  hDC = GetDC(0);
  if ( hDC )
  {
    giMainVideoModeColorDepth = GetDeviceCaps(hDC, BITSPIXEL);
    giMainVideoModeWidth = GetDeviceCaps(hDC, HORZRES);
    giMainVideoModeHeight = GetDeviceCaps(hDC, VERTRES);
    ReleaseDC(0, hDC);
    if ( giMainVideoModeColorDepth < 8 )
      ShutDown("Heroes II requires 256 color mode or higher.\n\nTo change color mode, right click in an open area on the Windows 95 background, choose 'Properties', then the 'Settings' tab, then change the entry in the 'Color Palette Box'.");
  }
}