{
  signed int i; // [sp+14h] [bp-8h]@6
  Castle *castle; // [sp+18h] [bp-4h]@3

  if ( !dword_523F1C )
    sub_4C3190(7, castleIdx, 0, 0, a3, 0, 0);
  castle = &this->castles[castleIdx];
  if ( this->castles[castleIdx].ownerIdx != a3 )
  {
    this->castles[castleIdx]._2[0] = 0;
    if ( this->_7[castleIdx] != -1 )
      sub_469B30(&gameObject->castles[castleIdx]);
    for ( i = 0; i < 5; ++i )
    {
      castle->garrison.creatureTypes[i] = -1;
      castle->garrison.quantities[i] = 0;
    }
    if ( this->castles[castleIdx].ownerIdx == -1 )
      this->castles[castleIdx].field_55 = 2;
    else
      this->castles[castleIdx].field_55 = 0;
    this->castles[castleIdx].ownerIdx = a3;
    this->_7[castleIdx] = a3;
    *(&this->players[0].castlesOwned[284 * a3] + this->players[a3].numCastles++ - a3) = castleIdx;
    sub_470100(
      &this->map,
      (int)(&this->map.tiles[this->map.width * this->castles[castleIdx].field_5].tileType
          + 2 * (3 * this->castles[castleIdx].field_4 - 3)),
      this->castles[castleIdx].field_4 - 1,
      this->castles[castleIdx].field_5,
      14,
      2 * this->players[(char)a3].color,
      1,
      -1);
    sub_470100(
      &this->map,
      (int)(&this->map.tiles[this->map.width * this->castles[castleIdx].field_5].tileType
          + 2 * (3 * this->castles[castleIdx].field_4 + 3)),
      this->castles[castleIdx].field_4 + 1,
      this->castles[castleIdx].field_5,
      14,
      2 * this->players[(char)a3].color + 1,
      1,
      -1);
    if ( !a4 )
    {
      explore(this->castles[castleIdx].field_4, this->castles[castleIdx].field_5, a3, byte_4F21F4);
      checkGameEnd(0, 0);
    }
  }
}
