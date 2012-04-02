int __fastcall sub_45F7F0(int a1, unsigned __int16 a2, const void *a3)
{
  unsigned __int16 v4; // [sp+Ch] [bp-Ch]@1
  int v5; // [sp+10h] [bp-8h]@1

  v4 = a2;
  v5 = a1;
  sub_45F910();
  if ( v5 == 127 )
    sub_45F5F0(0, 1, v4, a3);
  else
    sub_45F5F0(*((_DWORD *)&dword_522B78 + v5), 1, v4, a3);
  return 0;
}
