signed int __thiscall Castle::buildBuilding(Castle *this, signed int buildingCode)
{
  Castle *thisa; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@9

  thisa = this;
  if ( !buildingCode )
  {
    ++this->mageGuildLevel;
    this->mageGuildSpells[4][this->mageGuildLevel + 3] = mageGuildSpellsForLevel[this->mageGuildLevel];
    if ( this->factionID == FACTION_WIZARD && BYTE1(this->buildingsBuiltFlags) & 0x20 )
      ++this->mageGuildSpells[4][this->mageGuildLevel + 3];
    if ( this->visitingHeroIdx != -1 )
      Castle::grantHeroSpellsFromMageGuild(this, 0);
  }
  if ( buildingCode == BUILDING_SPECIAL )
  {
    if ( thisa->factionID == FACTION_WIZARD )
    {
      for ( i = 0; thisa->mageGuildLevel > i; ++i )
        ++thisa->numSpellsOfLevel[i];
      if ( thisa->visitingHeroIdx != -1 )
        Castle::grantHeroSpellsFromMageGuild(thisa, 0);
    }
  }
  thisa->buildingsBuiltFlags |= 1 << buildingCode;
  if ( buildingCode == BUILDING_UPGRADE_1 )
    thisa->buildingsBuiltFlags &= 0xFFEFFFFFu;
  if ( buildingCode == BUILDING_UPGRADE_2 )
    thisa->buildingsBuiltFlags &= 0xFFDFFFFFu;
  if ( buildingCode == BUILDING_UPGRADE_3 )
    thisa->buildingsBuiltFlags &= 0xFFBFFFFFu;
  if ( buildingCode == BUILDING_UPGRADE_4 )
    thisa->buildingsBuiltFlags &= 0xFF7FFFFFu;
  if ( buildingCode == BUILDING_UPGRADE_5 )
    thisa->buildingsBuiltFlags &= 0xFEFFFFFFu;
  if ( buildingCode == BUILDING_UPGRADE_5B )
    thisa->buildingsBuiltFlags &= 0xDEFFFFFFu;
  if ( buildingCode >= 19 && buildingCode <= 24 )
    *((_WORD *)thisa + buildingCode - 4) = creature_table[LOBYTE((&buildingShortNames[3 * thisa->factionID + 27])[buildingCode + 1])].growth;
  if ( buildingCode >= 25 && buildingCode <= 29 )
    *((_WORD *)thisa + buildingCode - 4) = *((_WORD *)thisa + buildingCode - 9);
  if ( buildingCode == 30 )
    thisa->numCreaturesInDwelling[11] = thisa->numCreaturesInDwelling[10];
  if ( buildingCode == BUILDING_CASTLE )
  {
    thisa->buildingsBuiltFlags &= 0xFFFFFFDFu;
    Castle::castleBuilt(thisa);
  }
  Castle::grantHeroSpellsFromMageGuild(thisa, 0);
  return sub_4D0606(&gameObject->_7[72], thisa->idx);
}
