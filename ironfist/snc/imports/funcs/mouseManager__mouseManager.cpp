{
  mouseManager *v1; // ebx@1
  signed int i; // edx@1

  v1 = this;
  baseManager::baseManager((baseManager *)this);
  i = 0;
  LODWORD(v1->vtable) = &mouseManager::_vftable_;
  v1->bitmap = 0;
  v1->ready = 0;
  v1->cursorCategory = -1;
  strcpy(v1->name, "mouseManager");
  v1->spriteIdx = 0;
  v1->couldBeShowMouse = 1;
  v1->cursorIcon = 0;
  memset(hbmpAndMask, 0, 0x180u);
  memset(&hMouseCursor, 0, 0x180u);
  memset(cColorBits, 0, sizeof(cColorBits));
  memset(cAndBits, 0, 0x180u);
  do
  {
    if ( iHotSpot[i].x == -1 )
      iHotSpot[i].x = iMouseSize[i].height / 2;
    if ( iHotSpot[i].y == -1 )
      iHotSpot[i].y = iMouseSize[i].height / 2;
    ++i;
  }
  while ( i < 96 );
  v1->cursorDisabled = 1;
}