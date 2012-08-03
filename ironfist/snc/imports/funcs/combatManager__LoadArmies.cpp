{
  combatManager *thisa; // [sp+Ch] [bp-10h]@1
  signed int i; // [sp+10h] [bp-Ch]@3
  signed int j; // [sp+10h] [bp-Ch]@7
  signed int armyIdx; // [sp+14h] [bp-8h]@1
  signed int armyIdxa; // [sp+14h] [bp-8h]@9
  int armyIdxb; // [sp+14h] [bp-8h]@13
  int attackerOccHex; // [sp+18h] [bp-4h]@18
  int defenderOccHex; // [sp+18h] [bp-4h]@26

  thisa = this;
  this->numCreatures[1] = 0;
  this->numCreatures[0] = this->numCreatures[1];
  for ( armyIdx = 0; armyIdx < 20; ++armyIdx )
  {
    for ( i = 0; i < 2; ++i )
    {
      this->creatures[i][armyIdx].quantity = 0;
      this->creatures[i][armyIdx].creatureIdx = -1;
    }
  }
  for ( j = 0; j < 2; ++j )
  {
    for ( armyIdxa = 0; armyIdxa < 20; ++armyIdxa )
      army::InitClean(&thisa->creatures[j][armyIdxa]);
  }
  for ( armyIdxb = 0; armyIdxb < 5; ++armyIdxb )
  {
    if ( thisa->armies[0]->creatureTypes[armyIdxb] != -1 )
    {
      if ( thisa->heroes[0] && thisa->heroes[0]->flags2 & HERO_ARMY_COMPACT )
        attackerOccHex = 13 * armyIdxb + 27;
      else
        attackerOccHex = 26 * armyIdxb + 1;
      army::Init(
        (army *)thisa->creatures + thisa->numCreatures[0],
        thisa->armies[0]->creatureTypes[armyIdxb],
        thisa->armies[0]->quantities[armyIdxb],
        0,
        thisa->numCreatures[0],
        attackerOccHex,
        armyIdxb);
      army::LoadResources((army *)thisa->creatures + thisa->numCreatures[0]++);
    }
    if ( thisa->armies[1]->creatureTypes[armyIdxb] != -1 )
    {
      if ( thisa->heroes[1] && thisa->heroes[1]->flags2 & HERO_ARMY_COMPACT
        || thisa->castles[1] && thisa->castles[1]->_2[0] )
        defenderOccHex = 13 * armyIdxb + 37;
      else
        defenderOccHex = 26 * armyIdxb + 11;
      army::Init(
        &thisa->creatures[1][thisa->numCreatures[1]],
        thisa->armies[1]->creatureTypes[armyIdxb],
        thisa->armies[1]->quantities[armyIdxb],
        1,
        thisa->numCreatures[1],
        defenderOccHex,
        armyIdxb);
      army::LoadResources(&thisa->creatures[1][thisa->numCreatures[1]++]);
    }
  }
}