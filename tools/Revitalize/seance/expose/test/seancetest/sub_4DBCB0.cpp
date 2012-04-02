void *__thiscall sub_4DBCB0(void *this, char a2)
{
  void *v2; // esi@1

  *(_DWORD *)this = &off_4EAFE8;
  v2 = this;
  AbstractGUIComponent_destructor(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
