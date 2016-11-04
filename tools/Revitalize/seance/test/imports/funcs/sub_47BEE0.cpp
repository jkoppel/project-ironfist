{
  int result; // eax@1

  *(_DWORD *)(this + 126) = 14;
  result = this;
  *(_DWORD *)(this + 130) = 0;
  return result;
}
