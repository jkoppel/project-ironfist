{
  unsigned int v7; // ebp@5
  int v8; // ebx@5
  int v9; // ecx@12
  int x; // [sp+10h] [bp-8h]@1
  Bitmap *bmpa; // [sp+14h] [bp-4h]@1

  x = xOff;
  bmpa = bmp;
  if ( dword_4F19B0 )
  {
    if ( dword_4F2E78 || dword_4F2E7C )
    {
      v7 = 448;
      v8 = dword_4F2E7C + 16;
      x = dword_4F2E78 + 16;
      height = 448;
    }
    else
    {
      v8 = yOff;
      v7 = width;
    }
    dword_532E78 = v7 + screenX - 1;
    dword_532E70 = screenY + height - 1;
    if ( MouseManager::mouseEnabled(mouseManager)
      && mouseManager->cursorTopLeftX <= dword_532E78
      && mouseManager->field_6E >= screenX
      && mouseManager->cursorTopLeftY <= dword_532E70
      && mouseManager->field_72 >= screenY )
    {
      sub_4CE8F0(mouseManager);
      Bitmap::outputToScreen(bmpa, x, v8, v7, height, screenX, screenY);
      v9 = mouseManager->field_6E;
      if ( v9 > dword_532E78
        || mouseManager->cursorTopLeftX < screenX
        || mouseManager->field_72 > dword_532E70
        || mouseManager->cursorTopLeftY < screenY )
        Bitmap::outputToScreen(
          bmpa,
          mouseManager->cursorTopLeftX,
          mouseManager->cursorTopLeftY,
          v9 - mouseManager->cursorTopLeftX + 1,
          mouseManager->field_72 - mouseManager->cursorTopLeftY + 1,
          mouseManager->cursorTopLeftX,
          mouseManager->cursorTopLeftY);
      MouseManager::drawMouse(mouseManager);
    }
    else
    {
      Bitmap::outputToScreen(bmpa, x, v8, v7, height, screenX, screenY);
    }
  }
  else
  {
    Bitmap::outputToScreen(bmp, xOff, yOff, width, height, screenX, screenY);
  }
}
