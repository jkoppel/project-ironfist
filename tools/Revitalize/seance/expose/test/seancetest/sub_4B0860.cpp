int __stdcall sub_4B0860(int a1, int a2, int a3)
{
  double v3; // st7@34
  double v4; // ST18_8@37
  double v5; // ST10_8@37
  char *v6; // eax@37
  int result; // eax@39
  int v8; // [sp+28h] [bp-34h]@30
  int v9; // [sp+2Ch] [bp-30h]@3
  int v10; // [sp+30h] [bp-2Ch]@5
  float v11; // [sp+34h] [bp-28h]@34
  float v12; // [sp+38h] [bp-24h]@1
  int creature; // [sp+3Ch] [bp-20h]@3
  int v14; // [sp+40h] [bp-1Ch]@30
  int j; // [sp+44h] [bp-18h]@5
  int v16; // [sp+48h] [bp-14h]@29
  int i; // [sp+4Ch] [bp-10h]@1
  int v18; // [sp+50h] [bp-Ch]@1
  int v19; // [sp+54h] [bp-8h]@1
  int v20; // [sp+58h] [bp-4h]@1

  v18 = -1;
  v19 = 0;
  v20 = -1027211264;
  v12 = -99.0;
  for ( i = 0; i < 12; ++i )
  {
    creature = dwelling_creatures[*(_BYTE *)(a1 + 3)][i];
    v9 = 999999;
    if ( (1 << (i + 19)) & *(_DWORD *)(a1 + 24) && (signed int)*(_WORD *)(a1 + 2 * i + 30) > 0 )
    {
      v10 = 0;
      for ( j = 0; j < 5; ++j )
      {
        if ( *(_BYTE *)(j + a1 + 8) == -1 || *(_BYTE *)(j + a1 + 8) == creature )
          v10 = 1;
      }
      for ( j = 0; j < 5; ++j )
      {
        if ( *(_BYTE *)(j + a1 + 8) != -1 && creature_table[*(_BYTE *)(j + a1 + 8)].fight_value < v9 )
          v9 = creature_table[*(_BYTE *)(j + a1 + 8)].fight_value;
      }
      if ( creature_table[creature].fight_value > v9 && creature_table[creature].fight_value > 1000 )
        v10 = 1;
      if ( !i
        && *(_BYTE *)(a1 + 23) != -1
        && (*(_BYTE *)(a1 + 27) & 0x10
         || *(_BYTE *)(a1 + 26) & 0x80
         || *(_BYTE *)(a1 + 27) & 0x20
         || *(_BYTE *)(a1 + 27) & 0x40
         || *(_BYTE *)(a1 + 27) & 1) )
        v10 = 0;
      if ( v10 )
      {
        v16 = sub_4B0BA0(a1, i);
        if ( v16 > 0 )
        {
          sub_4B0560(a1, creature, (int)&v8, v16, (int)&v14);
          if ( !curPlayer->personality )
            v8 = (signed __int64)((double)v8 * 1.3);
          if ( *(_BYTE *)(a1 + 2) )
            v8 *= 2;
          v3 = (double)(unseededNextRand(1, 10) + 90) * *(float *)&v14 / 100.0;
          v11 = v3;
          if ( v3 > v12 )
          {
            v18 = i;
            v20 = v14;
            v12 = v11;
            v19 = v16;
          }
          if ( debugLogLevel >= 5 )
          {
            v4 = v11;
            v5 = *(float *)&v14;
            v6 = getCreatureSingularName(creature);
            sprintf(
              globBuf,
              "Town:%2d  Creature: % 18s   Raw BC = %8.2f,  RandBC = %8.2f.",
              *(_BYTE *)a1,
              v6,
              *(_QWORD *)&v5,
              *(_QWORD *)&v4);
            debugLog(globBuf);
          }
        }
      }
    }
  }
  *(_DWORD *)a2 = a1;
  *(_DWORD *)(a2 + 4) = 2;
  *(_DWORD *)(a2 + 8) = v18;
  *(_DWORD *)(a2 + 12) = v19;
  result = a3;
  *(_DWORD *)a3 = v20;
  return result;
}
