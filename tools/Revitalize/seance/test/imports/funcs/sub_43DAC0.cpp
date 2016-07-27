{
  int thisa; // [sp+10h] [bp-10h]@1

  thisa = this;
  switch ( a2 )
  {
    case 1:
    case 2:
    case 3:
    case 15:
      couldBeCreatureActionType = 2;
      notTargetForAISpell = *(_DWORD *)(this + 62147);
      spellForAIToCast = -1;
      break;
    case 7:
      notTargetForAISpell = *(_DWORD *)(this + 62147);
      if ( *(_DWORD *)(this + 4 * *(_DWORD *)(this + 62127) + 13615) != -1
        && dword_524810[*(_DWORD *)(this + 4 * *(_DWORD *)(this + 62127) + 13615)]
        && !*(_DWORD *)(this + 62131) )
      {
        couldBeCreatureActionType = 6;
        spellForAIToCast = *(_DWORD *)(this + 62151);
      }
      else
      {
        couldBeCreatureActionType = 2;
        spellForAIToCast = -1;
      }
      break;
    case 4:
      MouseManager::setSpriteIdx(mouseManager, 6);
      sub_40FAF0((CombatManager *)thisa, *(_DWORD *)(thisa + 62127), 1, 0);
      sub_440ED0((CombatManager *)thisa);
      break;
    case 13:
      MouseManager::setSpriteIdx(mouseManager, 6);
      sub_40FAF0((CombatManager *)thisa, 1 - *(_DWORD *)(thisa + 62127), 1, 0);
      sub_440ED0((CombatManager *)thisa);
      break;
    case 5:
      MouseManager::setSpriteIdx(mouseManager, 6);
      if ( *(_DWORD *)(thisa + 62147) == 77 )
        sub_4429D0(thisa, 0);
      else
        sub_410530(
          (void *)thisa,
          thisa
        + 24234 * *(_BYTE *)(98 * *(_DWORD *)(thisa + 62147) + thisa + 1316)
        + 1154 * *(_BYTE *)(98 * *(_DWORD *)(thisa + 62147) + thisa + 1317)
        + 13647,
          0);
      sub_440ED0((CombatManager *)thisa);
      break;
    case 10:
      if ( CombatManager::sphereOfNegationInEffect((CombatManager *)this) )
      {
        display_message_window(
          "The Sphere of Negation artifact is in effect for this battle, disabling all combat spells.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
      }
      else
      {
        CombatManager::castCombatSpell((CombatManager *)thisa, 0);
        sub_440ED0((CombatManager *)thisa);
      }
      break;
    case 11:
      display_message_window("Are you sure you want to retreat?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
        couldBeCreatureActionType = 4;
      sub_440ED0((CombatManager *)thisa);
      break;
    case 12:
      if ( sub_440650(this) == 1 )
      {
        if ( gameObject->players[*(_DWORD *)(thisa + 4 * *(_DWORD *)(thisa + 62127) + 13615)].resources[6] >= dword_524CA0 )
        {
          couldBeCreatureActionType = 5;
          spellForAIToCast = dword_524CA0;
        }
        else
        {
          display_message_window("You don't have enough gold!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
      sub_440ED0((CombatManager *)thisa);
      break;
    case 0:
      return;
  }
}
