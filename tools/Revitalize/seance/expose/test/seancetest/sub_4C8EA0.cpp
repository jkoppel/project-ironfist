void __fastcall sub_4C8EA0(int a1)
{
  Palette *pal; // ebx@1
  Palette *v2; // eax@1
  signed int hit63; // ebp@5
  signed int i; // esi@7
  PaletteContents *contents; // ecx@12
  signed int j; // edx@13
  int left; // eax@13
  int stride; // [sp+10h] [bp-8h]@1
  int v8; // [sp+14h] [bp-4h]@11

  stride = a1;
  pal = 0;
  v2 = (Palette *)operator new(0x14u);
  if ( v2 )
    pal = Palette_constructor(v2);
  if ( !pal )
    fatalOutOfMemoryError();
  hit63 = 0;
  if ( !*(&mainWindows + 7 * gameOrEditorIdx + 5) )
    stride *= 2;
  memset(pal->contents, 0, 0x300u);
  for ( i = 0; ; i += stride )
  {
    if ( i < 64 )
      goto LABEL_11;
    if ( hit63 )
      break;
    i = 63;
LABEL_11:
    v8 = getTickCount() + 20;
    yieldToGlobalUpdater();
    if ( i == 63 )
    {
      hit63 = 1;
      contents = palette->contents;
    }
    else
    {
      j = 0;
      left = 63 - i;
      do
      {
        if ( *(&palette->contents->colors[0].red + j) > left )
          *(&pal->contents->colors[0].red + j) = *(&palette->contents->colors[0].red + j) - left;
        ++j;
      }
      while ( j < 768 );
      contents = pal->contents;
    }
    sub_49CFB0(contents);
    sleepUntilPointer(&v8);
  }
  if ( pal )
    pal->vtable->cleanUp((AbstractResource *)pal, 1);
}
