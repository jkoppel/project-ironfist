{
  Icon *thisa; // esi@1

  this->vtable = &Icon_vtable;
  thisa = this;
  KBFree(this->headersAndImageData, (int)"F:\\h2xsrc\\Base\\ICON.CPP", 26);
  AbstractResource_destructor(thisa);
  if ( shouldDelete & 1 )
    operator delete(thisa);
  return thisa;
}
