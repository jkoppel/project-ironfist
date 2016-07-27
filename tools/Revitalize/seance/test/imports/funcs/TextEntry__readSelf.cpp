{
  TextEntry *thisa; // esi@1
  __int16 v3; // ax@1
  __int16 v4; // cx@3
  __int16 v5; // dx@3
  __int16 v6; // ax@3
  __int16 v7; // cx@6
  __int16 v8; // ax@7
  __int16 v9; // cx@8
  __int16 v10; // cx@9
  __int16 v11; // dx@9
  __int16 v12; // ax@9
  __int16 result; // ax@10
  char buf; // [sp+8h] [bp-10h]@1

  thisa = this;
  this->offsetX = ResourceManager::readShort(resourceManager);
  thisa->offsetY = ResourceManager::readShort(resourceManager);
  thisa->width = ResourceManager::readShort(resourceManager);
  thisa->height = ResourceManager::readShort(resourceManager);
  v3 = ResourceManager::readShort(resourceManager);
  thisa->fifthShort = v3;
  thisa->ptrToFifthShortPlusFiveManyBytes = KBAlloc((unsigned __int16)v3 + 5, "F:\\h2xsrc\\Base\\Textntry.cpp", 99);
  ResourceManager::readFromCurrentFile(resourceManager, thisa->ptrToFifthShortPlusFiveManyBytes, thisa->fifthShort);
  ResourceManager::readNexDOSFilename(resourceManager, &buf);
  ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
  thisa->font = (int)ResourceManager::getFontByFilename(resourceManager, &buf);
  ResourceManager::popFileAndOffsetOffStack(resourceManager);
  thisa->field_28 = (unsigned __int8)ResourceManager::readShort(resourceManager);
  thisa->field_2A = ResourceManager::readShort(resourceManager);
  ResourceManager::readNexDOSFilename(resourceManager, &buf);
  ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
  thisa->icon = (int)ResourceManager::getIconByFilename(resourceManager, &buf);
  ResourceManager::popFileAndOffsetOffStack(resourceManager);
  thisa->type = type;
  if ( type == 2 )
  {
    thisa->field_35 = ResourceManager::readShort(resourceManager);
    thisa->field_37 = ResourceManager::readShort(resourceManager);
    thisa->field_39 = ResourceManager::readShort(resourceManager);
    thisa->field_3B = ResourceManager::readShort(resourceManager);
    thisa->_1 = ResourceManager::readShort(resourceManager);
    thisa->field_47 = ResourceManager::readShort(resourceManager);
  }
  else
  {
    v4 = thisa->offsetY;
    v5 = thisa->width;
    thisa->field_35 = thisa->offsetX;
    v6 = thisa->height;
    thisa->field_37 = v4;
    thisa->field_39 = v5;
    thisa->field_3B = v6;
    thisa->_1 = 1;
    thisa->field_47 = 1;
    if ( type != 3 )
      thisa->field_47 = 0;
  }
  if ( type == 4 )
  {
    thisa->field_41 = thisa->offsetX + 7;
    v7 = thisa->height;
    thisa->field_43 = thisa->offsetY + 5;
    thisa->field_3D = thisa->width - 14;
    thisa->field_3F = v7;
  }
  else
  {
    v8 = thisa->offsetX;
    if ( type == 5 )
    {
      thisa->field_41 = v8 + 7;
      v9 = thisa->height;
      thisa->field_43 = thisa->offsetY + 4;
      thisa->field_3D = thisa->width - 14;
      thisa->field_3F = v9;
    }
    else
    {
      v10 = thisa->offsetY;
      v11 = thisa->width;
      thisa->field_41 = v8;
      v12 = thisa->height;
      thisa->field_43 = v10;
      thisa->field_3D = v11;
      thisa->field_3F = v12;
    }
  }
  thisa->field_2F = ResourceManager::readShort(resourceManager);
  thisa->fieldID = ResourceManager::readShort(resourceManager);
  result = ResourceManager::readShort(resourceManager);
  thisa->field_14 = 16384;
  return result;
}
