signed int __thiscall CombatManager::handleInput(CombatManager *this, InputEvent *evt)
{
  int v2; // edx@7
  int v4; // [sp+14h] [bp-30h]@12
  CombatManager *thisa; // [sp+18h] [bp-2Ch]@1
  InputEvent a2; // [sp+1Ch] [bp-28h]@32
  char *v7; // [sp+38h] [bp-Ch]@10
  CreatureStack *stack; // [sp+3Ch] [bp-8h]@23
  int v9; // [sp+40h] [bp-4h]@1

  thisa = this;
  v9 = 1;
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
      CombatManager::doFlavorAnimations(thisa);
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
  v7 = (char *)sub_46E3F0(1, v2);
  if ( !v7 || v7[5] != 2 )
    goto LABEL_17;
  v4 = v7[6];
  if ( v4 == 11 )
  {
    sub_435F20(v7 + 9, (void *)*v7);
    goto LABEL_17;
  }
  if ( v4 != 23 )
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
  couldBeCreatureActionType = *(_DWORD *)(v7 + 9);
  spellForAIToCast = *(_DWORD *)(v7 + 13);
  notTargetForAISpell = *(_DWORD *)(v7 + 17);
  dword_524C68 = *(_DWORD *)(v7 + 21);
LABEL_36:
  if ( !couldBeCreatureActionType )
  {
    if ( thisa->playerID[thisa->currentActionSide] != -1
      && *(&byte_524758 + thisa->playerID[thisa->currentActionSide])
      && !thisa->notHandlingInputEvent )
      v9 = sub_43C500(thisa, evt);
    else
      CombatManager::toplevelCombatAIFunction(thisa);
  }
  if ( couldBeCreatureActionType )
    v9 = CombatManager::processAction(thisa, evt);
  return v9;
}
