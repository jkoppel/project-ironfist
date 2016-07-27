{
  signed int v2; // [sp+18h] [bp-20h]@3
  int evt; // [sp+20h] [bp-18h]@1
  int img2Type; // [sp+24h] [bp-14h]@9
  int img1Arg; // [sp+28h] [bp-10h]@8
  int img2Arg; // [sp+2Ch] [bp-Ch]@9

  evt = this;
  dword_522FCC = 0;
  dword_522C3C = 0;
  if ( *(_DWORD *)this != 512 || *(_DWORD *)(this + 4) != 13 )
    goto LABEL_30;
  v2 = *(_DWORD *)(this + 8);
  if ( v2 > 30721 )
  {
    if ( v2 == 30723 )
    {
      display_message_window("Are you sure you want to dismiss this army?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
      {
        dword_522FCC = 1;
        *(_DWORD *)(evt + 8) = 10;
        *(_DWORD *)(evt + 4) = *(_DWORD *)(evt + 8);
        return 2;
      }
    }
    goto LABEL_30;
  }
  if ( v2 >= 30720 )
  {
    HeroWindowManager::instance->buttonPressedCode = *(_DWORD *)(this + 8);
    *(_DWORD *)(this + 8) = 10;
    *(_DWORD *)(this + 4) = *(_DWORD *)(this + 8);
    return 2;
  }
  if ( v2 != 500 )
  {
LABEL_30:
    if ( !dword_4F74A8 )
    {
      if ( getTickCount() > animationFrameSwitchTime )
      {
        *(_DWORD *)evt = 512;
        *(_DWORD *)(evt + 4) = 4;
        *(_DWORD *)(evt + 8) = 5;
        dword_522FC8 = (dword_522FC8 + 1) % byte_522D39;
        *(_DWORD *)(evt + 24) = byte_522DB5[dword_522FC8];
        GUIWindow::processMessage(*(GUIWindow **)&gameObject->_10[612], (Event *)evt);
        *(_DWORD *)(evt + 4) = 52;
        *(_DWORD *)(evt + 24) = *(_DWORD *)&xGlob + dword_522F78 * byte_522CA5[dword_522FC8];
        GUIWindow::processMessage(*(GUIWindow **)&gameObject->_10[612], (Event *)evt);
        GUIWindow::repaintComponentsInRange(*(GUIWindow **)&gameObject->_10[612], 1, 0, 32767);
        animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                                  + (double)dword_522CE2 * 1.35 / (double)byte_522D39);
      }
    }
    return 1;
  }
  img1Arg = 2 * dword_522C38 * (creature_table[stackWindowDisplayedCreature].cost - creature_table[dword_522FD8].cost);
  if ( stackWindowDisplayedCreature == CREATURE_BLACK_DRAGON )
  {
    img2Type = 3;
    img2Arg = 2 * dword_522C38;
  }
  else
  {
    if ( stackWindowDisplayedCreature == CREATURE_TITAN )
    {
      img2Type = 5;
      img2Arg = 2 * dword_522C38;
    }
    else
    {
      img2Type = -1;
      img2Arg = 0;
    }
  }
  if ( curPlayer->resources[6] < img1Arg || img2Type != -1 && curPlayer->resources[img2Type] < img2Arg )
  {
    display_message_window("You can't afford to upgrade your troops!", 1, -1, -1, 6, img1Arg, img2Type, img2Arg, -1, 0);
    goto LABEL_30;
  }
  display_message_window(
    "Your troops can be upgraded, but it will cost you dearly.  Do you wish to upgrade them?",
    2,
    -1,
    -1,
    6,
    img1Arg,
    img2Type,
    img2Arg,
    -1,
    0);
  if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
    goto LABEL_30;
  curPlayer->resources[6] -= img1Arg;
  if ( img2Type != -1 )
    curPlayer->resources[img2Type] -= img2Arg;
  dword_522C3C = 1;
  *(_DWORD *)(evt + 8) = 10;
  *(_DWORD *)(evt + 4) = *(_DWORD *)(evt + 8);
  return 2;
}
