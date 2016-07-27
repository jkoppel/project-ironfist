{
  Tileset *thisa; // esi@1

  this->vtable = (ResourceVtable *)Tileset_vtable;
  thisa = this;
  KBFree(this->contents, (int)"F:\\h2xsrc\\Base\\TILESET.CPP", 28);
  AbstractResource_destructor(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}
