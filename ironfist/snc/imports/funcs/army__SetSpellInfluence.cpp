{
  signed int result; // eax@4
  __int64 v4; // qax@7
  army *thisa; // [sp+18h] [bp-8h]@1
  STACK_MODIFYING_EFFECT effect; // [sp+1Ch] [bp-4h]@15

  thisa = this;
  if ( this->effectStrengths[effectType] )
  {
    if ( this->effectStrengths[effectType] < strength )
      this->effectStrengths[effectType] = strength;
    result = 0;
  }
  else
  {
    switch ( effectType )
    {
      case 0:
        army::CancelIndividualSpell(this, EFFECT_SLOW);
        thisa->creature.speed += 2;
        *(_DWORD *)&thisa->gap_129[162] = (signed __int64)((double)*(signed int *)&thisa->gap_129[162] * 0.65);
        goto LABEL_24;
      case 1:
        army::CancelIndividualSpell(this, 0);
        v4 = (signed int)thisa->creature.speed + 1;
        thisa->creature.speed = ((signed int)v4 - HIDWORD(v4)) >> 1;
        if ( thisa->creature.creature_flags & 2 )
          *(_DWORD *)&thisa->creature.creature_flags -= 2;
        *(_DWORD *)&thisa->gap_129[162] = (signed __int64)((double)*(signed int *)&thisa->gap_129[162] * 1.5);
        goto LABEL_24;
      case 3:
        army::CancelIndividualSpell(this, EFFECT_CURSE);
        goto LABEL_24;
      case 4:
        army::CancelIndividualSpell(this, EFFECT_BLESS);
        goto LABEL_24;
      case 5:
        army::CancelIndividualSpell(this, EFFECT_HYPNOTIZE);
        goto LABEL_24;
      case 7:
        army::CancelIndividualSpell(this, EFFECT_BERSERKER);
        goto LABEL_24;
      case 9:
        this->creature.attack += 3;
        goto LABEL_24;
      case 12:
        for ( effect = 0; (signed int)effect < 15; ++effect )
          army::CancelIndividualSpell(thisa, effect);
        goto LABEL_24;
      case 13:
        if ( this->effectStrengths[14] )
        {
          result = 0;
        }
        else
        {
          this->creature.defense += 3;
LABEL_24:
          ++thisa->numActiveEffects;
          thisa->effectStrengths[effectType] = strength;
          result = 1;
        }
        break;
      case 14:
        army::CancelIndividualSpell(this, EFFECT_STONESKIN);
        thisa->creature.defense += 5;
        goto LABEL_24;
      case 2:
      case 6:
      case 8:
      case 10:
      case 11:
        goto LABEL_24;
    }
  }
  return result;
}