{
  int v3; // ST20_4@13
  army *thisa; // [sp+Ch] [bp-10h]@1
  int losses; // [sp+14h] [bp-8h]@5

  thisa = this;
  baseDam += this->damage;
  if ( spell != SPELL_NONE )
  {
    if ( gbRemoteOn )
      combatManager::ModifyDamageForArtifacts(
        &baseDam,
        spell,
        gpCombatManager->heroes[this->owningSide],
        gpCombatManager->heroes[gpCombatManager->currentActionSide]);
    else
      combatManager::ModifyDamageForArtifacts(
        &baseDam,
        spell,
        gpCombatManager->heroes[gpCombatManager->currentActionSide],
        gpCombatManager->heroes[this->owningSide]);
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
  thisa->facingRight = gpCombatManager->creatures[gpCombatManager->otherCurrentSideThing][gpCombatManager->someSortOfStackIdx].facingRight ^ 1;// Checked assembly; looks correct. Wow, this is odd!
  thisa->facingRight = v3;
  army::CancelSpellType(thisa, CREATURE_TOOK_DAMAGE_CODE);
  return losses;
}