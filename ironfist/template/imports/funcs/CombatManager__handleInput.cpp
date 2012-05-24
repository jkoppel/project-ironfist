{
  int v3; // [sp+14h] [bp-30h]@12
  CombatManager *thisa; // [sp+18h] [bp-2Ch]@1
  InputEvent a2; // [sp+1Ch] [bp-28h]@32
  char *v6; // [sp+38h] [bp-Ch]@10
  CreatureStack *stack; // [sp+3Ch] [bp-8h]@23
  int v8; // [sp+40h] [bp-4h]@1

  thisa = this;
  v8 = 1;
  if ( !combatGraphicsOff )
  {
    if ( getTickCount() > animationFrameSwitchTime )
    {
      yieldToGlobalUpdater();
      animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                                + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 75.0);
    }
    if ( getTickCount() > nextCombatAnimationTime && !dword_4F31B0 )
    {
      dword_4F31B0 = 1;
      sub_4419B0(thisa);
      dword_4F31B0 = 0;
    }
  }
  CombatManager::handleGarrisonAndCatapult(thisa);
  if ( CombatManager::checkCombatOver(thisa, evt) )
    return 2;
  if ( combatGraphicsOff )
  {
LABEL_23:
    stack = &thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx];
    if ( stack->effectStrengths[5] )
    {
      sub_482B40(stack);
      if ( CombatManager::checkCombatOver(thisa, evt) )
        return 2;
    }
    if ( !combatGraphicsOff )
    {
      if ( thisa->notHandlingInputEvent )
      {
        while ( evt->eventCode != INPUT_KEYDOWN_EVENT_CODE
             && evt->eventCode != INPUT_LEFT_CLICK_EVENT_CODE
             && evt->eventCode != INPUT_RIGHT_CLICK
             && evt->eventCode )
          memcpy(evt, InputManager::nextInputEvent(inputManager, &a2), 0x1Cu);
        if ( evt->eventCode )
          thisa->notHandlingInputEvent = 0;
      }
      sub_440A90(thisa);
    }
    goto LABEL_36;
  }
  v6 = (char *)sub_46E3F0(1);
  if ( !v6 || v6[5] != 2 )
    goto LABEL_17;
  v3 = v6[6];
  if ( v3 == 11 )
  {
    sub_435F20(v6 + 9, (void *)*v6);
    goto LABEL_17;
  }
  if ( v3 != 23 )
  {
LABEL_17:
    if ( !dword_524C60 )
    {
      if ( evt->eventCode == INPUT_KEYDOWN_EVENT_CODE )
      {
        if ( evt->xCoordOrKeycode == '<' )
          sub_435F20(0, (void *)0xFFFFFFFF);
      }
      return 1;
    }
    goto LABEL_23;
  }
  couldBeCreatureActionType = *(_DWORD *)(v6 + 9);
  spellForAIToCast = *(_DWORD *)(v6 + 13);
  notTargetForAISpell = *(_DWORD *)(v6 + 17);
  dword_524C68 = *(_DWORD *)(v6 + 21);
LABEL_36:
  if ( !couldBeCreatureActionType )
  {
    if ( thisa->playerID[thisa->currentActionSide] != -1
      && *(&byte_524758 + thisa->playerID[thisa->currentActionSide])
      && !thisa->notHandlingInputEvent )
      v8 = sub_43C500(thisa, evt);
    else
      CombatManager::toplevelCombatAIFunction(thisa);
  }
  if ( couldBeCreatureActionType )
    v8 = CombatManager::processAction(thisa, evt);
  return v8;
}
