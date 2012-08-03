{
  army::CancelIndividualSpell(this, EFFECT_SLOW);
  army::CancelIndividualSpell(this, EFFECT_BLIND);
  army::CancelIndividualSpell(this, EFFECT_CURSE);
  army::CancelIndividualSpell(this, EFFECT_BERSERKER);
  army::CancelIndividualSpell(this, EFFECT_PARALYZE);
  army::CancelIndividualSpell(this, EFFECT_HYPNOTIZE);
  army::CancelIndividualSpell(this, EFFECT_PETRIFY);
  this->damage -= 5 * spellpower;
  if ( this->damage < 0 )
    this->damage = 0;
}