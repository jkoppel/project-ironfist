void __thiscall GUIWindow::removeComponentByID(GUIWindow *this, int id)
{
  GUIWindow *thisa; // [sp+Ch] [bp-14h]@1
  AbstractGUIComponent *next; // [sp+18h] [bp-8h]@3
  AbstractGUIComponent *cur; // [sp+1Ch] [bp-4h]@1

  thisa = this;
  for ( cur = this->firstComponent; cur; cur = next )
  {
    next = cur->nextInLinkedList;
    if ( cur->fieldID == id )
    {
      GUIWindow::removeComponent(thisa, cur);
      if ( BYTE1(thisa->flags1) & 0x40 )
      {
        if ( cur )
          cur->vtable->cleanUp(cur, 1);
      }
    }
  }
}
