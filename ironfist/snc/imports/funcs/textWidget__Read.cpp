{
  textWidget *v1; // esi@1
  __int16 v2; // ax@1
  DWORD v3; // edi@1
  char *v4; // eax@1
  __int16 result; // ax@1
  char buf; // [sp+8h] [bp-10h]@1

  v1 = this;
  this->offsetX = resourceManager::ReadWord(gpResourceManager);
  v1->offsetY = resourceManager::ReadWord(gpResourceManager);
  v1->width = resourceManager::ReadWord(gpResourceManager);
  v1->height = resourceManager::ReadWord(gpResourceManager);
  v2 = resourceManager::ReadWord(gpResourceManager);
  v3 = v2;
  v4 = (char *)BaseAlloc(v2, "F:\\h2xsrc\\Base\\TEXTWDGT.CPP", 57);
  v1->content = v4;
  resourceManager::ReadBlock(gpResourceManager, v4, v3);
  resourceManager::Read13(gpResourceManager, &buf);
  resourceManager::SavePosition(gpResourceManager);
  v1->font = resourceManager::GetFont(gpResourceManager, &buf);
  resourceManager::RestorePosition(gpResourceManager);
  v1->field_28 = (unsigned __int8)resourceManager::ReadWord(gpResourceManager);
  v1->field_2A = resourceManager::ReadWord(gpResourceManager);
  v1->fieldID = resourceManager::ReadWord(gpResourceManager);
  result = resourceManager::ReadWord(gpResourceManager);
  v1->field_14 = 512;
  return result;
}