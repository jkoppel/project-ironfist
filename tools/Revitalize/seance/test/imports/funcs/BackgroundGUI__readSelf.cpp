{
  BackgroundGUI *thisa; // esi@1
  BACKGROUND_TYPE file_type; // ax@1
  char buf; // [sp+4h] [bp-10h]@2

  thisa = this;
  this->offsetX = ResourceManager::readShort(resourceManager);
  thisa->offsetY = ResourceManager::readShort(resourceManager);
  thisa->width = ResourceManager::readShort(resourceManager);
  thisa->height = ResourceManager::readShort(resourceManager);
  thisa->fieldID = ResourceManager::readShort(resourceManager);
  file_type = ResourceManager::readShort(resourceManager);
  thisa->bitmap = NULL;
  thisa->icon = NULL;
  thisa->backgroundType = file_type;
  if ( file_type == BACKGROUND_IS_FROM_FILE )
  {
    ResourceManager::readNexDOSFilename(resourceManager, &buf);
    ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
    thisa->bitmap = ResourceManager::getBitmapByFilename(resourceManager, &buf);
    ResourceManager::popFileAndOffsetOffStack(resourceManager);
  }
  else
  {
    if ( file_type == (BACKGROUND_IS_FROM_FILE|BACKGROUND_IS_ICON) )
    {
      ResourceManager::readNexDOSFilename(resourceManager, &buf);
      ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
      thisa->icon = ResourceManager::getIconByFilename(resourceManager, &buf);
      ResourceManager::popFileAndOffsetOffStack(resourceManager);
    }
    else
    {
      thisa->color = (unsigned __int8)ResourceManager::readShort(resourceManager);
    }
  }
}
