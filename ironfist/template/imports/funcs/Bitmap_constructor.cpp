{
  Bitmap *thisa; // esi@1

  thisa = this;
  AbstractResource_constructor((AbstractResource *)this, 0, 0, -1, 0);
  thisa->vtable = &Bitmap_vtable;
  thisa->setInConstructor = a2;
  thisa->width = width;
  thisa->height = height;
  thisa->contents = (unsigned __int8 *)KBAlloc(width * height, "F:\\h2xsrc\\Base\\BITMAP.CPP", 21);
  return thisa;
}
