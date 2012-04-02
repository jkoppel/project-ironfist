AbstractGUIComponent *__thiscall AbstractGUIComponent_constructor(AbstractGUIComponent *this, __int16 a2, __int16 a3, __int16 a4, __int16 a5, __int16 fieldID, __int16 a7)
{
  this->offsetX = a2;
  this->vtable = &AbstractGUIComponent_vtable;
  this->parentWindow = 0;
  this->offsetY = a3;
  this->nextInLinkedList = 0;
  this->prevInLinkedList = 0;
  this->field_16 = 6;
  this->componentIndex = -1;
  this->width = a4;
  this->height = a5;
  this->fieldID = fieldID;
  this->field_14 = a7;
  return this;
}
