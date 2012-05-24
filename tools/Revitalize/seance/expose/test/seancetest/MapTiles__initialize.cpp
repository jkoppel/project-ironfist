void __thiscall MapTiles::initialize(MapTiles *this, int width, int height)
{
  this->width = width;
  this->height = height;
  MapTiles_destructor(this);
  this->tiles = (MapTile *)operator new(12 * this->height * this->width);
}
