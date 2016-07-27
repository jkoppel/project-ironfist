{
  Palette *thisa; // edi@1

  thisa = this;
  AbstractResource_constructor((AbstractResource *)this, RESOURCE_TYPE_PALETTE, fileID, 1, 0);
  thisa->vtable = (ResourceVtable *)&Palette_vtable;
  thisa->contents = (PaletteContents *)KBAlloc(0x300u, "F:\\h2xsrc\\Base\\PALETTE.CPP", 13);
  ResourceManager::pointToFile(resourceManager, fileID);
  ResourceManager::readFromCurrentFile(resourceManager, thisa->contents, 0x300u);
  return thisa;
}
