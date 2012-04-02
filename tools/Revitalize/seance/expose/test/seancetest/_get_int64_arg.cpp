int __cdecl get_int64_arg(int a1)
{
  int v1; // ecx@1

  v1 = *(_DWORD *)a1 + 8;
  *(_DWORD *)a1 = v1;
  return *(_DWORD *)(v1 - 8);
}
