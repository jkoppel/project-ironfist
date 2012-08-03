{
  heroWindowManager *thisa; // esi@1
  heroWindow *v2; // eax@2
  heroWindow *v3; // edi@3
  bitmap *v4; // ecx@4

  thisa = this;
  if ( this->ready == 1 )
  {
    v2 = this->lastWindow;
    if ( v2 )
    {
      do
      {
        v3 = v2->prevWindow;
        heroWindowManager::RemoveWindow(thisa, v2);
        v2 = v3;
      }
      while ( v3 );
    }
    thisa->screenBuffer->contents = 0;
    v4 = thisa->screenBuffer;
    if ( v4 )
      ((void (__stdcall *)(_DWORD))v4->vtable->cleanUp)(1);
    thisa->ready = 0;
  }
}