{
  int v1; // ST28_4@33
  army *thisa; // [sp+Ch] [bp-50h]@1
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
  aliveStackBmask[0] = combatManager::GetAllMask(gpCombatManager, 0);
  aliveStackBmask[1] = combatManager::GetAllMask(gpCombatManager, 1);
  thisa->quantity = tmp;
  freeNeighborBmask = army::GetAttackMask(thisa, thisa->occupiedHex, 2, -1);
  if ( freeNeighborBmask != 255 )
  {
    while ( !targFound )
    {
      neighborIdx = Random(0, 7);
      if ( !((1 << neighborIdx) & freeNeighborBmask) )
      {
        giNextAction = 2;
        army::ValidAttack(thisa, thisa->occupiedHex, neighborIdx, 2, -1, &neighbor);
        giNextActionGridIndex = neighbor;
        targFound = 1;
        goto LABEL_46;
      }
    }
LABEL_42:
    if ( thisa->creature.creature_flags & FLYER
      || !combatManager::WalkTowardArmy(gpCombatManager, thisa, thisa->owningSide, aliveStackBmask[thisa->owningSide])
      && !combatManager::WalkTowardArmy(
            gpCombatManager,
            thisa,
            1 - thisa->owningSide,
            aliveStackBmask[1 - thisa->owningSide]) )
      giNextAction = 3;
    goto LABEL_46;
  }
  v7 = -1;
  v9 = -1;
  v8 = 999999;
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; gpCombatManager->numCreatures[i] > j; ++j )
    {
      if ( thisa->owningSide != i || thisa->stackIdx != j )
      {
        if ( !(gpCombatManager->creatures[i][j].creature.creature_flags & DEAD) )
        {
          if ( gpCombatManager->creatures[i][j].quantity > 0 )
          {
            v10 = searchArray::QuickDistance(
                    gpCombatManager->combatGrid[thisa->occupiedHex].centerX,
                    gpCombatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY,
                    gpCombatManager->combatGrid[gpCombatManager->creatures[i][j].occupiedHex].centerX,
                    gpCombatManager->combatGrid[gpCombatManager->creatures[i][j].occupiedHex].occupyingCreatureBottomY);
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
    giNextAction = 2;
    giNextActionGridIndex = gpCombatManager->creatures[v9][v7].occupiedHex;
    goto LABEL_46;
  }
  v3 = -1;
  v4 = -1;
  if ( combatManager::AttemptAttack(gpCombatManager, (int)thisa, 0, aliveStackBmask[0]) )
  {
    giNextAction = 2;
    v3 = giNextActionGridIndex;
  }
  if ( combatManager::AttemptAttack(gpCombatManager, (int)thisa, 1, aliveStackBmask[1]) )
  {
    giNextAction = 2;
    v4 = giNextActionGridIndex;
  }
  giNextActionGridIndex = -1;
  if ( v3 != -1 || v4 != -1 )
  {
    if ( v3 == -1 || v4 == -1 )
    {
      if ( v3 == -1 )
      {
        if ( v4 != -1 )
          giNextActionGridIndex = v4;
      }
      else
      {
        giNextActionGridIndex = v3;
      }
    }
    else
    {
      v1 = searchArray::QuickDistance(
             gpCombatManager->combatGrid[thisa->occupiedHex].centerX,
             gpCombatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY,
             gpCombatManager->combatGrid[v3].centerX,
             gpCombatManager->combatGrid[v3].occupyingCreatureBottomY);
      if ( v1 >= searchArray::QuickDistance(
                   gpCombatManager->combatGrid[thisa->occupiedHex].centerX,
                   gpCombatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY,
                   gpCombatManager->combatGrid[v4].centerX,
                   gpCombatManager->combatGrid[v4].occupyingCreatureBottomY) )
        giNextActionGridIndex = v4;
      else
        giNextActionGridIndex = v3;
    }
  }
  if ( giNextActionGridIndex == -1 )
    goto LABEL_42;
LABEL_46:
  if ( giNextAction == 2 )
  {
    if ( gpCombatManager->combatGrid[giNextActionGridIndex].unitOwner == thisa->owningSide )
      gpCombatManager->field_339D[thisa->owningSide] = 1;
  }
}