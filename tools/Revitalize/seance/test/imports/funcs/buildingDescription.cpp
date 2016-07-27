{
  char *v3; // ST0C_4@5
  char *hordeDesc; // eax@5
  char *v5; // ST0C_4@10
  char *v6; // eax@10
  char *v8; // eax@12
  signed int fieldIDa; // [sp+Ch] [bp-198h]@1
  int factiona; // [sp+10h] [bp-194h]@1
  char buf[1]; // [sp+14h] [bp-190h]@3

  fieldIDa = building;
  factiona = faction;
  if ( faction != FACTION_NECROMANCER || building != 2 )
  {
    if ( building == BUILDING_SPECIAL_GROWTH )
    {
      v3 = creaturePluralNames[dwelling_creatures[faction][0]];
      hordeDesc = buildingName(faction, BUILDING_SPECIAL_GROWTH);
      sprintf(buf, "The %s increases production of %s by 8 per week.", hordeDesc, v3);
    }
    else
    {
      if ( building == BUILDING_SPECIAL )
      {
        sprintf(buf, specialBuildingDescriptions[faction]);
      }
      else
      {
        if ( building >= BUILDING_DWELLING_1 )
        {
          v5 = creaturePluralNames[LOBYTE((&buildingShortNames[3 * faction + 27])[building + 1])];
          v6 = buildingName(faction, building);
          sprintf(globBuf, "The %s produces %s.", v6, v5);
          return globBuf;
        }
        sprintf(buf, (&off_4F6E68)[4 * building]);
      }
    }
  }
  else
  {
    sprintf(buf, off_51A8C0);
  }
  if ( withTitle )
  {
    v8 = buildingName(factiona, fieldIDa);
    sprintf(globBuf, "{%s}\n\n%s", v8, buf);
  }
  else
  {
    sprintf(globBuf, buf);
  }
  return globBuf;
}
