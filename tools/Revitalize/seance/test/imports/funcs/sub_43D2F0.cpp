{
  signed int result; // eax@43
  int thisa; // [sp+14h] [bp-20h]@1
  int v4; // [sp+18h] [bp-1Ch]@24
  signed int v5; // [sp+1Ch] [bp-18h]@24
  signed int v6; // [sp+28h] [bp-Ch]@1
  signed int v7; // [sp+2Ch] [bp-8h]@1
  int v8; // [sp+30h] [bp-4h]@24

  thisa = this;
  v6 = 0;
  v7 = 0;
  switch ( a2 )
  {
    case 4294967295:
      v6 = 0;
      break;
    case 25:
      if ( *(_DWORD *)(this + 12939) )
      {
        if ( *(_DWORD *)(this + 62127) == 1 )
          v6 = 4;
        else
          v6 = 13;
      }
      else
      {
        v6 = 0;
      }
      break;
    case 26:
      if ( *(_DWORD *)(this + 12935) )
      {
        if ( *(_DWORD *)(this + 62127) )
          v6 = 13;
        else
          v6 = 4;
      }
      else
      {
        v6 = 0;
      }
      break;
    case 77:
      if ( *(_DWORD *)(this + 62259) )
        v6 = 5;
      else
        v6 = 0;
      break;
    default:
      if ( a2 % 13 == 12 )
      {
        v6 = 0;
      }
      else
      {
        v5 = *(_BYTE *)(98 * a2 + this + 1316);
        v4 = *(_BYTE *)(98 * a2 + this + 1317);
        v8 = this + 1154 * *(_DWORD *)(this + 62119) + 24234 * *(_DWORD *)(this + 62115) + 13647;
        *(_DWORD *)(v8 + 82) = -1;
        *(_DWORD *)(v8 + 86) = -1;
        if ( *(_BYTE *)(98 * a2 + this + 1314)
          && (!combatManager->isCastleBattle
           || a2 != 58 && a2 != 59
           || combatManager->drawBridgePosition == 4
           && (combatManager->currentActionSide != 1
            || combatManager->combatGrid[58].unitOwner != -1
            || combatManager->combatGrid[58].numCorpses)) )
        {
          v6 = 0;
        }
        else
        {
          if ( v5 == -1 )
          {
            if ( sub_405F00(
                   (CreatureStack *)(1154 * *(_DWORD *)(this + 62119) + 24234 * *(_DWORD *)(this + 62115) + this + 13647),
                   a2,
                   0) == 1 )
              v6 = (char)(2
                        - ((*(_DWORD *)(1154 * *(_DWORD *)(thisa + 62119)
                                      + 24234 * *(_DWORD *)(thisa + 62115)
                                      + thisa
                                      + 13855) & 2u) < 1));
          }
          else
          {
            if ( *(_DWORD *)(this + 62115) != v5 || *(_DWORD *)(this + 62119) != v4 )
            {
              v7 = 1;
              if ( !dword_4F31B0 )
              {
                if ( !couldBeCreatureActionType )
                {
                  *(_DWORD *)(this + 62791) = v5;
                  *(_DWORD *)(this + 62799) = v4;
                  sub_4C66F0((CombatManager *)this, 1, 1);
                }
              }
            }
            if ( v5 >= 0 && v5 <= 1 )
            {
              if ( *(_DWORD *)(thisa + 62127) == v5
                || *(_DWORD *)(thisa + 62115) == v5 && *(_DWORD *)(thisa + 62119) == v4 )
                return 5;
              *(_DWORD *)(v8 + 82) = v5;
              *(_DWORD *)(v8 + 86) = v4;
              if ( (signed int)*(_BYTE *)(v8 + 202) > 0
                && CreatureStack::getFreeNeighborBitmask((CreatureStack *)v8, *(_DWORD *)(v8 + 122), 1, -1) == 255 )
              {
                if ( CombatManager::shouldHalveRangedAttack(
                       (CombatManager *)thisa,
                       *(_DWORD *)(v8 + 230),
                       *(_DWORD *)(v8 + 122),
                       a2) )
                  result = 15;
                else
                  result = 3;
                return result;
              }
              if ( sub_405F00((CreatureStack *)v8, a2, 0) == 1 )
                return 7;
              *(_DWORD *)(v8 + 82) = -1;
              *(_DWORD *)(v8 + 86) = -1;
              v6 = 0;
            }
          }
        }
      }
      break;
  }
  if ( !v7 )
  {
    if ( !dword_4F31B0 )
    {
      *(_DWORD *)(thisa + 62791) = -1;
      sub_4C66F0((CombatManager *)thisa, 1, 1);
    }
  }
  return v6;
}
