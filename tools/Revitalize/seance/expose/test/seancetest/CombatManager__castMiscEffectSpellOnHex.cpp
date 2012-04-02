void __thiscall CombatManager::castMiscEffectSpellOnHex(CombatManager *this, int hexIdx)
{
  CombatManager *v2; // [sp+Ch] [bp-8h]@1

  v2 = this;
  if ( checkHexGridIdxBounds(hexIdx) )
  {
    if ( v2->combatGrid[hexIdx].unitOwner >= 0 )
      CreatureStack::doEffectAnimation(
        &v2->creatures[v2->combatGrid[hexIdx].unitOwner][v2->combatGrid[hexIdx].stackIdx],
        spell_table[v2->current_spell_id].creatureEffectAnimationIdx,
        0,
        1);
  }
}
