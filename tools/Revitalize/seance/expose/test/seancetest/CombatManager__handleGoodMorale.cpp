void __thiscall CombatManager::handleGoodMorale(CombatManager *this, int side, int stackIdx)
{
  CombatManager *thisa; // [sp+Ch] [bp-18h]@1
  CreatureStack *v4; // [sp+18h] [bp-Ch]@6
  sample_resource res; // [sp+1Ch] [bp-8h]@0

  thisa = this;
  if ( side >= 0 && stackIdx >= 0 )
  {
    if ( prevGoodMoraleRollSucceeded )
    {
      prevGoodMoraleRollSucceeded = 0;
    }
    else
    {
      prevGoodMoraleRollSucceeded = 0;
      v4 = &this->creatures[side][stackIdx];
      if ( !(HIBYTE(this->creatures[side][stackIdx].creature.creature_flags) & ATTR_UNDEAD)
        && this->creatures[side][stackIdx].quantity
        && this->creatures[side][stackIdx].morale > 0
        && nextRandomInt(1, 24) <= this->creatures[side][stackIdx].morale )
      {
        prevGoodMoraleRollSucceeded = 1;
        if ( !combatGraphicsOff )
        {
          sprintf(globBuf, "goodmrle.82M");
          res = playSample(globBuf);
          if ( thisa->creatures[side][stackIdx].quantity > 1 )
            sprintf(
              globBuf,
              "High morale enables the \n%s to attack again.",
              creaturePluralNames[thisa->creatures[side][stackIdx].creatureIdx]);
          else
            sprintf(
              globBuf,
              "High morale enables the \n%s to attack again.",
              creatureSingularNames[thisa->creatures[side][stackIdx].creatureIdx]);
          CombatManager::displayCombatMessage(thisa, globBuf, 1, 1, 0);
        }
        CreatureStack::doEffectAnimation(v4, 11, 180, 0);
        if ( thisa->creatures[side][stackIdx].creature.creature_flags & MAYBE_NOT_LOST_TURN )
          *(_DWORD *)&thisa->creatures[side][stackIdx].creature.creature_flags -= MAYBE_NOT_LOST_TURN;
        *(_DWORD *)&thisa->creatures[side][stackIdx].creature.creature_flags |= HAS_GOOD_MORALE;
        if ( !combatGraphicsOff )
          waitForSampleToFinish(-1, res);
      }
    }
  }
}
