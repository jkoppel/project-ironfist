int __thiscall Font::cleanUp(int this, char a2)
{
  int thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  Font_destructor((Font *)this);
  if ( a2 & 1 )
    operator delete((void *)thisa);
  return thisa;
}
