{
  bitmap *thisa; // edi@1
  __int16 height; // ax@1
  DWORD size; // esi@1

  thisa = this;
  resource::resource((resource *)this, 0, fileID, 1, 0);
  thisa->vtable = &bitmap::_vftable_;
  resourceManager::PointToFile(gpResourceManager, fileID);
  thisa->setInConstructor = resourceManager::ReadWord(gpResourceManager);
  thisa->width = resourceManager::ReadWord(gpResourceManager);
  height = resourceManager::ReadWord(gpResourceManager);
  thisa->height = height;
  size = thisa->width * height;
  thisa->contents = (unsigned __int8 *)BaseAlloc(thisa->width * height, "F:\\h2xsrc\\Base\\BITMAP.CPP", 37);
  PollSound();
  resourceManager::ReadBlock(gpResourceManager, thisa->contents, size);
  PollSound();
  return thisa;
}