{
  int dist; // eax@4
  int hp; // edx@4
  combatManager *thisa; // [sp+Ch] [bp-1Ch]@1
  signed int t; // [sp+14h] [bp-14h]@1
  int i; // [sp+18h] [bp-10h]@1
  signed int bestIdx; // [sp+1Ch] [bp-Ch]@1
  int lowestScore; // [sp+20h] [bp-8h]@1

  thisa = this;
  t = 1;
  lowestScore = 9999999;
  bestIdx = -1;
  for ( i = 0; thisa->numCreatures[side] > i; ++i )
  {
    if ( t & stackBmask )
    {
      dist = searchArray::QuickDistance(
               thisa->combatGrid[stack->occupiedHex].centerX,
               thisa->combatGrid[stack->occupiedHex].occupyingCreatureBottomY,
               thisa->combatGrid[thisa->creatures[side][i].occupiedHex].centerX,
               thisa->combatGrid[thisa->creatures[side][i].occupiedHex].occupyingCreatureBottomY);
      hp = thisa->creatures[side][i].creature.hp;
      if ( lowestScore > 1000 * dist - thisa->creatures[side][i].quantity * hp )
      {
        bestIdx = i;
        lowestScore = 1000 * dist - thisa->creatures[side][i].quantity * hp;
      }
    }
    t *= 2;
  }
  return bestIdx;
}