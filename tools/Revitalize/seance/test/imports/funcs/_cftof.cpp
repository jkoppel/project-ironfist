{
  int v4; // [sp+8h] [bp-28h]@1
  int v5; // [sp+Ch] [bp-24h]@1
  char v6; // [sp+18h] [bp-18h]@1

  _fltout2(*(_DWORD *)a1, *(_DWORD *)(a1 + 4), &v4, &v6);
  _fptostr((char *)a2 + ((unsigned int)(v4 - 45) < 1), a3 + v5, &v4);
  _cftof2(a2, a3, &v4, 0);
  return a2;
}
