{
  int v2; // esi@1
  void *v3; // ecx@1

  *(_DWORD *)this = &palette::_vftable_;
  v2 = this;
  v3 = *(void **)(this + 16);
  if ( v3 )
    BaseFree(v3, (int)"F:\\h2xsrc\\Base\\PALETTE.CPP", 21);
  *(_DWORD *)(v2 + 16) = 0;
  resource::_resource((void *)v2);
  if ( a2 & 1 )
    operator delete((void *)v2);
  return v2;
}