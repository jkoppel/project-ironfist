int __thiscall HeroWindowManager::displayWindow(HeroWindowManager *this, GUIWindow *window, int (__fastcall *a3)(InputEvent *), int a4)
{
  HeroWindowManager *thisa; // ebx@1
  HeroWindowManager *v5; // esi@6
  int v6; // edi@8
  signed int v7; // ebp@9
  int evt; // [sp+10h] [bp-38h]@10
  int v10; // [sp+14h] [bp-34h]@15
  int v11; // [sp+18h] [bp-30h]@16
  InputEvent a2; // [sp+2Ch] [bp-1Ch]@10

  dword_4F2E8C = 1;
  thisa = this;
  if ( !dword_51E41C )
    sub_485C90(0);
  ++dword_51E41C;
  thisa->field_5E = -1;
  if ( window )
    HeroWindowManager::addWindow(thisa, window, -1, 1);
  if ( a4 )
  {
    v5 = HeroWindowManager::instance;
    if ( dword_524234 )
      someSortOfPaletteSwap(dword_524234->contents, 0);
    v6 = v5->field_56;
    v5->field_56 = 0;
    yieldToGlobalUpdater();
    sub_4C8EA0(8);
    v5->field_56 = v6 | dword_532E54;
    yieldToGlobalUpdater();
  }
  v7 = 0;
  InputManager::resetInfoFields(inputManager);
  thisa->buttonPressedCode = -1;
  do
  {
    yieldToGlobalUpdater();
    passOnMessages();
    memcpy(&evt, InputManager::nextInputEvent(inputManager, &a2), 0x1Cu);
    (*(void (__stdcall **)(int *))(LODWORD(mouseManager->vtable) + 8))(&evt);
    if ( window
      && (evt != 4 || dword_4F19AC)
      && GUIWindow::processMessage(window, (Event *)&evt) == 2
      && evt == 512
      && v10 == 10 )
    {
      v7 = 1;
      thisa->buttonPressedCode = v11;
    }
    if ( ((int (__thiscall *)(int *))a3)(&evt) == 2 && evt == 512 && v10 == 10 )
      v7 = 1;
  }
  while ( !v7 );
  if ( window )
    HeroWindowManager::removeWindow(thisa, window);
  InputManager::resetInfoFields(inputManager);
  dword_4F2E8C = 0;
  --dword_51E41C;
  if ( !dword_51E41C )
    sub_485C90(1);
  return 0;
}
