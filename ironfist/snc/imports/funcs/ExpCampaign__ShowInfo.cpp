{
  int v3; // [sp+Ch] [bp-44h]@1
  iconWidget *v4; // [sp+18h] [bp-38h]@14
  iconWidget *v5; // [sp+1Ch] [bp-34h]@8
  heroWindow *thisa; // [sp+20h] [bp-30h]@1
  widget *v7; // [sp+24h] [bp-2Ch]@15
  int evt; // [sp+28h] [bp-28h]@19
  int v9; // [sp+2Ch] [bp-24h]@20
  int v10; // [sp+30h] [bp-20h]@20
  int v11; // [sp+40h] [bp-10h]@20
  int v12; // [sp+44h] [bp-Ch]@1
  int i; // [sp+48h] [bp-8h]@6
  widget *guiObj; // [sp+4Ch] [bp-4h]@6

  v3 = this;
  *(_DWORD *)(this + 75) = a2;
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  mouseManager::ReallyShowPointer(gpMouseManager);
  v12 = gbUseEvilInterface;
  gbUseEvilInterface = 1;
  *(_DWORD *)(v3 + 67) = *(_DWORD *)(v3 + 4);
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    *(_DWORD *)(v3 + 71) = heroWindow::heroWindow(thisa, 0, 0, "x_camp.bin");
  else
    *(_DWORD *)(v3 + 71) = 0;
  if ( !*(_DWORD *)(v3 + 71) )
    MemError();
  guiObj = 0;
  for ( i = 0; *(_DWORD *)(v3 + 8) > i; ++i )
  {
    v5 = (iconWidget *)operator new(45);
    if ( v5 )
      guiObj = (widget *)iconWidget::iconWidget(
                           v5,
                           *(&dword_512930[16 * *(_DWORD *)v3] + 2 * i),
                           *(&dword_512934[16 * *(_DWORD *)v3] + 2 * i),
                           41,
                           41,
                           "x_cmpext.icn",
                           0,
                           0,
                           i + 850,
                           16,
                           1);
    else
      guiObj = 0;
    if ( !guiObj )
      MemError();
    heroWindow::AddWidget(*(heroWindow **)(v3 + 71), guiObj, -1);
  }
  v4 = (iconWidget *)operator new(45);
  if ( v4 )
    v7 = (widget *)iconWidget::iconWidget(v4, 24, 25, 376, 49, "x_cmpext.icn", *(_WORD *)v3 + 15, 0, -1, 16, 1);
  else
    v7 = 0;
  if ( !v7 )
    MemError();
  heroWindow::AddWidget(*(heroWindow **)(v3 + 71), v7, -1);
  evt = 512;
  if ( !a2 )
  {
    v9 = 6;
    v10 = 901;
    v11 = 6;
    heroWindow::BroadcastMessage(*(heroWindow **)(v3 + 71), (Event *)&evt);
  }
  if ( gbLowMemory )
  {
    v9 = 6;
    v10 = 902;
    v11 = 6;
    heroWindow::BroadcastMessage(*(heroWindow **)(v3 + 71), (Event *)&evt);
  }
  soundManager::SwitchAmbientMusic(gpSoundManager, 24);
  ExpCampaign::UpdateInfo((void *)v3, 0);
  heroWindowManager::DoDialog(
    gpWindowManager,
    *(heroWindow **)(v3 + 71),
    (int (__fastcall *)(tag_message *))ExpCampaign::MessageHandler,
    0);
  operator delete(*(void **)(v3 + 71));
  gbUseEvilInterface = v12;
  if ( gpWindowManager->buttonPressedCode == 901 )
  {
    NormalDialog("Are you sure you want to restart this scenario?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( gpWindowManager->buttonPressedCode == 30725 )
    {
      ExpCampaign::InitMap(v3);
      gpAdvManager->field_A2 = 0;
      giBottomViewOverride = 0;
      heroWindowManager::FadeScreen(gpWindowManager, 1, 8, gPalette);
      advManager::SetInitialMapOrigin(gpAdvManager);
      advManager::RedrawAdvScreen(gpAdvManager, 1, 0);
      heroWindowManager::FadeScreen(gpWindowManager, 0, 8, gPalette);
    }
  }
}