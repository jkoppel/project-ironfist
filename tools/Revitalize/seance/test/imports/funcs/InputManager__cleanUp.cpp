{
  int result; // eax@1

  result = *(_DWORD *)(this + 50);
  if ( result == 1 )
  {
    result = 0;
    *(_DWORD *)(this + 1850) = 0;
    *(_DWORD *)(this + 1846) = 0;
    *(_DWORD *)(this + 2130) = 0;
    *(_DWORD *)(this + 50) = 0;
  }
  return result;
}
