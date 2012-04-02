int __thiscall CreatureStack::getNextEffectAnimationBottomY(CreatureStack *this)
{
  CreatureStack *thisa; // [sp+Ch] [bp-8h]@1
  int v3; // [sp+10h] [bp-4h]@1

  thisa = this;
  v3 = CreatureStack::getCenterY(this);
  if ( nextCreatureEffectAnimationIdx == ANIM_HYPNOTIZE_IDX
    || nextCreatureEffectAnimationIdx == ANIM_PARALYZE_IDX
    || nextCreatureEffectAnimationIdx == ANIM_BLESS_IDX
    || nextCreatureEffectAnimationIdx == ANIM_CURSE_IDX
    || nextCreatureEffectAnimationIdx == ANIM_DRAGONSLAYER_IDX
    || nextCreatureEffectAnimationIdx == ANIM_BERZERK_IDX )
    v3 = CreatureStack::getStandingTopY(thisa);
  if ( nextCreatureEffectAnimationIdx == ANIM_STONESKIN_IDX || nextCreatureEffectAnimationIdx == ANIM_STEELSKIN_IDX )
    v3 = combatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY + 5;
  return v3;
}
