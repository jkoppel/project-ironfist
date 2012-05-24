void __thiscall CreatureStack::rollAndHandleLuck(CreatureStack *this)
{
  double v1; // st6@0
  CreatureStack *thisa; // [sp+Ch] [bp-1Ch]@1
  char *v3; // [sp+10h] [bp-18h]@18
  char *v4; // [sp+14h] [bp-14h]@14
  sample_resource sample; // [sp+20h] [bp-8h]@12

  thisa = this;
  this->luckStatus = 0;
  if ( combatManager->heroes[this->owningSide] )
  {
    if ( this->luck > 0 && nextRandomInt(1, 24) <= this->luck )
      thisa->luckStatus = 1;
    if ( thisa->luck < 0 && nextRandomInt(1, 24) < -thisa->luck )
      thisa->luckStatus = -1;
    if ( thisa->luckStatus )
    {
      if ( thisa->luckStatus >= 0 )
        sprintf(globBuf, "goodluck.82m");
      else
        sprintf(globBuf, "badluck.82m");
      sample = playSample(globBuf);
      if ( thisa->luckStatus >= 0 )
      {
        if ( thisa->quantity <= 1 )
          v3 = creatureSingularNames[thisa->creatureIdx];
        else
          v3 = creaturePluralNames[thisa->creatureIdx];
        sprintf(globBuf, "Good luck shines on the %s", v3);
        CombatManager::displayCombatMessage(combatManager, globBuf, 1, 1, 0);
        CombatManager::drawLuckAnimation(combatManager, v1, thisa->owningSide, thisa->stackIdx);
      }
      else
      {
        if ( thisa->quantity <= 1 )
          v4 = creatureSingularNames[thisa->creatureIdx];
        else
          v4 = creaturePluralNames[thisa->creatureIdx];
        sprintf(globBuf, "Bad luck descends on the %s", v4);
        CombatManager::displayCombatMessage(combatManager, globBuf, 1, 1, 0);
        CreatureStack::doEffectAnimation(thisa, ANIM_CLOUD_LUCK_IDX, 180, 0);
      }
      waitForSampleToFinish(-1, sample);
      if ( thisa->luckStatus > 0 )
      {
        CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
        MouseManager::enableCursor(mouseManager);
      }
    }
  }
}
