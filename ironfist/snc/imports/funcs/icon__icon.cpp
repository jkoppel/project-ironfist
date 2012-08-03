{
  icon *thisa; // edi@1
  int totalSize; // eax@1
  DWORD totalSizea; // esi@1
  ICNHeader *data; // eax@1

  thisa = this;
  resource::resource((resource *)this, RESOURCE_TYPE_ICN, fileID, 1, NULL);
  thisa->vtable = &icon::_vftable_;
  resourceManager::PointToFile(gpResourceManager, fileID);
  thisa->numSprites = resourceManager::ReadWord(gpResourceManager);
  totalSize = resourceManager::ReadLong(gpResourceManager);
  totalSizea = totalSize;
  data = (ICNHeader *)BaseAlloc(totalSize, "F:\\h2xsrc\\Base\\ICON.CPP", 18);
  thisa->headersAndImageData = data;
  resourceManager::ReadBlock(gpResourceManager, data, totalSizea);
  return thisa;
}