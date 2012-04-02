__int16 __thiscall Button::readSelf(Button *this)
{
  Button *v1; // esi@1
  int v2; // eax@1
  __int16 result; // ax@1
  char buf[13]; // [sp+4h] [bp-10h]@1

  v1 = this;
  HIWORD(this->flags) = ResourceManager::readShort(resourceManager);
  v1->offsetY = ResourceManager::readShort(resourceManager);
  v1->width = ResourceManager::readShort(resourceManager);
  v1->height = ResourceManager::readShort(resourceManager);
  ResourceManager::readNexDOSFilename(resourceManager, buf);
  ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
  v2 = ResourceManager::setResource(resourceManager, buf, 1);
  v1->icnFileID = v2;
  v1->icon = ResourceManager::getIconByFileID(resourceManager, v2);
  ResourceManager::popFileAndOffsetOffStack(resourceManager);
  v1->normalImageIdx = ResourceManager::readShort(resourceManager);
  v1->armedImageIdx = ResourceManager::readShort(resourceManager);
  v1->field_28 = ResourceManager::readShort(resourceManager);
  v1->field_2A = ResourceManager::readShort(resourceManager);
  v1->fieldID = ResourceManager::readShort(resourceManager);
  result = ResourceManager::readShort(resourceManager);
  v1->field_14 = result;
  return result;
}
