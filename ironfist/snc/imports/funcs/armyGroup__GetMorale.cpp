{
  signed int hasUndead; // [sp+10h] [bp-18h]@1
  signed int artifactMorale; // [sp+18h] [bp-10h]@1
  int totMorale; // [sp+18h] [bp-10h]@36
  signed int i; // [sp+1Ch] [bp-Ch]@6
  signed int enemyHasBoneDragon; // [sp+20h] [bp-8h]@5
  signed int v11; // [sp+24h] [bp-4h]@1

  artifactMorale = 0;
  hasUndead = 0;
  v11 = armyGroup::IsHomogeneous(this, -1);
  if ( armyGroup::HasAllUndead(this) )
    return 0;
  if ( armyGroup::HasSomeUndead(this) )
    hasUndead = 1;
  enemyHasBoneDragon = 0;
  if ( enemyCreaturesList )
  {
    for ( i = 0; i < 5; ++i )
    {
      if ( enemyCreaturesList[i] == CREATURE_BONE_DRAGON )
        enemyHasBoneDragon = 1;
    }
  }
  if ( enemyHasBoneDragon )
    artifactMorale = -1;
  if ( hro )
  {
    if ( hero::HasArtifact(hro, ARTIFACT_BATTLE_GARB_OF_ANDURAN) )
      return 3;
    artifactMorale += hro->_5[1] + hro->secondarySkillLevel[6];
    if ( hero::HasArtifact(hro, ARTIFACT_MEDAL_OF_VALOR) )
      ++artifactMorale;
    if ( hero::HasArtifact(hro, ARTIFACT_MEDAL_OF_COURAGE) )
      ++artifactMorale;
    if ( hero::HasArtifact(hro, ARTIFACT_MEDAL_OF_HONOR) )
      ++artifactMorale;
    if ( hero::HasArtifact(hro, ARTIFACT_MEDAL_OF_DISTINCTION) )
      ++artifactMorale;
    if ( hero::HasArtifact(hro, ARTIFACT_FIZBIN_OF_MISFOURTUNE) )
      artifactMorale -= 2;
    if ( hero::HasArtifact(hro, ARTIFACT_ARM_OF_THE_MARTYR) )
      hasUndead = 1;
    if ( hero::HasArtifact(hro, ARTIFACT_MASTHEAD) && hro->flags1 & HERO_AT_SEA )
      ++artifactMorale;
  }
  if ( hasUndead )
    --artifactMorale;
  if ( hasUndead && v11 > 0 )
    v11 = 0;
  totMorale = v11 + artifactMorale;
  if ( castle && castle->factionID != FACTION_NECROMANCER && castle->buildingsBuiltFlags & 4 )
    ++totMorale;
  if ( castle
    && castle->factionID == FACTION_BARBARIAN
    && BYTE1(castle->buildingsBuiltFlags) & BUILDING_SPECIAL_DEFENSE_BUILT )
    totMorale += 2;
  if ( totMorale >= -3 )
  {
    if ( totMorale > 3 )
      totMorale = 3;
  }
  else
  {
    totMorale = -3;
  }
  return totMorale;
}