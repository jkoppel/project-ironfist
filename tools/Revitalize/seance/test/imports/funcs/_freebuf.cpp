{
  BOOL result; // eax@1

  result = *(_DWORD *)(a1 + 12);
  if ( result & 0x83 )
  {
    if ( result & 8 )
    {
      result = free(*(_DWORD *)(a1 + 8));
      *(_DWORD *)a1 = 0;
      *(_DWORD *)(a1 + 12) &= 0xFFFFFBF7u;
      *(_DWORD *)(a1 + 8) = 0;
      *(_DWORD *)(a1 + 4) = 0;
    }
  }
  return result;
}
