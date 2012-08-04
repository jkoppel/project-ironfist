{
  int thisa; // [sp+10h] [bp-10h]@1

  thisa = this;
  switch ( a2 )
  {
    case 1:
    case 2:
    case 3:
    case 15:
      giNextAction = 2;
      giNextActionGridIndex = *(_DWORD *)(this + 62147);
      giNextActionExtra = -1;
      break;
    case 7:
      giNextActionGridIndex = *(_DWORD *)(this + 62147);
      if ( *(_DWORD *)(this + 4 * *(_DWORD *)(this + 62127) + 13615) != -1
        && gbHumanPlayer[*(_DWORD *)(this + 4 * *(_DWORD *)(this + 62127) + 13615)]
        && !*(_DWORD *)(this + 62131) )
      {
        giNextAction = 6;
        giNextActionExtra = *(_DWORD *)(this + 62151);
      }
      else
      {
        giNextAction = 2;
        giNextActionExtra = -1;
      }
      break;
    case 4:
      mouseManager::SetPointer(gpMouseManager, 6);
      combatManager::ViewGeneral((combatManager *)thisa, *(_DWORD *)(thisa + 62127), 1, 0);
      combatManager::ResetMouse((combatManager *)thisa);
      break;
    case 13:
      mouseManager::SetPointer(gpMouseManager, 6);
      combatManager::ViewGeneral((combatManager *)thisa, 1 - *(_DWORD *)(thisa + 62127), 1, 0);
      combatManager::ResetMouse((combatManager *)thisa);
      break;
    case 5:
      mouseManager::SetPointer(gpMouseManager, 6);
      if ( *(_DWORD *)(thisa + 62147) == 77 )
        combatManager::ViewBallista((combatManager *)thisa, 0);
      else
        combatManager::ViewArmy(
          (void *)thisa,
          thisa
        + 24234 * *(_BYTE *)(98 * *(_DWORD *)(thisa + 62147) + thisa + 1316)
        + 1154 * *(_BYTE *)(98 * *(_DWORD *)(thisa + 62147) + thisa + 1317)
        + 13647,
          0);
      combatManager::ResetMouse((combatManager *)thisa);
      break;
    case 10:
      if ( combatManager::IsNegationSphereInEffect((combatManager *)this) )
      {
        NormalDialog(
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
        combatManager::ViewSpells((combatManager *)thisa, 0);
        combatManager::ResetMouse((combatManager *)thisa);
      }
      break;
    case 11:
      NormalDialog("Are you sure you want to retreat?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( gpWindowManager->buttonPressedCode == 30725 )
        giNextAction = 4;
      combatManager::ResetMouse((combatManager *)thisa);
      break;
    case 12:
      if ( combatManager::DoSurrender(this) == 1 )
      {
        if ( gpGame->players[*(_DWORD *)(thisa + 4 * *(_DWORD *)(thisa + 62127) + 13615)].resources[6] >= giSurrenderCost )
        {
          giNextAction = 5;
          giNextActionExtra = giSurrenderCost;
        }
        else
        {
          NormalDialog("You don't have enough gold!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
      combatManager::ResetMouse((combatManager *)thisa);
      break;
    case 0:
      return;
  }
}