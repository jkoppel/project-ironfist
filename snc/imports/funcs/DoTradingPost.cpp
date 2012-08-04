{
  iconWidget *v3; // [sp+18h] [bp-24h]@6
  heroWindow *thisa; // [sp+1Ch] [bp-20h]@1

  bIsMarketPlace = (int)this;
  fTradingPostEfficiency = a2;
  bTradeMade = 0;
  tpX = 159;
  tpY = 23;
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    tpWindow = heroWindow::heroWindow(thisa, tpX, tpY, "tradpost.bin");
  else
    tpWindow = 0;
  if ( !tpWindow )
    MemError();
  leftResource = -1;
  rightResource = -1;
  qtyToTrade = 0;
  v3 = (iconWidget *)operator new(45);
  if ( v3 )
    tradeKnob = (widget *)iconWidget::iconWidget(v3, 67, 204, 17, 8, "tradpost.icn", 2, 0, 31, 16, 1);
  else
    tradeKnob = 0;
  if ( !tradeKnob )
    MemError();
  heroWindow::AddWidget(tpWindow, tradeKnob, -1);
  UpdateTradingPost(0);
  heroWindowManager::DoDialog(gpWindowManager, tpWindow, (int (__fastcall *)(tag_message *))TradingPostHandler, 0);
  return operator delete(tpWindow);
}