Bankbox *__thiscall Bankbox_constructor(Bankbox *this, __int16 x, __int16 y, Player *player)
{
  Bankbox *thisa; // [sp+Ch] [bp-8h]@1
  GUIWindow *window; // [sp+10h] [bp-4h]@1

  thisa = this;
  this->player = player;
  this->x = x;
  this->y = y;
  window = (GUIWindow *)operator new(0x44u);
  if ( window )
    thisa->window = GUIWindow_constructorFromFile(window, thisa->x, thisa->y, "bankbox.bin");
  else
    thisa->window = 0;
  if ( !thisa->window )
    fatalOutOfMemoryError();
  HeroWindowManager::addWindow(HeroWindowManager::instance, thisa->window, -1, 1);
  Bankbox::refreshCaptions(thisa, 1);
  return thisa;
}
