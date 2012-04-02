{
  AbstractGUIComponent *guiComp; // [sp+14h] [bp-8h]@1
  int v4; // [sp+18h] [bp-4h]@1

  v4 = 0;
  for ( guiComp = this->firstComponent; guiComp; guiComp = guiComp->nextInLinkedList )
  {
    v4 = guiComp->vtable->handleEvent(guiComp, &evt->inputEvt);
    if ( v4 && v4 >= 1 && v4 <= 2 )
      return v4;
  }
  return v4;
}
