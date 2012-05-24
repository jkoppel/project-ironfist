int __thiscall CombatManager::processAction(CombatManager *this, InputEvent *a2)
{
  int v2; // edx@6
  int v3; // ecx@32
  int v4; // ecx@32
  CombatManager *thisa; // [sp+10h] [bp-28h]@1
  int v7; // [sp+14h] [bp-24h]@15
  Spell v8; // [sp+18h] [bp-20h]@15
  int v9; // [sp+1Ch] [bp-1Ch]@15
  int v10; // [sp+20h] [bp-18h]@15
  int v11; // [sp+24h] [bp-14h]@15
  int v12; // [sp+28h] [bp-10h]@17
  int v13; // [sp+2Ch] [bp-Ch]@1
  int v14; // [sp+30h] [bp-8h]@1
  CreatureStack *v15; // [sp+34h] [bp-4h]@17

  thisa = this;
  sub_4C3300(this, 0);
  v13 = 1;
  v14 = 0;
  dword_4F31B0 = 1;
  if ( *(_DWORD *)&thisa->_15[100] != -1 || *(_DWORD *)&thisa->_15[104] != -1 )
  {
    *(_DWORD *)&thisa->_15[104] = -1;
    *(_DWORD *)&thisa->_15[100] = *(_DWORD *)&thisa->_15[104];
    v14 = 1;
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
  if ( sub_4C3FF0(thisa, v2, 0, 0) )
    v14 = 1;
  if ( v14 )
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
            v7 = couldBeCreatureActionType;
            v8 = spellForAIToCast;
            v9 = notTargetForAISpell;
            v10 = dword_524C68;
            logUpTo7Ints(
              (int)"About to T",
              *(&dword_523430 + 1 - thisa->currentActionSide),
              -999,
              -999,
              -999,
              -999,
              -999,
              -999);
            v11 = sub_46E1D0(&v7, *(&dword_523430 + 1 - thisa->currentActionSide), 0x10u, 23, 1, 1, -1);
            debugLog("Post T");
            if ( !v11 )
              terminate(0);
          }
        }
      }
    }
  }
  v15 = &thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx];
  v12 = 0;
  if ( !CombatManager::checkCombatOver(thisa, a2) )
  {
    switch ( couldBeCreatureActionType )
    {
      case 1:
        sub_441610(thisa);
        CombatManager::effectCombatSpell(thisa, spellForAIToCast, notTargetForAISpell, 0, dword_524C68);
        if ( thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].quantity <= 0 )
          v12 = 1;
        sub_441850(thisa);
        goto LABEL_36;
      case 2:
        sub_441610(thisa);
        sub_483190(v15, notTargetForAISpell, 0);
        *(_DWORD *)&v15->creature.creature_flags |= MAYBE_NOT_LOST_TURN;
        if ( CombatManager::checkCombatOver(thisa, a2) )
        {
          v13 = 2;
          break;
        }
        CombatManager::handleGoodMorale(thisa, thisa->otherCurrentSideThing, thisa->someSortOfStackIdx);
        v12 = 1;
        sub_441850(thisa);
        goto LABEL_36;
      case 6:
        sub_441610(thisa);
        if ( spellForAIToCast != -1 && v15->occupiedHex != spellForAIToCast )
          sub_483190(v15, spellForAIToCast, 1);
        sub_483190(v15, notTargetForAISpell, 0);
        *(_DWORD *)&v15->creature.creature_flags |= MAYBE_NOT_LOST_TURN;
        if ( CombatManager::checkCombatOver(thisa, a2) )
        {
          v13 = 2;
        }
        else
        {
          CombatManager::handleGoodMorale(thisa, thisa->otherCurrentSideThing, thisa->someSortOfStackIdx);
          v12 = 1;
          sub_441850(thisa);
LABEL_36:
          couldBeCreatureActionType = 0;
          if ( CombatManager::checkCombatOver(thisa, a2) )
          {
            v13 = 2;
          }
          else
          {
            CombatManager::handleMoatClosing(thisa);
            if ( v12 && !CombatManager::doCombatRound(thisa, 1) )
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
        v3 = thisa->playerID[thisa->currentActionSide];
        gameObject->players[v3].resources[6] -= spellForAIToCast;
        v4 = thisa->playerID[1 - thisa->currentActionSide];
        gameObject->players[v4].resources[6] += spellForAIToCast;
        sub_441850(thisa);
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
  dword_4F31B0 = 0;
  sub_440ED0(thisa);
  return v13;
}
