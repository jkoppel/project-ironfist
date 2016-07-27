{
  int result; // eax@1

  result = 0;
  memset(this->mainDataStructure, 0, sizeof(this->mainDataStructure));
  memset(this->field_2414, 0, 9 * mapHeight * mapWidth);
  this->field_8 = 0;
  this->field_0 = 0;
  return result;
}
