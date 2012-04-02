__int16 __cdecl get_short_arg(int a1)
{
  int v1; // ecx@1

  v1 = *(_DWORD *)a1 + 4;
  *(_DWORD *)a1 = v1;
  return *(_WORD *)(v1 - 4);
}
