{
  int v1; // ecx@1
  unsigned int v2; // edi@1
  unsigned int v3; // esi@1
  int result; // eax@1

  v1 = *(_DWORD *)(a1 + 4);
  v2 = (*(_DWORD *)a1 & 0x80000000u) >> 31;
  v3 = (*(_DWORD *)(a1 + 4) & 0x80000000u) >> 31;
  *(_DWORD *)a1 *= 2;
  *(_DWORD *)(a1 + 4) = v2 | 2 * v1;
  result = v3 | 2 * *(_DWORD *)(a1 + 8);
  *(_DWORD *)(a1 + 8) = result;
  return result;
}
