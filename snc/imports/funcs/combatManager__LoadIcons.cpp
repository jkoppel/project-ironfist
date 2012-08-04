{
  combatManager *thisa; // [sp+Ch] [bp-Ch]@1
  signed int v2; // [sp+10h] [bp-8h]@19
  signed int i; // [sp+14h] [bp-4h]@1
  signed int j; // [sp+14h] [bp-4h]@4
  signed int k; // [sp+14h] [bp-4h]@11

  thisa = this;
  for ( i = 0; i < 15; ++i )
    this->combatScreenIcons[i] = 0;
  for ( j = 0; j < 8; ++j )
    this->combatObjIcons[j] = 0;
  this->combatScreenIcons[8] = resourceManager::GetIcon(gpResourceManager, "spells.icn");
  thisa->combatScreenIcons[1] = resourceManager::GetIcon(gpResourceManager, "textbar.icn");
  thisa->combatScreenIcons[9] = resourceManager::GetIcon(gpResourceManager, "cmbtmisc.icn");
  thisa->combatScreenIcons[10] = resourceManager::GetIcon(gpResourceManager, "viewarsm.icn");
  thisa->combatScreenIcons[11] = resourceManager::GetIcon(gpResourceManager, "minilkmr.icn");
  thisa->combatScreenIcons[12] = resourceManager::GetIcon(gpResourceManager, "spellinf.icn");
  if ( thisa->isCastleBattle )
  {
    if ( BYTE1(thisa->castles[1]->buildingsBuiltFlags) & 0x10 )
    {
      thisa->combatScreenIcons[13] = resourceManager::GetIcon(gpResourceManager, "moatpart.icn");
      thisa->combatScreenIcons[14] = resourceManager::GetIcon(gpResourceManager, "moatwhol.icn");
    }
    thisa->combatScreenIcons[3] = resourceManager::GetIcon(gpResourceManager, "catapult.icn");
    sprintf(gText, "castle%c.icn", cHeroTypeInitial[thisa->castles[1]->factionID]);
    thisa->combatScreenIcons[5] = resourceManager::GetIcon(gpResourceManager, gText);
    thisa->combatScreenIcons[7] = resourceManager::GetIcon(gpResourceManager, "keep.icn");
  }
  for ( k = 0; k < 2; ++k )
  {
    thisa->heroIcon[k] = 0;
    thisa->heroFlagIcon[k] = 0;
    thisa->heroIconIdxRelated[k] = 0;
    thisa->countRelatedToSpellAnimation[k] = 0;
    thisa->heroType[k] = -1;
    if ( thisa->heroes[k] )
    {
      if ( thisa->heroes[k]->field_E7[0] )
      {
        sprintf(gText, "cmbtcap%c.icn", cHeroTypeInitial[thisa->heroes[k]->factionID]);
        thisa->heroIcon[k] = resourceManager::GetIcon(gpResourceManager, gText);
        thisa->heroType[k] = thisa->heroes[k]->factionID + 6;
      }
      else
      {
        sprintf(gText, "cmbthro%c.icn", cHeroTypeInitial[thisa->heroes[k]->factionID]);
        thisa->heroIcon[k] = resourceManager::GetIcon(gpResourceManager, gText);
        thisa->heroType[k] = thisa->heroes[k]->factionID;
      }
    }
    if ( thisa->heroIcon[k] )
    {
      if ( thisa->playerID[k] == -1 )
        v2 = 6;
      else
        v2 = gpGame->players[LOBYTE(thisa->playerID[k])].color;
      sprintf(gText, "herofl%02d.icn", v2);
      thisa->heroFlagIcon[k] = resourceManager::GetIcon(gpResourceManager, gText);
    }
  }
}