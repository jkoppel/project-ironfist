{
  palette *pal; // ebx@1
  palette *v2; // eax@1
  signed int hit63; // ebp@5
  signed int i; // esi@7
  PaletteContents *contents; // ecx@12
  signed int j; // edx@13
  int left; // eax@13
  int stride; // [sp+10h] [bp-8h]@1
  int v8; // [sp+14h] [bp-4h]@11

  stride = a1;
  pal = 0;
  v2 = (palette *)operator new(20);
  if ( v2 )
    pal = palette::palette(v2);
  if ( !pal )
    MemError();
  hit63 = 0;
  if ( !*(&bMenu + 7 * giCurExe + 5) )
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
    v8 = KBTickCount() + 20;
    PollSound();
    if ( i == 63 )
    {
      hit63 = 1;
      contents = gpBufferPalette->contents;
    }
    else
    {
      j = 0;
      left = 63 - i;
      do
      {
        if ( *(&gpBufferPalette->contents->colors[0].red + j) > left )
          *(&pal->contents->colors[0].red + j) = *(&gpBufferPalette->contents->colors[0].red + j) - left;
        ++j;
      }
      while ( j < 768 );
      contents = pal->contents;
    }
    UpdatePalette(contents);
    DelayTil(&v8);
  }
  if ( pal )
    pal->vtable->cleanUp((resource *)pal, 1);
}