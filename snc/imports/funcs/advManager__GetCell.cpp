{
  mapCell *result; // eax@4

  if ( (signed __int64)__PAIR__(row, col) >= 0 && MAP_WIDTH > col && MAP_HEIGHT > row )
    result = &this->map->tiles[row * this->map->width] + col;
  else
    result = this->map->tiles;
  return result;
}