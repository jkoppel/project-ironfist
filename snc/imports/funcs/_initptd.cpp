{
  int result; // eax@1

  result = a1;
  *(_DWORD *)(a1 + 80) = &_XcptActTab;
  *(_DWORD *)(a1 + 20) = 1;
  return result;
}