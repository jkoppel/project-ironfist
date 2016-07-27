{
  MouseManager *thisa; // esi@1
  Bitmap *v3; // eax@1

  this->field_7E = 0;
  thisa = this;
  v3 = (Bitmap *)operator new(0x1Au);
  if ( v3 )
    thisa->bitmap = Bitmap_constructor(v3, 33, 66, 64);
  else
    thisa->bitmap = 0;
  thisa->cursorTopLeftX = 319;
  thisa->cursorTopLeftY = 239;
  thisa->field_6E = 320;
  thisa->field_66 = 319;
  thisa->field_6A = 239;
  thisa->field_56 = 320;
  thisa->cursorIdx = 0;
  thisa->field_4A = 0;
  thisa->field_72 = 240;
  thisa->field_5A = 240;
  if ( dword_4F19B0 )
    ShowCursor(0);
  thisa->type = 64;
  thisa->ready = 1;
  thisa->idx = a2;
  return 0;
}
