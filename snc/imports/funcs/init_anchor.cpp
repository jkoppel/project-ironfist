{
  int result; // eax@1

  *(_DWORD *)this = 0;
  result = this;
  *(_DWORD *)(this + 4) = 0;
  return result;
}