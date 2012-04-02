void __thiscall CombatManager::animateDrawbridgeOpening(CombatManager *this)
{
  CombatManager *thisa; // [sp+Ch] [bp-18h]@1
  int i; // [sp+18h] [bp-Ch]@1
  sample_resource res; // [sp+1Ch] [bp-8h]@1

  thisa = this;
  res = playSample("drawbrg.82m");
  combatScreenRedrawRectLeft = 304;
  combatScreenRedrawRectTop = 218;
  combatScreenRedrawRectRight = 384;
  combatScreenRedrawRectBot = 294;
  for ( i = MOAT_CLOSING_2; i >= MOAT_OPEN; --i )
  {
    thisa->drawBridgePosition = i;
    CombatManager::drawBattlefield(thisa, 1, 0, 1, 0, 75, 1, 1);
  }
  waitForSampleToFinish(-1, res);
}
