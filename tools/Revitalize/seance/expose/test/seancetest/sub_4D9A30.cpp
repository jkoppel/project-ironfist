int __thiscall sub_4D9A30(int this, char a2)
{
  int v2; // esi@1

  v2 = this;
  sub_4D9A50(this);
  if ( a2 & 1 )
    operator delete((void *)v2);
  return v2;
}
