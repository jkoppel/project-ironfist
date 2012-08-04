{
  heroWindow *thisa; // [sp+Ch] [bp-8h]@1
  widget *component; // [sp+10h] [bp-4h]@1

  thisa = this;
  component = this->firstComponent;
  if ( index == -1 )
  {
    if ( component )
      index = component->componentIndex + 1;
    else
      index = 0;
  }
  if ( !widget::Open(guiObj, index, this) )
  {
    while ( component && component->componentIndex > index )
      component = component->nextInLinkedList;
    if ( component )
    {
      if ( component->prevInLinkedList )
      {
        guiObj->nextInLinkedList = component;
        guiObj->prevInLinkedList = component->prevInLinkedList;
        component->prevInLinkedList->nextInLinkedList = guiObj;
        component->prevInLinkedList = guiObj;
      }
      else
      {
        guiObj->nextInLinkedList = thisa->firstComponent;
        guiObj->prevInLinkedList = NULL;
        thisa->firstComponent->prevInLinkedList = guiObj;
        thisa->firstComponent = guiObj;
      }
    }
    else
    {
      guiObj->prevInLinkedList = thisa->lastComponent;
      guiObj->nextInLinkedList = NULL;
      thisa->lastComponent = guiObj;
      if ( !thisa->firstComponent )
        thisa->firstComponent = guiObj;
    }
  }
}