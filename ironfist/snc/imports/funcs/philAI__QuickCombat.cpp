{
  double v7; // st7@6
  signed int v8; // ST50_4@56
  signed int v9; // ST48_4@62
  float v11; // [sp+34h] [bp-60h]@10
  int v12; // [sp+38h] [bp-5Ch]@4
  float v13; // [sp+3Ch] [bp-58h]@7
  char v14; // [sp+40h] [bp-54h]@6
  __int16 quantity[2]; // [sp+44h] [bp-50h]@56
  char v16; // [sp+48h] [bp-4Ch]@6
  float v17; // [sp+4Ch] [bp-48h]@6
  char v18; // [sp+50h] [bp-44h]@6
  float v19; // [sp+54h] [bp-40h]@17
  char v20; // [sp+58h] [bp-3Ch]@6
  int v21; // [sp+60h] [bp-34h]@3
  Spell a2a; // [sp+64h] [bp-30h]@37
  int v23; // [sp+6Ch] [bp-28h]@37
  unsigned __int64 this; // [sp+70h] [bp-24h]@65
  float v25; // [sp+78h] [bp-1Ch]@12
  int v26; // [sp+7Ch] [bp-18h]@1
  int xp; // [sp+80h] [bp-14h]@3
  float v28; // [sp+84h] [bp-10h]@6
  int v29; // [sp+88h] [bp-Ch]@3
  int v30; // [sp+8Ch] [bp-8h]@37
  char v31; // [sp+90h] [bp-4h]@6

  v26 = game::ExperienceValueOfStack(a1, a2);
  if ( a4 )
    v26 += 500;
  xp = game::ExperienceValueOfStack(a3, SHIDWORD(a3));
  v26 = (signed __int64)(((double)gpGame->difficulty * 0.12 + 1.0) * (double)v26);
  xp = (signed __int64)(((double)gpGame->difficulty * 0.12 + 1.0) * (double)xp);
  v21 = 0;
  v29 = 0;
  if ( HIDWORD(a3) )
    v12 = *(_BYTE *)(HIDWORD(a3) + 3);
  else
    v12 = -1;
  philAI::ProbableOutcomeOfBattle(
    a1,
    a2,
    a3,
    0,
    a4,
    a5,
    v12,
    (int)&v17,
    (int)&v20,
    (int *)&v18,
    (int *)&v16,
    (int *)&v14,
    (int *)&v31);
  v7 = (double)Random(0, 100) / 100.0;
  v28 = v7;
  if ( v7 >= v17 )
  {
    v13 = 1.0 - v17;
    v29 = a3;
  }
  else
  {
    v21 = 1;
    v13 = v17;
    v29 = a1;
  }
  if ( v17 >= (double)v28 )
    v11 = v17 - v28;
  else
    v11 = v28 - v17;
  v25 = v11;
  if ( v21 && v17 > 0.6 )
    v25 = (v17 + 0.65) * v25;
  if ( v25 > 1.0 )
    v25 = 1.0;
  v19 = (1.0 - v25) * (1.0 - v25);
  if ( v13 > 0.8 && v19 > 0.2 )
    v19 = v19 * v19;
  if ( v13 > 0.96 && (1.0 - v13) / 2.0 < v19 )
    v19 = (1.0 - v13) / 2.0;
  if ( v19 > 0.6 && v19 < 0.99 )
    v19 = v19 - 0.1;
  if ( v21 )
  {
    if ( a2 )
    {
      advManager::GiveExperience((hero *)a2, xp, 1);
      hero::ApplyBattleWinTemps((hero *)a2);
    }
    hero::CheckLevel((hero *)a2);
    *(_DWORD *)a7 = 1065353216;
    *a6 = v19;
  }
  else
  {
    if ( a2 )
    {
      *(_DWORD *)(a2 + 53) = 0;
      hero::ApplyBattleLossTemps((hero *)a2);
    }
    if ( HIDWORD(a3) )
      hero::ApplyBattleWinTemps((hero *)a2);
    *a7 = v19;
    *(_DWORD *)a6 = 1065353216;
    if ( *a6 >= 0.99 && HIDWORD(a3) )
    {
      advManager::GiveExperience(HIDWORD(a3), xp, 1);
      hero::CheckLevel(HIDWORD(a3));
    }
  }
  v30 = 0;
  v23 = 0;
  for ( a2a = 0; (signed int)a2a < 5; ++a2a )
  {
    if ( *(_BYTE *)(a2a + a2 + 101) != -1 )
      v30 += *(_WORD *)(a2 + 2 * a2a + 106);
    if ( HIDWORD(a3) )
    {
      if ( *(_BYTE *)(a2a + HIDWORD(a3) + 101) != -1 )
        v23 += *(_WORD *)(HIDWORD(a3) + 2 * a2a + 106);
    }
  }
  gbRetreatWin = 0;
  if ( (!v21 || HIDWORD(a3)) && Random(0, 100) < 60 )
    gbRetreatWin = 1;
  if ( !gbRetreatWin )
  {
    if ( *a6 <= 0.99 )
    {
      if ( *a7 > 0.99 )
        advManager::TransferArtifacts(SHIDWORD(a3), a2);
    }
    else
    {
      advManager::TransferArtifacts(a2, SHIDWORD(a3));
    }
  }
  philAI::DamageGroup((void *)a1, a2, SHIDWORD(a3), *a6);
  philAI::DamageGroup((void *)a3, SHIDWORD(a3), a2, *a7);
  if ( v21 && hero::GetSSLevel((hero *)a2, SECONDARY_SKILL_NECROMANCY) )
  {
    v8 = hero::GetSSLevel((hero *)a2, SECONDARY_SKILL_NECROMANCY);
    *(_DWORD *)quantity = (signed __int64)((double)v8 * (double)v23 * 0.12);
    if ( *(_DWORD *)quantity <= 0 )
      *(_DWORD *)quantity = 1;
    armyGroup::Add((armyGroup *)(a2 + 101), 47, quantity[0], -1);
  }
  else if ( HIDWORD(a3) && *a7 <= 0.999 && hero::GetSSLevel(HIDWORD(a3), SECONDARY_SKILL_NECROMANCY) )
  {
    v9 = hero::GetSSLevel(HIDWORD(a3), SECONDARY_SKILL_NECROMANCY);
    *(_DWORD *)quantity = (signed __int64)((double)v9 * (double)v30 * 0.12);
    if ( *(_DWORD *)quantity <= 0 )
      *(_DWORD *)quantity = 1;
    armyGroup::Add((armyGroup *)(HIDWORD(a3) + 101), 47, quantity[0], -1);
  }
  this = 0i64;
  if ( v21 )
  {
    this = __PAIR__(a2, HIDWORD(a3));
  }
  else if ( *a7 <= 0.999 )
  {
    this = __PAIR__(HIDWORD(a3), a2);
  }
  if ( (_DWORD)this && *(_BYTE *)(this + 127) && HIDWORD(this) )
  {
    for ( a2a = 0; (signed int)a2a < 65; ++a2a )
    {
      if ( hero::HasSpell((hero *)this, a2a)
        && !hero::HasSpell(HIDWORD(this), a2a)
        && gsSpellInfo[a2a].level <= *(_BYTE *)(HIDWORD(this) + 127) + 1
        && gsSpellInfo[a2a].attributes & 2 )
      {
        *(_BYTE *)(a2a + HIDWORD(this) + 148) = 1;
        break;
      }
    }
  }
  hero::ApplyBattleWinTemps((hero *)a2);
  if ( HIDWORD(a3) )
    hero::ApplyBattleWinTemps(HIDWORD(a3));
  if ( v21 && a4 )
    game::ClaimTown(gpGame, a5, giCurPlayer, 0);
  gbRetreatWin = 0;
  return v21;
}