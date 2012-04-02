int __thiscall sub_4D27E0(int this)
{
  int result; // eax@2
  int v2; // [sp+Ch] [bp-8h]@1
  int v3; // [sp+10h] [bp-4h]@3

  v2 = this;
  if ( *(_DWORD *)(this + 8) <= 0 )
  {
    v3 = getc(*(FILE **)this);
    if ( v3 == -1 )
      sub_4D5F10();
    *(_DWORD *)(v2 + 8) = 7;
    *(_DWORD *)(v2 + 4) = v3;
    if ( *(_DWORD *)(v2 + 4) == -1 )
      sub_4D6030();
    result = (*(_DWORD *)(v2 + 4) >> 7) & 1;
  }
  else
  {
    --*(_DWORD *)(this + 8);
    result = (*(_DWORD *)(this + 4) >> *(_BYTE *)(this + 8)) & 1;
  }
  return result;
}
