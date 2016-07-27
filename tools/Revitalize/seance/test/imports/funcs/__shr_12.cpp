{
  unsigned int v1; // eax@1
  int v2; // edx@1
  int v3; // edi@1
  int result; // eax@1

  v1 = *(_DWORD *)(a1 + 4);
  v2 = *(_DWORD *)(a1 + 8) << 31;
  v3 = *(_DWORD *)(a1 + 4) << 31;
  *(_DWORD *)(a1 + 8) >>= 1;
  *(_DWORD *)(a1 + 4) = v2 | (v1 >> 1);
  result = v3 | (*(_DWORD *)a1 >> 1);
  *(_DWORD *)a1 = result;
  return result;
}
