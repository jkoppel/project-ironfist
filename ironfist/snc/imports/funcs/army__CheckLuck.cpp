{
  double v1; // st6@0
  army *thisa; // [sp+Ch] [bp-1Ch]@1
  char *v3; // [sp+10h] [bp-18h]@18
  char *v4; // [sp+14h] [bp-14h]@14
  sample_resource samp; // [sp+20h] [bp-8h]@12

  thisa = this;
  this->luckStatus = 0;
  if ( gpCombatManager->heroes[this->owningSide] )
  {
    if ( this->luck > 0 && SRandom(1, 24) <= this->luck )
      thisa->luckStatus = 1;
    if ( thisa->luck < 0 && SRandom(1, 24) < -thisa->luck )
      thisa->luckStatus = -1;
    if ( thisa->luckStatus )
    {
      if ( thisa->luckStatus >= 0 )
        sprintf(gText, "goodluck.82m");
      else
        sprintf(gText, "badluck.82m");
      samp = LoadPlaySample(gText);
      if ( thisa->luckStatus >= 0 )
      {
        if ( thisa->quantity <= 1 )
          v3 = gArmyNames[thisa->creatureIdx];
        else
          v3 = gArmyNamesPlural[thisa->creatureIdx];
        sprintf(gText, "Good luck shines on the %s", v3);
        combatManager::CombatMessage(gpCombatManager, gText, 1, 1, 0);
        combatManager::DoLuck(gpCombatManager, v1, thisa->owningSide, thisa->stackIdx);
      }
      else
      {
        if ( thisa->quantity <= 1 )
          v4 = gArmyNames[thisa->creatureIdx];
        else
          v4 = gArmyNamesPlural[thisa->creatureIdx];
        sprintf(gText, "Bad luck descends on the %s", v4);
        combatManager::CombatMessage(gpCombatManager, gText, 1, 1, 0);
        army::SpellEffect(thisa, ANIM_CLOUD_LUCK_IDX, 180, 0);
      }
      WaitEndSample(-1, samp);
      if ( thisa->luckStatus > 0 )
      {
        combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
        mouseManager::ShowColorPointer(gpMouseManager);
      }
    }
  }
}