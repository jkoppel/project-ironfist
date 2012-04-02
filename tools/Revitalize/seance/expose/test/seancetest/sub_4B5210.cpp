bool __stdcall sub_4B5210(int a1, char a2, int a3)
{
  char v4; // [sp+18h] [bp-24h]@7
  char v5; // [sp+1Ch] [bp-20h]@7
  char v6; // [sp+20h] [bp-1Ch]@7
  char v7; // [sp+24h] [bp-18h]@7
  int v8; // [sp+28h] [bp-14h]@1
  int i; // [sp+2Ch] [bp-10h]@1
  float v10; // [sp+30h] [bp-Ch]@7
  int v11; // [sp+34h] [bp-8h]@7
  int v12; // [sp+38h] [bp-4h]@7

  v8 = dword_4F2050[a1];
  for ( i = 0; i < 5; ++i )
  {
    *((_BYTE *)dword_5247BC + i) = a2;
    if ( i )
      *(_WORD *)((char *)dword_5247BC + 2 * i + 5) = 0;
    else
      *(_WORD *)((char *)dword_5247BC + 5) = 1;
  }
  sub_4AF410(
    (int)&dword_51D5BC->army,
    (int)dword_51D5BC,
    (unsigned int)dword_5247BC,
    0,
    0,
    0,
    -1,
    (int)&v10,
    (int)&v7,
    (int *)&v6,
    (int *)&v5,
    (int *)&v4,
    &v12);
  v11 = (signed __int64)((double)v8 * v10 + (double)v12);
  return v11 > 0;
}
