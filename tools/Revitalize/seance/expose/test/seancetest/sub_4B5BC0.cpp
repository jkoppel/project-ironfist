signed int __stdcall sub_4B5BC0(int a1, char a2, int a3, int a4)
{
  signed int result; // eax@12
  int v5; // [sp+10h] [bp-14h]@8
  signed int i; // [sp+14h] [bp-10h]@2
  int j; // [sp+14h] [bp-10h]@5
  signed int k; // [sp+14h] [bp-10h]@8
  char v9; // [sp+18h] [bp-Ch]@8
  char v10; // [sp+1Ch] [bp-8h]@8
  int v11; // [sp+20h] [bp-4h]@8

  memset(dword_5247BC, -1, 5u);
  memset((char *)dword_5247BC + 5, 0, 0xAu);
  if ( *(_DWORD *)a3 / 5 > 0 )
  {
    for ( i = 0; i < 5; ++i )
    {
      *((_BYTE *)dword_5247BC + i) = a2;
      *(_WORD *)((char *)dword_5247BC + 2 * i + 5) = *(_DWORD *)a3 / 5;
    }
  }
  for ( j = *(_DWORD *)a3 % 5 - 1; j >= 0; --j )
  {
    *((_BYTE *)dword_5247BC + j) = a2;
    ++*(_WORD *)((char *)dword_5247BC + 2 * j + 5);
  }
  v11 = sub_4B38C0(a1 + 101, a1, (unsigned int)dword_5247BC, 0, 0, (float *)&v10, (float *)&v9);
  v5 = 0;
  for ( k = 0; k < 5; ++k )
    v5 += *(_WORD *)((char *)dword_5247BC + 2 * k + 5);
  *(_DWORD *)a3 = v5;
  if ( v11 )
    result = 1;
  else
    result = 0;
  return result;
}
