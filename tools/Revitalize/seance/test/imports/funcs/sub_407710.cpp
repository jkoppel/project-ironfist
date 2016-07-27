{
  void *v1; // ST18_4@1
  void *result; // eax@1

  v1 = this;
  sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
  HeroWindowManager::removeWindow(HeroWindowManager::instance, *(GUIWindow **)((char *)v1 + 95));
  operator delete(*(void **)((char *)v1 + 95));
  result = v1;
  *(_DWORD *)((char *)v1 + 50) = 0;
  return result;
}
