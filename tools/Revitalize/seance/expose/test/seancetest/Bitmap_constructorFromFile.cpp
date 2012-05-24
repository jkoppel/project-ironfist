Bitmap *__thiscall Bitmap_constructorFromFile(Bitmap *this, int fileID)
{
  Bitmap *thisa; // edi@1
  __int16 height; // ax@1
  DWORD size; // esi@1

  thisa = this;
  AbstractResource_constructor((AbstractResource *)this, 0, fileID, 1, 0);
  thisa->vtable = &Bitmap_vtable;
  ResourceManager::pointToFile(resourceManager, fileID);
  thisa->setInConstructor = ResourceManager::readShort(resourceManager);
  thisa->width = ResourceManager::readShort(resourceManager);
  height = ResourceManager::readShort(resourceManager);
  thisa->height = height;
  size = thisa->width * height;
  thisa->contents = (unsigned __int8 *)KBAlloc(thisa->width * height, "F:\\h2xsrc\\Base\\BITMAP.CPP", 37);
  yieldToGlobalUpdater();
  ResourceManager::readFromCurrentFile(resourceManager, thisa->contents, size);
  yieldToGlobalUpdater();
  return thisa;
}
