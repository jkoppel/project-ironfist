{
  MIDIWrap *thisa; // esi@1

  this->vtable = &MIDIWrap::_vftable_;
  thisa = this;
  BaseFree(this->contents, (int)"F:\\h2xsrc\\Base\\SAMPLE.CPP", 118);
  thisa->contents = 0;
  resource::_resource(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}