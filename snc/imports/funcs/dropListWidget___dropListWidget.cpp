{
  resource *v1; // eax@1
  int v2; // esi@1
  int v3; // ecx@1
  int v4; // ebx@3
  signed int v5; // edi@3

  v1 = *(resource **)(this + 32);
  *(_DWORD *)this = &dropListWidget::_vftable_;
  v2 = this;
  resourceManager::Dispose(gpResourceManager, v1);
  resourceManager::Dispose(gpResourceManager, *(resource **)(v2 + 36));
  v3 = *(_DWORD *)(v2 + 176);
  if ( v3 )
    (**(void (__stdcall ***)(_DWORD))v3)(1);
  v4 = 0;
  v5 = 0;
  while ( *(_WORD *)(v2 + 60) > v5 )
  {
    v4 += 4;
    ++v5;
    BaseFree(*(void **)(*(_DWORD *)(v2 + 64) + v4 - 4), (int)"F:\\h2xsrc\\Base\\droplist.cpp", 25);
  }
  BaseFree(*(void **)(v2 + 64), (int)"F:\\h2xsrc\\Base\\droplist.cpp", 27);
  widget::_widget((void *)v2);
}