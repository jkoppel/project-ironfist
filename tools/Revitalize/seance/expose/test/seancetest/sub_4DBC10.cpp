int __thiscall sub_4DBC10(int this)
{
  int v1; // esi@1
  int result; // eax@1

  v1 = this;
  AbstractGUIComponent_constructor((AbstractGUIComponent *)this, 0, 0, 0, 0, 0, 0);
  result = v1;
  *(_DWORD *)v1 = &off_4EAFE8;
  return result;
}
