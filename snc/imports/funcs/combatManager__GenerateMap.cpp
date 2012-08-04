{
  signed int i; // [sp+18h] [bp-Ch]@4
  signed int j; // [sp+1Ch] [bp-8h]@6

  if ( this->isCastleBattle == 1 )
    this->probablyCatapultImgIdx[0] = 0;
  else
    this->probablyCatapultImgIdx[0] = -1;
  for ( i = 0; i < 9; ++i )
  {
    for ( j = 0; j < 13; ++j )
    {
      this->combatGrid[j + 13 * i].occupyingCreatureBottomY = 42 * (i + 1) + 63;
      this->combatGrid[j + 13 * i].centerX = 45 * (j - 1) + ((i & 1u) < 1 ? 44 : 22) - (j - 1) + 67;
      this->combatGrid[j + 13 * i].leftX = 45 * (j - 1) + ((i & 1u) < 1 ? 22 : 0) - (j - 1) + 67;
      this->combatGrid[j + 13 * i].topY = 42 * i + 63;
      this->combatGrid[j + 13 * i].rightX = this->combatGrid[j + 13 * i].leftX + 44;
      this->combatGrid[j + 13 * i].otherY1 = this->combatGrid[j + 13 * i].topY + 42;
      this->combatGrid[j + 13 * i].otherY2 = this->combatGrid[j + 13 * i].topY + 52;
      this->combatGrid[j + 13 * i].unitOwner = -1;
      this->combatGrid[j + 13 * i].stackIdx = -1;
      this->combatGrid[j + 13 * i].isOccupierNonPrimaryHex = -1;
      this->combatGrid[j + 13 * i].combatObjIdx = -1;
      this->combatGrid[j + 13 * i].isBlocked = 0;
      this->combatGrid[j + 13 * i].numCorpses = 0;
    }
  }
  return SRandom(8, 15);
}