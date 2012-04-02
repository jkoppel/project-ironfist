{
  signed __int64 result; // qax@6
  CombatManager *thisa; // [sp+14h] [bp-18h]@1
  CreatureStack *v6; // [sp+18h] [bp-14h]@4
  signed int hpRestored; // [sp+20h] [bp-Ch]@1
  signed int v8; // [sp+24h] [bp-8h]@4
  int creaturesRaised; // [sp+28h] [bp-4h]@4

  thisa = this;
  hpRestored = 50 * this->heroSpellpowers[this->currentActionSide];
  if ( this->heroes[this->currentActionSide] && Hero::hasArtifact(this->heroes[this->currentActionSide], ARTIFACT_ANKH) )
    hpRestored *= 2;
  v8 = CombatManager::getCorpseStackIdx(thisa, thisa->currentActionSide, spell, hexIdx);
  v6 = &thisa->creatures[thisa->currentActionSide][v8];
  creaturesRaised = hpRestored / thisa->creatures[thisa->currentActionSide][v8].creature.hp;
  if ( creaturesRaised + thisa->creatures[thisa->currentActionSide][v8].quantity > thisa->creatures[thisa->currentActionSide][v8].initialQuantity )
    creaturesRaised = thisa->creatures[thisa->currentActionSide][v8].initialQuantity
                    - thisa->creatures[thisa->currentActionSide][v8].quantity;
  *val = creaturesRaised * creature_table[thisa->creatures[thisa->currentActionSide][v8].creatureIdx].fight_value;
  result = (signed __int64)(CreatureStack::getSpellSuccessChance(v6, spell) * (double)*val);
  *val = result;
  if ( spell == SPELL_RESURRECT )
  {
    result = (signed __int64)((double)*val * 0.85);
    *val = result;
  }
  return result;
}
