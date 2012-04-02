__int16 __thiscall sub_4DA960(int this)
{
  int v1; // esi@1
  __int16 v2; // ax@1
  __int16 v3; // bp@1
  int v4; // edx@1
  __int16 v5; // bx@1
  int v6; // eax@1
  __int16 v7; // cx@1
  int v8; // edi@1
  int v9; // eax@1
  __int16 result; // ax@1
  char buf; // [sp+10h] [bp-10h]@1

  v1 = this;
  *(_WORD *)(this + 24) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 26) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 28) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 30) = ResourceManager::readShort(resourceManager);
  ResourceManager::readNexDOSFilename(resourceManager, &buf);
  ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
  *(_DWORD *)(v1 + 32) = ResourceManager::getFontByFilename(resourceManager, &buf);
  ResourceManager::popFileAndOffsetOffStack(resourceManager);
  ResourceManager::readNexDOSFilename(resourceManager, &buf);
  ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
  *(_DWORD *)(v1 + 36) = ResourceManager::getIconByFilename(resourceManager, &buf);
  ResourceManager::popFileAndOffsetOffStack(resourceManager);
  *(_WORD *)(v1 + 40) = ResourceManager::readShort(resourceManager) + *(_WORD *)(v1 + 24);
  *(_WORD *)(v1 + 42) = ResourceManager::readShort(resourceManager) + *(_WORD *)(v1 + 26);
  *(_WORD *)(v1 + 44) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 46) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 48) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 52) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 54) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 56) = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 58) = ResourceManager::readShort(resourceManager);
  v2 = ResourceManager::readShort(resourceManager);
  *(_WORD *)(v1 + 72) = 0;
  *(_WORD *)(v1 + 74) = 1;
  *(_WORD *)(v1 + 76) = 2;
  *(_WORD *)(v1 + 78) = 3;
  *(_WORD *)(v1 + 80) = 4;
  *(_WORD *)(v1 + 82) = 5;
  *(_WORD *)(v1 + 84) = 6;
  *(_WORD *)(v1 + 86) = 7;
  *(_WORD *)(v1 + 88) = 8;
  *(_WORD *)(v1 + 90) = 9;
  *(_WORD *)(v1 + 92) = 10;
  *(_WORD *)(v1 + 16) = v2;
  v3 = *(_WORD *)(v1 + 24);
  v4 = *(_DWORD *)(v1 + 36) + 18;
  *(_WORD *)(v1 + 94) = 11;
  *(_WORD *)(v1 + 96) = 12;
  *(_WORD *)(v1 + 98) = 13;
  v5 = *(_WORD *)(v1 + 26);
  v6 = *(_DWORD *)v4;
  *(_WORD *)(v1 + 108) = v3;
  *(_WORD *)(v1 + 110) = v5;
  v7 = *(_WORD *)(v6 + 4);
  *(_WORD *)(v1 + 112) = v7;
  *(_WORD *)(v1 + 114) = *(_WORD *)(v6 + 6);
  v8 = *(_DWORD *)v4;
  *(_WORD *)(v1 + 100) = v3 + v7;
  v8 += 13;
  *(_WORD *)(v1 + 102) = v5;
  *(_WORD *)(v1 + 104) = *(_WORD *)(v8 + 4);
  *(_WORD *)(v1 + 106) = *(_WORD *)(v8 + 6);
  v9 = *(_DWORD *)v4 + 169;
  *(_WORD *)(v1 + 166) = *(_WORD *)(*(_DWORD *)v4 + 173);
  result = *(_WORD *)(v9 + 6);
  *(_WORD *)(v1 + 168) = result;
  return result;
}
