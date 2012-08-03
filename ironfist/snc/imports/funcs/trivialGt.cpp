{
  int v3; // [sp+Ch] [bp-14h]@1
  int v4; // [sp+10h] [bp-10h]@1
  unsigned __int8 v5; // [sp+14h] [bp-Ch]@3
  unsigned __int8 v6; // [sp+18h] [bp-8h]@3
  int i; // [sp+1Ch] [bp-4h]@1

  v3 = a2;
  v4 = a1;
  for ( i = 0; last >= i; ++i )
  {
    v6 = *((_DWORD *)words + v4) >> 24;
    v5 = *((_DWORD *)words + v3) >> 24;
    if ( v5 != v6 )
      return v5 < (signed int)v6;
    v4 = NORMALISEHI(v4 + 1);
    v3 = NORMALISEHI(v3 + 1);
  }
  return 0;
}