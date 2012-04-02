__int16 __thiscall sub_4DBC30(int this)
{
  int v1; // esi@1
  __int16 result; // ax@1

  v1 = this;
  *(_WORD *)(this + 24) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 26) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 28) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 30) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 16) = ResourceManager::readShort(resourceManager);
  result = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 20) = result;
  return result;
}
