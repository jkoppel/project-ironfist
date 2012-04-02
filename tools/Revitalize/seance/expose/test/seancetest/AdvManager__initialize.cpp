int __thiscall AdvManager::initialize(AdvManager *this, int idx)
{
  int v2; // ST48_4@100
  int v3; // ST44_4@100
  AdvManager *thisa; // [sp+Ch] [bp-20h]@1
  GUIIcon *v6; // [sp+10h] [bp-1Ch]@15
  GUIIcon *thisb; // [sp+14h] [bp-18h]@10
  GUIWindow *window; // [sp+18h] [bp-14h]@5
  signed int i; // [sp+24h] [bp-8h]@1
  signed int j; // [sp+24h] [bp-8h]@35
  signed int k; // [sp+24h] [bp-8h]@89
  signed int l; // [sp+24h] [bp-8h]@92
  int v13; // [sp+28h] [bp-4h]@98

  thisa = this;
  dword_50EAA0 = 0;
  this->field_37A = 0;
  dword_524C14 = 0;
  this->field_BA = 0;
  for ( i = 0; i < 12; ++i )
  {
    *(_DWORD *)&this->field_3A[4 * i] = 0;
    *(_DWORD *)&this->field_3A[4 * i + 48] = 0;
  }
  if ( !this->adventureScreen )
  {
    window = (GUIWindow *)operator new(0x44u);
    if ( window )
      thisa->adventureScreen = GUIWindow_constructorFromFile(window, 0, 0, "adv_wind.bin");
    else
      thisa->adventureScreen = 0;
    if ( !thisa->adventureScreen )
      fatalOutOfMemoryError();
    thisb = (GUIIcon *)operator new(0x2Du);
    if ( thisb )
      thisa->heroScrollbarKnob = GUIIcon_constructor(thisb, 540, 195, 8, 17, "scroll.icn", 4, 0, 26, 16, 1);
    else
      thisa->heroScrollbarKnob = 0;
    if ( !thisa->heroScrollbarKnob )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(thisa->adventureScreen, (AbstractGUIComponent *)thisa->heroScrollbarKnob, -1);
    v6 = (GUIIcon *)operator new(0x2Du);
    if ( v6 )
      thisa->castleScrollbarKnob = GUIIcon_constructor(v6, 612, 195, 8, 17, "scroll.icn", 4, 0, 27, 16, 1);
    else
      thisa->castleScrollbarKnob = 0;
    if ( !thisa->castleScrollbarKnob )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(thisa->adventureScreen, (AbstractGUIComponent *)thisa->castleScrollbarKnob, -1);
  }
  if ( *(&byte_524758 + curPlayerIdx) )
    MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  else
    MouseManager::loadMSE(mouseManager, "advmice.mse", 1, -999);
  if ( !thisa->field_9E )
  {
    thisa->field_9E = (int)operator new(2 * mapHeight * mapWidth);
    if ( !thisa->field_9E )
      fatalOutOfMemoryError();
  }
  thisa->field_A2 = 0;
  HeroWindowManager::addWindow(HeroWindowManager::instance, thisa->adventureScreen, 0, 1);
  if ( !thisa->groundTileset )
    thisa->groundTileset = ResourceManager::getTilesetByFilename(resourceManager, "ground32.til");
  if ( !thisa->clofTileset )
    thisa->clofTileset = ResourceManager::getTilesetByFilename(resourceManager, "clof32.til");
  if ( !thisa->stonTileset )
    thisa->stonTileset = ResourceManager::getTilesetByFilename(resourceManager, "ston.til");
  if ( !thisa->clopIcon )
    thisa->clopIcon = ResourceManager::getIconByFilename(resourceManager, "clop32.icn");
  for ( j = 0; j < 64; ++j )
  {
    if ( strlen((&off_4F0A50)[4 * j]) > 1 && !thisa->field_CE[j] && j != 21 )
    {
      if ( j != 38 )
        thisa->field_CE[j] = (int)ResourceManager::getIconByFilename(resourceManager, (&off_4F0A50)[4 * j]);
    }
  }
  if ( !thisa->heroIcons[0] )
    thisa->heroIcons[0] = ResourceManager::getIconByFilename(resourceManager, "kngt32.icn");
  if ( !thisa->heroIcons[1] )
    thisa->heroIcons[1] = ResourceManager::getIconByFilename(resourceManager, "barb32.icn");
  if ( !thisa->heroIcons[2] )
    thisa->heroIcons[2] = ResourceManager::getIconByFilename(resourceManager, "sorc32.icn");
  if ( !thisa->heroIcons[3] )
    thisa->heroIcons[3] = ResourceManager::getIconByFilename(resourceManager, "wrlk32.icn");
  if ( !thisa->heroIcons[4] )
    thisa->heroIcons[4] = ResourceManager::getIconByFilename(resourceManager, "wzrd32.icn");
  if ( !thisa->heroIcons[5] )
    thisa->heroIcons[5] = ResourceManager::getIconByFilename(resourceManager, "necr32.icn");
  if ( !thisa->boatIcon )
    thisa->boatIcon = ResourceManager::getIconByFilename(resourceManager, "boat32.icn");
  if ( !thisa->frothIcon )
    thisa->frothIcon = ResourceManager::getIconByFilename(resourceManager, "froth.icn");
  neverReadGlobal1 = 1;
  if ( !thisa->shadowIcon )
    thisa->shadowIcon = ResourceManager::getIconByFilename(resourceManager, "shadow32.icn");
  if ( !thisa->boatShadowIcon )
    thisa->boatShadowIcon = ResourceManager::getIconByFilename(resourceManager, "boatshad.icn");
  neverReadGlobal1 = 0;
  if ( !thisa->flagIcons1[0] )
    thisa->flagIcons1[0] = ResourceManager::getIconByFilename(resourceManager, "b-flag32.icn");
  if ( !thisa->flagIcons1[1] )
    thisa->flagIcons1[1] = ResourceManager::getIconByFilename(resourceManager, "g-flag32.icn");
  if ( !thisa->flagIcons1[2] )
    thisa->flagIcons1[2] = ResourceManager::getIconByFilename(resourceManager, "r-flag32.icn");
  if ( !thisa->flagIcons1[3] )
    thisa->flagIcons1[3] = ResourceManager::getIconByFilename(resourceManager, "y-flag32.icn");
  if ( !thisa->flagIcons1[4] )
    thisa->flagIcons1[4] = ResourceManager::getIconByFilename(resourceManager, "o-flag32.icn");
  if ( !thisa->flagIcons1[5] )
    thisa->flagIcons1[5] = ResourceManager::getIconByFilename(resourceManager, "p-flag32.icn");
  if ( !thisa->flagIcons2[0] )
    thisa->flagIcons2[0] = ResourceManager::getIconByFilename(resourceManager, "b-bflg32.icn");
  if ( !thisa->flagIcons2[1] )
    thisa->flagIcons2[1] = ResourceManager::getIconByFilename(resourceManager, "g-bflg32.icn");
  if ( !thisa->flagIcons2[2] )
    thisa->flagIcons2[2] = ResourceManager::getIconByFilename(resourceManager, "r-bflg32.icn");
  if ( !thisa->flagIcons2[3] )
    thisa->flagIcons2[3] = ResourceManager::getIconByFilename(resourceManager, "y-bflg32.icn");
  if ( !thisa->flagIcons2[4] )
    thisa->flagIcons2[4] = ResourceManager::getIconByFilename(resourceManager, "o-bflg32.icn");
  if ( !thisa->flagIcons2[5] )
    thisa->flagIcons2[5] = ResourceManager::getIconByFilename(resourceManager, "p-bflg32.icn");
  neverReadGlobal1 = 1;
  if ( !thisa->radarIcon )
    thisa->radarIcon = ResourceManager::getIconByFilename(resourceManager, "radar.icn");
  neverReadGlobal1 = 0;
  for ( k = 0; k < 28; ++k )
    thisa->field_2E2[k] = 0;
  for ( l = 0; l < 4; ++l )
  {
    thisa->field_2C2[l][0] = -1;
    thisa->field_2C2[l][1] = 127;
    thisa->field_2BE = 0;
  }
  sub_443DA0(thisa, *(signed int *)&walkSpeed);
  if ( *(&byte_524758 + curPlayerIdx) )
  {
    sub_485C90(1);
  }
  else
  {
    sub_423DE0();
    sub_485C90(0);
  }
  animationFrameSwitchTime = getTickCount() + 120;
  v13 = *(_DWORD *)&soundVolume;
  if ( *(_DWORD *)&soundVolume )
    *(_DWORD *)&soundVolume = 10;
  sub_4557F0(thisa);
  dword_524C14 = *(&byte_524758 + curPlayerIdx);
  v2 = curPlayerIdx;
  v3 = dword_524C14;
  curPlayerIdx = dword_523EDC;
  curPlayer = &gameObject->players[dword_523EDC];
  dword_524C14 = 1;
  sub_4506B0(thisa, 1, 0);
  curPlayerIdx = v2;
  dword_524C14 = v3;
  curPlayer = &gameObject->players[v2];
  if ( !*(&byte_524758 + v2) )
    sub_429420();
  changeMenu(adventureMenu);
  sub_455380(thisa);
  sub_4C7C60(HeroWindowManager::instance, 0, 8, dword_524234);
  dword_52405C = 0;
  *(_DWORD *)&soundVolume = v13;
  sub_403AA0(soundManager);
  thisa->type = 1024;
  thisa->idx = idx;
  thisa->ready = 1;
  strcpy(thisa->name, "advManager");
  return 0;
}
