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
        memcpy(dword_524234->contents, (const void *)(a1 + 108), 0x300u);
        sub_458DD0(dword_524234->contents);
        if ( a4 )
          sub_49CFB0(dword_524234->contents);
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
      if ( byte_524EC0 == 35 )
      {
        if ( dword_5247B8 == 1 )
        {
          Icon::drawToScreen(dword_50FEE0, 0, 0, 0, 0);
          Icon::drawToScreen(dword_50FEE0, 0, 0, 3, 0);
        }
        else
        {
          Icon::drawToScreen(dword_50FEE0, 0, 0, 1, 0);
          Icon::drawToScreen(dword_50FEE0, 0, 0, 2, 0);
        }
      }
      if ( byte_524EC0 == 67 && dword_5304C8 != -1 )
        Icon::drawToScreen(dword_50FF08, 0, 0, 1, 0);
      if ( byte_524EC0 != 2
        || *(_DWORD *)(v10 + 884) < 0x24u
        || (Font::drawString(smallFont, dword_4F55F0, 409, 98, 134, 217, 4, 5), *(_DWORD *)(v10 + 884) != 36) )
        renderBitmapToScreenWithWinG(
          HeroWindowManager::instance->screenBuffer,
          *(_DWORD *)(v10 + 896),
          *(_DWORD *)(v10 + 900),
          *(_DWORD *)(v10 + 904),
          *(_DWORD *)(v10 + 908),
          *(_DWORD *)(v10 + 896),
          *(_DWORD *)(v10 + 900));
      else
        renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 0x27Fu, 479, 0, 0);
    }
  }
  if ( a3 )
    result = SmackNextFrame(v10);
  return result;
}
