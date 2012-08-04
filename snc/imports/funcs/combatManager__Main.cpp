{
  int v2; // edx@7
  int v4; // [sp+14h] [bp-30h]@12
  combatManager *thisa; // [sp+18h] [bp-2Ch]@1
  tag_message a2; // [sp+1Ch] [bp-28h]@32
  char *v7; // [sp+38h] [bp-Ch]@10
  army *stack; // [sp+3Ch] [bp-8h]@23
  int v9; // [sp+40h] [bp-4h]@1

  thisa = this;
  v9 = 1;
  if ( !gbNoShowCombat )
  {
    if ( KBTickCount() > glTimers )
    {
      PollSound();
      glTimers = (signed __int64)((double)KBTickCount() + gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 75.0);
    }
    if ( KBTickCount() > nextCombatAnimationTime && !gbProcessingCombatAction )
    {
      gbProcessingCombatAction = 1;
      combatManager::CycleCombatScreen(thisa);
      gbProcessingCombatAction = 0;
    }
  }
  combatManager::CheckCastleAttack(thisa);
  if ( combatManager::CheckWin(thisa, evt) )
    return 2;
  if ( gbNoShowCombat )
  {
LABEL_23:
    stack = &thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx];
    if ( stack->effectStrengths[5] )
    {
      army::GoBerserk(stack);
      if ( combatManager::CheckWin(thisa, evt) )
        return 2;
    }
    if ( !gbNoShowCombat )
    {
      if ( thisa->notHandlingInputEvent )
      {
        while ( evt->eventCode != INPUT_KEYDOWN_EVENT_CODE
             && evt->eventCode != INPUT_LEFT_CLICK_EVENT_CODE
             && evt->eventCode != INPUT_RIGHT_CLICK
             && evt->eventCode )
          memcpy(evt, inputManager::GetEvent(gpInputManager, &a2), 0x1Cu);
        if ( evt->eventCode )
          thisa->notHandlingInputEvent = 0;
      }
      combatManager::CheckChangeSelector(thisa);
    }
    goto LABEL_36;
  }
  v7 = (char *)GetRemoteData(1, v2);
  if ( !v7 || v7[5] != 2 )
    goto LABEL_17;
  v4 = v7[6];
  if ( v4 == 11 )
  {
    PopNetBox(v7 + 9, (void *)*v7);
    goto LABEL_17;
  }
  if ( v4 != 23 )
  {
LABEL_17:
    if ( !gbThisNetHasControl )
    {
      if ( evt->eventCode == INPUT_KEYDOWN_EVENT_CODE )
      {
        if ( evt->xCoordOrKeycode == '<' )
          PopNetBox(0, (void *)0xFFFFFFFF);
      }
      return 1;
    }
    goto LABEL_23;
  }
  giNextAction = *(_DWORD *)(v7 + 9);
  giNextActionExtra = *(_DWORD *)(v7 + 13);
  giNextActionGridIndex = *(_DWORD *)(v7 + 17);
  giNextActionGridIndex2 = *(_DWORD *)(v7 + 21);
LABEL_36:
  if ( !giNextAction )
  {
    if ( thisa->playerID[thisa->currentActionSide] != -1
      && *(&gbThisNetHumanPlayer + thisa->playerID[thisa->currentActionSide])
      && !thisa->notHandlingInputEvent )
      v9 = combatManager::ProcessCombatMsg(thisa, evt);
    else
      combatManager::CheckGetAIMove(thisa);
  }
  if ( giNextAction )
    v9 = combatManager::ProcessNextAction(thisa, evt);
  return v9;
}