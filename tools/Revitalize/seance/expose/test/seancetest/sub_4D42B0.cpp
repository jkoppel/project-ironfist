int __cdecl sub_4D42B0()
{
  int result; // eax@2
  unsigned __int8 v1; // ST0C_1@3
  int v2; // eax@3
  int v3; // eax@3
  int v4; // eax@3
  int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; ; ++i )
  {
    result = i;
    if ( dword_5347A0 <= i )
      break;
    v1 = *((_DWORD *)dword_51FDC0 + i) >> 24;
    v2 = sub_4D3CD0(i - 1);
    sub_4D3BD0(v2, v1);
    v3 = sub_4D3CD0(i - 2);
    sub_4D3C10(v3, v1);
    v4 = sub_4D3CD0(i - 3);
    sub_4D3C50(v4, v1);
  }
  return result;
}
