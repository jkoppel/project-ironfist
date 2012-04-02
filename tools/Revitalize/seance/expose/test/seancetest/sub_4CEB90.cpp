int __thiscall sub_4CEB90(MouseManager *this, int a2)
{
  int result; // eax@1
  MouseManager *v3; // edi@1
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
  if ( a2 != dword_4F19B0 )
  {
    v4 = HeroWindowManager::instance->field_56;
    HeroWindowManager::instance->field_56 = 0;
    v5 = dword_51F56C;
    ++mouseSemaphore1;
    dword_51F56C = 0;
    if ( dword_4F19B0 )
    {
      v6 = this->cursorDisabled + 1;
      this->cursorDisabled = v6;
      if ( v6 == 1 )
        sub_4CE410(this, 1);
    }
    else
    {
      ShowCursor(0);
    }
    v7 = v3->spriteIdx;
    v8 = v3->cursorCategory;
    v9 = v3->field_7E;
    v3->couldBeShowMouse = 0;
    dword_4F19B0 = a2;
    v3->spriteIdx = -99;
    v3->cursorCategory = -1;
    v3->field_7E = 0;
    MouseManager::loadMSE(v3, byte_51F6B4, v7, v8);
    v3->couldBeShowMouse = 1;
    v3->field_7E = v9;
    if ( dword_4F19B0 )
    {
      v10 = v3->cursorDisabled;
      if ( v10 > 0 )
      {
        v11 = v10 - 1;
        v3->cursorDisabled = v11;
        if ( !v11 )
        {
          ++mouseSemaphore1;
          if ( dword_4F19B0 )
          {
            GetCursorPos(&cursorLoc);
            ScreenToClient(windowHandle, &cursorLoc);
            v12 = 640 * cursorLoc.x / couldBeScreenWidth;
            v3->field_56 = v12;
            v13 = 480 * cursorLoc.y / couldBeScreenHeight;
            v3->field_5A = v13;
            sub_4D1480(v12, v13, 0);
          }
          sub_4CE410(v3, 1);
          --mouseSemaphore1;
        }
      }
    }
    else
    {
      ShowCursor(1);
    }
    result = mouseSemaphore1 - 1;
    dword_51F56C = v5;
    --mouseSemaphore1;
    HeroWindowManager::instance->field_56 = v4;
  }
  return result;
}
