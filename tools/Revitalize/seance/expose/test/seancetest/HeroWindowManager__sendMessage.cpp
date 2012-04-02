int __thiscall HeroWindowManager::sendMessage(HeroWindowManager *this, INPUT_EVENT_CODE code, int messageType, int fieldID, int payload)
{
  InputEvent evt; // [sp+4h] [bp-1Ch]@1

  evt.eventCode = code;
  evt.xCoordOrKeycode = messageType;
  evt.yCoord = fieldID;
  evt.payload = (void *)payload;
  return this->vtable->handleInput((AbstractManager *)this, &evt);
}
