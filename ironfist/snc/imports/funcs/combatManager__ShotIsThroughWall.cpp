{
  signed int result; // eax@2
  int colDist; // ebx@10
  double v6; // st7@15
  combatManager *thisa; // [sp+2Ch] [bp-3Ch]@1
  int rowDiff; // [sp+38h] [bp-30h]@10
  int colDiff; // [sp+3Ch] [bp-2Ch]@10
  int v10; // [sp+40h] [bp-28h]@15
  float v11; // [sp+44h] [bp-24h]@13
  float v12; // [sp+48h] [bp-20h]@13
  signed int j; // [sp+4Ch] [bp-1Ch]@15
  int i; // [sp+50h] [bp-18h]@13
  int v15; // [sp+54h] [bp-14h]@11
  float v16; // [sp+5Ch] [bp-Ch]@11
  float v17; // [sp+5Ch] [bp-Ch]@13
  float v18; // [sp+64h] [bp-4h]@11
  float v19; // [sp+64h] [bp-4h]@13

  thisa = this;
  if ( this->isCastleBattle )
  {
    if ( this->heroes[side]
      && (hero::HasArtifact(this->heroes[side], ARTIFACT_GOLDEN_BOW) || thisa->heroes[side]->secondarySkillLevel[1]) )
    {
      result = 0;
    }
    else if ( !combatManager::InCastle(occupiedHex) && combatManager::InCastle(targHex) )
    {
      colDiff = targHex % 13 - occupiedHex % 13;
      rowDiff = targHex / 13 - occupiedHex / 13;
      colDist = abs(targHex % 13 - occupiedHex % 13);
      if ( colDist <= abs(rowDiff) )
      {
        v15 = abs(rowDiff);
        v16 = (double)(rowDiff <= 0 ? -1 : 1);
        v18 = (double)colDiff / (double)abs(rowDiff);
      }
      else
      {
        v15 = abs(colDiff);
        v18 = (double)(colDiff <= 0 ? -1 : 1);
        v16 = (double)rowDiff / (double)abs(colDiff);
      }
      v19 = v18 / 10.0;
      v17 = v16 / 10.0;
      v12 = (double)(occupiedHex % 13);
      v11 = (double)(occupiedHex / 13);
      for ( i = 0; 10 * v15 > i; ++i )
      {
        v12 = v12 + v19;
        v6 = v11 + v17;
        v11 = v6;
        v10 = (signed __int64)v12 + 13 * (unsigned __int64)(signed __int64)v6;
        for ( j = 0; j < 4; ++j )
        {
          if ( byte_4F4C30[11][j + 121] == v10 && thisa->wallStatus[j] != 2 && thisa->wallStatus[j] != 6 )
            return 1;
          if ( byte_4F4C30[11][j + 125] == v10 && thisa->turretStatus[j] != 2 )
            return 1;
          if ( v10 == 59 && thisa->drawBridgePosition == 4 )
            return 1;
        }
      }
      result = 0;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}