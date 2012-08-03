{
  combatManager *thisa; // [sp+Ch] [bp-18h]@1
  army *v4; // [sp+18h] [bp-Ch]@6
  sample_resource res; // [sp+1Ch] [bp-8h]@0

  thisa = this;
  if ( side >= 0 && stackIdx >= 0 )
  {
    if ( bInHighMoraleBonus )
    {
      bInHighMoraleBonus = 0;
    }
    else
    {
      bInHighMoraleBonus = 0;
      v4 = &this->creatures[side][stackIdx];
      if ( !(HIBYTE(this->creatures[side][stackIdx].creature.creature_flags) & ATTR_UNDEAD)
        && this->creatures[side][stackIdx].quantity
        && this->creatures[side][stackIdx].morale > 0
        && SRandom(1, 24) <= this->creatures[side][stackIdx].morale )
      {
        bInHighMoraleBonus = 1;
        if ( !gbNoShowCombat )
        {
          sprintf(gText, "goodmrle.82M");
          res = LoadPlaySample(gText);
          if ( thisa->creatures[side][stackIdx].quantity > 1 )
            sprintf(
              gText,
              "High morale enables the \n%s to attack again.",
              gArmyNamesPlural[thisa->creatures[side][stackIdx].creatureIdx]);
          else
            sprintf(
              gText,
              "High morale enables the \n%s to attack again.",
              gArmyNames[thisa->creatures[side][stackIdx].creatureIdx]);
          combatManager::CombatMessage(thisa, gText, 1, 1, 0);
        }
        army::SpellEffect(v4, 11, 180, 0);
        if ( thisa->creatures[side][stackIdx].creature.creature_flags & MAYBE_NOT_LOST_TURN )
          *(_DWORD *)&thisa->creatures[side][stackIdx].creature.creature_flags -= MAYBE_NOT_LOST_TURN;
        *(_DWORD *)&thisa->creatures[side][stackIdx].creature.creature_flags |= HAS_GOOD_MORALE;
        if ( !gbNoShowCombat )
          WaitEndSample(-1, res);
      }
    }
  }
}