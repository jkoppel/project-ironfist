Font *__thiscall Font_constructor(Font *ecx0, int fileID)
{
  Font *this; // [sp+Ch] [bp-18h]@1
  char buf; // [sp+10h] [bp-14h]@4
  int v5; // [sp+20h] [bp-4h]@1

  this = ecx0;
  AbstractResource_constructor((AbstractResource *)ecx0, RESOURCE_TYPE_FONT, fileID, 1, 0);
  this->vtable = &Font_vtable;
  ResourceManager::pointToFile(resourceManager, fileID);
  this->lineHeight = ResourceManager::readShort(resourceManager);
  v5 = ResourceManager::readShort(resourceManager);
  this->whetherFirstShortIsMoreThan13 = this->lineHeight >= 14;
  ResourceManager::readNexDOSFilename(resourceManager, &buf);
  neverReadGlobal1 = 1;
  this->icon = ResourceManager::getIconByFilename(resourceManager, &buf);
  neverReadGlobal1 = 0;
  return this;
}
