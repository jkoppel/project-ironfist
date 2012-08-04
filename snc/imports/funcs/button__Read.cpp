{
  button *v1; // esi@1
  int v2; // eax@1
  __int16 result; // ax@1
  char buf[13]; // [sp+4h] [bp-10h]@1

  v1 = this;
  HIWORD(this->flags) = resourceManager::ReadWord(gpResourceManager);
  v1->offsetY = resourceManager::ReadWord(gpResourceManager);
  v1->width = resourceManager::ReadWord(gpResourceManager);
  v1->height = resourceManager::ReadWord(gpResourceManager);
  resourceManager::Read13(gpResourceManager, buf);
  resourceManager::SavePosition(gpResourceManager);
  v2 = resourceManager::MakeId(gpResourceManager, buf, 1);
  v1->icnFileID = v2;
  v1->icon = resourceManager::GetIcon(gpResourceManager, v2);
  resourceManager::RestorePosition(gpResourceManager);
  v1->normalImageIdx = resourceManager::ReadWord(gpResourceManager);
  v1->armedImageIdx = resourceManager::ReadWord(gpResourceManager);
  v1->field_28 = resourceManager::ReadWord(gpResourceManager);
  v1->field_2A = resourceManager::ReadWord(gpResourceManager);
  v1->fieldID = resourceManager::ReadWord(gpResourceManager);
  result = resourceManager::ReadWord(gpResourceManager);
  v1->field_14 = result;
  return result;
}