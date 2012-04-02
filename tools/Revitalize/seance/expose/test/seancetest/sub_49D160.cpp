signed int __thiscall sub_49D160(void *this)
{
  signed int result; // eax@2
  void *v2; // [sp+Ch] [bp-1Ch]@1
  void *a1; // [sp+10h] [bp-18h]@9
  int y; // [sp+14h] [bp-14h]@9
  int x; // [sp+18h] [bp-10h]@9
  unsigned int heightNeededToDisplay; // [sp+1Ch] [bp-Ch]@9
  unsigned int width; // [sp+20h] [bp-8h]@9
  int v8; // [sp+24h] [bp-4h]@9

  v2 = this;
  if ( (void *)graphicsLibraryToUse == this )
  {
    result = 1;
  }
  else
  {
    if ( this != (void *)1 || dword_5192E8 )
    {
      if ( this != (void *)2 || dword_5192EC )
      {
        v8 = *(&mainWindows + 7 * gameOrEditorIdx + 5);
        x = *(&mainWindows + 7 * gameOrEditorIdx + 1);
        y = *(&mainWindows + 7 * gameOrEditorIdx + 2);
        width = *(&mainWindows + 7 * gameOrEditorIdx + 3);
        heightNeededToDisplay = *(&mainWindows + 7 * gameOrEditorIdx + 4);
        a1 = KBAlloc(0x4B000u, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519F88 + 18);
        memcpy(a1, HeroWindowManager::instance->screenBuffer->contents, 0x4B000u);
        if ( v2 == (void *)1 )
        {
          *(&mainWindows + 7 * gameOrEditorIdx + 5) = 0;
          sub_49C060();
          graphicsLibraryToUse = 1;
          sub_49C580();
          HeroWindowManager::instance->screenBuffer->contents = (unsigned __int8 *)screenContents;
        }
        else
        {
          sub_49CC80();
          graphicsLibraryToUse = 2;
          sub_49AFB0();
          HeroWindowManager::instance->screenBuffer->contents = (unsigned __int8 *)screenContents;
        }
        memcpy(HeroWindowManager::instance->screenBuffer->contents, a1, 0x4B000u);
        KBFree(a1, (int)"F:\\h2xsrc\\Source\\wingraph.cpp", word_519F88 + 39);
        if ( v8 )
        {
          if ( v2 == (void *)1 )
          {
            sub_485B30(1);
            setWindowRectangle(x, y, width, heightNeededToDisplay);
          }
        }
        renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 640u, 480, 0, 0);
        sub_49CFB0(palette->contents);
        result = 1;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
