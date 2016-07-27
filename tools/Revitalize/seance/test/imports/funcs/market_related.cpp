{
  void *v1; // [sp+Ch] [bp-3Ch]@1
  int v2; // [sp+10h] [bp-38h]@46
  int v3; // [sp+14h] [bp-34h]@46
  char v4; // [sp+18h] [bp-30h]@46
  int v5; // [sp+1Ch] [bp-2Ch]@5
  int v6; // [sp+20h] [bp-28h]@5
  int j; // [sp+24h] [bp-24h]@19
  int evt; // [sp+28h] [bp-20h]@1
  int v9; // [sp+2Ch] [bp-1Ch]@11
  int v10; // [sp+30h] [bp-18h]@11
  int v11; // [sp+40h] [bp-8h]@11
  int i; // [sp+44h] [bp-4h]@11

  v1 = this;
  evt = 512;
  if ( dword_522C00 == -1 || dword_522C1C == -1 || dword_522C1C == dword_522C00 )
  {
    if ( dword_522C10 )
      sprintf(
        globBuf,
        "{%s}\n\nYou have received quite a bargain.  I expect to make no profit on the deal.  Can I interest you in any of my other wares?",
        &aMarketplace_0[("Trading Post" - "Marketplace") & ((dword_522C24 != 0) - 1)]);
    else
      sprintf(
        globBuf,
        "{%s}\n\nPlease inspect our fine wares.  If you feel like offering a trade, click on the items you wish to trade with and for.",
        &aMarketplace_1[("Trading Post" - "Marketplace") & ((dword_522C24 != 0) - 1)]);
  }
  else
  {
    if ( dword_522BFC )
    {
      v5 = 1;
      v6 = dword_522C18;
    }
    else
    {
      v5 = dword_522C18;
      v6 = 1;
    }
    sprintf(
      globBuf,
      "{%s}\n\nI can offer you %d %s of %s for %d %s of %s.",
      &aMarketplace[("Trading Post" - "Marketplace") & ((dword_522C24 != 0) - 1)],
      v6,
      &aUnits_0[("unit" - "units") & ((v6 > 1) - 1)],
      resourceNames[dword_522C1C],
      v5,
      &aUnits[("unit" - "units") & ((v5 > 1) - 1)],
      resourceNames[dword_522C00]);
  }
  evt = 512;
  v9 = 3;
  v10 = 1;
  v11 = (int)globBuf;
  GUIWindow::processMessage(dword_522C28, (Event *)&evt);
  for ( i = 20; i <= 31; ++i )
  {
    if ( dword_522C00 == -1 || dword_522C1C == -1 || dword_522C1C == dword_522C00 )
      v9 = 6;
    else
      v9 = 5;
    v10 = i;
    v11 = 6;
    GUIWindow::processMessage(dword_522C28, (Event *)&evt);
  }
  for ( j = 0; j < 2; ++j )
  {
    if ( dword_522C00 != -1 && dword_522C1C != -1 && dword_522C1C != dword_522C00 )
    {
      v9 = 4;
      if ( j )
        v10 = 21;
      else
        v10 = 20;
      if ( j )
        v11 = dword_522C1C;
      else
        v11 = dword_522C00;
      GUIWindow::processMessage(dword_522C28, (Event *)&evt);
      v9 = 3;
      v11 = (int)globBuf;
      if ( j )
      {
        v10 = 24;
        if ( dword_522BFC )
          sprintf(globBuf, "%d", dword_522C18 * dword_522C14);
        else
          sprintf(globBuf, "%d", dword_522C14);
      }
      else
      {
        v10 = 23;
        if ( dword_522BFC )
          sprintf(globBuf, "%d", dword_522C14);
        else
          sprintf(globBuf, "%d", dword_522C18 * dword_522C14);
      }
      GUIWindow::processMessage(dword_522C28, (Event *)&evt);
    }
    for ( i = 0; i < 7; ++i )
    {
      v9 = 3;
      v11 = (int)globBuf;
      if ( j )
      {
        v10 = i + 100;
        if ( dword_522C00 == -1 )
        {
          sprintf(globBuf, byte_4EE4A0);
        }
        else
        {
          if ( dword_522C00 == i )
          {
            sprintf(globBuf, "n/a");
          }
          else
          {
            sub_40F4C0(dword_522C00, i, (int)&v2, (int)&v3, (int)&v4);
            if ( v3 )
              sprintf(globBuf, "%d", v2);
            else
              sprintf(globBuf, "1/%d", v2);
          }
        }
      }
      else
      {
        v10 = i + 60;
        sprintf(globBuf, "%d", curPlayer->resources[i]);
      }
      GUIWindow::processMessage(dword_522C28, (Event *)&evt);
      if ( (j || dword_522C00 != i) && (j != 1 || dword_522C1C != i) )
        v9 = 6;
      else
        v9 = 5;
      if ( j )
        v10 = i + 90;
      else
        v10 = i + 50;
      v11 = 4;
      GUIWindow::processMessage(dword_522C28, (Event *)&evt);
    }
  }
  if ( dword_522C04 )
    globGuiObj->offsetX = 170 * dword_522C14 / dword_522C04 + 67;
  else
    globGuiObj->offsetX = 67;
  if ( v1 )
  {
    GUIWindow::repaint(dword_522C28, 0);
    HeroWindowManager::redrawRectangle(HeroWindowManager::instance, dword_522C08 + 32, dword_522C0C, 0x102u, 418);
  }
}
