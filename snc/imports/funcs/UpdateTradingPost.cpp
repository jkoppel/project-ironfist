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
  if ( leftResource == -1 || rightResource == -1 || rightResource == leftResource )
  {
    if ( bTradeMade )
      sprintf(
        gText,
        "{%s}\n\nYou have received quite a bargain.  I expect to make no profit on the deal.  Can I interest you in any of my other wares?",
        &aMarketplace_0[("Trading Post" - "Marketplace") & ((bIsMarketPlace != 0) - 1)]);
    else
      sprintf(
        gText,
        "{%s}\n\nPlease inspect our fine wares.  If you feel like offering a trade, click on the items you wish to trade with and for.",
        &aMarketplace_1[("Trading Post" - "Marketplace") & ((bIsMarketPlace != 0) - 1)]);
  }
  else
  {
    if ( bLeftDenominated )
    {
      v5 = 1;
      v6 = iTradeRatio;
    }
    else
    {
      v5 = iTradeRatio;
      v6 = 1;
    }
    sprintf(
      gText,
      "{%s}\n\nI can offer you %d %s of %s for %d %s of %s.",
      &aMarketplace[("Trading Post" - "Marketplace") & ((bIsMarketPlace != 0) - 1)],
      v6,
      &aUnits_0[("unit" - "units") & ((v6 > 1) - 1)],
      gResourceNames[rightResource],
      v5,
      &aUnits[("unit" - "units") & ((v5 > 1) - 1)],
      gResourceNames[leftResource]);
  }
  evt = 512;
  v9 = 3;
  v10 = 1;
  v11 = (int)gText;
  heroWindow::BroadcastMessage(tpWindow, (Event *)&evt);
  for ( i = 20; i <= 31; ++i )
  {
    if ( leftResource == -1 || rightResource == -1 || rightResource == leftResource )
      v9 = 6;
    else
      v9 = 5;
    v10 = i;
    v11 = 6;
    heroWindow::BroadcastMessage(tpWindow, (Event *)&evt);
  }
  for ( j = 0; j < 2; ++j )
  {
    if ( leftResource != -1 && rightResource != -1 && rightResource != leftResource )
    {
      v9 = 4;
      if ( j )
        v10 = 21;
      else
        v10 = 20;
      if ( j )
        v11 = rightResource;
      else
        v11 = leftResource;
      heroWindow::BroadcastMessage(tpWindow, (Event *)&evt);
      v9 = 3;
      v11 = (int)gText;
      if ( j )
      {
        v10 = 24;
        if ( bLeftDenominated )
          sprintf(gText, "%d", iTradeRatio * qtyToTrade);
        else
          sprintf(gText, "%d", qtyToTrade);
      }
      else
      {
        v10 = 23;
        if ( bLeftDenominated )
          sprintf(gText, "%d", qtyToTrade);
        else
          sprintf(gText, "%d", iTradeRatio * qtyToTrade);
      }
      heroWindow::BroadcastMessage(tpWindow, (Event *)&evt);
    }
    for ( i = 0; i < 7; ++i )
    {
      v9 = 3;
      v11 = (int)gText;
      if ( j )
      {
        v10 = i + 100;
        if ( leftResource == -1 )
        {
          sprintf(gText, byte_4EE4A0);
        }
        else if ( leftResource == i )
        {
          sprintf(gText, "n/a");
        }
        else
        {
          ComputeTradeRatios(leftResource, i, (int)&v2, (int)&v3, (int)&v4);
          if ( v3 )
            sprintf(gText, "%d", v2);
          else
            sprintf(gText, "1/%d", v2);
        }
      }
      else
      {
        v10 = i + 60;
        sprintf(gText, "%d", gpCurPlayer->resources[i]);
      }
      heroWindow::BroadcastMessage(tpWindow, (Event *)&evt);
      if ( (j || leftResource != i) && (j != 1 || rightResource != i) )
        v9 = 6;
      else
        v9 = 5;
      if ( j )
        v10 = i + 90;
      else
        v10 = i + 50;
      v11 = 4;
      heroWindow::BroadcastMessage(tpWindow, (Event *)&evt);
    }
  }
  if ( iMaxUnitsToTrade )
    tradeKnob->offsetX = (unsigned int)(170 * qtyToTrade / iMaxUnitsToTrade) + 67;
  else
    tradeKnob->offsetX = 67;
  if ( v1 )
  {
    heroWindow::DrawWindow(tpWindow, 0);
    heroWindowManager::UpdateScreenRegion(gpWindowManager, tpX + 32, tpY, 0x102u, 418);
  }
}