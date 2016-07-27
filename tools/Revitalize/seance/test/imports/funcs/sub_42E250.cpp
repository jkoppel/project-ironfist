{
  int v2; // edx@3
  int v4; // [sp+Ch] [bp-10h]@1
  signed int i; // [sp+14h] [bp-8h]@1
  int v6; // [sp+18h] [bp-4h]@3

  v4 = a2;
  for ( i = 0; *(_WORD *)&gameObject->_10[510] > i; ++i )
  {
    v2 = *(_WORD *)&gameObject->_10[2 * i + 512];
    v6 = *((_DWORD *)dword_524784 + v2);
    if ( *(_WORD *)(v6 + 38) == a1
      && *(_WORD *)(v6 + 40) == v4
      && *(_BYTE *)(v6 + 37)
      && *(_BYTE *)(gameObject->players[(char)curPlayerIdx].color + v6 + 43) )
      return *((_DWORD *)dword_524784 + v2);
  }
  return 0;
}
