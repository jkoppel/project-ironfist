Sequence *__thiscall Sequence_cleanUp(Sequence *this, char a2)
{
  Sequence *thisa; // esi@1

  this->vtable = &Sequence_vtable;
  thisa = this;
  KBFree(this->contents, (int)"F:\\h2xsrc\\Base\\SAMPLE.CPP", 118);
  thisa->contents = 0;
  AbstractResource_destructor(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}
