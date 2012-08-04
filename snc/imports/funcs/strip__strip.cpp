{
  border *v12; // [sp+10h] [bp-14h]@17
  border *this; // [sp+14h] [bp-10h]@10
  heroWindow *wind; // [sp+18h] [bp-Ch]@4
  signed int j; // [sp+1Ch] [bp-8h]@15
  signed int i; // [sp+20h] [bp-4h]@1

  ecx0->drawBorder = -1;
  ecx0->x = x;
  ecx0->y = y;
  ecx0->field_24 = a4;
  ecx0->portraitIcon = resourceManager::GetIcon(gpResourceManager, portraitFileID);
  ecx0->portraitIconIdx = portraitIconIdx;
  ecx0->army = armyGrp;
  ecx0->stripIcon = resourceManager::GetIcon(gpResourceManager, "strip.icn");
  for ( i = 0; i < 5; ++i )
  {
    ecx0->creaturePortraits[i] = 0;
    ecx0->creatureTypes[i] = -1;
  }
  ecx0->portraitFlagIcon = resourceManager::GetIcon(gpResourceManager, "portcflg.icn");
  ecx0->field_7C = a10;
  wind = (heroWindow *)operator new(68);
  if ( wind )
    ecx0->window = heroWindow::heroWindow(wind, ecx0->x, ecx0->y, 552, 105, 8);
  else
    ecx0->window = 0;
  if ( !ecx0->window )
    MemError();
  if ( ecx0->army )
  {
    this = (border *)operator new(42);
    if ( this )
      ecx0->field_2C[0] = border::border(this, 5, 6, 101, 93, fieldIDStart, 1, 0, 0);
    else
      ecx0->field_2C[0] = 0;
    if ( !ecx0->field_2C[0] )
      MemError();
    heroWindow::AddWidget(ecx0->window, (widget *)ecx0->field_2C[0], -1);
    for ( j = 0; j < 5; ++j )
    {
      v12 = (border *)operator new(42);
      if ( v12 )
        ecx0->field_2C[j + 1] = border::border(v12, 88 * j + 112, 6, 82, 93, fieldIDStart + j + 1, 1, 0, 0);
      else
        ecx0->field_2C[j + 1] = 0;
      if ( !ecx0->field_2C[j + 1] )
        MemError();
      heroWindow::AddWidget(ecx0->window, (widget *)ecx0->field_2C[j + 1], -1);
    }
  }
  strip::DrawIcons(ecx0, redraw);
  heroWindowManager::AddWindow(gpWindowManager, ecx0->window, -1, redraw);
  return ecx0;
}