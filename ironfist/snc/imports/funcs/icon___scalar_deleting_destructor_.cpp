{
  icon *thisa; // esi@1

  this->vtable = &icon::_vftable_;
  thisa = this;
  BaseFree(this->headersAndImageData, (int)"F:\\h2xsrc\\Base\\ICON.CPP", 26);
  resource::_resource(thisa);
  if ( shouldDelete & 1 )
    operator delete(thisa);
  return thisa;
}