{
  ArmyInfo *thisa; // [sp+Ch] [bp-1Ch]@1
  signed int hasUndead; // [sp+10h] [bp-18h]@1
  signed int artifactMorale; // [sp+18h] [bp-10h]@1
  int totMorale; // [sp+18h] [bp-10h]@36
  signed int i; // [sp+1Ch] [bp-Ch]@6
  signed int enemyHasBoneDragon; // [sp+20h] [bp-8h]@5
  signed int v11; // [sp+24h] [bp-4h]@1

  thisa = this;
  artifactMorale = 0;
  hasUndead = 0;
  v11 = ArmyInfo::computeMoraleBonusForAlignments(this, -1);
  if ( ArmyInfo::hasNonUndead(thisa) )
    return 0;
  if ( ArmyInfo::hasUndead(thisa) )
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
  if ( hero )
  {
    if ( Hero::hasArtifact(hero, ARTIFACT_BATTLE_GARB_OF_ANDURAN) )
      return 3;
    artifactMorale += hero->_5[1] + hero->secondarySkillLevel[6];
    if ( Hero::hasArtifact(hero, ARTIFACT_MEDAL_OF_VALOR) )
      ++artifactMorale;
    if ( Hero::hasArtifact(hero, ARTIFACT_MEDAL_OF_COURAGE) )
      ++artifactMorale;
    if ( Hero::hasArtifact(hero, ARTIFACT_MEDAL_OF_HONOR) )
      ++artifactMorale;
    if ( Hero::hasArtifact(hero, ARTIFACT_MEDAL_OF_DISTINCTION) )
      ++artifactMorale;
    if ( Hero::hasArtifact(hero, ARTIFACT_FIZBIN_OF_MISFOURTUNE) )
      artifactMorale -= 2;
    if ( Hero::hasArtifact(hero, ARTIFACT_ARM_OF_THE_MARTYR) )
      hasUndead = 1;
    if ( Hero::hasArtifact(hero, ARTIFACT_MASTHEAD) && hero->flags1 & HERO_AT_SEA )
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
