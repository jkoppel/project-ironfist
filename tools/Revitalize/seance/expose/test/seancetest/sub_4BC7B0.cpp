int __fastcall sub_4BC7B0(int a1, int a2)
{
  int result; // eax@2

  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)a2 = *(_DWORD *)(a2 + 4);
  if ( *(_DWORD *)(a1 + 4) )
  {
    *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) = a2;
    *(_DWORD *)a2 = *(_DWORD *)(a1 + 4);
    result = a2;
    *(_DWORD *)(a1 + 4) = a2;
  }
  else
  {
    *(_DWORD *)(a1 + 4) = a2;
    result = *(_DWORD *)(a1 + 4);
    *(_DWORD *)a1 = result;
  }
  return result;
}
