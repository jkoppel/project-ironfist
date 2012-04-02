int __fastcall sub_4D2D40(int a1, int a2)
{
  int v3; // [sp+Ch] [bp-24h]@1
  int v4; // [sp+10h] [bp-20h]@1
  unsigned int v5; // [sp+18h] [bp-18h]@1
  unsigned int i; // [sp+1Ch] [bp-14h]@1
  unsigned int v7; // [sp+20h] [bp-10h]@1
  unsigned int v8; // [sp+24h] [bp-Ch]@1
  int v9; // [sp+28h] [bp-8h]@1
  int v10; // [sp+2Ch] [bp-4h]@4

  v3 = a2;
  v4 = a1;
  v8 = *(_DWORD *)(a2 + 8);
  v7 = dword_534FF4 / v8;
  v5 = sub_4D2A10(v8 - 1, dword_534FEC / dword_534FF4 / v8);
  v9 = 0;
  for ( i = 0; v5 >= i; i += *(_DWORD *)(v3 + 4 * v9 + 28) )
    ++v9;
  v10 = i - *(_DWORD *)(v3 + 4 * v9 + 28);
  dword_534FEC -= v10 * v7;
  if ( v8 <= i )
    dword_534FF4 -= v10 * v7;
  else
    dword_534FF4 = v7 * (i - v10);
  while ( (unsigned int)dword_534FF4 <= 0x1000000 )
  {
    dword_534FF4 *= 2;
    dword_534FEC = sub_4D27E0(v4) + 2 * dword_534FEC;
  }
  return v9;
}
