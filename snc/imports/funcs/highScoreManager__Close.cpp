{
  void *v1; // ST18_4@1
  void *result; // eax@1

  v1 = this;
  heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
  heroWindowManager::RemoveWindow(gpWindowManager, *(heroWindow **)((char *)v1 + 95));
  operator delete(*(void **)((char *)v1 + 95));
  result = v1;
  *(_DWORD *)((char *)v1 + 50) = 0;
  return result;
}