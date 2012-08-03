{
  bitmap *thisa; // esi@1
  void *v3; // ecx@1

  this->vtable = &bitmap::_vftable_;
  thisa = this;
  v3 = this->contents;
  if ( v3 )
    BaseFree(v3, (int)"F:\\h2xsrc\\Base\\BITMAP.CPP", 51);
  thisa->contents = 0;
  resource::_resource(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}