{
  int result; // eax@1
  int v3; // ebx@1
  int v4; // esi@1
  int v5; // esi@3

  while ( 1 )
  {
    result = a1;
    v3 = *(_DWORD *)(a1 + 8);
    v4 = *(_DWORD *)(a1 + 12);
    if ( v4 == -1 || v4 == a2 )
      break;
    v5 = 3 * v4;
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v3 + 4 * v5);
    if ( !*(_DWORD *)(v3 + 4 * v5 + 4) )
    {
      _NLG_Notify(257);
      (*(void (**)(void))(v3 + 4 * v5 + 8))();
    }
  }
  return result;
}
