{
  int v5; // [sp+10h] [bp-14h]@8
  signed int i; // [sp+14h] [bp-10h]@2
  int j; // [sp+14h] [bp-10h]@5
  signed int k; // [sp+14h] [bp-10h]@8
  char v9; // [sp+18h] [bp-Ch]@8
  char v10; // [sp+1Ch] [bp-8h]@8
  int v11; // [sp+20h] [bp-4h]@8

  memset(gpMonGroup, 0xFFu, 5u);
  memset((char *)gpMonGroup + 5, 0, 0xAu);
  if ( *(_DWORD *)a3 / 5 > 0 )
  {
    for ( i = 0; i < 5; ++i )
    {
      *((_BYTE *)gpMonGroup + i) = a2;
      *(_WORD *)((char *)gpMonGroup + 2 * i + 5) = *(_DWORD *)a3 / 5;
    }
  }
  for ( j = *(_DWORD *)a3 % 5 - 1; j >= 0; --j )
  {
    *((_BYTE *)gpMonGroup + j) = a2;
    ++*(_WORD *)((char *)gpMonGroup + 2 * j + 5);
  }
  v11 = philAI::QuickCombat(a1 + 101, a1, (unsigned int)gpMonGroup, 0, 0, (float *)&v10, (float *)&v9);
  v5 = 0;
  for ( k = 0; k < 5; ++k )
    v5 += *(_WORD *)((char *)gpMonGroup + 2 * k + 5);
  *(_DWORD *)a3 = v5;
  return v11 != 0;
}