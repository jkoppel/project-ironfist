{
  mouseManager *thisa; // esi@1
  int result; // eax@2
  __int32 v3; // eax@5
  __int32 v4; // edx@5

  thisa = this;
  if ( gbColorMice )
  {
    result = this->cursorDisabled;
    if ( result > 0 )
    {
      --result;
      this->cursorDisabled = result;
      if ( !result )
      {
        ++gbPutzingWithMouseCtr;
        if ( gbColorMice )
        {
          GetCursorPos(&Point);
          ScreenToClient(hwndApp, &Point);
          v3 = 640 * Point.x / iMainWinScreenWidth;
          thisa->field_56 = v3;
          v4 = 480 * Point.y / iMainWinScreenHeight;
          thisa->field_5A = v4;
          CheckChangeCursor(v3, v4, 0);
        }
        mouseManager::NewUpdate(thisa, 1);
        result = gbPutzingWithMouseCtr-- - 1;
      }
    }
  }
  else
  {
    result = ShowCursor(1);
  }
  return result;
}