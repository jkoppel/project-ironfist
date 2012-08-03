{
  double v4; // st7@34
  double v5; // ST18_8@37
  double v6; // ST10_8@37
  char *v7; // eax@37
  int result; // eax@39
  int v9; // [sp+24h] [bp-38h]@1
  int v10; // [sp+28h] [bp-34h]@30
  int v11; // [sp+2Ch] [bp-30h]@3
  int v12; // [sp+30h] [bp-2Ch]@5
  float v13; // [sp+34h] [bp-28h]@34
  float v14; // [sp+38h] [bp-24h]@1
  int creature; // [sp+3Ch] [bp-20h]@3
  int v16; // [sp+40h] [bp-1Ch]@30
  int j; // [sp+44h] [bp-18h]@5
  int v18; // [sp+48h] [bp-14h]@29
  int i; // [sp+4Ch] [bp-10h]@1
  unsigned __int64 v20; // [sp+50h] [bp-Ch]@1
  int v21; // [sp+58h] [bp-4h]@1

  v9 = (int)this;
  v20 = 4294967295i64;
  v21 = -1027211264;
  v14 = -99.0;
  for ( i = 0; i < 12; ++i )
  {
    creature = gDwellingType[*(_BYTE *)(a1 + 3)][i];
    v11 = 999999;
    if ( (1 << (i + 19)) & *(_DWORD *)(a1 + 24) && (signed int)*(_WORD *)(a1 + 2 * i + 30) > 0 )
    {
      v12 = 0;
      for ( j = 0; j < 5; ++j )
      {
        if ( *(_BYTE *)(j + a1 + 8) == -1 || *(_BYTE *)(j + a1 + 8) == creature )
          v12 = 1;
      }
      for ( j = 0; j < 5; ++j )
      {
        if ( *(_BYTE *)(j + a1 + 8) != -1 && gMonsterDatabase[*(_BYTE *)(j + a1 + 8)].fight_value < v11 )
          v11 = gMonsterDatabase[*(_BYTE *)(j + a1 + 8)].fight_value;
      }
      if ( gMonsterDatabase[creature].fight_value > v11 && gMonsterDatabase[creature].fight_value > 1000 )
        v12 = 1;
      if ( !i
        && *(_BYTE *)(a1 + 23) != -1
        && (*(_BYTE *)(a1 + 27) & 0x10
         || *(_BYTE *)(a1 + 26) & 0x80
         || *(_BYTE *)(a1 + 27) & 0x20
         || *(_BYTE *)(a1 + 27) & 0x40
         || *(_BYTE *)(a1 + 27) & 1) )
        v12 = 0;
      if ( v12 )
      {
        v18 = philAI::CreaturesToBuy(v9, (town *)a1, i);
        if ( v18 > 0 )
        {
          philAI::ValueOfBuyingCreature(a1, creature, (int)&v10, v18, (int)&v16);
          if ( !gpCurPlayer->personality )
            v10 = (signed __int64)((double)v10 * 1.3);
          if ( *(_BYTE *)(a1 + 2) )
            v10 *= 2;
          v4 = (double)(Random(1, 10) + 90) * *(float *)&v16 / 100.0;
          v13 = v4;
          if ( v4 > v14 )
          {
            v20 = __PAIR__(v18, i);
            v21 = v16;
            v14 = v13;
          }
          if ( giDebugLevel >= 5 )
          {
            v5 = v13;
            v6 = *(float *)&v16;
            v7 = GetMonsterName(creature);
            sprintf(
              gText,
              "Town:%2d  Creature: % 18s   Raw BC = %8.2f,  RandBC = %8.2f.",
              *(_BYTE *)a1,
              v7,
              *(_QWORD *)&v6,
              *(_QWORD *)&v5);
            LogStr(gText);
          }
        }
      }
    }
  }
  *(_DWORD *)a2 = a1;
  *(_DWORD *)(a2 + 4) = 2;
  *(_QWORD *)(a2 + 8) = v20;
  result = a3;
  *(_DWORD *)a3 = v21;
  return result;
}