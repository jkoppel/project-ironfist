{
  resource *v1; // eax@1
  int v2; // esi@1
  int v3; // ecx@1
  int v4; // ebx@3
  signed int v5; // edi@3

  v1 = *(resource **)(this + 32);
  *(_DWORD *)this = &listBoxWidget::_vftable_;
  v2 = this;
  resourceManager::Dispose(gpResourceManager, v1);
  resourceManager::Dispose(gpResourceManager, *(resource **)(v2 + 36));
  v3 = *(_DWORD *)(v2 + 142);
  if ( v3 )
    (**(void (__stdcall ***)(_DWORD))v3)(1);
  v4 = 0;
  v5 = 0;
  while ( *(_WORD *)(v2 + 50) > v5 )
  {
    v4 += 4;
    ++v5;
    BaseFree(*(void **)(*(_DWORD *)(v2 + 60) + v4 - 4), (int)"F:\\h2xsrc\\Base\\listbox.cpp", 25);
  }
  BaseFree(*(void **)(v2 + 60), (int)"F:\\h2xsrc\\Base\\listbox.cpp", 27);
  gbSendMouseMoveMessages = 0;
  widget::_widget((void *)v2);
}