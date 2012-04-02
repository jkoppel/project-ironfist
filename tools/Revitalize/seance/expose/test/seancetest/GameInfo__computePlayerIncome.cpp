signed int __thiscall GameInfo::computePlayerIncome(GameInfo *this, int playerIdx)
{
  signed int income; // [sp+28h] [bp-Ch]@1 MAPDST
  signed int i; // [sp+2Ch] [bp-8h]@1
  signed int j; // [sp+2Ch] [bp-8h]@9
  signed int k; // [sp+30h] [bp-4h]@21

  income = 0;
  for ( i = 0; i < 144; ++i )
  {
    if ( this->_8[7 * i + 1] == playerIdx )
    {
      if ( this->_8[7 * i + 2] == 6 )
        income += 1000;
      if ( this->_8[7 * i + 2] == 101 )
        income += 1000;
    }
  }
  for ( j = 0; j < 72; ++j )
  {
    if ( this->castles[j].ownerIdx == playerIdx )
    {
      if ( this->castles[j].buildingsBuiltFlags & 32 )
        income += 250;
      else
        income += 1000;
      if ( this->castles[j].buildingsBuiltFlags & 0x80u )
        income += 250;
      if ( this->castles[j].factionID == FACTION_WARLOCK && BYTE1(this->castles[j].buildingsBuiltFlags) & 32 )
        income += 500;
    }
  }
  income += 1000 * Player::quantityOfArtifactOwned(&this->players[playerIdx], ARTIFACT_ENDLESS_SACK_OF_GOLD);
  income += 750 * Player::quantityOfArtifactOwned(&this->players[playerIdx], ARTIFACT_ENDLESS_BAG_OF_GOLD);
  income += 500 * Player::quantityOfArtifactOwned(&this->players[playerIdx], ARTIFACT_ENDLESS_PURSE_OF_GOLD);
  income += 10000 * Player::quantityOfArtifactOwned(&this->players[playerIdx], ARTIFACT_GOLDEN_GOOSE);
  income += -250 * Player::quantityOfArtifactOwned(&this->players[playerIdx], ARTIFACT_TAX_LIEN);
  for ( k = 0; this->players[playerIdx].numHeroes > k; ++k )
    income += estatesSkillIncome[gameObject->heroes[this->players[playerIdx].heroesOwned[k]].secondarySkillLevel[13]];
  if ( !dword_524810[playerIdx] )
  {
    if ( !gameObject->difficulty )
      income = (signed __int64)((double)income * 0.75);
    if ( gameObject->difficulty == 2 )
      income = (signed __int64)((double)income * 1.29);
    if ( gameObject->difficulty == 3 )
      income = (signed __int64)((double)income * 1.45);
    if ( gameObject->difficulty == 4 )
      income = (signed __int64)((double)income * 1.6);
  }
  if ( this->playerHandicap[playerIdx] == 1 )
  {
    income = (signed __int64)((double)income * 0.85);
  }
  else
  {
    if ( this->playerHandicap[playerIdx] == 2 )
      income = (signed __int64)((double)income * 0.7);
  }
  return income;
}
