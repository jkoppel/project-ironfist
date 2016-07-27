{
  AbstractResource *fnt; // eax@1
  TextWidget *thisa; // esi@1

  fnt = (AbstractResource *)this->font;
  this->vtable = &TextWidget_vtable;
  thisa = this;
  ResourceManager::reduceReferenceCountToResource(resourceManager, fnt);
  KBFree(thisa->content, (int)"F:\\h2xsrc\\Base\\TEXTWDGT.CPP", 85);
  AbstractGUIComponent_destructor(thisa);
}
