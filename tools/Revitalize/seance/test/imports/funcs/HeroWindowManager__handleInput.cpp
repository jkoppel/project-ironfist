{
  int result; // eax@1
  GUIWindow *i; // edi@1

  result = 0;
  for ( i = this->lastWindow; i; i = i->prevWindow )
  {
    result = GUIWindow::processMessage(i, (Event *)evt);
    if ( result >= 1 && result <= 2 )
      break;
  }
  return result;
}
