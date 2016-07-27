{
  signed int result; // eax@2
  char *v5; // eax@3
  int v6; // [sp+Ch] [bp-2Ch]@7
  CombatManager *thisa; // [sp+10h] [bp-28h]@1
  int v8; // [sp+14h] [bp-24h]@15
  int v9; // [sp+18h] [bp-20h]@15
  CreatureStack *othStack; // [sp+1Ch] [bp-1Ch]@3
  int targHex; // [sp+20h] [bp-18h]@3
  int bestIdx; // [sp+30h] [bp-8h]@1
  char v13; // [sp+34h] [bp-4h]@5

  thisa = this;
  bestIdx = CombatManager::findBestDistanceHPTradeoffStack(this, stack, side, stackBmask);
  if ( bestIdx == -1 )
  {
    result = 0;
  }
  else
  {
    v5 = (char *)thisa + 24234 * side + 1154 * bestIdx;
    othStack = (CreatureStack *)(v5 + 13647);
    targHex = *(_DWORD *)(v5 + 13769);
    stack->targetOwner = side;
    stack->targetStackIdx = bestIdx;
    if ( CreatureStack::getFreeNeighborBitmask(stack, stack->occupiedHex, 0, -1) == 255 )
    {
      v13 = stack->creature.speed;
      stack->creature.speed = 127;
      if ( !Pathfinder::doSomething1(pathfinder, stack->occupiedHex, targHex, stack, -1, 0)
        && othStack->creature.creature_flags & TWO_HEXER )
      {
        v6 = othStack->facingRight;
        if ( v6 )
        {
          if ( v6 == 1 )
            ++targHex;
        }
        else
        {
          --targHex;
        }
        if ( targHex != -1 )
          Pathfinder::doSomething1(pathfinder, stack->occupiedHex, targHex, stack, -1, 0);
      }
      stack->creature.speed = v13;
      if ( pathfinder->field_8 <= 1 )
      {
        result = 0;
      }
      else
      {
        couldBeCreatureActionType = 2;
        v8 = stack->creature.speed;
        v9 = pathfinder->field_8 - 1;
        notTargetForAISpell = stack->occupiedHex;
        while ( v9 >= 1 && v8 )
        {
          notTargetForAISpell = CreatureStack::getHexNeighbor(
                                  stack,
                                  notTargetForAISpell,
                                  *((_BYTE *)&pathfinder->field_2418 + v9--));
          --v8;
          if ( notTargetForAISpell > 0 )
          {
            if ( pathfindingRelatedArray[notTargetForAISpell] )
              v8 = 0;
          }
        }
        result = 1;
      }
    }
    else
    {
      couldBeCreatureActionType = 3;
      result = 1;
    }
  }
  return result;
}
