{
  _write(fd, &this->width, 4);
  _write(fd, &this->height, 4);
  _write(fd, this->tiles, sizeof(mapCell) * this->height * this->width);
  _write(fd, &this->field_10, 4);
  _write(fd, (LPCVOID)this->field_4, 7 * this->field_10);
}