{
  sample *thisa; // esi@1

  this->vtable = &sample::_vftable_;
  thisa = this;
  BaseFree(this->contents, (int)"F:\\h2xsrc\\Base\\SAMPLE.CPP", 97);
  thisa->contents = 0;
  thisa->nbytes = 0;
  thisa->field_28 = 0;
  resource::_resource(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}