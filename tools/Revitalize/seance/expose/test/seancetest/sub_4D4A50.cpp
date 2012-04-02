bool __fastcall sub_4D4A50(int a1, int a2)
{
  int v3; // [sp+Ch] [bp-14h]@1
  int v4; // [sp+10h] [bp-10h]@1
  unsigned __int8 v5; // [sp+14h] [bp-Ch]@3
  unsigned __int8 v6; // [sp+18h] [bp-8h]@3
  int i; // [sp+1Ch] [bp-4h]@1

  v3 = a2;
  v4 = a1;
  for ( i = 0; ; ++i )
  {
    if ( dword_5347A4 < i )
      return 0;
    v6 = *((_DWORD *)dword_51FDC0 + v4) >> 24;
    v5 = *((_DWORD *)dword_51FDC0 + v3) >> 24;
    if ( v5 != v6 )
      break;
    v4 = sub_4D3C90(v4 + 1);
    v3 = sub_4D3C90(v3 + 1);
  }
  return v5 < (signed int)v6;
}
