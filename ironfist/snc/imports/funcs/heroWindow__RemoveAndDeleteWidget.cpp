{
  heroWindow *thisa; // [sp+Ch] [bp-14h]@1
  widget *next; // [sp+18h] [bp-8h]@3
  widget *cur; // [sp+1Ch] [bp-4h]@1

  thisa = this;
  for ( cur = this->firstComponent; cur; cur = next )
  {
    next = cur->nextInLinkedList;
    if ( cur->fieldID == id )
    {
      heroWindow::RemoveWidget(thisa, cur);
      if ( BYTE1(thisa->flags1) & 0x40 )
      {
        if ( cur )
          cur->vtable->cleanUp(cur, 1);
      }
    }
  }
}