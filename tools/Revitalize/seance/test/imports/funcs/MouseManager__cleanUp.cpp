{
  MouseManager *v1; // esi@1
  Bitmap *v2; // ecx@2
  signed int i; // edi@4
  HCURSOR v4; // eax@4
  void *v5; // ecx@7
  void *v6; // ecx@9

  v1 = this;
  if ( this->ready == 1 )
  {
    this->ready = 0;
    v2 = this->bitmap;
    if ( v2 )
      ((void (__stdcall *)(_DWORD))v2->vtable->cleanUp)(1);
    i = 0;
    v1->bitmap = 0;
    v4 = LoadCursorA(0, (LPCSTR)0x7F00);
    SetCursor(v4);
    do
    {
      if ( *(HCURSOR *)((char *)&cursorCache + i * 4) )
        DestroyCursor(*(HCURSOR *)((char *)&cursorCache + i * 4));
      *(HCURSOR *)((char *)&cursorCache + i * 4) = NULL;
      v5 = cursorBmBits[i];
      if ( v5 )
        KBFree(v5, (int)"F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 330);
      cursorBmBits[i] = NULL;
      v6 = cursorBitmapFileContents[i];
      if ( v6 )
        KBFree(v6, (int)"F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 334);
      cursorBitmapFileContents[i] = 0;
      if ( dword_533B40[i] )
        DeleteObject(dword_533B40[i]);
      dword_533B40[i] = 0;
      ++i;
    }
    while ( i < 96 );
    if ( v1->cursorIcon )
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)v1->cursorIcon);
    v1->cursorIcon = 0;
  }
}
