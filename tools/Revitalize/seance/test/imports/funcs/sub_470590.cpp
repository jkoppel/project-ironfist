{
  int result; // eax@1

  result = *(_DWORD *)(this + 4);
  *(_BYTE *)(result + this + 20) = 1;
  return result;
}
