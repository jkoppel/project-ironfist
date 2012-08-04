{
  iconWidget *thisa; // esi@1
  int v2; // eax@1
  char buf[16]; // [sp+4h] [bp-10h]@1

  thisa = this;
  this->offsetX = resourceManager::ReadWord(gpResourceManager);
  thisa->offsetY = resourceManager::ReadWord(gpResourceManager);
  thisa->width = resourceManager::ReadWord(gpResourceManager);
  thisa->height = resourceManager::ReadWord(gpResourceManager);
  resourceManager::Read13(gpResourceManager, buf);
  resourceManager::SavePosition(gpResourceManager);
  v2 = resourceManager::MakeId(gpResourceManager, buf, 1);
  thisa->iconFileID = v2;
  thisa->icon = resourceManager::GetIcon(gpResourceManager, v2);
  resourceManager::RestorePosition(gpResourceManager);
  thisa->imgIdx = resourceManager::ReadWord(gpResourceManager);
  thisa->mirror = resourceManager::ReadWord(gpResourceManager);
  thisa->fieldID = resourceManager::ReadWord(gpResourceManager);
  thisa->field_14 = resourceManager::ReadWord(gpResourceManager);
  thisa->field_27 = (unsigned __int8)resourceManager::ReadWord(gpResourceManager);
}