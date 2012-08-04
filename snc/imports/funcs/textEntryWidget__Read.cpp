{
  textEntryWidget *thisa; // esi@1
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
  this->offsetX = resourceManager::ReadWord(gpResourceManager);
  thisa->offsetY = resourceManager::ReadWord(gpResourceManager);
  thisa->width = resourceManager::ReadWord(gpResourceManager);
  thisa->height = resourceManager::ReadWord(gpResourceManager);
  v3 = resourceManager::ReadWord(gpResourceManager);
  thisa->fifthShort = v3;
  thisa->ptrToFifthShortPlusFiveManyBytes = BaseAlloc((unsigned __int16)v3 + 5, "F:\\h2xsrc\\Base\\Textntry.cpp", 99);
  resourceManager::ReadBlock(gpResourceManager, thisa->ptrToFifthShortPlusFiveManyBytes, thisa->fifthShort);
  resourceManager::Read13(gpResourceManager, &buf);
  resourceManager::SavePosition(gpResourceManager);
  thisa->font = (int)resourceManager::GetFont(gpResourceManager, &buf);
  resourceManager::RestorePosition(gpResourceManager);
  thisa->field_28 = (unsigned __int8)resourceManager::ReadWord(gpResourceManager);
  thisa->field_2A = resourceManager::ReadWord(gpResourceManager);
  resourceManager::Read13(gpResourceManager, &buf);
  resourceManager::SavePosition(gpResourceManager);
  thisa->icon = (int)resourceManager::GetIcon(gpResourceManager, &buf);
  resourceManager::RestorePosition(gpResourceManager);
  thisa->type = type;
  if ( type == 2 )
  {
    thisa->field_35 = resourceManager::ReadWord(gpResourceManager);
    thisa->field_37 = resourceManager::ReadWord(gpResourceManager);
    thisa->field_39 = resourceManager::ReadWord(gpResourceManager);
    thisa->field_3B = resourceManager::ReadWord(gpResourceManager);
    thisa->_1 = resourceManager::ReadWord(gpResourceManager);
    thisa->field_47 = resourceManager::ReadWord(gpResourceManager);
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
  thisa->field_2F = resourceManager::ReadWord(gpResourceManager);
  thisa->fieldID = resourceManager::ReadWord(gpResourceManager);
  result = resourceManager::ReadWord(gpResourceManager);
  thisa->field_14 = 16384;
  return result;
}