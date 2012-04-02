{
  GUIWindow *window; // eax@1
  __int16 y; // bx@1
  __int16 x; // di@1
  GUIIcon *thisa; // esi@1
  int v5; // eax@1
  ICNHeader *imgHeader; // eax@6
  __int16 v7; // dx@6
  __int16 v8; // bx@6
  __int16 v9; // cx@6
  __int16 v10; // di@6

  window = this->parentWindow;
  y = LOWORD(window->yOffset) + this->offsetY;
  x = LOWORD(window->xOffset) + this->offsetX;
  thisa = this;
  v5 = this->field_14;
  switch ( v5 )
  {
    case 16:
      Icon::drawToScreen(this->icon, x, y, this->imgIdx, this->mirror);
      break;
    case 17:
      imgHeader = getNthHeader(this->icon, this->imgIdx);
      v7 = imgHeader->width;
      v8 = y - imgHeader->offsetY;
      v9 = thisa->width;
      v10 = x - imgHeader->offsetX;
      if ( v7 < v9 )
        v10 += (v9 - v7) >> 1;
      if ( imgHeader->height + 2 < thisa->height )
        v8 += thisa->height - imgHeader->height - 2;
      Icon::drawToScreen(thisa->icon, v10, v8, thisa->imgIdx, thisa->mirror);
      break;
    case 128:
      sub_4CF570(this->icon, x, y, this->imgIdx, this->field_27, this->mirror, 0);
      break;
  }
}
