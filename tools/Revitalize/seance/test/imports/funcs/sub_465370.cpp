{
  signed int v1; // eax@1
  int v2; // ebp@4
  signed int v3; // edi@4
  signed int v4; // edi@9
  int v5; // ebp@9
  int i; // edi@13
  int v7; // ecx@14
  char *v8; // ebx@14
  int v9; // ebp@14
  int v10; // ebx@20
  signed int result; // eax@25

  v1 = 0;
  do
  {
    v1 += 98;
    combatManager->field_49F[v1 + 84] = 0;
  }
  while ( v1 < 11466 );
  if ( *(_DWORD *)&stack->creature.creature_flags & FLYER )
  {
    v2 = 0;
    v3 = 0;
    do
    {
      if ( CreatureStack::canPlaceCreature(stack, v2, 0, 0) )
        combatManager->combatGrid[v3].field_41 = 1;
      ++v3;
      ++v2;
    }
    while ( v3 < 117 );
  }
  else
  {
    v4 = 0;
    v5 = 0;
    do
    {
      if ( sub_405F00(stack, v5, 1) )
        combatManager->combatGrid[v4].field_41 = 1;
      ++v4;
      ++v5;
    }
    while ( v4 < 117 );
  }
  for ( i = 0; combatManager->numCreatures[-stack->owningSide + 1] > i; ++i )
  {
    v7 = i + -21 * stack->owningSide;
    v8 = (char *)&combatManager->creatures[1][v7];
    stack->targetOwner = combatManager->creatures[1][v7].owningSide;
    stack->targetStackIdx = *(_DWORD *)(v8 + 234);
    v9 = *(_DWORD *)(v8 + 122);
    if ( stack->creature.shots <= 0 || CreatureStack::getFreeNeighborBitmask(stack, stack->occupiedHex, 1, -1) != 255 )
    {
      if ( sub_405F00(stack, v9, 1) == 1 )
        combatManager->combatGrid[v9].field_41 = 1;
    }
    else
    {
      combatManager->combatGrid[v9].field_41 = 1;
    }
    if ( *((_DWORD *)v8 + 52) & 1 )
    {
      if ( (v10 = CreatureStack::getHexNeighbor(
                    (CreatureStack *)v8,
                    v9,
                    (unsigned int)(*(_DWORD *)(v8 + 134) - 1) < 1 ? 1 : 4),
            stack->creature.shots > 0)
        && CreatureStack::getFreeNeighborBitmask(stack, stack->occupiedHex, 1, -1) == 255
        || sub_405F00(stack, v10, 1) == 1 )
        combatManager->combatGrid[v10].field_41 = 1;
    }
  }
  result = -1;
  stack->targetStackIdx = -1;
  stack->targetOwner = -1;
  return result;
}
