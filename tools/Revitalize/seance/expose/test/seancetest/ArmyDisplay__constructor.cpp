ArmyDisplay *__thiscall ArmyDisplay::constructor(ArmyDisplay *this, int x, int y, int a4, int portraitFileID, int portraitIconIdx, ArmyInfo *army, __int16 fieldIDStart, int redraw, int a10)
{
  BackgroundGUI *v12; // [sp+10h] [bp-14h]@17
  BackgroundGUI *v13; // [sp+14h] [bp-10h]@10
  GUIWindow *wind; // [sp+18h] [bp-Ch]@4
  signed int j; // [sp+1Ch] [bp-8h]@15
  signed int i; // [sp+20h] [bp-4h]@1

  this->drawBorder = -1;
  this->x = x;
  this->y = y;
  this->field_24 = a4;
  this->portraitIcon = ResourceManager::getIconByFileID(resourceManager, portraitFileID);
  this->portraitIconIdx = portraitIconIdx;
  this->army = army;
  this->stripIcon = ResourceManager::getIconByFilename(resourceManager, "strip.icn");
  for ( i = 0; i < 5; ++i )
  {
    this->creaturePortraits[i] = 0;
    this->creatureTypes[i] = -1;
  }
  this->portraitFlagIcon = ResourceManager::getIconByFilename(resourceManager, "portcflg.icn");
  this->field_7C = a10;
  wind = (GUIWindow *)operator new(0x44u);
  if ( wind )
    this->window = GUIWindow_constructor(wind, this->x, this->y, 552, 105, 8);
  else
    this->window = 0;
  if ( !this->window )
    fatalOutOfMemoryError();
  if ( this->army )
  {
    v13 = (BackgroundGUI *)operator new(0x2Au);
    if ( v13 )
      this->field_2C[0] = BackgroundGUI_constructor(v13, 5, 6, 101, 93, fieldIDStart, 1, 0, 0);
    else
      this->field_2C[0] = 0;
    if ( !this->field_2C[0] )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(this->window, (AbstractGUIComponent *)this->field_2C[0], -1);
    for ( j = 0; j < 5; ++j )
    {
      v12 = (BackgroundGUI *)operator new(0x2Au);
      if ( v12 )
        this->field_2C[j + 1] = BackgroundGUI_constructor(v12, 88 * j + 112, 6, 82, 93, fieldIDStart + j + 1, 1, 0, 0);
      else
        this->field_2C[j + 1] = 0;
      if ( !this->field_2C[j + 1] )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(this->window, (AbstractGUIComponent *)this->field_2C[j + 1], -1);
    }
  }
  ArmyDisplay::paint(this, redraw);
  HeroWindowManager::addWindow(HeroWindowManager::instance, this->window, -1, redraw);
  return this;
}
