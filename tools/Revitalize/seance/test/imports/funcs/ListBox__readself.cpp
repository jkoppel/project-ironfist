{
  ListBox *v1; // esi@1
  __int16 v2; // ax@1
  int v3; // ecx@1
  int v4; // eax@1
  __int16 v5; // ST14_2@1
  __int16 v6; // di@1
  __int16 v7; // bx@1
  __int16 v8; // bp@1
  __int16 v9; // dx@1
  __int16 v10; // bx@1
  int v11; // eax@1
  __int16 v12; // di@1
  __int16 v13; // dx@1
  int v14; // eax@1
  __int16 v15; // bp@1
  __int16 result; // ax@1
  char buf; // [sp+14h] [bp-10h]@1

  v1 = this;
  this->offsetX = ResourceManager::readShort(resourceManager);
  v1->offsetY = ResourceManager::readShort(resourceManager);
  v1->width = ResourceManager::readShort(resourceManager);
  v1->height = ResourceManager::readShort(resourceManager);
  ResourceManager::readNexDOSFilename(resourceManager, &buf);
  ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
  v1->fontID = (int)ResourceManager::getFontByFilename(resourceManager, &buf);
  ResourceManager::popFileAndOffsetOffStack(resourceManager);
  ResourceManager::readNexDOSFilename(resourceManager, &buf);
  ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
  v1->icon = ResourceManager::getIconByFilename(resourceManager, &buf);
  ResourceManager::popFileAndOffsetOffStack(resourceManager);
  v1->field_28 = ResourceManager::readShort(resourceManager);
  v1->field_2C = ResourceManager::readShort(resourceManager);
  v1->field_2E = ResourceManager::readShort(resourceManager);
  v1->field_30 = ResourceManager::readShort(resourceManager);
  v2 = ResourceManager::readShort(resourceManager);
  v1->field_44[0] = 0;
  v1->fieldID = v2;
  v1->field_44[1] = 1;
  v1->field_44[2] = 2;
  v1->field_44[3] = 3;
  v1->field_44[4] = 4;
  v1->field_44[5] = 5;
  v1->field_44[6] = 6;
  v1->field_44[7] = 7;
  v1->field_44[8] = 8;
  v1->field_44[9] = 9;
  v1->field_44[10] = 10;
  v3 = (int)v1->icon;
  v4 = *(_DWORD *)(v3 + 18);
  v3 += 18;
  v4 += 130;
  v1->field_72[9] = *(_WORD *)(v4 + 4);
  LOWORD(v4) = *(_WORD *)(v4 + 6);
  v5 = v4;
  v1->field_72[10] = v4;
  v6 = *(_WORD *)(*(_DWORD *)v3 + 6);
  v1->field_44[11] = v6;
  v7 = v1->offsetX;
  LOWORD(v4) = *(_WORD *)(*(_DWORD *)v3 + 19);
  v8 = v1->offsetY;
  v1->field_44[12] = v4;
  v9 = *(_WORD *)(*(_DWORD *)v3 + 32);
  v1->field_44[13] = v9;
  v1->field_44[14] = v7;
  v1->field_44[15] = v8;
  v1->field_44[16] = *(_WORD *)(*(_DWORD *)v3 + 4);
  v1->field_44[17] = v9 + v6 + (_WORD)v4 * (v1->field_28 - 2);
  v10 = *(_WORD *)(*(_DWORD *)v3 + 43);
  v11 = *(_DWORD *)v3 + 39;
  v1->field_44[20] = v10;
  v12 = *(_WORD *)(v11 + 6);
  v1->field_44[21] = v12;
  v13 = *(_WORD *)(*(_DWORD *)v3 + 69);
  v14 = *(_DWORD *)v3 + 65;
  LOWORD(v3) = v1->width - v10;
  v1->field_72[5] = v13;
  LOWORD(v3) = v1->offsetX + v3;
  LOWORD(v14) = *(_WORD *)(v14 + 6);
  v1->field_72[6] = v14;
  v1->field_44[18] = v3;
  v1->field_44[19] = v8;
  v15 = v1->height - v14;
  v1->field_72[3] = v3;
  LOWORD(v14) = v15 + v1->offsetY;
  v1->field_72[4] = v14;
  v1->field_44[22] = v3;
  LOWORD(v3) = v12 + v1->offsetY;
  LOWORD(v14) = v14 - v3;
  LOBYTE(v1->field_72[12]) = 0;
  HIBYTE(v1->field_72[12]) = 0;
  HIBYTE(v1->field_72[13]) = 0;
  LOBYTE(v1->field_72[13]) = 0;
  v1->field_40 = 0;
  v1->field_42 = 0;
  v1->field_2A = 0;
  v1->field_72[0] = v3;
  v1->field_72[1] = v13;
  v1->field_72[2] = v14;
  result = v14 - v5 - 7;
  v1->field_72[11] = result;
  return result;
}
