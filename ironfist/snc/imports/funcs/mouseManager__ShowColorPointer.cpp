{
  int v1; // eax@1
  mouseManager *thisa; // esi@1
  int v3; // eax@2
  __int32 v4; // eax@4
  __int32 v5; // edx@4

  v1 = this->cursorDisabled;
  thisa = this;
  if ( v1 > 0 )
  {
    v3 = v1 - 1;
    this->cursorDisabled = v3;
    if ( !v3 )
    {
      ++gbPutzingWithMouseCtr;
      if ( gbColorMice )
      {
        GetCursorPos(&Point);
        ScreenToClient(hwndApp, &Point);
        v4 = 640 * Point.x / iMainWinScreenWidth;
        thisa->field_56 = v4;
        v5 = 480 * Point.y / iMainWinScreenHeight;
        thisa->field_5A = v5;
        CheckChangeCursor(v4, v5, 0);
      }
      mouseManager::NewUpdate(thisa, 1);
      --gbPutzingWithMouseCtr;
    }
  }
}