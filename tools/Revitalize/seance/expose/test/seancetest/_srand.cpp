int __cdecl srand(int a1)
{
  int result; // eax@1

  result = _getptd();
  *(_DWORD *)(result + 20) = a1;
  return result;
}
