{
  char *v10; // eax@4
  combatManager *result; // eax@57
  combatManager *thisa; // [sp+Ch] [bp-8h]@1
  signed int side; // [sp+10h] [bp-4h]@12
  signed int sidea; // [sp+10h] [bp-4h]@45
  signed int sideb; // [sp+10h] [bp-4h]@48
  signed int sidec; // [sp+10h] [bp-4h]@51

  thisa = this;
  giSeed = a10;
  SRand(a9 + 100 * a8);
  *(_DWORD *)&thisa->_15[28] = a8;
  *(_DWORD *)&thisa->_15[32] = a9;
  if ( a2 < 0 )
    thisa->field_327B = 0;
  else
    thisa->field_327B = (int)advManager::GetCell(gpAdvManager, a2, SHIDWORD(a2));
  thisa->terrainType = (unsigned __int8)giGroundToTerrain[*(_WORD *)thisa->field_327B];
  v10 = combatManager::GetBackgroundName(thisa);
  sprintf(thisa->combatBackgroundFilename, v10);
  if ( a3 )
  {
    thisa->playerID[0] = *(_BYTE *)(a3 + 3);
    a4 = a3 + 101;
  }
  else
  {
    thisa->playerID[0] = -1;
  }
  if ( a6 )
  {
    thisa->playerID[1] = *(_BYTE *)(a6 + 3);
    a7 = a6 + 101;
  }
  else if ( a5 )
  {
    thisa->playerID[1] = *(_BYTE *)(a5 + 1);
    a7 = a5 + 8;
  }
  else
  {
    thisa->playerID[1] = -1;
  }
  for ( side = 0; side < 2; ++side )
  {
    if ( thisa->playerID[side] < 0 )
      thisa->involvedInBadMorale[side] = 0;
    else
      thisa->involvedInBadMorale[side] = gbHumanPlayer[thisa->playerID[side]];
    if ( side )
      thisa->heroes[side] = (hero *)a6;
    else
      thisa->heroes[0] = (hero *)a3;
    if ( thisa->heroes[side] )
      thisa->heroes[side]->field_E7[0] = 0;
    if ( side )
      thisa->armies[side] = (armyGroup *)a7;
    else
      thisa->armies[0] = (armyGroup *)a4;
    thisa->timesCatapultMustFire[side] = 1;
    *(_DWORD *)&thisa->_11[4 * side] = thisa->timesCatapultMustFire[side];
    if ( thisa->heroes[side] && hero::HasArtifact(thisa->heroes[side], ARTIFACT_BALLISTA_OF_QUICKNESS) )
    {
      thisa->timesCatapultMustFire[side] = 2;
      *(_DWORD *)&thisa->_11[4 * side] = thisa->timesCatapultMustFire[side];
    }
    if ( thisa->heroes[side] )
    {
      if ( thisa->heroes[side]->secondarySkillLevel[10] >= 2 )
      {
        ++*(_DWORD *)&thisa->_11[4 * side];
        ++thisa->timesCatapultMustFire[side];
      }
    }
    thisa->timesGarrisonMustFire[side] = 1;
    *(_DWORD *)&thisa->_12[4 * side + 8] = 0;
    *(&thisa->field_353F + side) = 0;
  }
  thisa->hasMoat = 0;
  if ( a5 )
  {
    if ( *(_BYTE *)(a5 + 23) == -1 )
    {
      *(_DWORD *)&thisa->_12[12] = 0;
    }
    else
    {
      thisa->armies[1] = &thisa->heroes[1]->army;
      combatManager::CombineGroups((armyGroup *)(a5 + 8), (armyGroup *)((char *)&thisa->heroes[26] + 1));
      *(_DWORD *)&thisa->_12[12] = 1;
    }
    if ( *(_BYTE *)(a5 + 24) & 0x40 )
      thisa->isCastleBattle = 1;
    else
      thisa->isCastleBattle = 0;
    if ( thisa->isCastleBattle )
    {
      if ( *(_BYTE *)(a5 + 25) & 0x10 )
        thisa->hasMoat = 1;
      else
        thisa->hasMoat = 0;
    }
    thisa->drawBridgePosition = 4;
    thisa->castles[1] = (town *)a5;
    thisa->field_31E6 = (int)thisa->castles[1];
    if ( !thisa->heroes[1] && *(_BYTE *)(a5 + 25) & 0x80 )
    {
      thisa->heroes[1] = &thisa->captains;
      memset(&thisa->captains, 0, 0xFAu);
      for ( sidea = 0; sidea < 4; ++sidea )
        thisa->captains.primarySkills[sidea] = *(&captainStats[4 * thisa->castles[1]->factionID] + sidea);
      thisa->captains.spellpoints = 10 * hero::Stats(&thisa->captains, PRIMARY_SKILL_KNOWLEDGE);
      thisa->captains.factionID = thisa->castles[1]->factionID;
      thisa->captains.heroID = thisa->castles[1]->factionID + 90;
      strcpy(thisa->captains.name, "Captain");
      for ( sideb = 0; sideb < 5; ++sideb )
        thisa->captains.army.creatureTypes[sideb] = -1;
      for ( sidec = 0; sidec < 14; ++sidec )
        thisa->captains.artifacts[sidec] = -1;
      thisa->captains.artifacts[0] = 81;
      town::GiveSpells(thisa->castles[1], &thisa->captains);
      thisa->captains.field_E7[0] = 1;
    }
  }
  else
  {
    thisa->isCastleBattle = 0;
    thisa->castles[1] = 0;
  }
  result = thisa;
  thisa->castles[0] = 0;
  return result;
}