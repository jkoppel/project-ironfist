{
  int result; // eax@1
  int v2; // eax@2
  int v3; // [sp+Ch] [bp-Ch]@1

  v3 = this;
  result = this;
  if ( *(_DWORD *)(this + 50) )
  {
    changeMenu(*(HMENU *)(this + 682));
    v2 = sub_40E630(v3);
    strcpy(byte_5240B0, (const char *)v2);
    sub_40BFA0(v3);
    HeroWindowManager::removeWindow(HeroWindowManager::instance, *(GUIWindow **)(v3 + 54));
    operator delete(*(void **)(v3 + 54));
    result = v3;
    *(_DWORD *)(v3 + 50) = 0;
  }
  return result;
}
