{
  combatManager *v2; // [sp+Ch] [bp-8h]@1

  v2 = this;
  if ( ValidHex(hexIdx) )
  {
    if ( v2->combatGrid[hexIdx].unitOwner >= 0 )
      army::SpellEffect(
        &v2->creatures[v2->combatGrid[hexIdx].unitOwner][v2->combatGrid[hexIdx].stackIdx],
        gsSpellInfo[v2->current_spell_id].creatureEffectAnimationIdx,
        0,
        1);
  }
}