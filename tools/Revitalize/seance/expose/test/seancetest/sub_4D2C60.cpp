void __fastcall sub_4D2C60(void *a1, int a2, signed int a3)
{
  int v3; // [sp+18h] [bp-14h]@4
  unsigned int v4; // [sp+20h] [bp-Ch]@1
  signed int i; // [sp+24h] [bp-8h]@1
  int v6; // [sp+28h] [bp-4h]@1

  v4 = *(_DWORD *)(a2 + 8);
  v6 = 0;
  for ( i = 1; a3 > i; ++i )
    v6 += *(_DWORD *)(a2 + 4 * i + 28);
  v3 = v6 + *(_DWORD *)(a2 + 4 * a3 + 28);
  dword_534FF0 += v6 * (dword_534FF4 / v4);
  if ( v4 <= v3 )
    dword_534FF4 -= v6 * (dword_534FF4 / v4);
  else
    dword_534FF4 = dword_534FF4 / v4 * (v3 - v6);
  sub_4D2BC0(a1);
  if ( (unsigned int)dword_5347AC > 0x1DCD6500 )
    unknown_libname_27();
}
