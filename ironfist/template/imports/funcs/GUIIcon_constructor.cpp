{
  GUIIcon *thisa; // edi@1
  int v12; // eax@1
  GUIIcon *result; // eax@1

  thisa = this;
  AbstractGUIComponent_constructor((AbstractGUIComponent *)this, x, y, width, height, fieldID, a10);
  thisa->vtable = &GUIIcon_vtable;
  v12 = ResourceManager::setResource(resourceManager, filename, 1);
  thisa->iconFileID = v12;
  thisa->icon = ResourceManager::getIconByFileID(resourceManager, v12);
  thisa->imgIdx = imgIdx;
  thisa->mirror = mirror;
  thisa->field_27 = a11;
  result = thisa;
  thisa->field_14 = a10;
  return result;
}
