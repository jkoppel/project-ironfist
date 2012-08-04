{
  int result; // eax@6
  int v9; // [sp+Ch] [bp-8h]@1
  int v10; // [sp+10h] [bp-4h]@1

  v9 = a2;
  v10 = a1;
  if ( a2 )
  {
    if ( *(_DWORD *)(a1 + 104) )
    {
      if ( !a5 )
      {
        memcpy(gPalette->contents, (const void *)(a1 + 108), 0x300u);
        ConvertSmackerPalette(gPalette->contents);
        if ( a4 )
          UpdatePalette(gPalette->contents);
      }
    }
  }
  result = SmackDoFrame(v10);
  if ( v9 )
  {
    while ( 1 )
    {
      result = SmackToBufferRect(v10, 1);
      if ( !result )
        break;
      if ( bSmackNum == 35 )
      {
        if ( *(_DWORD *)gbCampaignSideChoice == 1 )
        {
          icon::DrawToBuffer(brotherIcon, 0, 0, 0, 0);
          icon::DrawToBuffer(brotherIcon, 0, 0, 3, 0);
        }
        else
        {
          icon::DrawToBuffer(brotherIcon, 0, 0, 1, 0);
          icon::DrawToBuffer(brotherIcon, 0, 0, 2, 0);
        }
      }
      if ( bSmackNum == 67 && xLastChoice != -1 )
        icon::DrawToBuffer(backImage, 0, 0, 1, 0);
      if ( bSmackNum != 2
        || *(_DWORD *)(v10 + 884) < 0x24u
        || (font::DrawBoundedString(smallFont, congratsText, 409, 98, 134, 217, 4, 5), *(_DWORD *)(v10 + 884) != 36) )
        BlitBitmapToScreen(
          gpWindowManager->screenBuffer,
          *(_DWORD *)(v10 + 896),
          *(_DWORD *)(v10 + 900),
          *(_DWORD *)(v10 + 904),
          *(_DWORD *)(v10 + 908),
          *(_DWORD *)(v10 + 896),
          *(_DWORD *)(v10 + 900));
      else
        BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 0x27Fu, 479, 0, 0);
    }
  }
  if ( a3 )
    result = SmackNextFrame(v10);
  return result;
}