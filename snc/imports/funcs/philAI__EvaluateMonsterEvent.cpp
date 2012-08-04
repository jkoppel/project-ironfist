{
  signed int v3; // ST50_4@8
  char v5; // [sp+20h] [bp-34h]@8
  char v6; // [sp+24h] [bp-30h]@8
  char v7; // [sp+28h] [bp-2Ch]@8
  char v8; // [sp+2Ch] [bp-28h]@8
  int v9; // [sp+30h] [bp-24h]@8
  int i; // [sp+34h] [bp-20h]@2
  char v11; // [sp+38h] [bp-1Ch]@8
  float v12; // [sp+3Ch] [bp-18h]@8
  int v13; // [sp+40h] [bp-14h]@1
  float v14; // [sp+44h] [bp-10h]@8
  int v15; // [sp+48h] [bp-Ch]@1
  int v16; // [sp+4Ch] [bp-8h]@1
  int v17; // [sp+50h] [bp-4h]@8

  v16 = a2 & 0xFFF;
  v13 = a2 & 0x1000;
  v15 = 0;
  memset(gpMonGroup, 0xFFu, 5u);
  memset((char *)gpMonGroup + 5, 0, 0xAu);
  if ( v16 / 5 > 0 )
  {
    for ( i = 0; i < 5; ++i )
    {
      *((_BYTE *)gpMonGroup + i) = a1;
      *(_WORD *)((char *)gpMonGroup + 2 * i + 5) = v16 / 5;
    }
  }
  for ( i = v16 % 5 - 1; i >= 0; --i )
  {
    *((_BYTE *)gpMonGroup + i) = a1;
    ++*(_WORD *)((char *)gpMonGroup + 2 * i + 5);
  }
  philAI::ProbableOutcomeOfBattle(
    (int)&gpCurAIHero->army,
    (int)gpCurAIHero,
    (unsigned int)gpMonGroup,
    0,
    0,
    0,
    -1,
    (int)&v12,
    (int)&v9,
    (int *)&v8,
    (int *)&v6,
    (int *)&v5,
    &v17);
  philAI::EvaluateOneTimeCreaturePurchase(a1, v16, 1, (int)&v11, (int)&v9, (int)&v7);
  v3 = philAI::FightValueOfStack(&gpCurAIHero->army, gpCurAIHero, 0, 0, 0, 0);
  v14 = (double)v3 / (double)(v16 * gMonsterDatabase[a1].fight_value);
  if ( v13
    && v14 > 2.0
    && !hero::HasArtifact(gpCurAIHero, ARTIFACT_HIDEOUS_MASK)
    && armyGroup::CanJoin(&gpCurAIHero->army, a1)
    && a1 != 59
    && a1 != 62
    && a1 != 63
    && a1 != 64
    && a1 != 65 )
  {
    *(_DWORD *)a3 = 100;
    *(_DWORD *)a3 = (signed __int64)(v12 * 60.0 + 40.0);
    if ( armyGroup::CanJoin(&gpCurAIHero->army, a1) )
      v15 = v9;
    else
      v15 = 0;
    v15 = (signed __int64)((double)v15 * 0.6 + (double)v17 * 0.4);
  }
  else if ( v14 <= 5.0 )
  {
    *(_DWORD *)a3 = (signed __int64)(v12 * 100.0);
    v15 = v17;
  }
  else
  {
    if ( hero::GetSSLevel(gpCurAIHero, SECONDARY_SKILL_NECROMANCY) )
      v15 = 120;
    else
      v15 = 0;
    v15 += v16 * gMonsterDatabase[a1].hp;
  }
  if ( v15 < 0 )
    gbReduceByReload = 0;
  return v15;
}