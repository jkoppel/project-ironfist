{
  qtyToTrade = 0;
  return ComputeTradeRatios(
           leftResource,
           rightResource,
           (int)&iTradeRatio,
           (int)&bLeftDenominated,
           (int)&iMaxUnitsToTrade);
}