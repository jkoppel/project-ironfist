{
  Bitmap *thisa; // esi@1
  void *v3; // ecx@1

  this->vtable = &Bitmap_vtable;
  thisa = this;
  v3 = this->contents;
  if ( v3 )
    KBFree(v3, (int)"F:\\h2xsrc\\Base\\BITMAP.CPP", 51);
  thisa->contents = 0;
  AbstractResource_destructor(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}
