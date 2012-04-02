void __thiscall HeroWindowManager::addWindow(HeroWindowManager *this, GUIWindow *window, int idx, int redraw)
{
  GUIWindow *lastWindow; // ebx@1
  HeroWindowManager *thisa; // edi@1
  int idxToPlace; // ebp@1
  GUIWindow *v7; // eax@13
  GUIWindow *v8; // ecx@13
  GUIWindow *v9; // eax@16

  lastWindow = this->lastWindow;
  thisa = this;
  idxToPlace = 0;
  if ( !(window->flags1 & 1) )
    idxToPlace = idx;
  if ( idxToPlace == -1 )
  {
    idxToPlace = 0;
    if ( lastWindow )
      idxToPlace = lastWindow->idx + 1;
  }
  if ( (!idxToPlace || this->firstWindow) && !GUIWindow::placeInIdx(window, idxToPlace, redraw) )
  {
    if ( !lastWindow )
      goto LABEL_21;
    do
    {
      if ( lastWindow->idx <= idxToPlace )
        break;
      lastWindow = lastWindow->prevWindow;
    }
    while ( lastWindow );
    if ( lastWindow )
    {
      if ( lastWindow->nextWindow )
      {
        window->prevWindow = lastWindow;
        window->nextWindow = lastWindow->nextWindow;
        lastWindow->nextWindow->prevWindow = window;
        lastWindow->nextWindow = window;
      }
      else
      {
        v9 = thisa->lastWindow;
        window->nextWindow = 0;
        window->prevWindow = v9;
        thisa->lastWindow->nextWindow = window;
        thisa->lastWindow = window;
      }
    }
    else
    {
LABEL_21:
      v7 = thisa->firstWindow;
      window->prevWindow = 0;
      window->nextWindow = v7;
      v8 = thisa->lastWindow;
      thisa->firstWindow = window;
      if ( !v8 )
        thisa->lastWindow = window;
    }
    thisa->nextTopmostWindow = thisa->topmostWindow;
    thisa->topmostWindow = window;
  }
}
