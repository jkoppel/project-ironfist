{
  LPVOID result; // eax@1

  result = _getptd();
  *((_DWORD *)result + 5) = a1;
  return result;
}