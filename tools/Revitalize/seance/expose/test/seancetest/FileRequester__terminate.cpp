int __thiscall FileRequester::terminate(int this)
{
  int result; // eax@1
  int v2; // [sp+Ch] [bp-Ch]@1

  v2 = this;
  result = this;
  if ( *(_DWORD *)(this + 50) )
  {
    changeMenu(*(HMENU *)(this + 682));
    sub_40E630(v2);
    strcpy((int)byte_5240B0);
    sub_40BFA0(v2);
    HeroWindowManager::removeWindow(HeroWindowManager::instance, *(GUIWindow **)(v2 + 54));
    operator delete(*(void **)(v2 + 54));
    result = v2;
    *(_DWORD *)(v2 + 50) = 0;
  }
  return result;
}
