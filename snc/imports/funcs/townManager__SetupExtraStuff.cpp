{
  town *result; // eax@17
  townManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  this->castle->buildingsBuiltFlags &= 0x7FF8BFFFu;
  if ( this->castle->factionID == FACTION_WIZARD )
    this->castle->buildingsBuiltFlags |= 0x10000u;
  if ( this->castle->factionID == FACTION_SORCERESS )
  {
    this->castle->buildingsBuiltFlags |= 0x10000u;
    this->castle->buildingsBuiltFlags |= 0x20000u;
  }
  if ( !this->castle->factionID )
  {
    this->castle->buildingsBuiltFlags |= 0x20000u;
    this->castle->buildingsBuiltFlags |= 0x40000u;
  }
  if ( this->castle->factionID == FACTION_BARBARIAN )
  {
    this->castle->buildingsBuiltFlags |= 0x20000u;
    this->castle->buildingsBuiltFlags |= 0x40000u;
    this->castle->buildingsBuiltFlags |= 0x80000000u;
  }
  if ( (this->castle->factionID == FACTION_WARLOCK
     || !this->castle->factionID
     || this->castle->factionID == FACTION_BARBARIAN
     || this->castle->factionID == FACTION_NECROMANCER)
    && town::CanBuildDock(this->castle) )
    thisa->castle->buildingsBuiltFlags |= 0x10000u;
  if ( thisa->castle->buildingsBuiltFlags & 8
    && advManager::GetCell(gpAdvManager, LOBYTE(thisa->castle->field_6), HIBYTE(thisa->castle->field_6))->objType )
  {
    result = thisa->castle;
    result->buildingsBuiltFlags |= 0x4000u;
  }
  else
  {
    result = thisa->castle;
    result->buildingsBuiltFlags &= 0xFFFFBFFFu;
  }
  return result;
}