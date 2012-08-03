{
  unsigned int v7; // ebp@5
  int v8; // ebx@5
  int v9; // ecx@12
  int x; // [sp+10h] [bp-8h]@1
  bitmap *bmpa; // [sp+14h] [bp-4h]@1

  x = xOff;
  bmpa = bmp;
  if ( gbColorMice )
  {
    if ( giScrollX || giScrollY )
    {
      v7 = 448;
      v8 = giScrollY + 16;
      x = giScrollX + 16;
      height = 448;
    }
    else
    {
      v8 = yOff;
      v7 = width;
    }
    dword_532E78 = v7 + screenX - 1;
    dword_532E70 = screenY + height - 1;
    if ( mouseManager::IsVis(gpMouseManager)
      && gpMouseManager->cursorTopLeftX <= dword_532E78
      && gpMouseManager->field_6E >= screenX
      && gpMouseManager->cursorTopLeftY <= dword_532E70
      && gpMouseManager->field_72 >= screenY )
    {
      mouseManager::SaveAndDraw(gpMouseManager);
      BlitBitmapToScreenVesa(bmpa, x, v8, v7, height, screenX, screenY);
      v9 = gpMouseManager->field_6E;
      if ( v9 > dword_532E78
        || gpMouseManager->cursorTopLeftX < screenX
        || gpMouseManager->field_72 > dword_532E70
        || gpMouseManager->cursorTopLeftY < screenY )
        BlitBitmapToScreenVesa(
          bmpa,
          gpMouseManager->cursorTopLeftX,
          gpMouseManager->cursorTopLeftY,
          v9 - gpMouseManager->cursorTopLeftX + 1,
          gpMouseManager->field_72 - gpMouseManager->cursorTopLeftY + 1,
          gpMouseManager->cursorTopLeftX,
          gpMouseManager->cursorTopLeftY);
      mouseManager::RestoreUnderlying(gpMouseManager);
    }
    else
    {
      BlitBitmapToScreenVesa(bmpa, x, v8, v7, height, screenX, screenY);
    }
  }
  else
  {
    BlitBitmapToScreenVesa(bmp, xOff, yOff, width, height, screenX, screenY);
  }
}