{
  int result; // eax@1
  mouseManager *v3; // edi@1
  int v4; // esi@2
  int v5; // ebx@2
  int v6; // eax@3
  int v7; // ecx@6
  signed int v8; // edx@6
  int v9; // ebp@6
  int v10; // eax@7
  int v11; // eax@8
  __int32 v12; // eax@10
  __int32 v13; // edx@10

  result = a2;
  v3 = this;
  if ( a2 != gbColorMice )
  {
    v4 = gpWindowManager->field_56;
    gpWindowManager->field_56 = 0;
    v5 = bInNewMouseUpdate;
    ++gbPutzingWithMouseCtr;
    bInNewMouseUpdate = 0;
    if ( gbColorMice )
    {
      v6 = this->cursorDisabled + 1;
      this->cursorDisabled = v6;
      if ( v6 == 1 )
        mouseManager::NewUpdate(this, 1);
    }
    else
    {
      ShowCursor(0);
    }
    v7 = v3->spriteIdx;
    v8 = v3->cursorCategory;
    v9 = v3->field_7E;
    v3->couldBeShowMouse = 0;
    gbColorMice = a2;
    v3->spriteIdx = -99;
    v3->cursorCategory = -1;
    v3->field_7E = 0;
    mouseManager::SetPointer(v3, byte_51F6B4, v7, v8);
    v3->couldBeShowMouse = 1;
    v3->field_7E = v9;
    if ( gbColorMice )
    {
      v10 = v3->cursorDisabled;
      if ( v10 > 0 )
      {
        v11 = v10 - 1;
        v3->cursorDisabled = v11;
        if ( !v11 )
        {
          ++gbPutzingWithMouseCtr;
          if ( gbColorMice )
          {
            GetCursorPos(&Point);
            ScreenToClient(hwndApp, &Point);
            v12 = 640 * Point.x / iMainWinScreenWidth;
            v3->field_56 = v12;
            v13 = 480 * Point.y / iMainWinScreenHeight;
            v3->field_5A = v13;
            CheckChangeCursor(v12, v13, 0);
          }
          mouseManager::NewUpdate(v3, 1);
          --gbPutzingWithMouseCtr;
        }
      }
    }
    else
    {
      ShowCursor(1);
    }
    result = gbPutzingWithMouseCtr - 1;
    bInNewMouseUpdate = v5;
    --gbPutzingWithMouseCtr;
    gpWindowManager->field_56 = v4;
  }
  return result;
}