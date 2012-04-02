void __stdcall sub_4B43E0(int a1, signed int a2, int a3, int a4)
{
  int v4; // ebx@4
  int v5; // ebx@14
  int v6; // ebx@44
  double v7; // st7@73
  float v8; // ST54_4@73
  float v9; // [sp+28h] [bp-5Ch]@62
  signed int v10; // [sp+2Ch] [bp-58h]@39
  signed int v11; // [sp+30h] [bp-54h]@75
  float v12; // [sp+34h] [bp-50h]@71
  int v13; // [sp+3Ch] [bp-48h]@73
  int v14; // [sp+40h] [bp-44h]@111
  float v15; // [sp+44h] [bp-40h]@44
  signed int j; // [sp+48h] [bp-3Ch]@35
  int v17; // [sp+4Ch] [bp-38h]@108
  signed int n; // [sp+50h] [bp-34h]@90
  float v19; // [sp+54h] [bp-30h]@47
  int v20; // [sp+58h] [bp-2Ch]@4
  int v21; // [sp+58h] [bp-2Ch]@14
  signed int k; // [sp+58h] [bp-2Ch]@76
  signed int l; // [sp+58h] [bp-2Ch]@82
  signed int m; // [sp+58h] [bp-2Ch]@88
  int i; // [sp+5Ch] [bp-28h]@33
  int v26; // [sp+60h] [bp-24h]@44
  float v27; // [sp+64h] [bp-20h]@64
  int v28; // [sp+68h] [bp-1Ch]@44
  int v29; // [sp+70h] [bp-14h]@67
  int v30; // [sp+74h] [bp-10h]@111
  int v31; // [sp+7Ch] [bp-8h]@105
  signed int v32; // [sp+80h] [bp-4h]@44

  *(_DWORD *)a4 = 0;
  if ( a3 )
  {
    if ( *(_BYTE *)(a2 + 24) & 8 && *(_BYTE *)a2 != dword_5305CC )
    {
      v4 = abs(*(_BYTE *)(a2 + 4) - *(_DWORD *)(a1 + 25));
      v20 = abs(*(_BYTE *)(a2 + 5) - *(_DWORD *)(a1 + 29)) + v4;
      if ( dword_532CE8 )
      {
        if ( v20 < dword_5304E0 )
        {
          dword_5304E0 = v20;
          dword_5305CC = *(_BYTE *)a2;
        }
      }
      else
      {
        dword_5304E0 = v20;
        dword_5305CC = *(_BYTE *)a2;
      }
      dword_5306E0 = 1;
      dword_532CE8 = 1;
    }
    else
    {
      if ( *(_BYTE *)(a2 + 24) & 0x40
        && !tileToTerrainType[*(_WORD *)usedToCheckForBoatByCastle(
                                          advManager,
                                          *(_BYTE *)(a2 + 4) - 1,
                                          *(_BYTE *)(a2 + 5) + 1)]
        && !dword_532CE8
        && *(_BYTE *)a2 != dword_5305CC )
      {
        v5 = abs(*(_BYTE *)(a2 + 4) - *(_DWORD *)(a1 + 25));
        v21 = abs(*(_BYTE *)(a2 + 5) - *(_DWORD *)(a1 + 29)) + v5;
        if ( dword_5306E0 )
        {
          if ( v21 < dword_5304E0 )
          {
            dword_5304E0 = v21;
            dword_5305CC = *(_BYTE *)a2;
          }
        }
        else
        {
          dword_5304E0 = v21;
          dword_5305CC = *(_BYTE *)a2;
        }
        dword_5306E0 = 1;
      }
    }
  }
  else
  {
    *(_WORD *)(a1 + 7) = dword_532C54;
    *(_BYTE *)(a1 + 9) = *(_BYTE *)a2;
    if ( !Hero::hasArtifact((Hero *)a1, ARTIFACT_MAGIC_BOOK) && *(_BYTE *)(a2 + 24) & 1 )
    {
      if ( curPlayer->resources[6] < 500 )
      {
        *(_DWORD *)(a1 + 53) = 0;
      }
      else
      {
        grantArtifact((Hero *)a1, ARTIFACT_MAGIC_BOOK, 1, -1);
        curPlayer->resources[6] -= 500;
      }
    }
    if ( *(_BYTE *)(a2 + 24) & 1
      && Hero::hasArtifact((Hero *)a1, ARTIFACT_MAGIC_BOOK)
      && 10 * Hero::getPrimarySkill((Hero *)a1, PRIMARY_SKILL_KNOWLEDGE) > *(_WORD *)a1 )
      *(_DWORD *)(a1 + 53) = 0;
  }
  if ( *(_BYTE *)(a2 + 24) & 1 && (a3 || Hero::hasArtifact((Hero *)a1, ARTIFACT_MAGIC_BOOK)) )
  {
    *(_DWORD *)a4 += sub_4B6AC0(a1, 1);
    for ( i = 1; *(_BYTE *)(a1 + 123) + 2 >= i; ++i )
    {
      for ( j = 0; *(_BYTE *)(i + a2 + 79) > j; ++j )
      {
        if ( !Hero::hasSpell((Hero *)a1, (Spell)*(_BYTE *)(j + 4 * i - 4 + a2 + 60)) )
        {
          if ( spell_table[*(_BYTE *)(j + 4 * i - 4 + a2 + 60)].attributes & 1 )
            v10 = Hero::getPrimarySkill((Hero *)a1, PRIMARY_SKILL_KNOWLEDGE);
          else
            v10 = 1;
          *(_DWORD *)a4 += v10 * *(_WORD *)&spell_table[*(_BYTE *)(j + 4 * i - 4 + a2 + 60)].appearingChance;
        }
      }
    }
  }
  v28 = getArmyStrength((ArmyInfo *)(a1 + 101), 0, 0, 0, 0, 0);
  v32 = getArmyStrength((ArmyInfo *)(a2 + 8), 0, 0, 0, 0, 0);
  v15 = (double)v32 / (double)(v32 + v28);
  v6 = Hero::getPrimarySkill((Hero *)a1, 0);
  v26 = Hero::getPrimarySkill((Hero *)a1, PRIMARY_SKILL_DEFENSE) + v6;
  if ( v26 > 10 )
    v26 = 10;
  if ( *(_BYTE *)(a2 + 24) & 0x40 )
    v19 = 0.54 - (double)v26 * 0.02;
  else
    v19 = 0.33 - (double)v26 * 0.01;
  if ( dword_532C54 > 7 )
  {
    if ( dword_532C54 > 14 )
    {
      if ( dword_532C54 <= 21 )
        v19 = v19 * 0.8;
    }
    else
    {
      v19 = v19 * 0.5;
    }
  }
  else
  {
    v19 = *(float *)&dword_51D58C;
  }
  if ( *(_BYTE *)(a1 + 2) == dword_530734 )
    v19 = v19 * 0.5;
  if ( gameObject->winConditionType == 1
    && gameObject->winConditionArgument == *(_BYTE *)(a2 + 4)
    && *(_WORD *)&gameObject->field_2D5 == *(_BYTE *)(a2 + 5) )
    v19 = 0.80000001;
  if ( v19 < (double)v15 )
    v9 = v15 - v19;
  else
    v9 = v19 - v15;
  v27 = v9;
  if ( v19 * 0.15 <= v9 && v9 >= 0.08 )
  {
    v29 = 0;
    if ( v19 < (double)v15 )
      v29 = 1;
    if ( a3 )
    {
      if ( v28 >= v32 )
        v12 = 0.13;
      else
        v12 = 0.25;
      v7 = v9 + 1.0 - 0.22;
      v8 = v7;
      v13 = (signed __int64)((v7 * v8 - 1.0) * *(float *)&curPlayer->_4[100] * (double)(v32 + v28) * v12);
      if ( v13 < 0 )
        v13 = 0;
      v11 = 0;
      if ( v29 )
      {
        for ( k = 0; k < 5; ++k )
        {
          if ( (signed int)*(_WORD *)(a1 + 2 * k + 106) <= 0 )
            v11 = 1;
        }
      }
      else
      {
        for ( l = 0; l < 5; ++l )
        {
          if ( (signed int)*(_WORD *)(a2 + 2 * l + 13) <= 0 )
            v11 = 1;
        }
      }
      if ( !v11 )
      {
        for ( m = 0; m < 5; ++m )
        {
          for ( n = 0; n < 5; ++n )
          {
            if ( *(_BYTE *)(n + a1 + 101) == *(_BYTE *)(m + a2 + 8) )
            {
              v11 = 1;
              break;
            }
          }
        }
      }
      if ( !v11 )
        v13 = 0;
      *(_DWORD *)a4 += v13;
      if ( *(_BYTE *)(a2 + 2) && *(_BYTE *)(a2 + 23) == -1 )
        *(_DWORD *)a4 += 500;
    }
    else
    {
      Castle::grantHeroSpellsFromMageGuild((Castle *)a2, 0);
      if ( v29 )
        v27 = v9 + 0.04;
      if ( v29 )
        v31 = a2 + 8;
      else
        v31 = a1 + 101;
      if ( v29 )
        v17 = a1 + 101;
      else
        v17 = a2 + 8;
      if ( v29 )
      {
        v30 = v32;
        v14 = v28;
      }
      else
      {
        v30 = v28;
        v14 = v32;
      }
      sub_4B4C50(v31, (void *)v17, (unsigned int)v29 < 1, v29, v30, v14, (signed __int64)((double)(v32 + v28) * v27));
      if ( *(_BYTE *)a2 == dword_5305C4 && *(_DWORD *)(a1 + 53) <= 20 )
        *(_DWORD *)(a1 + 53) = 0;
    }
  }
}
