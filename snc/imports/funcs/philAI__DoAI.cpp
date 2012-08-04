{
  char *v2; // eax@8
  mouseManager *result; // eax@124
  int v4; // [sp+0h] [bp-A0h]@0
  int v5; // [sp+4h] [bp-9Ch]@0
  int v6; // [sp+8h] [bp-98h]@0
  int v7; // [sp+Ch] [bp-94h]@26
  int v8; // [sp+10h] [bp-90h]@26
  int v9; // [sp+14h] [bp-8Ch]@26
  int v10; // [sp+18h] [bp-88h]@26
  void *v11; // [sp+1Ch] [bp-84h]@1
  int v12; // [sp+20h] [bp-80h]@0
  int v13; // [sp+24h] [bp-7Ch]@0
  int v14; // [sp+28h] [bp-78h]@0
  int v15; // [sp+2Ch] [bp-74h]@0
  int v16; // [sp+30h] [bp-70h]@0
  int v17; // [sp+34h] [bp-6Ch]@0
  int v18; // [sp+38h] [bp-68h]@0
  int v19; // [sp+3Ch] [bp-64h]@0
  signed int a8; // [sp+40h] [bp-60h]@68
  int a6; // [sp+44h] [bp-5Ch]@68
  int v22; // [sp+48h] [bp-58h]@36
  int v23; // [sp+4Ch] [bp-54h]@35
  int a2a; // [sp+50h] [bp-50h]@40
  int v25; // [sp+54h] [bp-4Ch]@35
  int v26; // [sp+58h] [bp-48h]@35
  int v27; // [sp+5Ch] [bp-44h]@80
  int v28; // [sp+60h] [bp-40h]@114
  int v29; // [sp+64h] [bp-3Ch]@114
  int v30; // [sp+68h] [bp-38h]@61
  int i; // [sp+6Ch] [bp-34h]@6
  int v32; // [sp+70h] [bp-30h]@40
  void *v33; // [sp+74h] [bp-2Ch]@1
  int v34; // [sp+78h] [bp-28h]@1
  int v35; // [sp+7Ch] [bp-24h]@24
  char *v36; // [sp+80h] [bp-20h]@13
  int v37; // [sp+84h] [bp-1Ch]@23
  int v38; // [sp+88h] [bp-18h]@26
  int a5; // [sp+8Ch] [bp-14h]@81
  int a4; // [sp+90h] [bp-10h]@81
  int v41; // [sp+94h] [bp-Ch]@1
  char v42; // [sp+98h] [bp-8h]@76
  signed int a3; // [sp+9Ch] [bp-4h]@68

  v11 = this;
  v34 = 0;
  v41 = 0;
  v33 = 0;
  LogInt((int)"DO AI 1", a2, -999, -999, -999, -999, -999, -999);
  PollSound();
  if ( !gbGameOver && (!giLimitPlayer || giLimitPlayer == a2) )
  {
    LogInt((int)"DO AI", a2, -999, -999, -999, -999, -999, -999);
    InitAIMapVars();
    philAI::GetTurnAIVars(a2);
    if ( gpGame->day == 1 || gpGame->day == 1 )
    {
      for ( i = 0; gpCurPlayer->numHeroes > i; ++i )
      {
        v2 = (char *)gpGame + 250 * gpCurPlayer->heroesOwned[i];
        v12 = (int)(v2 + 10180);
        *(_WORD *)(v2 + 10187) = -99;
      }
    }
    ShowStatus();
    philAI::SetupRelativeHeroStrengths();
    for ( i = 0; i < 7; ++i )
    {
      sprintf(
        gText,
        "RES - %15s  %d  %d",
        gResourceNames[i],
        gpCurPlayer->resources[i],
        *(_DWORD *)&gpCurPlayer->_4[4 * i + 60]);
      LogStr(gText);
    }
    philAI::CheckBuyStuff(v11);
    philAI::IncrementHourGlass();
    while ( 1 )
    {
      v36 = philAI::DetermineHeroToMove(a2);
      if ( !v36 )
        break;
      ValidateHero((hero *)v36);
      gpCurAIHero = (hero *)v36;
      if ( (unsigned __int8)v36[41] == 255 || LOBYTE(gpCurAIHero->field_2B) )
      {
        giCurAIHeroMorale = armyGroup::GetMorale(&gpCurAIHero->army, gpCurAIHero, 0, 0);
        giCurAIHeroLuck = game::GetLuck(gpCurAIHero, 0, 0);
        armyGroup::GetMorale(&gpCurAIHero->army, gpCurAIHero, 0, 0);
        dword_5305C4 = -1;
        dword_532CE0 = 0;
        if ( gbGameOver )
          break;
        LogStr("\n\n\n\n");
        LogStr("===================================");
        LogInt((int)"Player with HeroTOMOVE", a2, -999, -999, -999, -999, -999, -999);
        LogStr(gpCurAIHero->name);
        LogStr(L"\n");
        philAI::CheckReload();
        philAI::CheckBerserk();
        giShowComputerRoute = 0;
        if ( *(_DWORD *)&blackoutComputer
          || gbRemoteOn
          || !MapExtraPosAndAdjacentsSet(gpCurAIHero->x, gpCurAIHero->y, giCurWatchPlayerBit) )
        {
          bShowIt = 0;
          advManager::SetHeroContext(gpAdvManager, gpCurAIHero->couldBeHeroIdx, 0);
        }
        else
        {
          bShowIt = 1;
          advManager::SetHeroContext(gpAdvManager, gpCurAIHero->couldBeHeroIdx, 0);
        }
        v37 = 0;
        ResetHeroRVs(0, 0, 0);
        if ( gpCurAIHero->flags1 & 0x80 )
          v35 = 15;
        else
          v35 = 5;
        v38 = *(_DWORD *)&gpCurAIHero->field_31 + 800;
        v10 = gpGame->difficulty;
        v9 = v35;
        v35 = (signed __int64)((1.7 - (double)v10 * 0.1) * (double)v35);
        v8 = gpGame->difficulty - 1;
        v7 = v38;
        v38 = (signed __int64)(((double)v8 * 0.06 + 0.8) * (double)v38);
LABEL_27:
        if ( v37 || *(_DWORD *)&gpCurAIHero->field_35 < 75 )
        {
          *(_DWORD *)&gpCurAIHero->field_35 = 0;
          advManager::DeactivateCurrHero(gpAdvManager);
        }
        else
        {
          if ( gbGameOver )
            break;
          if ( *(_DWORD *)&gpCurAIHero->field_35 == *(_DWORD *)&gpCurAIHero->field_31
            && gpCurPlayer->field_40 > 15
            && LOBYTE(gpCurPlayer->field_41) == gpCurAIHero->x
            && HIBYTE(gpCurPlayer->field_41) == gpCurAIHero->y )
            advManager::ProcessSearch(gpAdvManager, *(_QWORD *)&gpCurAIHero->x);
          do
          {
            do
            {
              v25 = philAI::DetermineTargetPosition(
                      v11,
                      (int *)&gpCurAIHero->field_21,
                      (int *)&gpCurAIHero->field_25,
                      v38,
                      (int)&v26);
              v23 = game::GetTownId(gpGame, gpCurAIHero->x, gpCurAIHero->y);
              if ( v23 != -1 )
              {
                v22 = (int)&gpGame->castles[v23];
                if ( gpGame->castles[v23].alignment )
                {
                  if ( (advManager::GetCell(
                          gpAdvManager,
                          *(_DWORD *)&gpCurAIHero->field_21,
                          *(_DWORD *)&gpCurAIHero->field_25)->objType & 0x7F) != 42 )
                    *(_DWORD *)&gpCurAIHero->field_35 = 0;
                }
              }
              if ( v26 != -1 )
              {
                a2a = v26;
                v32 = 99;
                goto LABEL_79;
              }
            }
            while ( v25 < 1000 && v26 == -1 && philAI::DoAnywhereDDoorTownGate(v11, v25) );
            if ( v25 < 75 && gpGame->day == 7 && gpCurAIHero->occupiedObjType == 163 )
              *(_DWORD *)&gpCurAIHero->field_35 = 0;
            for ( i = 0; dword_532CE0 > i; ++i )
            {
              if ( dword_5305D8[2 * i] == *(_DWORD *)&gpCurAIHero->field_21
                && dword_5305DC[2 * i] == *(_DWORD *)&gpCurAIHero->field_25
                && advManager::GetCell(
                     gpAdvManager,
                     *(_DWORD *)&gpCurAIHero->field_21,
                     *(_DWORD *)&gpCurAIHero->field_25)->objType != 163 )
                *(_DWORD *)&gpCurAIHero->field_35 = 0;
            }
            if ( dword_532CE0 < 30 )
            {
              dword_5305D8[2 * dword_532CE0] = gpCurAIHero->x;
              dword_5305DC[2 * dword_532CE0++] = gpCurAIHero->y;
            }
            giShowComputerRoute = 1;
            if ( *(_DWORD *)&gpCurAIHero->field_35 == *(_DWORD *)&gpCurAIHero->field_31 )
            {
              v41 = 0;
              philAI::IncrementHourGlass();
            }
            if ( *(_DWORD *)&gpCurAIHero->field_21 == -1 || *(_DWORD *)&gpCurAIHero->field_25 == -1 )
            {
              v37 = 1;
              goto LABEL_27;
            }
            v30 = 0;
            advManager::SetHeroContext(gpAdvManager, gpCurAIHero->couldBeHeroIdx, 0);
            searchArray::BuildPath(
              gpSearchArray,
              gpCurAIHero->x,
              gpCurAIHero->y,
              *(_DWORD *)&gpCurAIHero->field_21,
              *(_DWORD *)&gpCurAIHero->field_25,
              *(_DWORD *)&gpCurAIHero->field_35);
            if ( !gpSearchArray->field_8 )
            {
              v37 = 1;
              goto LABEL_113;
            }
            if ( gpSearchArray->field_8 <= 0 )
            {
              v37 = 1;
              goto LABEL_113;
            }
            advManager::UpdateScreen(gpAdvManager, 0, 0);
          }
          while ( v25 > 1000
               && hero::HasSpell(gpCurAIHero, SPELL_DIMENSION_DOOR)
               && gpCurAIHero->spellpoints >= 30
               && philAI::DoDimensionDoor((int)gpCurAIHero) );
          v32 = 0;
          i = gpSearchArray->field_8 - 1;
          a6 = 0;
          a8 = 0;
          a3 = 1;
          while ( i >= 0 && v32 < v35 )
          {
            a3 = v32 + 1 == v35 || !i;
            if ( i > 0 )
            {
              a6 = 0;
              a8 = 0;
              if ( philAI::GoodAdjacent(v11, (int)&v42) )
              {
                *((_BYTE *)&gpSearchArray->field_2418 + i) = v42;
                a3 = 1;
              }
            }
            a2a = *((_BYTE *)&gpSearchArray->field_2418 + i);
LABEL_79:
            if ( advManager::GetMoveShowIt((int)gpCurAIHero, a2a) )
            {
              v27 = bShowIt;
              bShowIt = 1;
              mouseManager::HideColorPointer(gpMouseManager);
              ++v34;
              bShowIt = v27;
            }
            v30 = (int)advManager::MoveHero(gpAdvManager, a2a, a3, &a4, &a5, (int)&a6, 1, (signed int)&a8, 0);
            ++v32;
            if ( v30 || a6 || a8 )
              break;
            --i;
          }
          if ( gpCurAIHero->probablyOwnerIdx != giCurPlayer )
          {
            if ( !v33 )
            {
              v33 = (void *)1;
              philAI::CheckBuyStuff(v11);
            }
            goto LABEL_120;
          }
          if ( *(_DWORD *)&gpCurAIHero->field_31 >> 1 >= *(_DWORD *)&gpCurAIHero->field_35 && !v41 )
          {
            v41 = 1;
            philAI::IncrementHourGlass();
          }
          if ( i < 0
            && gpCurPlayer->field_40 > 15
            && LOBYTE(gpCurPlayer->field_41) == gpCurAIHero->x
            && HIBYTE(gpCurPlayer->field_41) == gpCurAIHero->y )
          {
            if ( *(_DWORD *)&gpCurAIHero->field_35 == *(_DWORD *)&gpCurAIHero->field_31 )
              advManager::ProcessSearch(gpAdvManager, -1i64);
            else
              *(_DWORD *)&gpCurAIHero->field_35 = 0;
          }
          if ( i < 0
            && ((gpCurAIHero->x != *(_DWORD *)&gpCurAIHero->field_21
              || *(_DWORD *)&gpCurAIHero->field_25 != gpCurAIHero->y)
             && !v30
             || *(_DWORD *)&gpCurAIHero->field_35 < 75
             || a6 && !v30) )
            v37 = 1;
          v27 = bShowIt;
          bShowIt = 1;
          while ( v34 )
          {
            mouseManager::ShowColorPointer(gpMouseManager);
            --v34;
          }
          bShowIt = v27;
          advManager::UpdateRadar((int)gpAdvManager, 1, 0);
LABEL_113:
          if ( !v30 )
            goto LABEL_27;
          advManager::DoAIEvent(
            (int)gpAdvManager,
            v30,
            (int)gpCurAIHero,
            __PAIR__(a5, a4),
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            (int)v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            a8,
            a6,
            v22,
            v23,
            a2a,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            i,
            v32,
            v33,
            v34,
            v35);
          if ( gpCurPlayer->curHeroIdx != -1 )
          {
            ValidateHero(gpCurAIHero);
            ResetHeroRVs(1, *(_DWORD *)&gpCurAIHero->field_21, *(_DWORD *)&gpCurAIHero->field_25);
            goto LABEL_27;
          }
        }
LABEL_120:
        if ( gpCurAIHero->occupiedObjType == 163 )
          philAI::CheckBuyStuff(v11);
      }
      else
      {
        *(_DWORD *)&gpCurAIHero->field_35 = 0;
      }
    }
  }
  game::CheckHeroConsistency(gpGame);
  gpCurAIHero = 0;
  CloseAIMapVars();
  while ( 1 )
  {
    result = gpMouseManager;
    if ( !gpMouseManager->cursorDisabled )
      break;
    mouseManager::ShowColorPointer(gpMouseManager);
  }
  return result;
}