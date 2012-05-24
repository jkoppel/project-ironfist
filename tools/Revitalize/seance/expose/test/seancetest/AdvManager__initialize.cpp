// Bringing up Hero Info or Kingdom Overview and switching back does not call this to be called. Towns and battles do, though.
int __thiscall AdvManager::initialize(AdvManager *this, int idx)
{
  int v2; // ST48_4@100
  int v3; // ST44_4@100
  GUIIcon *v6; // [sp+10h] [bp-1Ch]@15
  GUIIcon *thisb; // [sp+14h] [bp-18h]@10
  GUIWindow *window; // [sp+18h] [bp-14h]@5
  signed int i; // [sp+24h] [bp-8h]@1
  signed int j; // [sp+24h] [bp-8h]@35
  signed int k; // [sp+24h] [bp-8h]@89
  signed int l; // [sp+24h] [bp-8h]@92
  int v13; // [sp+28h] [bp-4h]@98

  dword_50EAA0 = 0;
  this->field_37A = 0;
  dword_524C14 = 0;
  this->field_BA = 0;
  for ( i = 0; i < 12; ++i )
  {
    this->someComponents[0][i] = 0;
    this->someComponents[1][i] = 0;
  }
  if ( !this->adventureScreen )
  {
    window = (GUIWindow *)operator new(68);
    if ( window )
      this->adventureScreen = GUIWindow_constructorFromFile(window, 0, 0, "adv_wind.bin");
    else
      this->adventureScreen = 0;
    if ( !this->adventureScreen )
      fatalOutOfMemoryError();
    thisb = (GUIIcon *)operator new(45);
    if ( thisb )
      this->heroScrollbarKnob = GUIIcon_constructor(thisb, 540, 195, 8, 17, "scroll.icn", 4, 0, 26, 16, 1);
    else
      this->heroScrollbarKnob = 0;
    if ( !this->heroScrollbarKnob )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(this->adventureScreen, (AbstractGUIComponent *)this->heroScrollbarKnob, -1);
    v6 = (GUIIcon *)operator new(45);
    if ( v6 )
      this->castleScrollbarKnob = GUIIcon_constructor(v6, 612, 195, 8, 17, "scroll.icn", 4, 0, 27, 16, 1);
    else
      this->castleScrollbarKnob = 0;
    if ( !this->castleScrollbarKnob )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(this->adventureScreen, (AbstractGUIComponent *)this->castleScrollbarKnob, -1);
  }
  if ( *(&byte_524758 + curPlayerIdx) )
    MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  else
    MouseManager::loadMSE(mouseManager, "advmice.mse", 1, -999);
  if ( !this->sizeOfSomethingMapRelated )
  {
    this->sizeOfSomethingMapRelated = (int)operator new(2 * mapHeight * mapWidth);
    if ( !this->sizeOfSomethingMapRelated )
      fatalOutOfMemoryError();
  }
  this->field_A2 = 0;
  HeroWindowManager::addWindow(HeroWindowManager::instance, this->adventureScreen, 0, 1);
  if ( !this->groundTileset )
    this->groundTileset = ResourceManager::getTilesetByFilename(resourceManager, "ground32.til");
  if ( !this->clofTileset )
    this->clofTileset = ResourceManager::getTilesetByFilename(resourceManager, "clof32.til");
  if ( !this->stonTileset )
    this->stonTileset = ResourceManager::getTilesetByFilename(resourceManager, "ston.til");
  if ( !this->clopIcon )
    this->clopIcon = ResourceManager::getIconByFilename(resourceManager, "clop32.icn");
  for ( j = 0; j < 64; ++j )
  {
    if ( (unsigned int)strlen((int)(&off_4F0A50)[4 * j]) > 1 && !this->field_CE[j] && j != 21 )
    {
      if ( j != 38 )
        this->field_CE[j] = (int)ResourceManager::getIconByFilename(resourceManager, (&off_4F0A50)[4 * j]);
    }
  }
  if ( !this->heroIcons[0] )
    this->heroIcons[0] = ResourceManager::getIconByFilename(resourceManager, "kngt32.icn");
  if ( !this->heroIcons[1] )
    this->heroIcons[1] = ResourceManager::getIconByFilename(resourceManager, "barb32.icn");
  if ( !this->heroIcons[2] )
    this->heroIcons[2] = ResourceManager::getIconByFilename(resourceManager, "sorc32.icn");
  if ( !this->heroIcons[3] )
    this->heroIcons[3] = ResourceManager::getIconByFilename(resourceManager, "wrlk32.icn");
  if ( !this->heroIcons[4] )
    this->heroIcons[4] = ResourceManager::getIconByFilename(resourceManager, "wzrd32.icn");
  if ( !this->heroIcons[5] )
    this->heroIcons[5] = ResourceManager::getIconByFilename(resourceManager, "necr32.icn");
  if ( !this->boatIcon )
    this->boatIcon = ResourceManager::getIconByFilename(resourceManager, "boat32.icn");
  if ( !this->frothIcon )
    this->frothIcon = ResourceManager::getIconByFilename(resourceManager, "froth.icn");
  neverReadGlobal1 = 1;
  if ( !this->shadowIcon )
    this->shadowIcon = ResourceManager::getIconByFilename(resourceManager, "shadow32.icn");
  if ( !this->boatShadowIcon )
    this->boatShadowIcon = ResourceManager::getIconByFilename(resourceManager, "boatshad.icn");
  neverReadGlobal1 = 0;
  if ( !this->flagIcons1[0] )
    this->flagIcons1[0] = ResourceManager::getIconByFilename(resourceManager, "b-flag32.icn");
  if ( !this->flagIcons1[1] )
    this->flagIcons1[1] = ResourceManager::getIconByFilename(resourceManager, "g-flag32.icn");
  if ( !this->flagIcons1[2] )
    this->flagIcons1[2] = ResourceManager::getIconByFilename(resourceManager, "r-flag32.icn");
  if ( !this->flagIcons1[3] )
    this->flagIcons1[3] = ResourceManager::getIconByFilename(resourceManager, "y-flag32.icn");
  if ( !this->flagIcons1[4] )
    this->flagIcons1[4] = ResourceManager::getIconByFilename(resourceManager, "o-flag32.icn");
  if ( !this->flagIcons1[5] )
    this->flagIcons1[5] = ResourceManager::getIconByFilename(resourceManager, "p-flag32.icn");
  if ( !this->flagIcons2[0] )
    this->flagIcons2[0] = ResourceManager::getIconByFilename(resourceManager, "b-bflg32.icn");
  if ( !this->flagIcons2[1] )
    this->flagIcons2[1] = ResourceManager::getIconByFilename(resourceManager, "g-bflg32.icn");
  if ( !this->flagIcons2[2] )
    this->flagIcons2[2] = ResourceManager::getIconByFilename(resourceManager, "r-bflg32.icn");
  if ( !this->flagIcons2[3] )
    this->flagIcons2[3] = ResourceManager::getIconByFilename(resourceManager, "y-bflg32.icn");
  if ( !this->flagIcons2[4] )
    this->flagIcons2[4] = ResourceManager::getIconByFilename(resourceManager, "o-bflg32.icn");
  if ( !this->flagIcons2[5] )
    this->flagIcons2[5] = ResourceManager::getIconByFilename(resourceManager, "p-bflg32.icn");
  neverReadGlobal1 = 1;
  if ( !this->radarIcon )
    this->radarIcon = ResourceManager::getIconByFilename(resourceManager, "radar.icn");
  neverReadGlobal1 = 0;
  for ( k = 0; k < 28; ++k )
    this->loopSamples[k] = 0;
  for ( l = 0; l < 4; ++l )
  {
    this->field_2C2[l][0] = -1;
    this->field_2C2[l][1] = 127;
    this->field_2BE = 0;
  }
  AdvManager::loadWalkSounds(this, *(signed int *)&walkSpeed);
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
  AdvManager::couldBeCenterOnHero(this);
  dword_524C14 = *(&byte_524758 + curPlayerIdx);
  v2 = curPlayerIdx;
  v3 = dword_524C14;
  curPlayerIdx = dword_523EDC;
  curPlayer = &gameObject->players[dword_523EDC];
  dword_524C14 = 1;
  sub_4506B0(this, 1, 0);
  curPlayerIdx = v2;
  dword_524C14 = v3;
  curPlayer = &gameObject->players[v2];
  if ( !*(&byte_524758 + v2) )
    sub_429420();
  changeMenu(adventureMenu);
  sub_455380(this);
  sub_4C7C60(HeroWindowManager::instance, 0, 8, dword_524234);
  dword_52405C = 0;
  *(_DWORD *)&soundVolume = v13;
  sub_403AA0(soundManager);
  this->type = 1024;
  this->idx = idx;
  this->ready = 1;
  strcpy((int)this->name);
  return 0;
}
