{
  heroWindowManager *thisa; // ebx@1
  bitmap *v3; // eax@1

  thisa = this;
  InitVideo();
  memset(gpBufferPalette->contents, 0, 0x300u);
  SetPalette(gpBufferPalette->contents, 1);
  v3 = (bitmap *)operator new(26);
  if ( v3 )
    thisa->screenBuffer = bitmap::bitmap(v3);
  else
    thisa->screenBuffer = 0;
  if ( !thisa->screenBuffer )
    MemError();
  thisa->screenBuffer->setInConstructor = 33;
  thisa->screenBuffer->width = 640;
  thisa->screenBuffer->height = 480;
  thisa->screenBuffer->contents = (unsigned __int8 *)lpInitWin;
  memset(thisa->screenBuffer->contents, 0x24u, 0x4B000u);
  thisa->idx = a2;
  thisa->type = 32;
  thisa->ready = 1;
  strcpy(thisa->name, "heroWindowManager");
  return 0;
}