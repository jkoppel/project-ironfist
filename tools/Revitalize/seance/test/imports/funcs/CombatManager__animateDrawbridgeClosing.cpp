{
  CombatManager *thisa; // ST28_4@1
  sample_resource v2; // ST34_8@1

  thisa = this;
  v2 = playSample("drawbrg.82m");
  combatScreenRedrawRectLeft = 304;
  combatScreenRedrawRectTop = 218;
  combatScreenRedrawRectRight = 384;
  combatScreenRedrawRectBot = 294;
  thisa->drawBridgePosition = MOAT_CLOSING_1;
  CombatManager::drawBattlefield(thisa, 1, 0, 1, 0, 75, 1, 1);
  thisa->drawBridgePosition = MOAT_CLOSING_2;
  CombatManager::drawBattlefield(thisa, 1, 0, 1, 0, 75, 1, 1);
  thisa->drawBridgePosition = MOAT_CLOSED;
  CombatManager::drawBattlefield(thisa, 1, 0, 1, 0, 75, 1, 1);
  waitForSampleToFinish(-1, v2);
}
