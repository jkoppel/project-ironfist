{
  int v3; // [sp+10h] [bp-8h]@1
  signed int i; // [sp+14h] [bp-4h]@1

  v3 = 0;
  for ( i = 0; this->players[playerIdx].numCastles > i; ++i )
  {
    if ( gameObject->castles[*(&this->players[0].castlesOwned[284 * playerIdx] + i - playerIdx)].buildingsBuiltFlags & 2 )
      ++v3;
  }
  return v3;
}
