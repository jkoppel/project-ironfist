void __thiscall sub_4C3300(CombatManager *this, int a2)
{
  CombatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  this->couldBeShouldResetCombatMessage = 0;
  if ( strlen(this->combatMessageRow2) > 1 || strlen(thisa->combatMessageRow1) > 1 )
  {
    if ( a2 || getTickCount() > thisa->combatMessageRelatedTime )
    {
      strcpy(thisa->combatMessageRow1, byte_51E390);
      strcpy(thisa->combatMessageRow2, byte_51E394);
      thisa->otherCombatMessageRelatedTime = 0;
      thisa->combatMessageRelatedTime = thisa->otherCombatMessageRelatedTime;
      CombatManager::displayCombatMessage(thisa, byte_51E398, 1, 0, 0);
    }
  }
}
