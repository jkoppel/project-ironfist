{
  Sample *thisa; // esi@1

  this->vtable = &Sample_vtable;
  thisa = this;
  KBFree(this->contents, (int)"F:\\h2xsrc\\Base\\SAMPLE.CPP", 97);
  thisa->contents = 0;
  thisa->nbytes = 0;
  thisa->field_28 = 0;
  AbstractResource_destructor(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}
