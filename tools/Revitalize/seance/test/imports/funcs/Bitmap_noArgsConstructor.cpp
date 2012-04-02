{
  Bitmap *thisa; // esi@1
  Bitmap *result; // eax@1

  thisa = this;
  AbstractResource_constructor((AbstractResource *)this, 0, 0, -1, 0u);
  thisa->setInConstructor = 0;
  thisa->vtable = &Bitmap_vtable;
  thisa->width = 0;
  result = thisa;
  thisa->height = 0;
  thisa->contents = 0;
  return result;
}
