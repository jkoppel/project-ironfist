{
  army *thisa; // [sp+Ch] [bp-8h]@1
  int v3; // [sp+10h] [bp-4h]@1

  thisa = this;
  v3 = army::MidY(this);
  if ( gCurLoadedSpellEffect == ANIM_HYPNOTIZE_IDX
    || gCurLoadedSpellEffect == ANIM_PARALYZE_IDX
    || gCurLoadedSpellEffect == ANIM_BLESS_IDX
    || gCurLoadedSpellEffect == ANIM_CURSE_IDX
    || gCurLoadedSpellEffect == ANIM_DRAGONSLAYER_IDX
    || gCurLoadedSpellEffect == ANIM_BERZERK_IDX )
    v3 = army::TopY(thisa);
  if ( gCurLoadedSpellEffect == ANIM_STONESKIN_IDX || gCurLoadedSpellEffect == ANIM_STEELSKIN_IDX )
    v3 = gpCombatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY + 5;
  return v3;
}