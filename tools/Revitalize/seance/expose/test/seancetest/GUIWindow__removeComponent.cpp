void __thiscall GUIWindow::removeComponent(GUIWindow *this, AbstractGUIComponent *comp)
{
  GUIWindow *thisa; // [sp+Ch] [bp-8h]@1
  AbstractGUIComponent *v3; // [sp+10h] [bp-4h]@10

  thisa = this;
  if ( comp )
  {
    nullsub_2();
    if ( thisa->lastComponent == comp )
    {
      thisa->lastComponent = comp->prevInLinkedList;
      if ( thisa->lastComponent )
        thisa->lastComponent->nextInLinkedList = 0;
      else
        thisa->firstComponent = 0;
    }
    else
    {
      if ( thisa->firstComponent == comp )
      {
        thisa->firstComponent = comp->nextInLinkedList;
        thisa->firstComponent->prevInLinkedList = 0;
      }
      else
      {
        comp->nextInLinkedList->prevInLinkedList = comp->prevInLinkedList;
        comp->prevInLinkedList->nextInLinkedList = comp->nextInLinkedList;
      }
    }
    v3 = comp->nextInLinkedList;
    if ( v3 )
    {
      v3->prevInLinkedList = comp->prevInLinkedList;
      if ( v3->prevInLinkedList )
        v3->prevInLinkedList->nextInLinkedList = v3;
    }
    else
    {
      thisa->firstComponent = 0;
      thisa->lastComponent = thisa->firstComponent;
    }
  }
}
