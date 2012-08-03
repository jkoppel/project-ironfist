{
  int v1; // ecx@0
  int result; // eax@1

  result = *(_DWORD *)(v1 + 4);
  *(_BYTE *)(result + v1 + 20) = 1;
  return result;
}