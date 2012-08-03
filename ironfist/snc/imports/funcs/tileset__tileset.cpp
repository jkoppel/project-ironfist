{
  tileset *thisa; // esi@1
  int v3; // edi@1
  int v4; // eax@1
  int v5; // edi@1
  void *v6; // eax@1

  thisa = this;
  resource::resource((resource *)this, RESOURCE_TYPE_TILESET, fileID, 1, 0);
  thisa->vtable = (ResourceVtable *)button::_vftable_;
  resourceManager::PointToFile(gpResourceManager, fileID);
  thisa->numTiles = resourceManager::ReadWord(gpResourceManager);
  HIWORD(v3) = 0;
  thisa->field_12 = resourceManager::ReadWord(gpResourceManager);
  LOWORD(v4) = resourceManager::ReadWord(gpResourceManager);
  LOWORD(v3) = v4;
  thisa->field_14 = v4;
  v4 = (unsigned __int16)v4;
  LOWORD(v4) = thisa->numTiles;
  v5 = thisa->field_12 * v4 * v3;
  v6 = BaseAlloc(v5, "F:\\h2xsrc\\Base\\TILESET.CPP", 18);
  thisa->contents = v6;
  resourceManager::ReadBlock(gpResourceManager, v6, v5);
  return thisa;
}