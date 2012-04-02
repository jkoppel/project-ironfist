GameInfo *__thiscall sub_4A9550(int this)
{
  char v1; // ST6C_1@38
  char *v2; // ST2C_4@62
  char *v3; // ST28_4@94
  GameInfo *result; // eax@107
  int v5; // [sp+Ch] [bp-5Ch]@87
  int v6; // [sp+14h] [bp-54h]@1
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

  v6 = this;
  v17 = *(_BYTE *)(dword_5304DC + 12 * dword_5304D8 + this + 138);
  if ( *(_BYTE *)(this + 2) == *(_BYTE *)(this + 3) || dword_5304DC != 4 )
    v14 = (char *)&unk_4F5488 + 180 * *(_BYTE *)(this + 2) + 15 * *(_BYTE *)(this + 4) + 5 * v17;
  else
    v14 = (char *)&unk_4F5488 + 180 * dword_5304D8 + 5 * v17 + 165;
  gameObject->_1[203] = 0;
  memset((void *)(this + 1101), 0, 0x41u);
  if ( *(_BYTE *)(v6 + 4) != 4 || *(_BYTE *)(v6 + 3) == *(_BYTE *)(v6 + 2) )
    sprintf(
      (char *)(v6 + 1126),
      "CAMP%c%02d.H2C",
      (unsigned int)*(_BYTE *)(v6 + 2) < 1 ? 71 : 69,
      *(_BYTE *)(v6 + 4) + 1);
  else
    sprintf(
      (char *)(v6 + 1126),
      "CAMP%c%02dB.H2C",
      (unsigned int)*(_BYTE *)(v6 + 2) < 1 ? 69 : 71,
      *(_BYTE *)(v6 + 4) + 1);
  *(_BYTE *)(v6 + 1146) = 0;
  if ( !*(_BYTE *)(v6 + 4) )
    *(_WORD *)(v6 + 186) = 0;
  strcpy(byte_524740, (const char *)(v6 + 1126));
  sub_40B430(v6 + 1126, (void *)(v6 + 681));
  sub_41B5F0((void *)v6, "origdata.bin", 1, 0);
  sub_45AA00(v6, 0);
  if ( (unsigned __int8)*v14 == 8 )
  {
    v13 = 0;
    if ( *(_BYTE *)(v6 + 2) == 1 )
    {
      if ( *(_BYTE *)(v6 + 689) )
        v13 = 1;
      if ( *(_BYTE *)(v6 + 690) )
        ++v13;
    }
    *(_BYTE *)(v13 + v6 + 1113) = v14[1];
  }
  if ( *(_BYTE *)(v6 + 4) + 1 > 2 )
  {
    if ( *(_BYTE *)(v6 + 4) + 1 > 5 )
      gameObject->difficulty = 2;
    else
      gameObject->difficulty = 1;
  }
  else
  {
    gameObject->difficulty = 0;
  }
  *(_BYTE *)(v6 + 1166) = *(_BYTE *)(v6 + 707);
  sub_41C580((void *)v6, byte_524740);
  v16 = 0;
  v25 = (char *)gameObject->players;
  for ( i = 0; v25[1] > i; ++i )
  {
    v24 = -1;
    for ( j = i; v25[1] > j; ++j )
    {
      if ( gameObject->heroes[v25[j + 4]].heroID != 54 && gameObject->heroes[v25[j + 4]].heroID != 57 )
      {
        if ( gameObject->heroes[v25[j + 4]].heroID != 55 && gameObject->heroes[v25[j + 4]].heroID != 58 )
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
      *(_DWORD *)(v6 + 4 * *(_WORD *)(v14 + 1) + 1323) += *(_WORD *)(v14 + 3);
      break;
    case 1:
      if ( (signed int)*(_BYTE *)(v6 + 1181) > 0 )
        grantArtifact(&gameObject->heroes[*(_BYTE *)(v6 + 1184)], (ARTIFACT)*(_WORD *)(v14 + 1), 0, -1);
      break;
    case 2:
      if ( (signed int)*(_BYTE *)(v6 + 1181) > 0 )
      {
        v11 = 0;
        if ( !*(_BYTE *)(v6 + 2) && *(_BYTE *)(v6 + 4) == 5 && (signed int)*(_BYTE *)(v6 + 1181) > 1 )
          v11 = 1;
        gameObject->heroes[*(_BYTE *)(v11 + v6 + 1184)].spellsLearned[*(_WORD *)(v14 + 1)] = 1;
      }
      break;
    case 3:
      if ( (signed int)*(_BYTE *)(v6 + 1181) > 0 )
        Hero::setSecondarySkillLevel(
          &gameObject->heroes[*(_BYTE *)(v6 + 1184)],
          *(_WORD *)(v14 + 1),
          *(_WORD *)(v14 + 3));
      break;
    case 4:
      if ( (signed int)*(_BYTE *)(v6 + 1181) > 0 )
        ArmyInfo::addCreatures(
          &gameObject->heroes[*(_BYTE *)(v6 + 1184)].army,
          *(_WORD *)(v14 + 1),
          *(_WORD *)(v14 + 3),
          -1);
      break;
    case 5:
      *(_BYTE *)(v6 + 1199) = v14[1];
      break;
    case 6:
      v12 = dword_523F1C;
      dword_523F1C = 1;
      if ( (signed int)*(_BYTE *)(v6 + 1181) > 0 )
      {
        v2 = (char *)&gameObject->heroes[*(_BYTE *)(v6 + 1184)];
        *(_DWORD *)(v2 + 57) += *(_WORD *)(v14 + 1);
        Hero::checkForLevelUp(&gameObject->heroes[*(_BYTE *)(v6 + 1184)]);
      }
      dword_523F1C = v12;
      break;
    case 7:
      break;
  }
  if ( (*(_BYTE *)(v6 + 136) || *(_BYTE *)(v6 + 131) && *(_BYTE *)(v6 + 4) == 9)
    && (signed int)*(_BYTE *)(v6 + 1181) > 0 )
    grantArtifact(&gameObject->heroes[*(_BYTE *)(v6 + 1184)], ARTIFACT_ULTIMATE_CROWN, 0, -1);
  isRetreating = 1;
  if ( *(_BYTE *)(v6 + 130) )
  {
    for ( k = 0; k < 54; ++k )
    {
      if ( gameObject->heroes[k].heroID == 55 )
        Hero::delete(&gameObject->heroes[k], 0);
    }
  }
  if ( *(_BYTE *)(v6 + 128) )
  {
    v10 = (char *)&gameObject->heroes[*(_BYTE *)(v6 + 2033)];
    for ( l = 0; l < 5; ++l )
    {
      if ( (signed int)*(_WORD *)&v10[2 * l + 106] >= 1 )
        *(_WORD *)&v10[2 * l + 106] *= 3;
    }
  }
  if ( *(_BYTE *)(v6 + 4) == 6 && *(_BYTE *)(v6 + 2) == 1 )
  {
    v8 = dword_523F1C;
    dword_523F1C = 1;
    v9 = (char *)&gameObject->heroes[*(_BYTE *)(v6 + 1184)];
    for ( m = 0; m < 5; ++m )
    {
      v9[m + 101] = -1;
      *(_WORD *)&v9[2 * m + 106] = 0;
    }
    v5 = (unsigned __int8)v9[23];
    switch ( v5 )
    {
      case 1:
        ArmyInfo::addCreatures((ArmyInfo *)(v9 + 101), 13, 12, -1);
        ArmyInfo::addCreatures((ArmyInfo *)(v9 + 101), 15, 18, -1);
        ArmyInfo::addCreatures((ArmyInfo *)(v9 + 101), 11, 40, -1);
        break;
      case 3:
        ArmyInfo::addCreatures((ArmyInfo *)(v9 + 101), 29, 40, -1);
        ArmyInfo::addCreatures((ArmyInfo *)(v9 + 101), 30, 24, -1);
        ArmyInfo::addCreatures((ArmyInfo *)(v9 + 101), 31, 18, -1);
        break;
      case 5:
        ArmyInfo::addCreatures((ArmyInfo *)(v9 + 101), 47, 50, -1);
        ArmyInfo::addCreatures((ArmyInfo *)(v9 + 101), 51, 18, -1);
        ArmyInfo::addCreatures((ArmyInfo *)(v9 + 101), 53, 8, -1);
        break;
    }
    v3 = (char *)&gameObject->heroes[*(_BYTE *)(v6 + 1184)];
    *(_DWORD *)(v3 + 57) += 5000;
    Hero::checkForLevelUp(&gameObject->heroes[*(_BYTE *)(v6 + 1184)]);
    dword_523F1C = v8;
  }
  if ( *(_BYTE *)(v6 + 129) && *(_BYTE *)(v6 + 4) == 9 || *(_BYTE *)(v6 + 137) )
  {
    v7 = (char *)&gameObject->heroes[*(_BYTE *)(v6 + 1184)];
    for ( n = 0; n < 5; ++n )
    {
      v7[n + 101] = *(_BYTE *)(v6 + 2 * n + 188);
      *(_WORD *)&v7[2 * n + 106] = *(_WORD *)(v6 + 2 * n + 198) * ((unsigned int)*(_BYTE *)(v6 + 128) < 1 ? 1 : 3);
    }
  }
  if ( *(_BYTE *)(v6 + 2) == 1 && *(_BYTE *)(v6 + 4) == 5 )
  {
    gameObject->winConditionType = 4;
    gameObject->winConditionArgument = 99;
    gameObject->field_2C8 = 1;
  }
  if ( !*(_BYTE *)(v6 + 2) && *(_BYTE *)(v6 + 4) == 8 )
  {
    gameObject->_2[0] = 0;
    *(_WORD *)&gameObject->_2[1] = 0;
  }
  result = (GameInfo *)v6;
  if ( !*(_BYTE *)(v6 + 2) )
  {
    result = (GameInfo *)(*(_BYTE *)(v6 + 4) + 1);
    if ( result == (GameInfo *)7 )
    {
      result = gameObject;
      *(_WORD *)&gameObject->_2[1] = 90;
    }
  }
  return result;
}
