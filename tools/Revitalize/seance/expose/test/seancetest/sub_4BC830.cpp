int __thiscall sub_4BC830(int this)
{
  int v2; // [sp+10h] [bp-4h]@1

  v2 = *(_DWORD *)this;
  if ( *(_DWORD *)this )
    *(_DWORD *)this = *(_DWORD *)(v2 + 4);
  if ( !*(_DWORD *)this )
    *(_DWORD *)(this + 4) = 0;
  return v2;
}
