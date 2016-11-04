{
  int result; // eax@2
  signed int artifactLuck; // [sp+10h] [bp-4h]@3
  int totLuck; // [sp+10h] [bp-4h]@14

  if ( hero )
  {
    artifactLuck = 0;
    if ( Hero::hasArtifact(hero, ARTIFACT_LUCKY_RABBITS_FOOT) )
      artifactLuck = 1;
    if ( Hero::hasArtifact(hero, ARTIFACT_GOLDEN_HORSESHOE) )
      ++artifactLuck;
    if ( Hero::hasArtifact(hero, ARTIFACT_GAMBLERS_LUCKY_COIN) )
      ++artifactLuck;
    if ( Hero::hasArtifact(hero, ARTIFACT_FOUR_LEAF_CLOVER) )
      ++artifactLuck;
    if ( Hero::hasArtifact(hero, ARTIFACT_MASTHEAD) && hero->flags1 & HERO_AT_SEA )
      ++artifactLuck;
    totLuck = hero->secondarySkillLevel[9] + hero->_5[2] + artifactLuck;
    if ( castle
      && castle->factionID == FACTION_SORCERESS
      && BYTE1(castle->buildingsBuiltFlags) & BUILDING_SPECIAL_DEFENSE_BUILT )
      totLuck += 2;
    if ( totLuck < -3 )
      totLuck = -3;
    if ( totLuck > 3 )
      totLuck = 3;
    if ( Hero::hasArtifact(hero, ARTIFACT_BATTLE_GARB_OF_ANDURAN) )
      totLuck = 3;
    result = totLuck;
  }
  else
  {
    result = 0;
  }
  return result;
}
