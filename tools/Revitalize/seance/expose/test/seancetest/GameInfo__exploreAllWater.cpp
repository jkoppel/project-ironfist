int __thiscall GameInfo::exploreAllWater(GameInfo *this, char playerIdx)
{
  int result; // eax@2
  int row; // [sp+14h] [bp-8h]@3
  int col; // [sp+18h] [bp-4h]@1

  for ( col = 0; ; ++col )
  {
    result = col;
    if ( mapWidth <= col )
      break;
    for ( row = 0; row < mapHeight; ++row )
    {
      if ( !tileToTerrainType[*(&this->map.tiles[row * this->map.width].tileType + 6 * col)] )
        *(&tileExplored[col] + mapWidth * row) |= 1 << playerIdx;
    }
  }
  return result;
}
