{
  int result; // eax@1
  signed int i; // [sp+14h] [bp-4h]@2

  *(_DWORD *)(a1 + 8) += *(_DWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 4 * a2 + 28) += *(_DWORD *)(a1 + 16);
  result = a1;
  if ( *(_DWORD *)(a1 + 20) < *(_DWORD *)(a1 + 8) )
  {
    *(_DWORD *)(a1 + 8) = 0;
    ++*(_DWORD *)a1;
    for ( i = 1; ; ++i )
    {
      result = a1;
      if ( *(_DWORD *)(a1 + 12) < (unsigned int)i )
        break;
      *(_DWORD *)(a1 + 4 * i + 28) = (unsigned int)(*(_DWORD *)(a1 + 4 * i + 28) + 1) >> 1;
      *(_DWORD *)(a1 + 8) += *(_DWORD *)(a1 + 4 * i + 28);
    }
  }
  return result;
}