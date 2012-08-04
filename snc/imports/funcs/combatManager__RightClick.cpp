{
  int result; // eax@2
  int thisa; // [sp+14h] [bp-14h]@1
  signed int v4; // [sp+1Ch] [bp-Ch]@15

  thisa = this;
  switch ( a2 )
  {
    case -1:
      result = 0;
      break;
    case 25:
      if ( *(_DWORD *)(this + 12939) )
      {
        combatManager::ViewGeneral((combatManager *)this, 1, 0, 1);
        combatManager::ResetMouse((combatManager *)thisa);
      }
      result = 0;
      break;
    case 26:
      if ( *(_DWORD *)(this + 12935) )
      {
        combatManager::ViewGeneral((combatManager *)this, 0, 0, 1);
        combatManager::ResetMouse((combatManager *)thisa);
      }
      result = 0;
      break;
    case 77:
      if ( *(_DWORD *)(this + 62259) )
        combatManager::ViewBallista((combatManager *)this, 1u);
      result = 0;
      break;
    default:
      if ( a2 % 13 == 12 )
      {
        result = 0;
      }
      else
      {
        v4 = *(_BYTE *)(98 * a2 + this + 1316);
        if ( *(_BYTE *)(98 * a2 + this + 1314)
          && (!gpCombatManager->isCastleBattle
           || a2 != 58 && a2 != 59
           || gpCombatManager->drawBridgePosition == 4
           && (gpCombatManager->currentActionSide != 1
            || gpCombatManager->combatGrid[58].unitOwner != -1
            || gpCombatManager->combatGrid[58].numCorpses)) )
        {
          result = 0;
        }
        else if ( v4 == -1 )
        {
          result = 0;
        }
        else if ( v4 >= 0 && v4 <= 1 )
        {
          mouseManager::SetPointer(gpMouseManager, 6);
          combatManager::ViewArmy(
            (void *)thisa,
            thisa + 24234 * v4 + 1154 * *(_BYTE *)(98 * *(_DWORD *)(thisa + 62147) + thisa + 1317) + 13647,
            1);
          combatManager::ResetMouse((combatManager *)thisa);
          result = 0;
        }
        else
        {
          result = 0;
        }
      }
      break;
  }
  return result;
}