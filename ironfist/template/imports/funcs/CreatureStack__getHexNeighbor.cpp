{
  signed int result; // eax@2

  if ( knownHex == -1 )
  {
    result = -1;
  }
  else
  {
    if ( hexIdx == 6 )
    {
      if ( this->facingRight == 1 )
        hexIdx = 5;
      else
        hexIdx = 0;
    }
    else
    {
      if ( hexIdx == 7 )
      {
        if ( this->facingRight == 1 )
          hexIdx = 3;
        else
          hexIdx = 2;
      }
    }
    result = combatManager->hexNeighbors[knownHex][hexIdx];
  }
  return result;
}
