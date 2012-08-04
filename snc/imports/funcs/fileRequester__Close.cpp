{
  int result; // eax@1
  int v2; // eax@2
  int v3; // [sp+Ch] [bp-Ch]@1

  v3 = this;
  result = this;
  if ( *(_DWORD *)(this + 50) )
  {
    KBChangeMenu(*(HMENU *)(this + 682));
    v2 = fileRequester::GetFilename(v3);
    strcpy(gLastFilename, (char *)v2);
    fileRequester::CleanUpData(v3);
    heroWindowManager::RemoveWindow(gpWindowManager, *(heroWindow **)(v3 + 54));
    operator delete(*(void **)(v3 + 54));
    result = v3;
    *(_DWORD *)(v3 + 50) = 0;
  }
  return result;
}