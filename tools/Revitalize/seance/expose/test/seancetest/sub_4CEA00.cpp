int __thiscall sub_4CEA00(MouseManager *this)
{
  MouseManager *thisa; // esi@1
  int result; // eax@2
  __int32 v3; // eax@5
  __int32 v4; // edx@5

  thisa = this;
  if ( dword_4F19B0 )
  {
    result = this->cursorDisabled;
    if ( result > 0 )
    {
      --result;
      this->cursorDisabled = result;
      if ( !result )
      {
        ++mouseSemaphore1;
        if ( dword_4F19B0 )
        {
          GetCursorPos(&cursorLoc);
          ScreenToClient(windowHandle, &cursorLoc);
          v3 = 640 * cursorLoc.x / couldBeScreenWidth;
          thisa->field_56 = v3;
          v4 = 480 * cursorLoc.y / couldBeScreenHeight;
          thisa->field_5A = v4;
          sub_4D1480(v3, v4, 0);
        }
        sub_4CE410(thisa, 1);
        result = mouseSemaphore1-- - 1;
      }
    }
  }
  else
  {
    result = ShowCursor(1);
  }
  return result;
}
