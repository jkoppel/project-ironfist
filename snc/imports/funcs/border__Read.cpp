{
  border *thisa; // esi@1
  BACKGROUND_TYPE file_type; // ax@1
  char buf; // [sp+4h] [bp-10h]@2

  thisa = this;
  this->offsetX = resourceManager::ReadWord(gpResourceManager);
  thisa->offsetY = resourceManager::ReadWord(gpResourceManager);
  thisa->width = resourceManager::ReadWord(gpResourceManager);
  thisa->height = resourceManager::ReadWord(gpResourceManager);
  thisa->fieldID = resourceManager::ReadWord(gpResourceManager);
  file_type = resourceManager::ReadWord(gpResourceManager);
  thisa->bitmap = NULL;
  thisa->icon = NULL;
  thisa->backgroundType = file_type;
  if ( file_type == BACKGROUND_IS_FROM_FILE )
  {
    resourceManager::Read13(gpResourceManager, &buf);
    resourceManager::SavePosition(gpResourceManager);
    thisa->bitmap = resourceManager::GetBitmap(gpResourceManager, &buf);
    resourceManager::RestorePosition(gpResourceManager);
  }
  else if ( file_type == (BACKGROUND_IS_FROM_FILE|BACKGROUND_IS_ICON) )
  {
    resourceManager::Read13(gpResourceManager, &buf);
    resourceManager::SavePosition(gpResourceManager);
    thisa->icon = resourceManager::GetIcon(gpResourceManager, &buf);
    resourceManager::RestorePosition(gpResourceManager);
  }
  else
  {
    thisa->color = (unsigned __int8)resourceManager::ReadWord(gpResourceManager);
  }
}