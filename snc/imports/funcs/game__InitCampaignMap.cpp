{
  char v1; // ST6C_1@38
  char *v2; // ST2C_4@62
  char *v3; // ST28_4@94
  game *result; // eax@107
  int v5; // [sp+Ch] [bp-5Ch]@87
  int thisa; // [sp+14h] [bp-54h]@1
  char *v7; // [sp+24h] [bp-44h]@98
  int v8; // [sp+28h] [bp-40h]@84
  char *v9; // [sp+2Ch] [bp-3Ch]@84
  char *v10; // [sp+30h] [bp-38h]@77
  signed int v11; // [sp+34h] [bp-34h]@48
  int v12; // [sp+38h] [bp-30h]@61
  signed int v13; // [sp+3Ch] [bp-2Ch]@12
  char *v14; // [sp+40h] [bp-28h]@3
  signed int v15; // [sp+44h] [bp-24h]@29
  signed int v16; // [sp+48h] [bp-20h]@23
  int v17; // [sp+4Ch] [bp-1Ch]@1
  signed int j; // [sp+54h] [bp-14h]@25
  signed int i; // [sp+58h] [bp-10h]@23
  signed int k; // [sp+58h] [bp-10h]@71
  signed int l; // [sp+58h] [bp-10h]@77
  signed int m; // [sp+58h] [bp-10h]@84
  signed int n; // [sp+58h] [bp-10h]@98
  signed int v24; // [sp+60h] [bp-8h]@25
  char *v25; // [sp+64h] [bp-4h]@23

  thisa = this;
  v17 = *(_BYTE *)(iCurViewMap + 12 * iCurViewSide + this + 138);
  if ( *(_BYTE *)(this + 2) == *(_BYTE *)(this + 3) || iCurViewMap != 4 )
    v14 = (char *)&campaignChoices + 180 * *(_BYTE *)(this + 2) + 15 * *(_BYTE *)(this + 4) + 5 * v17;
  else
    v14 = (char *)&campaignChoices + 180 * iCurViewSide + 5 * v17 + 165;
  gpGame->_1[203] = 0;
  memset((void *)(this + 1101), 0, 0x41u);
  if ( *(_BYTE *)(thisa + 4) != 4 || *(_BYTE *)(thisa + 3) == *(_BYTE *)(thisa + 2) )
    sprintf(
      (char *)(thisa + 1126),
      "CAMP%c%02d.H2C",
      (unsigned int)*(_BYTE *)(thisa + 2) < 1 ? 71 : 69,
      *(_BYTE *)(thisa + 4) + 1);
  else
    sprintf(
      (char *)(thisa + 1126),
      "CAMP%c%02dB.H2C",
      (unsigned int)*(_BYTE *)(thisa + 2) < 1 ? 69 : 71,
      *(_BYTE *)(thisa + 4) + 1);
  *(_BYTE *)(thisa + 1146) = 0;
  if ( !*(_BYTE *)(thisa + 4) )
    *(_WORD *)(thisa + 186) = 0;
  strcpy(gMapName, (char *)(thisa + 1126));
  GetMapHeader(thisa + 1126, (void *)(thisa + 681));
  game::LoadGame((game *)thisa, "origdata.bin", 1, 0);
  game::InitNewGame(thisa, 0);
  if ( (unsigned __int8)*v14 == 8 )
  {
    v13 = 0;
    if ( *(_BYTE *)(thisa + 2) == 1 )
    {
      if ( *(_BYTE *)(thisa + 689) )
        v13 = 1;
      if ( *(_BYTE *)(thisa + 690) )
        ++v13;
    }
    *(_BYTE *)(v13 + thisa + 1113) = v14[1];
  }
  if ( *(_BYTE *)(thisa + 4) + 1 > 2 )
  {
    if ( *(_BYTE *)(thisa + 4) + 1 > 5 )
      gpGame->difficulty = 2;
    else
      gpGame->difficulty = 1;
  }
  else
  {
    gpGame->difficulty = 0;
  }
  *(_BYTE *)(thisa + 1166) = *(_BYTE *)(thisa + 707);
  game::NewMap((game *)thisa, gMapName);
  v16 = 0;
  v25 = (char *)gpGame->players;
  for ( i = 0; v25[1] > i; ++i )
  {
    v24 = -1;
    for ( j = i; v25[1] > j; ++j )
    {
      if ( gpGame->heroes[v25[j + 4]].heroID != 54 && gpGame->heroes[v25[j + 4]].heroID != 57 )
      {
        if ( gpGame->heroes[v25[j + 4]].heroID != 55 && gpGame->heroes[v25[j + 4]].heroID != 58 )
          v15 = 0;
        else
          v15 = 90;
      }
      else
      {
        v15 = 100;
      }
      if ( v24 < v15 )
      {
        v24 = v15;
        v16 = j;
      }
    }
    if ( v24 != -1 )
    {
      v1 = v25[i + 4];
      v25[i + 4] = v25[v16 + 4];
      v25[v16 + 4] = v1;
    }
  }
  if ( v25[1] )
    v25[2] = v25[4];
  switch ( *v14 )
  {
    case 0:
      *(_DWORD *)(thisa + 4 * *(_WORD *)(v14 + 1) + 1323) += *(_WORD *)(v14 + 3);
      break;
    case 1:
      if ( (signed int)*(_BYTE *)(thisa + 1181) > 0 )
        GiveArtifact(&gpGame->heroes[*(_BYTE *)(thisa + 1184)], (ARTIFACT)*(_WORD *)(v14 + 1), 0, -1);
      break;
    case 2:
      if ( (signed int)*(_BYTE *)(thisa + 1181) > 0 )
      {
        v11 = 0;
        if ( !*(_BYTE *)(thisa + 2) && *(_BYTE *)(thisa + 4) == 5 && (signed int)*(_BYTE *)(thisa + 1181) > 1 )
          v11 = 1;
        gpGame->heroes[*(_BYTE *)(v11 + thisa + 1184)].spellsLearned[*(_WORD *)(v14 + 1)] = 1;
      }
      break;
    case 3:
      if ( (signed int)*(_BYTE *)(thisa + 1181) > 0 )
        hero::SetSS(&gpGame->heroes[*(_BYTE *)(thisa + 1184)], *(_WORD *)(v14 + 1), *(_WORD *)(v14 + 3));
      break;
    case 4:
      if ( (signed int)*(_BYTE *)(thisa + 1181) > 0 )
        armyGroup::Add(&gpGame->heroes[*(_BYTE *)(thisa + 1184)].army, *(_WORD *)(v14 + 1), *(_WORD *)(v14 + 3), -1);
      break;
    case 5:
      *(_BYTE *)(thisa + 1199) = v14[1];
      break;
    case 6:
      v12 = gbInNewGameSetup;
      gbInNewGameSetup = 1;
      if ( (signed int)*(_BYTE *)(thisa + 1181) > 0 )
      {
        v2 = (char *)&gpGame->heroes[*(_BYTE *)(thisa + 1184)];
        *(_DWORD *)(v2 + 57) += *(_WORD *)(v14 + 1);
        hero::CheckLevel(&gpGame->heroes[*(_BYTE *)(thisa + 1184)]);
      }
      gbInNewGameSetup = v12;
      break;
    case 7:
      break;
  }
  if ( (*(_BYTE *)(thisa + 136) || *(_BYTE *)(thisa + 131) && *(_BYTE *)(thisa + 4) == 9)
    && (signed int)*(_BYTE *)(thisa + 1181) > 0 )
    GiveArtifact(&gpGame->heroes[*(_BYTE *)(thisa + 1184)], ARTIFACT_ULTIMATE_CROWN, 0, -1);
  gbRetreatWin = 1;
  if ( *(_BYTE *)(thisa + 130) )
  {
    for ( k = 0; k < 54; ++k )
    {
      if ( gpGame->heroes[k].heroID == 55 )
        hero::Deallocate(&gpGame->heroes[k], 0);
    }
  }
  if ( *(_BYTE *)(thisa + 128) )
  {
    v10 = (char *)&gpGame->heroes[*(_BYTE *)(thisa + 2033)];
    for ( l = 0; l < 5; ++l )
    {
      if ( (signed int)*(_WORD *)&v10[2 * l + 106] >= 1 )
        *(_WORD *)&v10[2 * l + 106] *= 3;
    }
  }
  if ( *(_BYTE *)(thisa + 4) == 6 && *(_BYTE *)(thisa + 2) == 1 )
  {
    v8 = gbInNewGameSetup;
    gbInNewGameSetup = 1;
    v9 = (char *)&gpGame->heroes[*(_BYTE *)(thisa + 1184)];
    for ( m = 0; m < 5; ++m )
    {
      v9[m + 101] = -1;
      *(_WORD *)&v9[2 * m + 106] = 0;
    }
    v5 = (unsigned __int8)v9[23];
    switch ( v5 )
    {
      case 1:
        armyGroup::Add((armyGroup *)(v9 + 101), 13, 12, -1);
        armyGroup::Add((armyGroup *)(v9 + 101), 15, 18, -1);
        armyGroup::Add((armyGroup *)(v9 + 101), 11, 40, -1);
        break;
      case 3:
        armyGroup::Add((armyGroup *)(v9 + 101), 29, 40, -1);
        armyGroup::Add((armyGroup *)(v9 + 101), 30, 24, -1);
        armyGroup::Add((armyGroup *)(v9 + 101), 31, 18, -1);
        break;
      case 5:
        armyGroup::Add((armyGroup *)(v9 + 101), 47, 50, -1);
        armyGroup::Add((armyGroup *)(v9 + 101), 51, 18, -1);
        armyGroup::Add((armyGroup *)(v9 + 101), 53, 8, -1);
        break;
    }
    v3 = (char *)&gpGame->heroes[*(_BYTE *)(thisa + 1184)];
    *(_DWORD *)(v3 + 57) += 5000;
    hero::CheckLevel(&gpGame->heroes[*(_BYTE *)(thisa + 1184)]);
    gbInNewGameSetup = v8;
  }
  if ( *(_BYTE *)(thisa + 129) && *(_BYTE *)(thisa + 4) == 9 || *(_BYTE *)(thisa + 137) )
  {
    v7 = (char *)&gpGame->heroes[*(_BYTE *)(thisa + 1184)];
    for ( n = 0; n < 5; ++n )
    {
      v7[n + 101] = *(_BYTE *)(thisa + 2 * n + 188);
      *(_WORD *)&v7[2 * n + 106] = *(_WORD *)(thisa + 2 * n + 198) * ((unsigned int)*(_BYTE *)(thisa + 128) < 1 ? 1 : 3);
    }
  }
  if ( *(_BYTE *)(thisa + 2) == 1 && *(_BYTE *)(thisa + 4) == 5 )
  {
    gpGame->winConditionType = 4;
    gpGame->winConditionArgument = 99;
    gpGame->field_2C8 = 1;
  }
  if ( !*(_BYTE *)(thisa + 2) && *(_BYTE *)(thisa + 4) == 8 )
  {
    gpGame->_2[0] = 0;
    *(_WORD *)&gpGame->_2[1] = 0;
  }
  result = (game *)thisa;
  if ( !*(_BYTE *)(thisa + 2) )
  {
    result = (game *)(*(_BYTE *)(thisa + 4) + 1);
    if ( result == (game *)7 )
    {
      result = gpGame;
      *(_WORD *)&gpGame->_2[1] = 90;
    }
  }
  return result;
}