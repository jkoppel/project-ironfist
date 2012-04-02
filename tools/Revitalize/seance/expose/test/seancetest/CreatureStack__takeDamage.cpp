int __thiscall CreatureStack::takeDamage(CreatureStack *this, signed int baseDam, Spell spell)
{
  int v3; // ST20_4@13
  CreatureStack *thisa; // [sp+Ch] [bp-10h]@1
  int losses; // [sp+14h] [bp-8h]@5

  thisa = this;
  baseDam += this->damage;
  if ( spell != SPELL_NONE )
  {
    if ( dword_4F7494 )
      modifySpellDamageForArtifacts(
        &baseDam,
        spell,
        combatManager->heroes[this->owningSide],
        combatManager->heroes[combatManager->currentActionSide]);
    else
      modifySpellDamageForArtifacts(
        &baseDam,
        spell,
        combatManager->heroes[combatManager->currentActionSide],
        combatManager->heroes[this->owningSide]);
  }
  losses = baseDam / thisa->creature.hp;
  thisa->damage = baseDam % thisa->creature.hp;
  if ( HIBYTE(thisa->creature.creature_flags) & ATTR_MIRROR_IMAGE )
  {
    losses = thisa->quantity;
    thisa->damage = 0;
  }
  thisa->damageTakenDuringSomeTimePeriod = 1;
  if ( losses > 0 )
  {
    thisa->hasTakenLosses = 1;
    thisa->previousQuantity = thisa->quantity;
  }
  if ( thisa->quantity < losses )
    losses = thisa->quantity;
  thisa->quantity -= losses;
  if ( thisa->quantity <= 0 )
    thisa->dead = 1;
  v3 = thisa->facingRight;
  thisa->facingRight = combatManager->creatures[combatManager->otherCurrentSideThing][combatManager->someSortOfStackIdx].facingRight ^ 1;// Checked assembly; looks correct. Wow, this is odd!
  thisa->facingRight = v3;
  CreatureStack::handleCreatureEvent(thisa, CREATURE_TOOK_DAMAGE_CODE);
  return losses;
}
