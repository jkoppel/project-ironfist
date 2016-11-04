{
  TextWidget *v1; // esi@1
  __int16 v2; // ax@1
  unsigned int v3; // edi@1
  void *v4; // eax@1
  __int16 result; // ax@1
  char buf; // [sp+8h] [bp-10h]@1

  v1 = this;
  this->offsetX = ResourceManager::readShort(resourceManager);
  v1->offsetY = ResourceManager::readShort(resourceManager);
  v1->width = ResourceManager::readShort(resourceManager);
  v1->height = ResourceManager::readShort(resourceManager);
  v2 = ResourceManager::readShort(resourceManager);
  v3 = v2;
  v4 = KBAlloc(v2, "F:\\h2xsrc\\Base\\TEXTWDGT.CPP", 57);
  v1->content = (char *)v4;
  ResourceManager::readFromCurrentFile(resourceManager, v4, v3);
  ResourceManager::readNexDOSFilename(resourceManager, &buf);
  ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
  v1->font = ResourceManager::getFontByFilename(resourceManager, &buf);
  ResourceManager::popFileAndOffsetOffStack(resourceManager);
  v1->field_28 = (unsigned __int8)ResourceManager::readShort(resourceManager);
  v1->field_2A = ResourceManager::readShort(resourceManager);
  v1->fieldID = ResourceManager::readShort(resourceManager);
  result = ResourceManager::readShort(resourceManager);
  v1->field_14 = 512;
  return result;
}
