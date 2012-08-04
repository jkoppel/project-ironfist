{
  MIDIWrap *thisa; // esi@1
  int v3; // eax@1
  int v4; // eax@1
  int size; // edi@1

  thisa = this;
  v3 = resourceManager::MakeId(gpResourceManager, filename, 1);
  resource::resource((resource *)thisa, RESOURCE_TYPE_SAMPLE, v3, 1, 0);
  v4 = thisa->fileID;
  thisa->vtable = &MIDIWrap::_vftable_;
  size = resourceManager::GetFileSize(gpResourceManager, v4);
  thisa->contents = BaseAlloc(size, "F:\\h2xsrc\\Base\\SAMPLE.CPP", 110);
  resourceManager::PointToFile(gpResourceManager, thisa->fileID);
  resourceManager::ReadBlock(gpResourceManager, thisa->contents, size);
  return thisa;
}