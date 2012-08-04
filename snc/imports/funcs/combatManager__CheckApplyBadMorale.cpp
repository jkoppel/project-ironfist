{
  signed int result; // eax@3
  combatManager *thisa; // [sp+Ch] [bp-18h]@1
  army *creature; // [sp+18h] [bp-Ch]@4
  sample_resource res; // [sp+1Ch] [bp-8h]@0

  thisa = this;
  if ( side >= 0 && stackIdx >= 0 )
  {
    creature = &this->creatures[side][stackIdx];
    if ( HIBYTE(this->creatures[side][stackIdx].creature.creature_flags) & ATTR_UNDEAD )
    {
      result = 0;
    }
    else if ( this->creatures[side][stackIdx].morale < 0 && SRandom(1, 12) <= -this->creatures[side][stackIdx].morale )
    {
      if ( thisa->involvedInBadMorale[side] || SRandom(1, 4) != 1 )
      {
        if ( !gbNoShowCombat )
        {
          res = LoadPlaySample("BADMRLE.82M");
          if ( thisa->creatures[side][stackIdx].quantity > 1 )
            sprintf(
              gText,
              "Low morale causes the \n%s to freeze in panic.",
              gArmyNamesPlural[thisa->creatures[side][stackIdx].creatureIdx]);
          else
            sprintf(
              gText,
              "Low morale causes the \n%s to freeze in panic.",
              gArmyNames[thisa->creatures[side][stackIdx].creatureIdx]);
          combatManager::CombatMessage(thisa, gText, 1, 1, 0);
        }
        army::SpellEffect(creature, ANIM_MORALE_BAD_IDX, 180, 1);
        *(_DWORD *)&thisa->creatures[side][stackIdx].creature.creature_flags |= MAYBE_NOT_LOST_TURN;
        if ( !gbNoShowCombat )
          WaitEndSample(-1, res);
        result = 1;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}