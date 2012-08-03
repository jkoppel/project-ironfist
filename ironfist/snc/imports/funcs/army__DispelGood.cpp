{
  army *thisa; // ST10_4@1

  thisa = this;
  army::CancelIndividualSpell(this, EFFECT_HASTE);
  army::CancelIndividualSpell(thisa, EFFECT_BLESS);
  army::CancelIndividualSpell(thisa, EFFECT_DRAGON_SLAYER);
  army::CancelIndividualSpell(thisa, EFFECT_BLOOD_LUST);
  army::CancelIndividualSpell(thisa, EFFECT_SHIELD);
  army::CancelIndividualSpell(thisa, EFFECT_ANTI_MAGIC);
  army::CancelIndividualSpell(thisa, EFFECT_STONESKIN);
  army::CancelIndividualSpell(thisa, EFFECT_STEELSKIN);
}