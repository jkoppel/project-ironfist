MapTile *__thiscall AdvManager::getTile(AdvManager *this, int col, int row)
{
  MapTile *result; // eax@4

  if ( (signed __int64)__PAIR__(row, col) >= 0 && mapWidth > col && mapHeight > row )
    result = &this->map->tiles[row * this->map->width] + col;
  else
    result = this->map->tiles;
  return result;
}
