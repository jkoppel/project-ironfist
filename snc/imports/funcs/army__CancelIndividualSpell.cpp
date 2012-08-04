{
  if ( this->effectStrengths[effect] )
  {
    --this->numActiveEffects;
    this->effectStrengths[effect] = 0;
    switch ( effect )
    {
      case EFFECT_HASTE:
      case EFFECT_SLOW:
        this->creature.speed = LOBYTE(this->speed);
        *(_DWORD *)&this->gap_129[162] = this->field_B2;
        *(_DWORD *)&this->creature.creature_flags |= *(_DWORD *)&gMonsterDatabase[this->creatureIdx].creature_flags & FLYER;
        break;
      case EFFECT_BLOOD_LUST:
        this->creature.attack -= 3;
        break;
      case EFFECT_STONESKIN:
        this->creature.defense -= 3;
        break;
      case EFFECT_STEELSKIN:
        this->creature.defense -= 5;
        break;
      case EFFECT_BLIND:
      case EFFECT_BLESS:
      case EFFECT_CURSE:
      case EFFECT_BERSERKER:
      case EFFECT_PARALYZE:
      case EFFECT_HYPNOTIZE:
      case EFFECT_DRAGON_SLAYER:
      case EFFECT_SHIELD:
      case EFFECT_PETRIFY:
      case EFFECT_ANTI_MAGIC:
        return;
    }
  }
}