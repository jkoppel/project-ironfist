void __thiscall CombatManager::initializeArmyAndHeroData(CombatManager *this)
{
  CombatManager *thisa; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  thisa = this;
  this->notHandlingInputEvent = 0;
  this->field_F357 = 0;
  for ( i = 0; i < 2; ++i )
  {
    thisa->heroSpellpowers[i] = 0;
    if ( thisa->heroes[i] )
      thisa->heroSpellpowers[i] = Hero::getPrimarySkill(thisa->heroes[i], PRIMARY_SKILL_SPELLPOWER);
    if ( thisa->castles[i] && thisa->castles[i]->factionID == FACTION_NECROMANCER )
    {
      if ( BYTE1(thisa->castles[i]->buildingsBuiltFlags) & BUILDING_SPECIAL_DEFENSE_BUILT )
        thisa->heroSpellpowers[i] += 2;
    }
  }
  thisa->heroFlagIconIdx[0] = 0;
  thisa->heroFlagIconIdx[1] = 3;
  thisa->field_F377[0] = 0;
  thisa->field_F377[1] = 0;
  thisa->winningSide = 3;
  thisa->field_33A2 = 0;
  thisa->field_33A1 = thisa->field_33A2;
  thisa->field_33A3[1] = 0;
  thisa->field_33A3[0] = thisa->field_33A3[1];
  thisa->field_339D[1] = 0;
  thisa->field_339D[0] = thisa->field_339D[1];
  thisa->field_339F[1] = 0;
  thisa->field_339F[0] = thisa->field_339F[1];
  thisa->eagleEyeSpellLearned[0] = -1;
  thisa->eagleEyeSpellLearned[1] = -1;
  couldBeCreatureActionType = 0;
  thisa->summonedCreatureType[0] = 0;
  thisa->summonedCreatureType[1] = 0;
  thisa->field_F2C3 = -1;
  thisa->field_F2BB = -1;
  thisa->field_F2CB = -99;
  thisa->currentActionSide = 1;
  thisa->otherCurrentSideThing = 1;
  thisa->field_F2AB = 15;
  isRetreating = 0;
  isSurrendering = 0;
  thisa->field_351F[0] = 0;
  thisa->field_351F[1] = 0;
  thisa->field_F2B7 = 1;
  thisa->numCombatObjs = 0;
  CombatManager::initializeHexNeighbors(thisa);
  CombatManager::resetCombatGrid(thisa);
  CombatManager::initializeCreatureStacks(thisa);
}
