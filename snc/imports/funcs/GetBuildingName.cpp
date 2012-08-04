{
  char *result; // eax@3

  if ( faction != FACTION_NECROMANCER || building != BUILDING_TAVERN )
  {
    if ( building == BUILDING_SPECIAL_GROWTH )
    {
      result = gWellExtraNames[faction];
    }
    else if ( building == BUILDING_SPECIAL )
    {
      result = gSpecialBuildingNames[faction];
    }
    else if ( building >= BUILDING_DWELLING_1 )
    {
      result = (char *)*(&off_4F6C54 + 12 * faction + building);
    }
    else
    {
      result = gNeutralBuildingNames[building];
    }
  }
  else
  {
    result = xNecromancerShrine;
  }
  return result;
}