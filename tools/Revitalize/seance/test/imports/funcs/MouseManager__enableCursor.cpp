{
  int v1; // eax@1
  MouseManager *thisa; // esi@1
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
      ++mouseSemaphore1;
      if ( dword_4F19B0 )
      {
        GetCursorPos(&cursorLoc);
        ScreenToClient(windowHandle, &cursorLoc);
        v4 = 640 * cursorLoc.x / couldBeScreenWidth;
        thisa->field_56 = v4;
        v5 = 480 * cursorLoc.y / couldBeScreenHeight;
        thisa->field_5A = v5;
        sub_4D1480(v4, v5, 0);
      }
      sub_4CE410(thisa, 1);
      --mouseSemaphore1;
    }
  }
}
