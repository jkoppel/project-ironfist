{
  signed int v4; // ecx@1
  int v6; // [sp+8h] [bp-28h]@1
  char v7; // [sp+18h] [bp-18h]@1

  _fltout2(*(_DWORD *)a1, *(_DWORD *)(a1 + 4), &v6, &v7);
  v4 = 1;
  if ( a3 <= 0 )
    v4 = 0;
  _fptostr(a2 + ((unsigned int)(v6 - 45) < 1) + v4, a3 + 1, &v6);
  _cftoe2(a2, a3, a4, &v6, 0);
  return a2;
}
