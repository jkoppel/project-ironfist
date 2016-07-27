{
  int v1; // eax@1
  int result; // eax@4

  ++dword_521AB8;
  v1 = malloc(0x1000u);
  *(_DWORD *)(a1 + 8) = v1;
  if ( v1 )
  {
    *(_DWORD *)(a1 + 12) |= 8u;
    *(_DWORD *)(a1 + 24) = 4096;
  }
  else
  {
    *(_DWORD *)(a1 + 12) |= 4u;
    *(_DWORD *)(a1 + 8) = a1 + 20;
    *(_DWORD *)(a1 + 24) = 2;
  }
  result = *(_DWORD *)(a1 + 8);
  *(_DWORD *)a1 = result;
  *(_DWORD *)(a1 + 4) = 0;
  return result;
}
