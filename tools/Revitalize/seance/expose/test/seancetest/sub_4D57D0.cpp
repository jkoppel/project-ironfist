void __fastcall sub_4D57D0(FILE *a1, int a2)
{
  int v2; // [sp+Ch] [bp-28h]@1
  FILE *v3; // [sp+10h] [bp-24h]@1
  signed int i; // [sp+14h] [bp-20h]@11
  int v5; // [sp+1Ch] [bp-18h]@4
  int v6; // [sp+20h] [bp-14h]@4
  int v7; // [sp+24h] [bp-10h]@6
  int v8; // [sp+28h] [bp-Ch]@4
  signed int v9; // [sp+2Ch] [bp-8h]@4
  int v10; // [sp+30h] [bp-4h]@2

  v2 = a2;
  v3 = a1;
  if ( a2 )
    v10 = dword_5347A4 - 1;
  else
    v10 = dword_5347A4;
  v9 = 0;
  v6 = 0;
  v5 = 256;
  v8 = sub_4D2630();
  while ( v6 <= v10 )
  {
    v7 = v5;
    v5 = *((_BYTE *)dword_51FDCC + v6++);
    if ( putc(v5, v3) == -1 )
      sub_4D5F60();
    v8 = (v8 << 8) ^ dword_51F9C0[((unsigned int)v8 >> 24) ^ (unsigned __int8)v5];
    if ( v5 == v7 )
    {
      ++v9;
      if ( v9 >= 4 )
      {
        for ( i = 0; *((_BYTE *)dword_51FDCC + v6) > i; ++i )
        {
          if ( putc(v5, v3) == -1 )
            sub_4D5F60();
          v8 = (v8 << 8) ^ dword_51F9C0[((unsigned int)v8 >> 24) ^ (unsigned __int8)v5];
        }
        ++v6;
        v9 = 0;
      }
    }
    else
    {
      v9 = 1;
    }
  }
  sub_4D2650((void *)v8);
  if ( v2 && *((_BYTE *)dword_51FDCC + dword_5347A4) != 42 )
    sub_4D5FF0();
}
