{
  signed int v3; // ST28_4@31
  __int16 result; // ax@32
  signed int v5; // [sp+24h] [bp-28h]@16
  int v6; // [sp+28h] [bp-24h]@22
  char v7; // [sp+2Ch] [bp-20h]@10
  int v8; // [sp+30h] [bp-1Ch]@1
  float v9; // [sp+34h] [bp-18h]@1
  int v10; // [sp+38h] [bp-14h]@10
  int creatureType; // [sp+3Ch] [bp-10h]@1
  signed int slot; // [sp+40h] [bp-Ch]@10
  int a3a; // [sp+44h] [bp-8h]@1
  int v14; // [sp+48h] [bp-4h]@33

  creatureType = *(_BYTE *)(a1 + 3);
  a3a = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5);
  v8 = ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 0;
  v9 = (double)getArmyStrength((ArmyInfo *)(a2 + 101), (Hero *)a2, 0, 0, 0, 0)
     / (double)(a3a * creature_table[creatureType].fight_value);
  if ( ArmyInfo::hasRoomForCreatureType((ArmyInfo *)(a2 + 101), creatureType)
    && !Hero::hasArtifact((Hero *)a2, ARTIFACT_HIDEOUS_MASK)
    && v9 > 2.0
    && creatureType != 59
    && creatureType != 62
    && creatureType != 63
    && creatureType != 64
    && creatureType != 65 )
  {
    if ( !v8 )
    {
      if ( !*(_BYTE *)(a2 + 120) )
        goto LABEL_28;
      if ( *(_BYTE *)(a2 + 120) == 3 )
      {
        v5 = a3a;
      }
      else
      {
        if ( *(_BYTE *)(a2 + 120) == 2 )
          v5 = a3a / 2;
        else
          v5 = a3a / 4;
      }
      if ( !v5 )
        v5 = 1;
      v6 = (signed __int64)((double)(a3a * (signed int)creature_table[creatureType].cost) * 0.75);
      if ( gameObject->players[*(_BYTE *)(a2 + 3)].resources[6] >= v6 )
      {
        sub_4B36D0(creatureType, a3a, 1, (int)&v10, (int)&v7, (int)&slot);
        if ( v10 > 0 )
        {
          gameObject->players[*(_BYTE *)(a2 + 3)].resources[6] -= v6;
          addCreaturesToArmy((ArmyInfo *)(a2 + 101), creatureType, v5, slot);
          *(_DWORD *)a3 = 1;
          goto LABEL_28;
        }
      }
      else
      {
        if ( v9 > 5.0 )
          goto LABEL_29;
      }
LABEL_33:
      v14 = sub_4B5BC0(a2, creatureType, (int)&a3a, a1);
      if ( v14 )
      {
        result = a3;
        *(_DWORD *)a3 = 1;
      }
      else
      {
        result = *(_WORD *)(a1 + 4) & 7 | 8 * ((a3a & 0xFFF) + (((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 0));
        *(_WORD *)(a1 + 4) = result;
      }
      return result;
    }
    sub_4B36D0(creatureType, a3a, 1, (int)&v10, (int)&v7, (int)&slot);
    if ( v10 <= 0 )
    {
      *(_DWORD *)a3 = 1;
    }
    else
    {
      addCreaturesToArmy((ArmyInfo *)(a2 + 101), creatureType, a3a, slot);
      *(_DWORD *)a3 = 1;
    }
  }
LABEL_28:
  if ( v9 <= 5.0 )
    goto LABEL_33;
LABEL_29:
  giveXPToHero((Hero *)a2, a3a * creature_table[creatureType].hp, 1);
  Hero::checkForLevelUp((Hero *)a2);
  if ( Hero::getSecondarySkillLevelWithBonii((Hero *)a2, SECONDARY_SKILL_NECROMANCY) )
  {
    if ( ArmyInfo::hasRoomForCreatureType((ArmyInfo *)(a2 + 101), 47) )
    {
      v3 = Hero::getSecondarySkillLevelWithBonii((Hero *)a2, SECONDARY_SKILL_NECROMANCY);
      addCreaturesToArmy((ArmyInfo *)(a2 + 101), 47, (signed __int64)((double)v3 * (double)a3a * 0.1), -1);
    }
  }
  result = a3;
  *(_DWORD *)a3 = 1;
  return result;
}
