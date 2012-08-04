{
  tag_message evt; // [sp+4h] [bp-1Ch]@1

  evt.eventCode = code;
  evt.xCoordOrKeycode = messageType;
  evt.yCoord = fieldID;
  evt.payload = (void *)payload;
  return this->vtable->handleInput((baseManager *)this, &evt);
}