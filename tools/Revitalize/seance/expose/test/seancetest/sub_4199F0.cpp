signed int __stdcall sub_4199F0(int a1, int a2, int a3, int a4, char a5)
{
  signed int i; // [sp+10h] [bp-8h]@1
  int v7; // [sp+14h] [bp-4h]@3

  for ( i = 0; i < 10000; ++i )
  {
    v7 = unseededNextRand(0, a3 - 1) + a2;
    if ( *(_BYTE *)(v7 + a1) == a5 )
      return v7;
  }
  return -1;
}
