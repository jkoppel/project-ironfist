void __thiscall CombatManager::loadManyCombatImages(CombatManager *this)
{
  CombatManager *thisa; // [sp+Ch] [bp-Ch]@1
  signed int v2; // [sp+10h] [bp-8h]@19
  signed int i; // [sp+14h] [bp-4h]@1
  signed int j; // [sp+14h] [bp-4h]@4
  signed int k; // [sp+14h] [bp-4h]@11

  thisa = this;
  for ( i = 0; i < 15; ++i )
    this->combatScreenIcons[i] = 0;
  for ( j = 0; j < 8; ++j )
    this->combatObjIcons[j] = 0;
  this->combatScreenIcons[8] = ResourceManager::getIconByFilename(resourceManager, "spells.icn");
  thisa->combatScreenIcons[1] = ResourceManager::getIconByFilename(resourceManager, "textbar.icn");
  thisa->combatScreenIcons[9] = ResourceManager::getIconByFilename(resourceManager, "cmbtmisc.icn");
  thisa->combatScreenIcons[10] = ResourceManager::getIconByFilename(resourceManager, "viewarsm.icn");
  thisa->combatScreenIcons[11] = ResourceManager::getIconByFilename(resourceManager, "minilkmr.icn");
  thisa->combatScreenIcons[12] = ResourceManager::getIconByFilename(resourceManager, "spellinf.icn");
  if ( thisa->isCastleBattle )
  {
    if ( BYTE1(thisa->castles[1]->buildingsBuiltFlags) & 0x10 )
    {
      thisa->combatScreenIcons[13] = ResourceManager::getIconByFilename(resourceManager, "moatpart.icn");
      thisa->combatScreenIcons[14] = ResourceManager::getIconByFilename(resourceManager, "moatwhol.icn");
    }
    thisa->combatScreenIcons[3] = ResourceManager::getIconByFilename(resourceManager, "catapult.icn");
    sprintf(globBuf, "castle%c.icn", asciiCharacterForFaction[thisa->castles[1]->factionID]);
    thisa->combatScreenIcons[5] = ResourceManager::getIconByFilename(resourceManager, globBuf);
    thisa->combatScreenIcons[7] = ResourceManager::getIconByFilename(resourceManager, "keep.icn");
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
        sprintf(globBuf, "cmbtcap%c.icn", asciiCharacterForFaction[thisa->heroes[k]->factionID]);
        thisa->heroIcon[k] = ResourceManager::getIconByFilename(resourceManager, globBuf);
        thisa->heroType[k] = thisa->heroes[k]->factionID + 6;
      }
      else
      {
        sprintf(globBuf, "cmbthro%c.icn", asciiCharacterForFaction[thisa->heroes[k]->factionID]);
        thisa->heroIcon[k] = ResourceManager::getIconByFilename(resourceManager, globBuf);
        thisa->heroType[k] = thisa->heroes[k]->factionID;
      }
    }
    if ( thisa->heroIcon[k] )
    {
      if ( thisa->playerID[k] == -1 )
        v2 = 6;
      else
        v2 = gameObject->players[LOBYTE(thisa->playerID[k])].color;
      sprintf(globBuf, "herofl%02d.icn", v2);
      thisa->heroFlagIcon[k] = ResourceManager::getIconByFilename(resourceManager, globBuf);
    }
  }
}
