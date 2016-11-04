{
  MapTile *result; // eax@1

  this->width = a2;
  this->height = a3;
  sub_46F710((void **)&this->tiles);
  result = (MapTile *)operator new(12 * this->height * this->width);
  this->tiles = result;
  return result;
}
