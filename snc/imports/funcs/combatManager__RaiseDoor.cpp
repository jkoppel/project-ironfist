{
  combatManager *thisa; // ST28_4@1
  sample_resource v2; // ST34_8@1

  thisa = this;
  v2 = LoadPlaySample("drawbrg.82m");
  giMinExtentX = 304;
  giMinExtentY = 218;
  giMaxExtentX = 384;
  giMaxExtentY = 294;
  thisa->drawBridgePosition = MOAT_CLOSING_1;
  combatManager::DrawFrame(thisa, 1, 0, 1, 0, 75, 1, 1);
  thisa->drawBridgePosition = MOAT_CLOSING_2;
  combatManager::DrawFrame(thisa, 1, 0, 1, 0, 75, 1, 1);
  thisa->drawBridgePosition = MOAT_CLOSED;
  combatManager::DrawFrame(thisa, 1, 0, 1, 0, 75, 1, 1);
  WaitEndSample(-1, v2);
}