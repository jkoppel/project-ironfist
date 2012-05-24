ArmyDisplay *__thiscall ArmyDisplay::constructor(ArmyDisplay *ecx0, int x, int y, int a4, int portraitFileID, int portraitIconIdx, ArmyInfo *army, __int16 fieldIDStart, int redraw, int a10)
{
  BackgroundGUI *v12; // [sp+10h] [bp-14h]@17
  BackgroundGUI *this; // [sp+14h] [bp-10h]@10
  GUIWindow *wind; // [sp+18h] [bp-Ch]@4
  signed int j; // [sp+1Ch] [bp-8h]@15
  signed int i; // [sp+20h] [bp-4h]@1

  ecx0->drawBorder = -1;
  ecx0->x = x;
  ecx0->y = y;
  ecx0->field_24 = a4;
  ecx0->portraitIcon = ResourceManager::getIconByFileID(resourceManager, portraitFileID);
  ecx0->portraitIconIdx = portraitIconIdx;
  ecx0->army = army;
  ecx0->stripIcon = ResourceManager::getIconByFilename(resourceManager, "strip.icn");
  for ( i = 0; i < 5; ++i )
  {
    ecx0->creaturePortraits[i] = 0;
    ecx0->creatureTypes[i] = -1;
  }
  ecx0->portraitFlagIcon = ResourceManager::getIconByFilename(resourceManager, "portcflg.icn");
  ecx0->field_7C = a10;
  wind = (GUIWindow *)operator new(68);
  if ( wind )
    ecx0->window = GUIWindow_constructor(wind, ecx0->x, ecx0->y, 552, 105, 8);
  else
    ecx0->window = 0;
  if ( !ecx0->window )
    fatalOutOfMemoryError();
  if ( ecx0->army )
  {
    this = (BackgroundGUI *)operator new(42);
    if ( this )
      ecx0->field_2C[0] = BackgroundGUI_constructor(this, 5, 6, 101, 93, fieldIDStart, 1, 0, 0);
    else
      ecx0->field_2C[0] = 0;
    if ( !ecx0->field_2C[0] )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(ecx0->window, (AbstractGUIComponent *)ecx0->field_2C[0], -1);
    for ( j = 0; j < 5; ++j )
    {
      v12 = (BackgroundGUI *)operator new(42);
      if ( v12 )
        ecx0->field_2C[j + 1] = BackgroundGUI_constructor(v12, 88 * j + 112, 6, 82, 93, fieldIDStart + j + 1, 1, 0, 0);
      else
        ecx0->field_2C[j + 1] = 0;
      if ( !ecx0->field_2C[j + 1] )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(ecx0->window, (AbstractGUIComponent *)ecx0->field_2C[j + 1], -1);
    }
  }
  ArmyDisplay::paint(ecx0, redraw);
  HeroWindowManager::addWindow(HeroWindowManager::instance, ecx0->window, -1, redraw);
  return ecx0;
}
