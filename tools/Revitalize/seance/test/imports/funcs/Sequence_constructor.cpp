{
  Sequence *thisa; // esi@1
  int v3; // eax@1
  int v4; // eax@1
  size_t size; // edi@1

  thisa = this;
  v3 = ResourceManager::setResource(resourceManager, filename, 1);
  AbstractResource_constructor((AbstractResource *)thisa, RESOURCE_TYPE_SAMPLE, v3, 1, 0);
  v4 = thisa->fileID;
  thisa->vtable = &Sequence_vtable;
  size = ResourceManager::getFileSize(resourceManager, v4);
  thisa->contents = KBAlloc(size, "F:\\h2xsrc\\Base\\SAMPLE.CPP", 110);
  ResourceManager::pointToFile(resourceManager, thisa->fileID);
  ResourceManager::readFromCurrentFile(resourceManager, thisa->contents, size);
  return thisa;
}
