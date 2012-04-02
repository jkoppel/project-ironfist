void __thiscall CreatureStack::cure(CreatureStack *this, int spellpower)
{
  CreatureStack::removeEffect(this, EFFECT_SLOW);
  CreatureStack::removeEffect(this, EFFECT_BLIND);
  CreatureStack::removeEffect(this, EFFECT_CURSE);
  CreatureStack::removeEffect(this, EFFECT_BERSERKER);
  CreatureStack::removeEffect(this, EFFECT_PARALYZE);
  CreatureStack::removeEffect(this, EFFECT_HYPNOTIZE);
  CreatureStack::removeEffect(this, EFFECT_PETRIFY);
  this->damage -= 5 * spellpower;
  if ( this->damage < 0 )
    this->damage = 0;
}
