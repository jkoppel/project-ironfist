{
  void *thisa; // [sp+Ch] [bp-3Ch]@1
  heroWindow *thisb; // [sp+18h] [bp-30h]@1
  signed int i; // [sp+1Ch] [bp-2Ch]@7
  int v4; // [sp+20h] [bp-28h]@1
  int v5; // [sp+40h] [bp-8h]@1
  int v6; // [sp+44h] [bp-4h]@1

  thisa = this;
  advManager::TrimLoopingSounds((advManager *)this, 4);
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  v5 = *(_DWORD *)&walkSpeed;
  v6 = *(_DWORD *)&evilInterfaceUsage;
  v4 = *(_DWORD *)((char *)thisa + 678);
  bPrefsChanged = 0;
  advManager::DemobilizeCurrHero((advManager *)thisa);
  thisb = (heroWindow *)operator new(68);
  if ( thisb )
    cPanel = heroWindow::heroWindow(thisb, 160, 33, "spanel.bin");
  else
    cPanel = 0;
  if ( !cPanel )
    MemError();
  SetWinText(cPanel, 2);
  UpdateSystemOptions((void *)1);
  heroWindowManager::DoDialog(gpWindowManager, cPanel, (int (__fastcall *)(tag_message *))SystemOptionsHandler, 0);
  operator delete(cPanel);
  if ( *(_DWORD *)&walkSpeed != v5 )
  {
    for ( i = 0; i < 9; ++i )
      resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 4 * i + 850));
    advManager::GetCursorSampleSet((advManager *)thisa, *(signed int *)&walkSpeed);
  }
  if ( bPrefsChanged )
    WritePrefs();
  if ( *(_DWORD *)&evilInterfaceUsage != v6 )
    advManager::CheckSetEvilInterface(thisa, 1, -1);
  if ( v4 )
    advManager::MobilizeCurrHero((advManager *)thisa, 0);
}