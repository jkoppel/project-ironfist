signed int __stdcall sub_42D980(int a1, int a2)
{
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; *(_BYTE *)(a1 + 1) > i; ++i )
  {
    if ( *(_BYTE *)(i + a1 + 4) == a2 )
      return i;
  }
  return -1;
}
