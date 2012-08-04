{
  tileset *thisa; // esi@1

  this->vtable = (ResourceVtable *)button::_vftable_;
  thisa = this;
  BaseFree(this->contents, (int)"F:\\h2xsrc\\Base\\TILESET.CPP", 28);
  resource::_resource(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}