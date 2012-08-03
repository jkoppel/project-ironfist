{
  double v5; // st7@21
  double v6; // st7@21
  signed __int64 v7; // qax@21
  int result; // eax@21
  signed int j; // [sp+40h] [bp-50h]@14
  signed int i; // [sp+44h] [bp-4Ch]@5
  char *v11; // [sp+48h] [bp-48h]@2
  signed int v12; // [sp+4Ch] [bp-44h]@1
  char v13; // [sp+50h] [bp-40h]@21
  char v14; // [sp+54h] [bp-3Ch]@21
  float v15; // [sp+58h] [bp-38h]@21
  char v16; // [sp+5Ch] [bp-34h]@21
  char v17; // [sp+60h] [bp-30h]@21
  int v18; // [sp+64h] [bp-2Ch]@1
  char v19; // [sp+68h] [bp-28h]@21
  int costs; // [sp+6Ch] [bp-24h]@1
  float v21; // [sp+88h] [bp-8h]@21
  int v22; // [sp+8Ch] [bp-4h]@1

  v12 = 0;
  getCreatureCosts(a2, &costs);
  v18 = a4 * (unsigned __int64)philAI::RVConversion((int)&costs);
  v22 = (signed __int64)((double)(a4 * gMonsterDatabase[a2].fight_value) * *(float *)&gpCurPlayer->_4[100]);
  if ( *(_BYTE *)(a1 + 23) != -1 )
  {
    v11 = (char *)&gpGame->heroes[*(_BYTE *)(a1 + 23)];
    v22 = (signed __int64)((double)v22 * 1.1);
    if ( gMonsterDatabase[a2].faction == (unsigned __int8)v11[23] )
      v22 = (signed __int64)((double)v22 * 1.1);
    if ( gMonsterDatabase[a2].creature_flags & 4 )
    {
      for ( i = 0; i < 5; ++i )
      {
        if ( v11[i + 101] != -1 )
        {
          if ( gMonsterDatabase[v11[i + 101]].creature_flags & 4 )
            ++v12;
        }
      }
      v22 = (signed __int64)((1.18 - (double)v12 * 0.06) * (double)v22);
    }
    v22 = (signed __int64)((*(float *)&gpGame->players[*(_BYTE *)(a1 + 1)]._4[24] + 0.66) * (double)v22);
  }
  if ( gMonsterDatabase[a2].creature_flags & 4 )
  {
    for ( j = 0; j < 5; ++j )
    {
      if ( *(_BYTE *)(j + a1 + 8) != -1 && gMonsterDatabase[*(_BYTE *)(j + a1 + 8)].creature_flags & 4 )
        ++v12;
    }
    v22 = (signed __int64)((1.18 - (double)v12 * 0.06) * (double)v22);
  }
  philAI::LikelihoodOfEnemyAttacking(a1, 0, (int)&v19, (int)&v17, (int)&v16, (int)&v14, (int)&v13, (int)&v21);
  v5 = v21 + 0.96;
  v15 = v5;
  v22 = (signed __int64)(v5 * v15 * v15 * (double)v22);
  v6 = philAI::FutureDeflator((int)&costs);
  v7 = (signed __int64)(v6 * (double)v22);
  v22 = v7;
  *(_DWORD *)a3 = v7;
  result = a5;
  *(float *)a5 = (double)*(signed int *)a3 / (double)v18;
  return result;
}