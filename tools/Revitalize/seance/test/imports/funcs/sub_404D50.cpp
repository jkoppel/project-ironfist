{
  unsigned __int16 v4; // [sp+Ch] [bp-Ch]@1
  int v5; // [sp+10h] [bp-8h]@1
  int v6; // [sp+14h] [bp-4h]@2

  v4 = a2;
  v5 = a1;
  sub_404EA0();
  if ( v5 == 127 )
    v6 = 0;
  else
    v6 = *((_DWORD *)&dword_522B78 + v5);
  sub_404C60(v6, 1, v4, a3);
  return 0;
}
