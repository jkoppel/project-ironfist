{
  GUIWindow *thisa; // ST14_4@1

  thisa = this;
  strcpy(this->filename, "Dynamic Construct");
  thisa->prevWindow = 0;
  thisa->nextWindow = thisa->prevWindow;
  thisa->idx = -1;
  thisa->xOffset = x;
  thisa->yOffset = y;
  thisa->width = width;
  thisa->height = height;
  thisa->flags1 = flags;
  thisa->flags2 = 0;
  thisa->firstComponent = 0;
  thisa->lastComponent = thisa->firstComponent;
  thisa->bitmap = 0;
  return thisa;
}
