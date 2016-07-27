{
  Pathfinder *thisa; // esi@1
  int othHex; // edx@2
  CreatureStack *stacka; // ebp@2
  signed int deltaX; // ecx@3
  signed int row; // edi@4
  int moatHex; // ecx@5
  int v12; // eax@16
  int v13; // eax@22
  signed int v14; // edi@22
  char *v15; // ebx@23
  char *v16; // ecx@23
  __int64 v17; // qax@23
  __int64 v18; // qax@23
  signed int v19; // ecx@23
  int v20; // ebx@24
  int v21; // eax@27
  signed int v22; // ebx@30
  int v23; // eax@32
  int v24; // ecx@32
  signed int v25; // ecx@38
  int result; // eax@45
  signed int v27; // esi@47
  char v28; // dl@48
  int v29; // ebx@48
  int v30; // edx@52
  int v31; // eax@52
  int v32; // eax@53
  int v33; // [sp+10h] [bp-30h]@16
  char *v34; // [sp+18h] [bp-28h]@21
  signed int v35; // [sp+1Ch] [bp-24h]@23
  int availNeighborBmask; // [sp+1Ch] [bp-24h]@30
  int othTargetHex; // [sp+20h] [bp-20h]@2
  int othTargetHexa; // [sp+20h] [bp-20h]@22
  signed int minSomething; // [sp+2Ch] [bp-14h]@16
  int a4; // [sp+30h] [bp-10h]@18
  char v41[12]; // [sp+34h] [bp-Ch]@5

  thisa = this;
  memset(pathfindingRelatedArray, 0, 116u);
  pathfindingRelatedArray[116] = 0;
  if ( combatManager->hasMoat )
  {
    othHex = -1;
    stacka = stack;
    othTargetHex = -1;
    if ( *(_DWORD *)&stack->creature.creature_flags & TWO_HEXER )
    {
      deltaX = (unsigned int)(stack->facingRight - 1) < 1 ? 1 : -1;
      othHex = deltaX + stack->occupiedHex;
      othTargetHex = deltaX + targHex;
    }
    row = 0;
    do
    {
      moatHex = moatHexes[row];
      v41[row] = combatManager->combatGrid[moatHex].probablyIsBlocked;
      if ( (row != 4 || combatManager->drawBridgePosition == MOAT_CLOSED)
        && (targHex != moatHex && othTargetHex != moatHex || a6)
        && stack->occupiedHex != moatHex
        && othHex != moatHex )
        pathfindingRelatedArray[moatHex] = 1;
      ++row;
    }
    while ( row < 9 );
  }
  else
  {
    stacka = stack;
  }
  minSomething = 640;
  v33 = -1;
  v12 = targHex;
  if ( !a5 )
    v12 = -1;
  a4 = v12;
  memset(thisa->mainDataStructure, 0, sizeof(thisa->mainDataStructure));
  memset(thisa->field_2414, 0, 9 * mapHeight * mapWidth);
  thisa->field_0 = 0;
  thisa->field_8 = 0;
  if ( !checkHexGridIdxBounds(sourceHex) || !checkHexGridIdxBounds(targHex) || !stacka )
  {
LABEL_45:
    result = 0;
    goto LABEL_46;
  }
  v34 = (char *)&thisa->field_2418;
  Pathfinder::doSomething5(thisa, sourceHex, stacka->facingRight < 1u ? 4 : 1, 0, stacka->creature.speed);
  if ( !thisa->field_0 )
    goto LABEL_43;
  while ( 1 )
  {
    v13 = thisa->field_0 - 1;
    thisa->field_0 = v13;
    HIWORD(v14) = 0;
    othTargetHexa = *(_DWORD *)&thisa->mainDataStructure[v13].field_0;
    LOWORD(v14) = *(_DWORD *)&thisa->mainDataStructure[v13].field_0 >> 16;
    if ( stacka->creature.speed < v14 )
      goto LABEL_36;
    v15 = (char *)combatManager + 98 * (unsigned __int8)othTargetHexa;
    v16 = (char *)combatManager + 98 * targHex;
    v17 = (signed int)*((_WORD *)v15 + 650) - (signed int)*((_WORD *)v16 + 650);
    v35 = (HIDWORD(v17) ^ v17) - HIDWORD(v17);
    v18 = (signed int)*((_WORD *)v15 + 651) - (signed int)*((_WORD *)v16 + 651);
    v19 = (HIDWORD(v18) ^ v18) - HIDWORD(v18);
    v20 = v35 < v19 ? v19 + v35 / 2 : v19 / 2 + v35;
    if ( stacka->targetOwner != -1 )
    {
      v21 = CreatureStack::getFreeNeighborBitmask(stacka, (unsigned __int8)othTargetHexa, 0, a4);
      if ( v21 != 255 )
        break;
    }
    if ( v20 < minSomething )
    {
      minSomething = v20;
      v33 = (unsigned __int8)othTargetHexa;
      if ( !v20 )
        goto LABEL_43;
    }
    v22 = 0;
    availNeighborBmask = CreatureStack::canMoveToNeighborBitmask(stacka, (unsigned __int8)othTargetHexa);
    do
    {
      if ( !((1 << v22) & availNeighborBmask) )
      {
        v23 = CreatureStack::getHexNeighbor(stacka, (unsigned __int8)othTargetHexa, v22);
        v24 = 0;
        if ( pathfindingRelatedArray[v23] )
          v24 = stacka->speed + 2;
        Pathfinder::doSomething5(thisa, v23, v22, v14 + v24 + 1, stacka->creature.speed);
      }
      ++v22;
    }
    while ( v22 < 8 );
LABEL_36:
    if ( !thisa->field_0 )
      goto LABEL_43;
  }
  v25 = 0;
  while ( (1 << v25) & v21 )
  {
    ++v25;
    if ( v25 >= 8 )
      goto LABEL_43;
  }
  v34 = (char *)&thisa->field_2418 + 1;
  LOBYTE(thisa->field_2418) = v25;
  v33 = (unsigned __int8)othTargetHexa;
  ++thisa->field_8;
LABEL_43:
  if ( stacka->targetOwner == -1 )
  {
    if ( v33 == targHex )
      goto LABEL_51;
    goto LABEL_45;
  }
  if ( !thisa->field_8 )
    goto LABEL_45;
LABEL_51:
  while ( v33 != sourceHex )
  {
    v30 = (int)&thisa->field_2414[v33];
    ++v34;
    *(v34 - 1) = *(_BYTE *)(v30 + 4) >> 4;
    v31 = thisa->field_8 + 1;
    thisa->field_8 = v31;
    if ( v31 >= 256 )
      break;
    v32 = mirrorNeighborIdx((unsigned __int8)(*(_BYTE *)(v30 + 4) >> 4));
    v33 = CreatureStack::getHexNeighbor(stacka, v33, v32);
  }
  result = thisa->field_8;
LABEL_46:
  if ( combatManager->hasMoat )
  {
    v27 = 0;
    do
    {
      v28 = v41[v27];
      v29 = moatHexes[v27++];
      combatManager->combatGrid[v29].probablyIsBlocked = v28;
    }
    while ( v27 < 9 );
  }
  return result;
}
