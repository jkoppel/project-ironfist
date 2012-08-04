{
  int thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  font::_font((font *)this);
  if ( a2 & 1 )
    operator delete((void *)thisa);
  return thisa;
}