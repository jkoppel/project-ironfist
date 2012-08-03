void __thiscall MapTiles::save(MapTiles *this, int fd)
{
  _write(fd, &this->width, 4);
  _write(fd, &this->height, 4);
  _write(fd, this->tiles, sizeof(MapTile) * this->height * this->width);
  _write(fd, &this->field_10, 4);
  _write(fd, (LPCVOID)this->field_4, 7 * this->field_10);
}
