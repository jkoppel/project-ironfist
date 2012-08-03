{
  combatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  this->couldBeShouldResetCombatMessage = 0;
  if ( (unsigned int)strlen((int)this->combatMessageRow2) > 1 || (unsigned int)strlen((int)thisa->combatMessageRow1) > 1 )
  {
    if ( a2 || KBTickCount() > thisa->combatMessageRelatedTime )
    {
      strcpy(thisa->combatMessageRow1, byte_51E390);
      strcpy(thisa->combatMessageRow2, byte_51E394);
      thisa->otherCombatMessageRelatedTime = 0;
      thisa->combatMessageRelatedTime = thisa->otherCombatMessageRelatedTime;
      combatManager::CombatMessage(thisa, byte_51E398, 1, 0, 0);
    }
  }
}