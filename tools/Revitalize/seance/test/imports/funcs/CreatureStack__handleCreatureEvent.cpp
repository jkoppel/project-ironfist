{
  CreatureStack *thisa; // [sp+10h] [bp-4h]@1

  thisa = this;
  switch ( code )
  {
    case CREATURE_TOOK_TURN_EVENT_CODE:
      CreatureStack::removeEffect(this, EFFECT_BERSERKER);
      CreatureStack::removeEffect(thisa, EFFECT_HYPNOTIZE);
      break;
    case CREATURE_TOOK_DAMAGE_CODE:
      if ( this->effectStrengths[2] )
      {
        CreatureStack::removeEffect(this, EFFECT_BLIND);
        thisa->otherBadLuckThing = 2;
        *(_DWORD *)&thisa->creature.creature_flags |= MAYBE_NOT_LOST_TURN;
      }
      if ( thisa->effectStrengths[6] || thisa->effectStrengths[7] || thisa->effectStrengths[11] )
      {
        *(_DWORD *)&thisa->creature.creature_flags |= MAYBE_NOT_LOST_TURN;
        *(_DWORD *)&thisa->creature.creature_flags |= RETALIATED;
        CreatureStack::removeEffect(thisa, EFFECT_PARALYZE);
        CreatureStack::removeEffect(thisa, EFFECT_PETRIFY);
      }
      break;
    case CREATURE_MOVED_CODE:
    case CREATURE_TOOK_DAMAGE_CODE|CREATURE_TOOK_TURN_EVENT_CODE:
      return;
  }
}
