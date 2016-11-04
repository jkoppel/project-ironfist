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
    case -4294967271:
      if ( *(_DWORD *)(this + 12939) )
      {
        sub_40FAF0((CombatManager *)this, 1, 0, 1);
        sub_440ED0((CombatManager *)thisa);
      }
      result = 0;
      break;
    case -4294967270:
      if ( *(_DWORD *)(this + 12935) )
      {
        sub_40FAF0((CombatManager *)this, 0, 0, 1);
        sub_440ED0((CombatManager *)thisa);
      }
      result = 0;
      break;
    case -4294967219:
      if ( *(_DWORD *)(this + 62259) )
        sub_4429D0(this, 1u);
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
          && (!combatManager->isCastleBattle
           || a2 != 58 && a2 != 59
           || combatManager->drawBridgePosition == 4
           && (combatManager->currentActionSide != 1
            || combatManager->combatGrid[58].unitOwner != -1
            || combatManager->combatGrid[58].numCorpses)) )
        {
          result = 0;
        }
        else
        {
          if ( v4 == -1 )
          {
            result = 0;
          }
          else
          {
            if ( v4 >= 0 && v4 <= 1 )
            {
              MouseManager::setSpriteIdx(mouseManager, 6);
              sub_410530(
                (void *)thisa,
                thisa + 24234 * v4 + 1154 * *(_BYTE *)(98 * *(_DWORD *)(thisa + 62147) + thisa + 1317) + 13647,
                1);
              sub_440ED0((CombatManager *)thisa);
              result = 0;
            }
            else
            {
              result = 0;
            }
          }
        }
      }
      break;
  }
  return result;
}
