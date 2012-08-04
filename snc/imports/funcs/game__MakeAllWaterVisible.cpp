{
  int result; // eax@2
  int row; // [sp+14h] [bp-8h]@3
  int col; // [sp+18h] [bp-4h]@1

  for ( col = 0; ; ++col )
  {
    result = col;
    if ( MAP_WIDTH <= col )
      break;
    for ( row = 0; row < MAP_HEIGHT; ++row )
    {
      if ( !giGroundToTerrain[*(&this->map.tiles[row * this->map.width].tileType + 6 * col)] )
        *(&mapExtra[col] + MAP_WIDTH * row) |= 1 << playerIdx;
    }
  }
  return result;
}