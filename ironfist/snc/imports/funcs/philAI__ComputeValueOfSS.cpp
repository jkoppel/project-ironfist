{
  int v4; // [sp+30h] [bp-1Ch]@10
  signed int v5; // [sp+38h] [bp-14h]@7
  signed int v6; // [sp+3Ch] [bp-10h]@7
  signed int i; // [sp+40h] [bp-Ch]@7
  signed int v8; // [sp+44h] [bp-8h]@1
  signed int v9; // [sp+48h] [bp-4h]@1

  v8 = *(&dword_4F1F3C[3 * a2] + a3);
  v9 = philAI::FightValueOfStack((armyGroup *)(a1 + 101), (hero *)a1, 1, 0, 0, 0);
  if ( a2 != 13 )
    v8 = (signed __int64)(((double)v9 / *(float *)&gpCurPlayer->_4[100] / 2500.0 + 0.5) * (double)v8);
  switch ( a2 )
  {
    case 5:
      if ( *(_BYTE *)(a1 + 227) & 0x80 )
        v8 = (signed __int64)((double)v8 * 1.3);
      break;
    case 1:
      v6 = 0;
      v5 = 0;
      for ( i = 0; i < 5; ++i )
      {
        if ( *(_BYTE *)(i + a1 + 101) != -1 )
        {
          v4 = *(_WORD *)(a1 + 2 * i + 106) * gMonsterDatabase[*(_BYTE *)(i + a1 + 101)].fight_value;
          v5 += v4;
          if ( gMonsterDatabase[*(_BYTE *)(i + a1 + 101)].creature_flags & 4 )
            v6 += v4;
        }
      }
      v8 = (signed __int64)(((double)v6 / (double)v5 / 0.2 + 0.25) * (double)v8);
      break;
    case 7:
    case 8:
      if ( !hero::HasArtifact((hero *)a1, ARTIFACT_MAGIC_BOOK) || hero::Stats((hero *)a1, PRIMARY_SKILL_KNOWLEDGE) < 2 )
        v8 = (signed __int64)((double)v8 * 0.5);
      break;
    default:
      return v8;
  }
  return v8;
}