{
  hero *thisa; // [sp+14h] [bp-38h]@1
  signed int minSpeed; // [sp+18h] [bp-34h]@7
  __int16 speedToMovementPoints[9]; // [sp+1Ch] [bp-30h]@1
  int i; // [sp+30h] [bp-1Ch]@7
  __int16 v6; // [sp+34h] [bp-18h]@1
  __int16 v7; // [sp+38h] [bp-14h]@1
  __int16 v8; // [sp+3Ch] [bp-10h]@1
  __int16 v9; // [sp+40h] [bp-Ch]@1
  int points; // [sp+44h] [bp-8h]@2
  __int16 v11; // [sp+48h] [bp-4h]@1

  thisa = this;
  speedToMovementPoints[0] = 1000;
  speedToMovementPoints[1] = 1000;
  speedToMovementPoints[2] = 1000;
  speedToMovementPoints[3] = 1100;
  speedToMovementPoints[4] = 1200;
  speedToMovementPoints[5] = 1300;
  speedToMovementPoints[6] = 1400;
  speedToMovementPoints[7] = 1500;
  speedToMovementPoints[8] = 1500;
  v8 = 500;
  v9 = 1000;
  v11 = 500;
  v7 = 600;
  v6 = 300;
  if ( this->flags1 & 0x80 )
  {
    points = 1500;
    points = (signed __int64)((double)1500 * gfSSNavigationMod[this->secondarySkillLevel[5]]);
    if ( this->probablyOwnerIdx != -1 )
      points += 500 * game::MineTypesOwned(gpGame, this->probablyOwnerIdx, 100);
    if ( hero::HasArtifact(thisa, ARTIFACT_SAILORS_ASTROLABE_OF_MOBILITY) )
      points += 1000;
  }
  else
  {
    minSpeed = 7;
    for ( i = 0; i < 5; ++i )
    {
      if ( this->army.creatureTypes[i] != -1 && gMonsterDatabase[this->army.creatureTypes[i]].speed < minSpeed )
        minSpeed = gMonsterDatabase[this->army.creatureTypes[i]].speed;
    }
    points = speedToMovementPoints[minSpeed];
    points = (signed __int64)((double)points * gfSSLogisticsMod[this->secondarySkillLevel[2]]);
    if ( hero::HasArtifact(this, ARTIFACT_NOMAD_BOOTS_OF_MOBILITY) )
      points += 600;
    if ( hero::HasArtifact(thisa, ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY) )
      points += 300;
    if ( thisa->flags3 & 0x80 )
      points += 400;
  }
  if ( hero::HasArtifact(thisa, ARTIFACT_TRUE_COMPASS_OF_MOBILITY) )
    points += 500;
  if ( thisa->probablyOwnerIdx >= 0 )
  {
    if ( thisa->probablyOwnerIdx < 6 )
    {
      if ( !gbHumanPlayer[thisa->probablyOwnerIdx] )
      {
        if ( gpGame->difficulty >= 2 )
        {
          points += 75;
          if ( gpGame->players[thisa->probablyOwnerIdx].personality == 2 )
            points += 50;
        }
      }
    }
  }
  return points;
}