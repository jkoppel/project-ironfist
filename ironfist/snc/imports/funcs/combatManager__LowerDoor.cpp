{
  combatManager *thisa; // [sp+Ch] [bp-18h]@1
  int i; // [sp+18h] [bp-Ch]@1
  sample_resource res; // [sp+1Ch] [bp-8h]@1

  thisa = this;
  res = LoadPlaySample("drawbrg.82m");
  giMinExtentX = 304;
  giMinExtentY = 218;
  giMaxExtentX = 384;
  giMaxExtentY = 294;
  for ( i = MOAT_CLOSING_2; i >= MOAT_OPEN; --i )
  {
    thisa->drawBridgePosition = i;
    combatManager::DrawFrame(thisa, 1, 0, 1, 0, 75, 1, 1);
  }
  WaitEndSample(-1, res);
}