void __thiscall sub_4A8140(void *this, int a2, int a3)
{
  int v3; // [sp+Ch] [bp-48h]@1
  unsigned __int8 v4; // [sp+14h] [bp-40h]@37
  unsigned __int8 v5; // [sp+18h] [bp-3Ch]@34
  GUIIcon *v6; // [sp+20h] [bp-34h]@32
  GUIWindow *thisa; // [sp+24h] [bp-30h]@13
  signed __int16 v8; // [sp+28h] [bp-2Ch]@30
  int evt; // [sp+2Ch] [bp-28h]@45
  int v10; // [sp+30h] [bp-24h]@46
  int v11; // [sp+34h] [bp-20h]@46
  int v12; // [sp+44h] [bp-10h]@46
  int v13; // [sp+48h] [bp-Ch]@1
  int i; // [sp+4Ch] [bp-8h]@18
  AbstractGUIComponent *guiObj; // [sp+50h] [bp-4h]@18

  v3 = (int)this;
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  sub_4CEA00(mouseManager);
  v13 = useEvilBorders;
  useEvilBorders = *(_BYTE *)(v3 + 2) == 1;
  dword_5304D4 = a2;
  dword_5304D8 = *(_BYTE *)(v3 + 2);
  dword_5304DC = *(_BYTE *)(v3 + 4);
  if ( *(_BYTE *)(v3 + 4) != 4 || a2 )
  {
    dword_5304D0 = *(_BYTE *)(v3 + 2) + 2 * *(_BYTE *)(v3 + 3);
  }
  else
  {
    if ( *(_BYTE *)(v3 + 2) )
    {
      if ( *(_BYTE *)(v3 + 19) )
        dword_5304D0 = 5;
      else
        dword_5304D0 = 6;
    }
    else
    {
      dword_5304D0 = 4;
    }
  }
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    dword_51D158 = GUIWindow_constructorFromFile(thisa, 0, 0, "campaign.bin");
  else
    dword_51D158 = 0;
  if ( !dword_51D158 )
    fatalOutOfMemoryError();
  guiObj = 0;
  for ( i = 0; i < 13; ++i )
  {
    if ( (dword_5304D0 >= 4 || i < 11)
      && (dword_5304D0 != 4 || i != 12)
      && (dword_5304D0 != 5 || i != 12)
      && (dword_5304D0 != 6 || i != 11)
      && *(&word_51D0F0[26 * dword_5304D8] + 2 * i) != -1 )
    {
      v8 = i;
      if ( i > 11 )
        v8 = 11;
      v6 = (GUIIcon *)operator new(0x2Du);
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
        guiObj = (AbstractGUIComponent *)GUIIcon_constructor(
                                           v6,
                                           *(&word_51D0F0[26 * v4] + 2 * i) - 2,
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
        fatalOutOfMemoryError();
      GUIWindow::insertElement(dword_51D158, guiObj, -1);
    }
  }
  evt = 512;
  if ( !a2 )
  {
    v10 = 6;
    v11 = 901;
    v12 = 6;
    GUIWindow::processMessage(dword_51D158, (Event *)&evt);
  }
  if ( dword_4F74A8 )
  {
    v10 = 6;
    v11 = 902;
    v12 = 6;
    GUIWindow::processMessage(dword_51D158, (Event *)&evt);
  }
  SoundManager::couldBePlayCDTrack(soundManager, (unsigned int)*(_BYTE *)(v3 + 2) < 1 ? 24 : 22);
  sub_4A85D0((void *)v3, 0);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    dword_51D158,
    (int (__fastcall *)(InputEvent *))sub_4A8FE0,
    0);
  operator delete(dword_51D158);
  useEvilBorders = v13;
  if ( HeroWindowManager::instance->buttonPressedCode == 901 )
  {
    display_message_window("Are you sure you want to restart this scenario?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
    {
      sub_4A9550(v3);
      advManager->field_A2 = 0;
      dword_52405C = 0;
      sub_4C7C60(HeroWindowManager::instance, 1, 8, dword_524234);
      sub_4557F0(advManager);
      sub_4506B0(advManager, 1, 0);
      sub_4C7C60(HeroWindowManager::instance, 0, 8, dword_524234);
    }
  }
}
