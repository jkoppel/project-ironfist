{
  int v2; // ecx@32
  int v3; // ecx@32
  CombatManager *thisa; // [sp+10h] [bp-28h]@1
  int v6; // [sp+14h] [bp-24h]@15
  Spell v7; // [sp+18h] [bp-20h]@15
  int v8; // [sp+1Ch] [bp-1Ch]@15
  int v9; // [sp+20h] [bp-18h]@15
  int v10; // [sp+24h] [bp-14h]@15
  int v11; // [sp+28h] [bp-10h]@17
  int v12; // [sp+2Ch] [bp-Ch]@1
  int v13; // [sp+30h] [bp-8h]@1
  CreatureStack *v14; // [sp+34h] [bp-4h]@17

  thisa = this;
  sub_4C3300(this, 0);
  v12 = 1;
  v13 = 0;
  dword_4F31B0 = 1;
  if ( *(_DWORD *)&thisa->_15[100] != -1 || *(_DWORD *)&thisa->_15[104] != -1 )
  {
    *(_DWORD *)&thisa->_15[104] = -1;
    *(_DWORD *)&thisa->_15[100] = *(_DWORD *)&thisa->_15[104];
    v13 = 1;
  }
  if ( couldBeCreatureActionType )
    logUpTo7Ints(
      (int)"Process Act",
      couldBeCreatureActionType,
      notTargetForAISpell,
      dword_524C68,
      spellForAIToCast,
      thisa->otherCurrentSideThing,
      thisa->someSortOfStackIdx,
      thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].occupiedHex);
  MouseManager::setSpriteIdx(mouseManager, 6);
  sub_4C4960(thisa, -1, 1);
  memset(thisa->field_49F, 0, 0x75u);
  if ( sub_4C3FF0(thisa, 0, 0) )
    v13 = 1;
  if ( v13 )
    CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
  if ( dword_524C60 )
  {
    if ( dword_4F7494 )
    {
      if ( *(_QWORD *)&thisa->playerID[0] >= 0i64 )
      {
        if ( dword_524810[thisa->playerID[1]] )
        {
          if ( dword_524810[thisa->playerID[0]] )
          {
            v6 = couldBeCreatureActionType;
            v7 = spellForAIToCast;
            v8 = notTargetForAISpell;
            v9 = dword_524C68;
            logUpTo7Ints(
              (int)"About to T",
              *(&dword_523430 + 1 - thisa->currentActionSide),
              -999,
              -999,
              -999,
              -999,
              -999,
              -999);
            v10 = sub_46E1D0(&v6, *(&dword_523430 + 1 - thisa->currentActionSide), 0x10u, 23, 1, 1, -1);
            debugLog("Post T");
            if ( !v10 )
              terminate(0);
          }
        }
      }
    }
  }
  v14 = &thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx];
  v11 = 0;
  if ( !CombatManager::checkCombatOver(thisa, a2) )
  {
    switch ( couldBeCreatureActionType )
    {
      case 1:
        sub_441610(thisa);
        CombatManager::effectCombatSpell(thisa, spellForAIToCast, notTargetForAISpell, 0, dword_524C68);
        if ( thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].quantity <= 0 )
          v11 = 1;
        sub_441850(thisa);
        goto LABEL_36;
      case 2:
        sub_441610(thisa);
        sub_483190(v14, notTargetForAISpell, 0);
        *(_DWORD *)&v14->creature.creature_flags |= MAYBE_NOT_LOST_TURN;
        if ( CombatManager::checkCombatOver(thisa, a2) )
        {
          v12 = 2;
          break;
        }
        CombatManager::handleGoodMorale(thisa, thisa->otherCurrentSideThing, thisa->someSortOfStackIdx);
        v11 = 1;
        sub_441850(thisa);
        goto LABEL_36;
      case 6:
        sub_441610(thisa);
        if ( spellForAIToCast != -1 && v14->occupiedHex != spellForAIToCast )
          sub_483190(v14, spellForAIToCast, 1);
        sub_483190(v14, notTargetForAISpell, 0);
        *(_DWORD *)&v14->creature.creature_flags |= MAYBE_NOT_LOST_TURN;
        if ( CombatManager::checkCombatOver(thisa, a2) )
        {
          v12 = 2;
        }
        else
        {
          CombatManager::handleGoodMorale(thisa, thisa->otherCurrentSideThing, thisa->someSortOfStackIdx);
          v11 = 1;
          sub_441850(thisa);
LABEL_36:
          couldBeCreatureActionType = 0;
          if ( CombatManager::checkCombatOver(thisa, a2) )
          {
            v12 = 2;
          }
          else
          {
            CombatManager::handleMoatClosing(thisa);
            if ( v11 && !CombatManager::doCombatRound(thisa, 1) )
            {
              sub_43CE60(thisa);
              CombatManager::doCombatRound(thisa, 1);
            }
            sub_440A90(thisa);
          }
        }
        break;
      case 4:
        thisa->field_F377[thisa->currentActionSide] = 1;
        isRetreating = 1;
        sub_441850(thisa);
        goto LABEL_36;
      case 5:
        isSurrendering = 1;
        isRetreating = 1;
        thisa->field_351F[thisa->currentActionSide] = 1;
        v2 = thisa->playerID[thisa->currentActionSide];
        gameObject->players[v2].resources[6] -= spellForAIToCast;
        v3 = thisa->playerID[1 - thisa->currentActionSide];
        gameObject->players[v3].resources[6] += spellForAIToCast;
        sub_441850(thisa);
        goto LABEL_36;
      case 3:
        *(_DWORD *)&v14->creature.creature_flags |= MAYBE_NOT_LOST_TURN;
        v11 = 1;
        goto LABEL_36;
      case 7:
        *(_DWORD *)&v14->creature.creature_flags |= 0x1000u;
        v11 = 1;
        goto LABEL_36;
      case 0:
        goto LABEL_36;
    }
  }
  dword_4F31B0 = 0;
  sub_440ED0(thisa);
  return v12;
}
