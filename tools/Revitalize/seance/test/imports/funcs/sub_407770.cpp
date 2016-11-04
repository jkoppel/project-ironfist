{
  signed int result; // eax@9
  int v3; // [sp+Ch] [bp-34h]@12
  int v4; // [sp+18h] [bp-28h]@1
  int evt; // [sp+1Ch] [bp-24h]@6
  int v6; // [sp+20h] [bp-20h]@6
  int v7; // [sp+24h] [bp-1Ch]@6
  int v8; // [sp+34h] [bp-Ch]@6
  int i; // [sp+38h] [bp-8h]@4
  int v10; // [sp+3Ch] [bp-4h]@1

  v4 = (int)this;
  v10 = 0;
  if ( dword_4F74A4 )
    dword_4F74A4 = 0;
  if ( getTickCount() > animationFrameSwitchTime )
  {
    animationFrameSwitchTime = getTickCount() + 120;
    for ( i = 0; i < 10; ++i )
    {
      *(_WORD *)(v4 + 2 * i + 54) = (*(_WORD *)(v4 + 2 * i + 54) + 1) % 18;
      evt = 512;
      v7 = i + 201;
      v6 = 4;
      v8 = 9 * *(_WORD *)(v4 + 2 * i + 74) + (unsigned __int8)byte_50F100[*(_WORD *)(v4 + 2 * i + 54)] + 1;
      GUIWindow::processMessage(*(GUIWindow **)(v4 + 95), (Event *)&evt);
    }
    GUIWindow::repaintComponentsInRange(*(GUIWindow **)(v4 + 95), 0, 200, 230);
    HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 512, 51, 0x4Cu, 406);
  }
  if ( *(_BYTE *)(a2 + 13) & 2 )
  {
    result = 1;
  }
  else
  {
    if ( *(_DWORD *)a2 == 512 && *(_DWORD *)(a2 + 4) == 13 )
    {
      v3 = *(_DWORD *)(a2 + 8);
      if ( v3 == 100 || v3 == 147 )
      {
        *(_BYTE *)(v4 + 94) = 1 - *(_BYTE *)(v4 + 94);
        sub_4079A0(v4);
        GUIWindow::repaint(*(GUIWindow **)(v4 + 95), 1);
      }
      else
      {
        if ( v3 == 30720 )
        {
          *(_DWORD *)(a2 + 24) = *(_DWORD *)(a2 + 8);
          v10 = 1;
        }
      }
    }
    if ( v10 == 1 )
    {
      *(_DWORD *)a2 = 16384;
      *(_DWORD *)(a2 + 4) = 4;
      result = 2;
    }
    else
    {
      result = 1;
    }
  }
  return result;
}
