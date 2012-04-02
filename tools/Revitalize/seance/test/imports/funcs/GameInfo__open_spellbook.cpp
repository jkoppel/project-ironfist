{
  GameInfo *thisa; // [sp+Ch] [bp-2Ch]@1
  GUIWindow *window; // [sp+18h] [bp-20h]@6
  InputEvent evt; // [sp+1Ch] [bp-1Ch]@12

  thisa = this;
  dword_522FB0 = hero;
  *(_DWORD *)&this->_10[648] = -1;
  if ( Hero::numSpellsKnown(hero, type) )
  {
    thisa->callback = callback;
    LOBYTE(thisa->field_660D) = a5;
    *(_DWORD *)&thisa->_10[624] = hero;
    if ( type == 2 )
      *(_DWORD *)&thisa->_10[628] = 1;
    else
      *(_DWORD *)&thisa->_10[628] = type;
    *(_DWORD *)&thisa->_10[632] = 0;
    *(_DWORD *)&thisa->_10[640] = Hero::numSpellsKnown(hero, 0);
    *(_DWORD *)&thisa->_10[636] = 0;
    *(_DWORD *)&thisa->_10[644] = Hero::numSpellsKnown(hero, SPELL_CATEGORY_ADVENTURE);
    window = (GUIWindow *)operator new(0x44u);
    if ( window )
      *(_DWORD *)&thisa->_10[620] = GUIWindow_constructorFromFile(window, 86, 87, "spellwin.bin");
    else
      *(_DWORD *)&thisa->_10[620] = 0;
    if ( !*(_DWORD *)&thisa->_10[620] )
      fatalOutOfMemoryError();
    if ( type != 2 )
    {
      evt.eventCode = INPUT_GUI_MESSAGE_CODE;
      evt.xCoordOrKeycode = 6;
      if ( type )
        evt.yCoord = 5;
      else
        evt.yCoord = 4;
      evt.payload = (void *)6;
      GUIWindow::processMessage(*(GUIWindow **)&thisa->_10[620], (Event *)&evt);
    }
    sub_4219A0((int)thisa);
    HeroWindowManager::displayWindow(
      HeroWindowManager::instance,
      *(GUIWindow **)&thisa->_10[620],
      (int (__fastcall *)(InputEvent *))sub_421E70,
      0);
    operator delete(*(void **)&thisa->_10[620]);
  }
  else
  {
    display_message_window("No spells to cast.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  return *(_DWORD *)&thisa->_10[648];
}
