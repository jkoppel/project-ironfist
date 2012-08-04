{
  if ( this->tiles )
    operator delete(this->tiles);
  this->tiles = 0;
  if ( this->field_4 )
    operator delete((void *)this->field_4);
  this->field_4 = 0;
  this->field_10 = 0;
}