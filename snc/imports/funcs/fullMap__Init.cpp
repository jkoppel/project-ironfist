{
  this->width = width;
  this->height = height;
  fullMap::Close(this);
  this->tiles = (mapCell *)operator new(12 * this->height * this->width);
}