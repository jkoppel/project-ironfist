{
  palette *thisa; // edi@1

  thisa = this;
  resource::resource((resource *)this, RESOURCE_TYPE_PALETTE, fileID, 1, 0);
  thisa->vtable = (ResourceVtable *)&palette::_vftable_;
  thisa->contents = (PaletteContents *)BaseAlloc(0x300u, "F:\\h2xsrc\\Base\\PALETTE.CPP", 13);
  resourceManager::PointToFile(gpResourceManager, fileID);
  resourceManager::ReadBlock(gpResourceManager, thisa->contents, 0x300u);
  return thisa;
}