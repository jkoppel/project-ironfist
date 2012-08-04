{
  bool result; // eax@6
  int secondHex; // [sp+10h] [bp-8h]@11
  int othSecondHex; // [sp+10h] [bp-8h]@23
  hexcell *tile; // [sp+14h] [bp-4h]@1

  tile = 0;
  if ( rearHex )
    *rearHex = hex;
  if ( ValidHex(hex) && hex % 13 && hex % 13 != 12 )
  {
    if ( gpCombatManager->combatGrid[hex].unitOwner != -1 || gpCombatManager->combatGrid[hex].isBlocked )
    {
      result = 0;
    }
    else if ( this->creature.creature_flags & TWO_HEXER )
    {
      secondHex = army::GetAdjacentCellIndex(this, hex, (unsigned int)(this->facingRight - 1) < 1 ? 1 : 4);
      if ( ValidHex(secondHex) && secondHex % 13 && secondHex % 13 != 12 )
        tile = &gpCombatManager->combatGrid[secondHex];
      if ( !ValidHex(secondHex)
        || tile->unitOwner != -1
        && (tile->unitOwner != gpCombatManager->otherCurrentSideThing
         || tile->stackIdx != gpCombatManager->someSortOfStackIdx)
        || tile->isBlocked )
      {
        if ( mayShiftTwoHexers )
        {
          othSecondHex = army::GetAdjacentCellIndex(this, hex, (unsigned int)(this->facingRight - 1) < 1 ? 4 : 1);
          if ( ValidHex(othSecondHex) )
          {
            if ( gpCombatManager->combatGrid[othSecondHex].unitOwner != -1
              && (gpCombatManager->combatGrid[othSecondHex].unitOwner != gpCombatManager->otherCurrentSideThing
               || gpCombatManager->combatGrid[othSecondHex].stackIdx != gpCombatManager->someSortOfStackIdx)
              || gpCombatManager->combatGrid[othSecondHex].isBlocked )
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
  else
  {
    result = 0;
  }
  return result;
}