{
  signed int result; // eax@2
  Hero *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  display_message_window(byte_518DDC, 2, -1, -1, -1, 0, -1, 0, -1, 0);
  if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
  {
    Hero::delete(thisa, 1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
