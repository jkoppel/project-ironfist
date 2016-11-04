{
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; player->numCastles > i; ++i )
  {
    if ( player->castlesOwned[i] == castleIdx )
      return i;
  }
  return -1;
}
