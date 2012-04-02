void __thiscall GUIIcon::readSelf(GUIIcon *this)
{
  GUIIcon *thisa; // esi@1
  int v2; // eax@1
  char buf[16]; // [sp+4h] [bp-10h]@1

  thisa = this;
  this->offsetX = ResourceManager::readShort(resourceManager);
  thisa->offsetY = ResourceManager::readShort(resourceManager);
  thisa->width = ResourceManager::readShort(resourceManager);
  thisa->height = ResourceManager::readShort(resourceManager);
  ResourceManager::readNexDOSFilename(resourceManager, buf);
  ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
  v2 = ResourceManager::setResource(resourceManager, buf, 1);
  thisa->iconFileID = v2;
  thisa->icon = ResourceManager::getIconByFileID(resourceManager, v2);
  ResourceManager::popFileAndOffsetOffStack(resourceManager);
  thisa->imgIdx = ResourceManager::readShort(resourceManager);
  thisa->mirror = ResourceManager::readShort(resourceManager);
  thisa->fieldID = ResourceManager::readShort(resourceManager);
  thisa->field_14 = ResourceManager::readShort(resourceManager);
  thisa->field_27 = (unsigned __int8)ResourceManager::readShort(resourceManager);
}
