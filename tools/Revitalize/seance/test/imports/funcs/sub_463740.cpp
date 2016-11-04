{
  __int16 imgIdx; // [sp+10h] [bp-80h]@10
  TextWidget *v2; // [sp+18h] [bp-78h]@16
  GUIIcon *v3; // [sp+1Ch] [bp-74h]@8
  GUIWindow *this; // [sp+20h] [bp-70h]@1
  int evt; // [sp+30h] [bp-60h]@6
  int v6; // [sp+34h] [bp-5Ch]@6
  int v7; // [sp+38h] [bp-58h]@6
  char *v8; // [sp+48h] [bp-48h]@6
  int xOff; // [sp+4Ch] [bp-44h]@1
  int v10; // [sp+50h] [bp-40h]@1
  int v11; // [sp+5Ch] [bp-34h]@1
  int i; // [sp+64h] [bp-2Ch]@6
  int v13; // [sp+68h] [bp-28h]@6
  int v14; // [sp+6Ch] [bp-24h]@6
  int v15; // [sp+70h] [bp-20h]@1
  char filename; // [sp+74h] [bp-1Ch]@1
  int guiObj[3]; // [sp+84h] [bp-Ch]@17

  v15 = 5;
  v11 = 306;
  v10 = 405;
  xOff = 159;
  dword_52523C = 0;
  sprintf(&filename, "evntwin%d.bin", 5);
  this = (GUIWindow *)operator new(0x44u);
  if ( this )
    dword_525228 = GUIWindow_constructorFromFile(this, xOff, 28, &filename);
  else
    dword_525228 = 0;
  if ( !dword_525228 )
    fatalOutOfMemoryError();
  strcpy(
    globBuf,
    "You enter the arena and face a pack of vicious lions.  You handily defeat them, to the wild cheers of the crowd.  Impressed by your skill, the aged trainer of gladiators agrees to train you in a skill of your choice.");
  v13 = Font::numLinesNeededToDisplay(bigFont, globBuf, 244);
  v14 = 16 * v13;
  evt = 512;
  v6 = 3;
  v7 = 1;
  v8 = globBuf;
  GUIWindow::processMessage(dword_525228, (Event *)&evt);
  for ( i = 0; i < 3; ++i )
  {
    v3 = (GUIIcon *)operator new(0x2Du);
    if ( v3 )
    {
      if ( dword_52523C == i )
        imgIdx = i + 4;
      else
        imgIdx = i;
      dword_525230[i] = (int)GUIIcon_constructor(
                               v3,
                               60 * i + 84,
                               244,
                               39,
                               34,
                               "xprimary.icn",
                               imgIdx,
                               0,
                               i + 100,
                               16,
                               1);
    }
    else
    {
      dword_525230[i] = 0;
    }
    if ( !dword_525230[i] )
      fatalOutOfMemoryError();
    v2 = (TextWidget *)operator new(0x2Bu);
    if ( v2 )
      guiObj[i] = (int)TextWidget_constructor(
                         v2,
                         60 * i + 79,
                         282,
                         49,
                         24,
                         primarySkillNames[i],
                         "smalfont.fnt",
                         1,
                         -1,
                         512,
                         1);
    else
      guiObj[i] = 0;
    if ( !guiObj[i] )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(dword_525228, (AbstractGUIComponent *)dword_525230[i], -1);
    GUIWindow::insertElement(dword_525228, (AbstractGUIComponent *)guiObj[i], -1);
  }
  evt = 512;
  v6 = 6;
  v8 = (char *)6;
  v7 = 30727;
  GUIWindow::processMessage(dword_525228, (Event *)&evt);
  v7 = 30728;
  GUIWindow::processMessage(dword_525228, (Event *)&evt);
  v7 = 30721;
  GUIWindow::processMessage(dword_525228, (Event *)&evt);
  v7 = 30725;
  GUIWindow::processMessage(dword_525228, (Event *)&evt);
  v7 = 30726;
  GUIWindow::processMessage(dword_525228, (Event *)&evt);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    dword_525228,
    (int (__fastcall *)(InputEvent *))sub_463AA0,
    0);
  operator delete(dword_525228);
  return dword_52523C;
}
