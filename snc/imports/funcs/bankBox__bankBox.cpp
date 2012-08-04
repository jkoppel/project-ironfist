{
  bankBox *thisa; // [sp+Ch] [bp-8h]@1
  heroWindow *window; // [sp+10h] [bp-4h]@1

  thisa = this;
  this->player = player;
  this->x = x;
  this->y = y;
  window = (heroWindow *)operator new(68);
  if ( window )
    thisa->window = heroWindow::heroWindow(window, thisa->x, thisa->y, "bankbox.bin");
  else
    thisa->window = 0;
  if ( !thisa->window )
    MemError();
  heroWindowManager::AddWindow(gpWindowManager, thisa->window, -1, 1);
  bankBox::Update(thisa, 1);
  return thisa;
}