{
  int v2; // edx@6
  int v3; // ecx@32
  int v4; // ecx@32
  combatManager *thisa; // [sp+10h] [bp-28h]@1
  int v7; // [sp+14h] [bp-24h]@15
  Spell v8; // [sp+18h] [bp-20h]@15
  int v9; // [sp+1Ch] [bp-1Ch]@15
  int v10; // [sp+20h] [bp-18h]@15
  int v11; // [sp+24h] [bp-14h]@15
  int v12; // [sp+28h] [bp-10h]@17
  int v13; // [sp+2Ch] [bp-Ch]@1
  int v14; // [sp+30h] [bp-8h]@1
  army *v15; // [sp+34h] [bp-4h]@17

  thisa = this;
  combatManager::ClearCombatMessages(this, 0);
  v13 = 1;
  v14 = 0;
  gbProcessingCombatAction = 1;
  if ( *(_DWORD *)&thisa->_15[100] != -1 || *(_DWORD *)&thisa->_15[104] != -1 )
  {
    *(_DWORD *)&thisa->_15[104] = -1;
    *(_DWORD *)&thisa->_15[100] = *(_DWORD *)&thisa->_15[104];
    v14 = 1;
  }
  if ( giNextAction )
    LogInt(
      (int)"Process Act",
      giNextAction,
      giNextActionGridIndex,
      giNextActionGridIndex2,
      giNextActionExtra,
      thisa->otherCurrentSideThing,
      thisa->someSortOfStackIdx,
      thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].occupiedHex);
  mouseManager::SetPointer(gpMouseManager, 6);
  combatManager::UpdateMouseGrid(thisa, -1, 1);
  memset(thisa->field_49F, 0, 0x75u);
  if ( combatManager::UpdateGrid(thisa, v2, 0, 0) )
    v14 = 1;
  if ( v14 )
    combatManager::DrawFrame(thisa, 1, 0, 0, 0, 75, 1, 1);
  if ( gbThisNetHasControl )
  {
    if ( gbRemoteOn )
    {
      if ( *(_QWORD *)&thisa->playerID[0] >= 0i64 )
      {
        if ( gbHumanPlayer[thisa->playerID[1]] )
        {
          if ( gbHumanPlayer[thisa->playerID[0]] )
          {
            v7 = giNextAction;
            v8 = giNextActionExtra;
            v9 = giNextActionGridIndex;
            v10 = giNextActionGridIndex2;
            LogInt(
              (int)"About to T",
              *(&iCombatControlNetPos + 1 - thisa->currentActionSide),
              -999,
              -999,
              -999,
              -999,
              -999,
              -999);
            v11 = TransmitRemoteData(&v7, *(&iCombatControlNetPos + 1 - thisa->currentActionSide), 0x10u, 23, 1, 1, -1);
            LogStr("Post T");
            if ( !v11 )
              ShutDown(0);
          }
        }
      }
    }
  }
  v15 = &thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx];
  v12 = 0;
  if ( !combatManager::CheckWin(thisa, a2) )
  {
    switch ( giNextAction )
    {
      case 1:
        combatManager::ResetCyclingCreatures(thisa);
        combatManager::CastSpell(thisa, giNextActionExtra, giNextActionGridIndex, 0, giNextActionGridIndex2);
        if ( thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].quantity <= 0 )
          v12 = 1;
        combatManager::ResetCycleTimers(thisa);
        goto LABEL_36;
      case 2:
        combatManager::ResetCyclingCreatures(thisa);
        army::MoveAttack(v15, giNextActionGridIndex, 0);
        *(_DWORD *)&v15->creature.creature_flags |= MAYBE_NOT_LOST_TURN;
        if ( combatManager::CheckWin(thisa, a2) )
        {
          v13 = 2;
          break;
        }
        combatManager::CheckApplyGoodMorale(thisa, thisa->otherCurrentSideThing, thisa->someSortOfStackIdx);
        v12 = 1;
        combatManager::ResetCycleTimers(thisa);
        goto LABEL_36;
      case 6:
        combatManager::ResetCyclingCreatures(thisa);
        if ( giNextActionExtra != -1 && v15->occupiedHex != giNextActionExtra )
          army::MoveAttack(v15, giNextActionExtra, 1);
        army::MoveAttack(v15, giNextActionGridIndex, 0);
        *(_DWORD *)&v15->creature.creature_flags |= MAYBE_NOT_LOST_TURN;
        if ( combatManager::CheckWin(thisa, a2) )
        {
          v13 = 2;
        }
        else
        {
          combatManager::CheckApplyGoodMorale(thisa, thisa->otherCurrentSideThing, thisa->someSortOfStackIdx);
          v12 = 1;
          combatManager::ResetCycleTimers(thisa);
LABEL_36:
          giNextAction = 0;
          if ( combatManager::CheckWin(thisa, a2) )
          {
            v13 = 2;
          }
          else
          {
            combatManager::TestRaiseDoor(thisa);
            if ( v12 && !combatManager::GetNextArmy(thisa, 1) )
            {
              combatManager::ResetRound(thisa);
              combatManager::GetNextArmy(thisa, 1);
            }
            combatManager::CheckChangeSelector(thisa);
          }
        }
        break;
      case 4:
        thisa->field_F377[thisa->currentActionSide] = 1;
        gbRetreatWin = 1;
        combatManager::ResetCycleTimers(thisa);
        goto LABEL_36;
      case 5:
        gbCombatSurrender = 1;
        gbRetreatWin = 1;
        thisa->field_351F[thisa->currentActionSide] = 1;
        v3 = thisa->playerID[thisa->currentActionSide];
        gpGame->players[v3].resources[6] -= giNextActionExtra;
        v4 = thisa->playerID[1 - thisa->currentActionSide];
        gpGame->players[v4].resources[6] += giNextActionExtra;
        combatManager::ResetCycleTimers(thisa);
        goto LABEL_36;
      case 3:
        *(_DWORD *)&v15->creature.creature_flags |= MAYBE_NOT_LOST_TURN;
        v12 = 1;
        goto LABEL_36;
      case 7:
        *(_DWORD *)&v15->creature.creature_flags |= 0x1000u;
        v12 = 1;
        goto LABEL_36;
      case 0:
        goto LABEL_36;
    }
  }
  gbProcessingCombatAction = 0;
  combatManager::ResetMouse(thisa);
  return v13;
}