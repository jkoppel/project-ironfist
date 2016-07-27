{
  Font *font; // eax@1
  TextWidget *thisa; // esi@1

  font = this->font;
  this->vtable = &TextWidget_vtable;
  thisa = this;
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)font);
  KBFree(thisa->content, (int)"F:\\h2xsrc\\Base\\TEXTWDGT.CPP", 85);
  AbstractGUIComponent_destructor(thisa);
  if ( a2 & 1 )
    operator delete(thisa);
  return thisa;
}
