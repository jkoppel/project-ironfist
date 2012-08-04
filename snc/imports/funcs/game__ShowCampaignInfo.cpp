{
  int v3; // [sp+Ch] [bp-48h]@1
  unsigned __int8 v4; // [sp+14h] [bp-40h]@34
  unsigned __int8 v5; // [sp+18h] [bp-3Ch]@31
  iconWidget *v6; // [sp+20h] [bp-34h]@29
  heroWindow *thisa; // [sp+24h] [bp-30h]@10
  signed __int16 v8; // [sp+28h] [bp-2Ch]@27
  int evt; // [sp+2Ch] [bp-28h]@42
  int v10; // [sp+30h] [bp-24h]@43
  int v11; // [sp+34h] [bp-20h]@43
  int v12; // [sp+44h] [bp-10h]@43
  int v13; // [sp+48h] [bp-Ch]@1
  int i; // [sp+4Ch] [bp-8h]@15
  widget *guiObj; // [sp+50h] [bp-4h]@15

  v3 = (int)this;
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  mouseManager::ReallyShowPointer(gpMouseManager);
  v13 = gbUseEvilInterface;
  gbUseEvilInterface = *(_BYTE *)(v3 + 2) == 1;
  bCampaignViewOnly = a2;
  iCurViewSide = *(_BYTE *)(v3 + 2);
  iCurViewMap = *(_BYTE *)(v3 + 4);
  if ( *(_BYTE *)(v3 + 4) != 4 || a2 )
  {
    iCampaignTrackType = *(_BYTE *)(v3 + 2) + 2 * *(_BYTE *)(v3 + 3);
  }
  else if ( *(_BYTE *)(v3 + 2) )
  {
    if ( *(_BYTE *)(v3 + 19) )
      iCampaignTrackType = 5;
    else
      iCampaignTrackType = 6;
  }
  else
  {
    iCampaignTrackType = 4;
  }
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    campWin = heroWindow::heroWindow(thisa, 0, 0, "campaign.bin");
  else
    campWin = 0;
  if ( !campWin )
    MemError();
  guiObj = 0;
  for ( i = 0; i < 13; ++i )
  {
    if ( (iCampaignTrackType >= 4 || i < 11)
      && (iCampaignTrackType != 4 || i != 12)
      && (iCampaignTrackType != 5 || i != 12)
      && (iCampaignTrackType != 6 || i != 11)
      && *(&trackXY[26 * iCurViewSide] + 2 * i) != -1 )
    {
      v8 = i;
      if ( i > 11 )
        v8 = 11;
      v6 = (iconWidget *)operator new(45);
      if ( v6 )
      {
        if ( i < 4 )
          v5 = *(_BYTE *)(v3 + 3);
        else
          v5 = *(_BYTE *)(v3 + 2);
        if ( i < 4 )
          v4 = *(_BYTE *)(v3 + 3);
        else
          v4 = *(_BYTE *)(v3 + 2);
        guiObj = (widget *)iconWidget::iconWidget(
                             v6,
                             *(&trackXY[26 * v4] + 2 * i) - 2,
                             *(&word_51D0F2[26 * v5] + 2 * i) - 2,
                             41,
                             41,
                             "campxtrg.icn",
                             10,
                             0,
                             v8 + 850,
                             16,
                             1);
      }
      else
      {
        guiObj = 0;
      }
      if ( !guiObj )
        MemError();
      heroWindow::AddWidget(campWin, guiObj, -1);
    }
  }
  evt = 512;
  if ( !a2 )
  {
    v10 = 6;
    v11 = 901;
    v12 = 6;
    heroWindow::BroadcastMessage(campWin, (Event *)&evt);
  }
  if ( gbLowMemory )
  {
    v10 = 6;
    v11 = 902;
    v12 = 6;
    heroWindow::BroadcastMessage(campWin, (Event *)&evt);
  }
  soundManager::SwitchAmbientMusic(gpSoundManager, (unsigned int)*(_BYTE *)(v3 + 2) < 1 ? 24 : 22);
  game::CampaignInfoUpdate((void *)v3, 0);
  heroWindowManager::DoDialog(gpWindowManager, campWin, (int (__fastcall *)(tag_message *))CampaignHandler, 0);
  operator delete(campWin);
  gbUseEvilInterface = v13;
  if ( gpWindowManager->buttonPressedCode == 901 )
  {
    NormalDialog("Are you sure you want to restart this scenario?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( gpWindowManager->buttonPressedCode == 30725 )
    {
      game::InitCampaignMap(v3);
      gpAdvManager->field_A2 = 0;
      giBottomViewOverride = 0;
      heroWindowManager::FadeScreen(gpWindowManager, 1, 8, gPalette);
      advManager::SetInitialMapOrigin(gpAdvManager);
      advManager::RedrawAdvScreen(gpAdvManager, 1, 0);
      heroWindowManager::FadeScreen(gpWindowManager, 0, 8, gPalette);
    }
  }
}