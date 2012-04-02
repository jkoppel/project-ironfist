// Microsoft VisualC 2-8/net runtime
// __except_handler3
signed int __usercall unknown_libname_81<eax>(int a1<ebp>, int a2, int a3, int a4)
{
  int v4; // ebx@1
  int v5; // eax@1
  int v6; // esi@2
  int v7; // edi@2
  int v8; // eax@5
  int v9; // edi@7
  int v10; // ecx@7
  signed int result; // eax@9

  v4 = *(_DWORD *)(a1 + 12);
  v5 = *(_DWORD *)(a1 + 8);
  if ( *(_DWORD *)(v5 + 4) & 6 )
  {
    _local_unwind2(v4, -1);
    result = 1;
  }
  else
  {
    *(_DWORD *)(a1 - 8) = v5;
    *(_DWORD *)(a1 - 4) = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(v4 - 4) = a1 - 8;
    v6 = *(_DWORD *)(v4 + 12);
    v7 = *(_DWORD *)(v4 + 8);
    while ( v6 != -1 )
    {
      if ( *(_DWORD *)(v7 + 12 * v6 + 4) )
      {
        v8 = (*(int (**)(void))(v7 + 12 * v6 + 4))();
        v4 = *(_DWORD *)(a1 + 12);
        if ( v8 )
        {
          if ( v8 < 0 )
            return 0;
          v9 = *(_DWORD *)(v4 + 8);
          _global_unwind2(*(PVOID *)(a1 + 12));
          a1 = v4 + 16;
          _local_unwind2(v4, v6);
          _NLG_Notify(*(_DWORD *)(v9 + 12 * v6 + 8), v4 + 16, 1);
          *(_DWORD *)(v4 + 12) = *(_DWORD *)(v9 + 4 * v10);
          (*(void (**)(void))(v9 + 4 * v10 + 8))();
        }
      }
      v7 = *(_DWORD *)(v4 + 8);
      v6 = *(_DWORD *)(v7 + 12 * v6);
    }
    result = 1;
  }
  return result;
}
