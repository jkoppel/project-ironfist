{
  int result; // eax@2
  signed int artifactLuck; // [sp+10h] [bp-4h]@3
  int totLuck; // [sp+10h] [bp-4h]@14

  if ( hro )
  {
    artifactLuck = 0;
    if ( hero::HasArtifact(hro, ARTIFACT_LUCKY_RABBITS_FOOT) )
      artifactLuck = 1;
    if ( hero::HasArtifact(hro, ARTIFACT_GOLDEN_HORSESHOE) )
      ++artifactLuck;
    if ( hero::HasArtifact(hro, ARTIFACT_GAMBLERS_LUCKY_COIN) )
      ++artifactLuck;
    if ( hero::HasArtifact(hro, ARTIFACT_FOUR_LEAF_CLOVER) )
      ++artifactLuck;
    if ( hero::HasArtifact(hro, ARTIFACT_MASTHEAD) && hro->flags1 & HERO_AT_SEA )
      ++artifactLuck;
    totLuck = hro->secondarySkillLevel[9] + hro->_5[2] + artifactLuck;
    if ( castle
      && castle->factionID == FACTION_SORCERESS
      && BYTE1(castle->buildingsBuiltFlags) & BUILDING_SPECIAL_DEFENSE_BUILT )
      totLuck += 2;
    if ( totLuck < -3 )
      totLuck = -3;
    if ( totLuck > 3 )
      totLuck = 3;
    if ( hero::HasArtifact(hro, ARTIFACT_BATTLE_GARB_OF_ANDURAN) )
      totLuck = 3;
    result = totLuck;
  }
  else
  {
    result = 0;
  }
  return result;
}