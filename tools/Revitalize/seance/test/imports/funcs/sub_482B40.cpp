{
  int v1; // ST28_4@33
  CreatureStack *thisa; // [sp+Ch] [bp-50h]@1
  signed int v3; // [sp+18h] [bp-44h]@25
  signed int v4; // [sp+1Ch] [bp-40h]@25
  signed int i; // [sp+24h] [bp-38h]@7
  int j; // [sp+28h] [bp-34h]@9
  signed int v7; // [sp+2Ch] [bp-30h]@7
  signed int v8; // [sp+30h] [bp-2Ch]@7
  signed int v9; // [sp+34h] [bp-28h]@7
  int v10; // [sp+38h] [bp-24h]@17
  int neighbor; // [sp+3Ch] [bp-20h]@4
  int tmp; // [sp+40h] [bp-1Ch]@1
  int freeNeighborBmask; // [sp+44h] [bp-18h]@1
  int targFound; // [sp+48h] [bp-14h]@1
  int v15; // [sp+4Ch] [bp-10h]@1
  signed int neighborIdx; // [sp+50h] [bp-Ch]@1
  int aliveStackBmask[2]; // [sp+54h] [bp-8h]@1

  thisa = this;
  targFound = 0;
  neighborIdx = 0;
  v15 = 0;
  tmp = this->quantity;
  this->quantity = 0;
  aliveStackBmask[0] = CombatManager::getAliveStackBitmask(combatManager, 0);
  aliveStackBmask[1] = CombatManager::getAliveStackBitmask(combatManager, 1);
  thisa->quantity = tmp;
  freeNeighborBmask = CreatureStack::getFreeNeighborBitmask(thisa, thisa->occupiedHex, 2, -1);
  if ( freeNeighborBmask != 255 )
  {
    while ( !targFound )
    {
      neighborIdx = unseededNextRand(0, 7);
      if ( !((1 << neighborIdx) & freeNeighborBmask) )
      {
        couldBeCreatureActionType = 2;
        CreatureStack::neighboringHexOccupied(thisa, thisa->occupiedHex, neighborIdx, 2, -1, &neighbor);
        notTargetForAISpell = neighbor;
        targFound = 1;
        goto LABEL_46;
      }
    }
LABEL_42:
    if ( thisa->creature.creature_flags & FLYER
      || !sub_46D110(combatManager, thisa, thisa->owningSide, aliveStackBmask[thisa->owningSide])
      && !sub_46D110(combatManager, thisa, 1 - thisa->owningSide, aliveStackBmask[1 - thisa->owningSide]) )
      couldBeCreatureActionType = 3;
    goto LABEL_46;
  }
  v7 = -1;
  v9 = -1;
  v8 = 999999;
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; combatManager->numCreatures[i] > j; ++j )
    {
      if ( thisa->owningSide != i || thisa->stackIdx != j )
      {
        if ( !(combatManager->creatures[i][j].creature.creature_flags & DEAD) )
        {
          if ( combatManager->creatures[i][j].quantity > 0 )
          {
            v10 = octogonalDistance(
                    combatManager->combatGrid[thisa->occupiedHex].centerX,
                    combatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY,
                    combatManager->combatGrid[combatManager->creatures[i][j].occupiedHex].centerX,
                    combatManager->combatGrid[combatManager->creatures[i][j].occupiedHex].occupyingCreatureBottomY);
            if ( v10 < v8 )
            {
              v7 = j;
              v9 = i;
              v8 = v10;
            }
          }
        }
      }
    }
  }
  if ( v7 != -1 && thisa->creature.creature_flags & 4 && thisa->creature.shots > 0 )
  {
    couldBeCreatureActionType = 2;
    notTargetForAISpell = combatManager->creatures[v9][v7].occupiedHex;
    goto LABEL_46;
  }
  v3 = -1;
  v4 = -1;
  if ( sub_46CB80(combatManager, (int)thisa, 0, aliveStackBmask[0]) )
  {
    couldBeCreatureActionType = 2;
    v3 = notTargetForAISpell;
  }
  if ( sub_46CB80(combatManager, (int)thisa, 1, aliveStackBmask[1]) )
  {
    couldBeCreatureActionType = 2;
    v4 = notTargetForAISpell;
  }
  notTargetForAISpell = -1;
  if ( v3 != -1 || v4 != -1 )
  {
    if ( v3 == -1 || v4 == -1 )
    {
      if ( v3 == -1 )
      {
        if ( v4 != -1 )
          notTargetForAISpell = v4;
      }
      else
      {
        notTargetForAISpell = v3;
      }
    }
    else
    {
      v1 = octogonalDistance(
             combatManager->combatGrid[thisa->occupiedHex].centerX,
             combatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY,
             combatManager->combatGrid[v3].centerX,
             combatManager->combatGrid[v3].occupyingCreatureBottomY);
      if ( v1 >= octogonalDistance(
                   combatManager->combatGrid[thisa->occupiedHex].centerX,
                   combatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY,
                   combatManager->combatGrid[v4].centerX,
                   combatManager->combatGrid[v4].occupyingCreatureBottomY) )
        notTargetForAISpell = v4;
      else
        notTargetForAISpell = v3;
    }
  }
  if ( notTargetForAISpell == -1 )
    goto LABEL_42;
LABEL_46:
  if ( couldBeCreatureActionType == 2 )
  {
    if ( combatManager->combatGrid[notTargetForAISpell].unitOwner == thisa->owningSide )
      combatManager->field_339D[thisa->owningSide] = 1;
  }
}
