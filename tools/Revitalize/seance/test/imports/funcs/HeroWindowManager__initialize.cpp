{
  HeroWindowManager *thisa; // ebx@1
  Bitmap *v3; // eax@1

  thisa = this;
  doNothing();
  memset(palette->contents, 0, 0x300u);
  someSortOfPaletteSwap(palette->contents, 1);
  v3 = (Bitmap *)operator new(0x1Au);
  if ( v3 )
    thisa->screenBuffer = Bitmap_noArgsConstructor(v3);
  else
    thisa->screenBuffer = 0;
  if ( !thisa->screenBuffer )
    fatalOutOfMemoryError();
  thisa->screenBuffer->setInConstructor = 33;
  thisa->screenBuffer->width = 640;
  thisa->screenBuffer->height = 480;
  thisa->screenBuffer->contents = (unsigned __int8 *)screenContents;
  memset(thisa->screenBuffer->contents, 0x24u, 0x4B000u);
  thisa->idx = a2;
  thisa->type = 32;
  thisa->ready = 1;
  strcpy(thisa->name, "heroWindowManager");
  return 0;
}
