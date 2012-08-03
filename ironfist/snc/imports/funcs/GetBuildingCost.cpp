{
  void *result; // eax@3

  if ( a2 != 2 || a1 != 5 )
  {
    if ( a2 < 19 || a2 > 30 )
    {
      if ( a2 )
      {
        if ( a2 == 13 )
        {
          result = memcpy(a3, (char *)&gSpecialBuildingCosts + 28 * a1, 0x1Cu);
        }
        else if ( a2 < 16 )
        {
          result = memcpy(a3, (char *)&gNeutralBuildingCosts + 28 * a2, 0x1Cu);
        }
      }
      else
      {
        result = memcpy(a3, &gMageBuildingCosts[7 * (a4 + 1)], 0x1Cu);
      }
    }
    else
    {
      result = memcpy(a3, &gDwellingCosts[12 * a1] + a2 - 19, 0x1Cu);
    }
  }
  else
  {
    result = memcpy(a3, &xShrineBuildingCost, 0x1Cu);
  }
  return result;
}