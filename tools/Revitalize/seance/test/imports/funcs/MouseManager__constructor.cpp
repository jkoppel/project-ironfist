{
  MouseManager *v1; // ebx@1
  signed int i; // edx@1

  v1 = this;
  AbstractManager_constructor((AbstractManager *)this);
  i = 0;
  LODWORD(v1->vtable) = &MouseManager__vtable;
  v1->bitmap = 0;
  v1->ready = 0;
  v1->cursorCategory = -1;
  strcpy(v1->name, "mouseManager");
  v1->spriteIdx = 0;
  v1->couldBeShowMouse = 1;
  v1->cursorIcon = 0;
  memset(dword_533B40, 0, 0x180u);
  memset(&cursorCache, 0, 0x180u);
  memset(cursorBitmapFileContents, 0, sizeof(cursorBitmapFileContents));
  memset(cursorBmBits, 0, 0x180u);
  do
  {
    if ( cursorHotspots[i].x == -1 )
      cursorHotspots[i].x = cursorDimensions[i].height / 2;
    if ( cursorHotspots[i].y == -1 )
      cursorHotspots[i].y = cursorDimensions[i].height / 2;
    ++i;
  }
  while ( i < 96 );
  v1->cursorDisabled = 1;
}
