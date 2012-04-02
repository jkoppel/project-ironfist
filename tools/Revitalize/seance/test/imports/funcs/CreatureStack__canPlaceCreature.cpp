{
  bool result; // eax@6
  int secondHex; // [sp+10h] [bp-8h]@11
  int othSecondHex; // [sp+10h] [bp-8h]@23
  CombatHexTile *tile; // [sp+14h] [bp-4h]@1

  tile = 0;
  if ( rearHex )
    *rearHex = hex;
  if ( checkHexGridIdxBounds(hex) && hex % 13 && hex % 13 != 12 )
  {
    if ( combatManager->combatGrid[hex].unitOwner != -1 || combatManager->combatGrid[hex].probablyIsBlocked )
    {
      result = 0;
    }
    else
    {
      if ( this->creature.creature_flags & TWO_HEXER )
      {
        secondHex = CreatureStack::getHexNeighbor(this, hex, (unsigned int)(this->facingRight - 1) < 1 ? 1 : 4);
        if ( checkHexGridIdxBounds(secondHex) && secondHex % 13 && secondHex % 13 != 12 )
          tile = &combatManager->combatGrid[secondHex];
        if ( !checkHexGridIdxBounds(secondHex)
          || tile->unitOwner != -1
          && (tile->unitOwner != combatManager->otherCurrentSideThing
           || tile->stackIdx != combatManager->someSortOfStackIdx)
          || tile->probablyIsBlocked )
        {
          if ( mayShiftTwoHexers )
          {
            othSecondHex = CreatureStack::getHexNeighbor(this, hex, (unsigned int)(this->facingRight - 1) < 1 ? 4 : 1);
            if ( checkHexGridIdxBounds(othSecondHex) )
            {
              if ( combatManager->combatGrid[othSecondHex].unitOwner != -1
                && (combatManager->combatGrid[othSecondHex].unitOwner != combatManager->otherCurrentSideThing
                 || combatManager->combatGrid[othSecondHex].stackIdx != combatManager->someSortOfStackIdx)
                || combatManager->combatGrid[othSecondHex].probablyIsBlocked )
              {
                result = 0;
              }
              else
              {
                if ( rearHex )
                  *rearHex = othSecondHex;
                result = 1;
              }
            }
            else
            {
              result = 0;
            }
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          result = 1;
        }
      }
      else
      {
        result = 1;
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
