{
  int v1; // esi@1
  __int16 result; // ax@1

  v1 = this;
  *(_WORD *)(this + 24) = resourceManager::ReadWord(gpResourceManager);
  *(_WORD *)(v1 + 26) = resourceManager::ReadWord(gpResourceManager);
  *(_WORD *)(v1 + 28) = resourceManager::ReadWord(gpResourceManager);
  *(_WORD *)(v1 + 30) = resourceManager::ReadWord(gpResourceManager);
  *(_WORD *)(v1 + 16) = resourceManager::ReadWord(gpResourceManager);
  result = resourceManager::ReadWord(gpResourceManager);
  *(_WORD *)(v1 + 20) = result;
  return result;
}