{
  if ( __addl(*(_DWORD *)a1, *(_DWORD *)a2, a1) && __addl(*(_DWORD *)(a1 + 4), 1, a1 + 4) )
    ++*(_DWORD *)(a1 + 8);
  if ( __addl(*(_DWORD *)(a1 + 4), *(_DWORD *)(a2 + 4), a1 + 4) )
    ++*(_DWORD *)(a1 + 8);
  return __addl(*(_DWORD *)(a1 + 8), *(_DWORD *)(a2 + 8), a1 + 8);
}
