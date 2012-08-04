{
  mouseManager *thisa; // esi@1
  __int32 v3; // eax@7
  __int32 v4; // edx@7
  int v5; // edx@10
  int v6; // edi@12
  int v7; // edx@12
  int v8; // ecx@12
  int v9; // edx@12
  int v10; // ebx@12
  int v11; // eax@12
  int v12; // ecx@24
  int v13; // ecx@32
  int v14; // eax@34
  int v15; // ecx@51
  int v16; // ebx@51
  int *v17; // edi@51
  int v18; // edx@51
  int v19; // ebp@54
  int v20; // edx@54
  int *v21; // ebx@54

  thisa = this;
  if ( (!this->cursorDisabled || a2) && this->couldBeShowMouse && !bInNewMouseUpdate )
  {
    bInNewMouseUpdate = 1;
    ++gbPutzingWithMouseCtr;
    if ( !a2 )
    {
      if ( !gbColorMice )
        goto LABEL_61;
      GetCursorPos(&Point);
      ScreenToClient(hwndApp, &Point);
      v3 = 640 * Point.x / iMainWinScreenWidth;
      thisa->field_56 = v3;
      v4 = 480 * Point.y / iMainWinScreenHeight;
      thisa->field_5A = v4;
      CheckChangeCursor(v3, v4, 0);
    }
    if ( gbColorMice )
    {
      if ( a2
        || (v5 = thisa->cursorIdx, thisa->field_56 - iHotSpot[v5].x != thisa->field_66)
        || thisa->field_5A - iHotSpot[v5].y != thisa->field_6A )
      {
        dword_5330B0 = thisa->cursorTopLeftX;
        dword_533B38 = thisa->cursorTopLeftY;
        dword_533B3C = thisa->field_6E;
        dword_534748 = thisa->field_72;
        v6 = thisa->cursorIdx;
        v7 = thisa->field_5A;
        v8 = thisa->field_56 - iHotSpot[v6].x;
        thisa->field_66 = v8;
        v9 = v7 - iHotSpot[v6].y;
        thisa->field_6A = v9;
        v10 = iMouseSize[v6].width + v8 - 1;
        thisa->field_6E = v10;
        v11 = iMouseSize[v6].height + v9 - 1;
        thisa->field_72 = v11;
        if ( v10 > 639 )
          thisa->field_6E = 639;
        if ( v11 > 479 )
          thisa->field_72 = 479;
        thisa->cursorTopLeftX = 0;
        if ( v8 >= 0 )
          thisa->cursorTopLeftX = v8;
        thisa->cursorTopLeftY = 0;
        if ( v9 >= 0 )
          thisa->cursorTopLeftY = v9;
        if ( dword_5330B0 <= 639 && dword_533B38 <= 479 && dword_533B3C >= 0 && dword_534748 >= 0 )
        {
          v12 = thisa->cursorTopLeftX;
          if ( dword_533B3C >= v12
            && thisa->field_6E >= dword_5330B0
            && thisa->cursorTopLeftY <= dword_534748
            && thisa->field_72 >= dword_533B38 )
          {
            if ( dword_5330B0 > v12 )
              dword_5330B0 = thisa->cursorTopLeftX;
            if ( dword_533B38 > thisa->cursorTopLeftY )
              dword_533B38 = thisa->cursorTopLeftY;
            v13 = thisa->cursorTopLeftX;
            if ( dword_533B3C < iMouseSize[thisa->cursorIdx].width + v13 - 1 )
              dword_533B3C = iMouseSize[thisa->cursorIdx].width + v13 - 1;
            v14 = iMouseSize[thisa->cursorIdx].height + thisa->cursorTopLeftY - 1;
            if ( dword_534748 >= v14 )
              goto LABEL_43;
            goto LABEL_42;
          }
          if ( dword_533B3C > 639 )
            dword_533B3C = 639;
          if ( dword_534748 > 479 )
            dword_534748 = 479;
          BlitBitmapToScreenNoMouseCheck(
            (int)gpWindowManager->screenBuffer,
            dword_5330B0,
            dword_533B38,
            dword_533B3C - dword_5330B0 + 1,
            dword_534748 - dword_533B38 + 1,
            dword_5330B0,
            dword_533B38);
        }
        dword_5330B0 = thisa->cursorTopLeftX;
        dword_533B38 = thisa->cursorTopLeftY;
        dword_533B3C = thisa->cursorTopLeftX + iMouseSize[thisa->field_4A].width - 1;
        v14 = thisa->cursorTopLeftY + iMouseSize[thisa->field_4A].height - 1;
LABEL_42:
        dword_534748 = v14;
LABEL_43:
        if ( dword_5330B0 <= 639 && dword_533B38 <= 479 && dword_533B3C >= 0 && dword_534748 >= 0 )
        {
          if ( dword_533B3C > 639 )
            dword_533B3C = 639;
          if ( dword_534748 > 479 )
            dword_534748 = 479;
          v15 = thisa->cursorTopLeftX;
          v16 = thisa->cursorIdx;
          v17 = &thisa->cursorWidth;
          v18 = iMouseSize[v16].width;
          if ( v15 + v18 <= 640 )
            *v17 = v18;
          else
            *v17 = 640 - v15;
          v19 = iMouseSize[v16].height;
          v20 = thisa->cursorTopLeftY;
          v21 = &thisa->cursorHeight;
          if ( v20 + v19 <= 480 )
            *v21 = v19;
          else
            *v21 = 480 - v20;
          bitmap::CopyToCareful(gpWindowManager->screenBuffer, thisa->bitmap, 0, 0, v15, v20, *v17, *v21);
          if ( !thisa->cursorDisabled )
            IconToBitmap(
              thisa->cursorIcon,
              gpWindowManager->screenBuffer,
              thisa->field_66,
              thisa->field_6A,
              thisa->spriteIdx,
              1,
              0,
              0,
              0x280u,
              480,
              0);
          BlitBitmapToScreenNoMouseCheck(
            (int)gpWindowManager->screenBuffer,
            dword_5330B0,
            dword_533B38,
            dword_533B3C - dword_5330B0 + 1,
            dword_534748 - dword_533B38 + 1,
            dword_5330B0,
            dword_533B38);
          bitmap::CopyToCareful(
            thisa->bitmap,
            gpWindowManager->screenBuffer,
            thisa->cursorTopLeftX,
            thisa->cursorTopLeftY,
            0,
            0,
            *v17,
            *v21);
        }
        thisa->field_4A = thisa->cursorIdx;
        goto LABEL_61;
      }
    }
LABEL_61:
    bInNewMouseUpdate = 0;
    --gbPutzingWithMouseCtr;
  }
}