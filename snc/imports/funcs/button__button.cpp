{
  button *result; // eax@1

  widget::widget((widget *)this, 0, 0, 0, 0, 0, 0);
  this->normalImageIdx = 0;
  this->vtable = &tileset::_vftable_;
  this->armedImageIdx = 0;
  this->icnFileID = 0;
  this->field_28 = 0;
  result = this;
  this->field_2A = -1;
  this->icon = 0;
  return result;
}