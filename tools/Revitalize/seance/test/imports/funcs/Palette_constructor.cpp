{
  Palette *thisa; // esi@1

  thisa = this;
  AbstractResource_constructor((AbstractResource *)this, RESOURCE_TYPE_PALETTE, 0, 1, 0);
  thisa->vtable = (ResourceVtable *)&Palette_vtable;
  thisa->contents = (PaletteContents *)KBAlloc(0x300u, "F:\\h2xsrc\\Base\\PALETTE.CPP", 8);
  return thisa;
}
