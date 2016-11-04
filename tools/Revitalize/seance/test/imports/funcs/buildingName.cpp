{
  char *result; // eax@3

  if ( faction != FACTION_NECROMANCER || building != BUILDING_TAVERN )
  {
    if ( building == BUILDING_SPECIAL_GROWTH )
    {
      result = growth_building_names[faction];
    }
    else
    {
      if ( building == BUILDING_SPECIAL )
      {
        result = special_building_names[faction];
      }
      else
      {
        if ( building >= BUILDING_DWELLING_1 )
          result = (char *)*(&off_4F6C54 + 12 * faction + building);
        else
          result = town_building_names[building];
      }
    }
  }
  else
  {
    result = shrineName;
  }
  return result;
}
