{
  mouseManager *v1; // esi@1
  bitmap *v2; // ecx@2
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
      if ( *(HCURSOR *)((char *)&hMouseCursor + i * 4) )
        DestroyIcon(*(HCURSOR *)((char *)&hMouseCursor + i * 4));
      *(HCURSOR *)((char *)&hMouseCursor + i * 4) = NULL;
      v5 = cAndBits[i];
      if ( v5 )
        BaseFree(v5, (int)"F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 330);
      cAndBits[i] = NULL;
      v6 = cColorBits[i];
      if ( v6 )
        BaseFree(v6, (int)"F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 334);
      cColorBits[i] = 0;
      if ( hbmpAndMask[i] )
        DeleteObject(hbmpAndMask[i]);
      hbmpAndMask[i] = 0;
      ++i;
    }
    while ( i < 96 );
    if ( v1->cursorIcon )
      resourceManager::Dispose(gpResourceManager, (resource *)v1->cursorIcon);
    v1->cursorIcon = 0;
  }
}