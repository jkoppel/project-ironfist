{
  Tileset *thisa; // esi@1
  int v3; // edi@1
  int v4; // eax@1
  size_t v5; // edi@1
  void *v6; // eax@1

  thisa = this;
  AbstractResource_constructor((AbstractResource *)this, RESOURCE_TYPE_TILESET, fileID, 1, 0);
  thisa->vtable = (ResourceVtable *)Tileset_vtable;
  ResourceManager::pointToFile(resourceManager, fileID);
  thisa->field_10 = ResourceManager::readShort(resourceManager);
  HIWORD(v3) = 0;
  thisa->field_12 = ResourceManager::readShort(resourceManager);
  LOWORD(v4) = ResourceManager::readShort(resourceManager);
  LOWORD(v3) = v4;
  thisa->field_14 = v4;
  v4 = (unsigned __int16)v4;
  LOWORD(v4) = thisa->field_10;
  v5 = thisa->field_12 * v4 * v3;
  v6 = KBAlloc(v5, "F:\\h2xsrc\\Base\\TILESET.CPP", 18);
  thisa->contents = v6;
  ResourceManager::readFromCurrentFile(resourceManager, v6, v5);
  return thisa;
}
