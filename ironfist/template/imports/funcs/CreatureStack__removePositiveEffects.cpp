{
  CreatureStack *thisa; // ST10_4@1

  thisa = this;
  CreatureStack::removeEffect(this, EFFECT_HASTE);
  CreatureStack::removeEffect(thisa, EFFECT_BLESS);
  CreatureStack::removeEffect(thisa, EFFECT_DRAGON_SLAYER);
  CreatureStack::removeEffect(thisa, EFFECT_BLOOD_LUST);
  CreatureStack::removeEffect(thisa, EFFECT_SHIELD);
  CreatureStack::removeEffect(thisa, EFFECT_ANTI_MAGIC);
  CreatureStack::removeEffect(thisa, EFFECT_STONESKIN);
  CreatureStack::removeEffect(thisa, EFFECT_STEELSKIN);
}
