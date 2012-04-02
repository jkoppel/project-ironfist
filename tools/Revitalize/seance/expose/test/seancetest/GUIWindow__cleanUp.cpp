GUIWindow *__thiscall GUIWindow::cleanUp(GUIWindow *this)
{
  GUIWindow *result; // eax@10
  GUIWindow *thisa; // [sp+Ch] [bp-14h]@1
  AbstractGUIComponent *next; // [sp+18h] [bp-8h]@6
  AbstractGUIComponent *cur; // [sp+1Ch] [bp-4h]@4

  thisa = this;
  if ( this->flags1 & 2 && this->flags2 & 1 )
    GUIWindow::emptyBuffer(this);
  for ( cur = thisa->firstComponent; cur; cur = next )
  {
    next = cur->nextInLinkedList;
    GUIWindow::removeComponent(thisa, cur);
    if ( BYTE1(thisa->flags1) & 0x40 )
    {
      if ( cur )
        ((void (__thiscall *)(_DWORD))cur->vtable->cleanUp)(cur);
    }
  }
  result = thisa;
  thisa->flags2 = 0;
  return result;
}
