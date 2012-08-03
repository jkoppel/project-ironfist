{
  font *this; // [sp+Ch] [bp-18h]@1
  char buf; // [sp+10h] [bp-14h]@4
  int v5; // [sp+20h] [bp-4h]@1

  this = ecx0;
  resource::resource((resource *)ecx0, RESOURCE_TYPE_FONT, fileID, 1, 0);
  this->vtable = &font::_vftable_;
  resourceManager::PointToFile(gpResourceManager, fileID);
  this->lineHeight = resourceManager::ReadWord(gpResourceManager);
  v5 = resourceManager::ReadWord(gpResourceManager);
  this->whetherFirstShortIsMoreThan13 = this->lineHeight >= 14;
  resourceManager::Read13(gpResourceManager, &buf);
  gbLoadingMonoIcon = 1;
  this->icon = resourceManager::GetIcon(gpResourceManager, &buf);
  gbLoadingMonoIcon = 0;
  return this;
}