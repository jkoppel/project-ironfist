{
  signed int result; // eax@2
  int v2; // eax@44
  HWND hWnd; // [sp+10h] [bp-5Ch]@1
  struct tagPOINT Point; // [sp+14h] [bp-58h]@18
  struct tagPAINTSTRUCT Paint; // [sp+1Ch] [bp-50h]@7
  __int32 v6; // [sp+5Ch] [bp-10h]@14
  int v7; // [sp+60h] [bp-Ch]@14
  int v8; // [sp+64h] [bp-8h]@14
  __int32 v9; // [sp+68h] [bp-4h]@14

  hWnd = this;
  if ( dword_519708 )
  {
    result = 1;
  }
  else
  {
    if ( initiallyMinimized )
    {
      result = 1;
    }
    else
    {
      if ( directDrawObject )
      {
        dword_519708 = 1;
        BeginPaint(this, &Paint);
        GetClientRect(hWnd, &stru_52FF70);
        if ( !Paint.rcPaint.right || !Paint.rcPaint.bottom )
        {
          Paint.rcPaint.left = stru_52FF70.left;
          Paint.rcPaint.top = stru_52FF70.top;
          Paint.rcPaint.right = stru_52FF70.right;
          Paint.rcPaint.bottom = stru_52FF70.bottom;
        }
        if ( Paint.rcPaint.right < 640 )
          ++Paint.rcPaint.right;
        if ( Paint.rcPaint.bottom < 480 )
          ++Paint.rcPaint.bottom;
        dword_530430.left = Paint.rcPaint.left;
        dword_530430.top = Paint.rcPaint.top;
        dword_530430.right = Paint.rcPaint.right;
        dword_530430.bottom = Paint.rcPaint.bottom;
        v9 = ((5 * (dword_530438 - dword_530430.left) + 5) << 7) / couldBeScreenWidth;
        v8 = 160 * (3 * (dword_53043C - dword_530434) + 3) / couldBeScreenHeight;
        v6 = 640 * dword_530430.left / couldBeScreenWidth;
        v7 = 480 * dword_530434 / couldBeScreenHeight;
        if ( dword_4F2E78 )
        {
          v6 = dword_4F2E78 + 16;
          v9 = 448;
        }
        if ( dword_4F2E7C )
        {
          v7 = dword_4F2E7C + 16;
          v8 = 448;
        }
        dword_530420 = v6;
        dword_530428 = v6 + v9 - 1;
        dword_530424 = v7;
        dword_53042C = v7 + v8 - 1;
        Point.y = 0;
        Point.x = 0;
        ClientToScreen(windowHandle, &Point);
        OffsetRect(&dword_530430, Point.x, Point.y);
        errorCode = (*(int (__cdecl **)(int, _DWORD))(*(_DWORD *)dword_519718 + 128))(dword_519718, 0);
        if ( errorCode )
          fatalDirectDrawError((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 71);
        if ( dword_530420 < 0 )
          dword_530420 = 0;
        if ( dword_530424 < 0 )
          dword_530424 = 0;
        if ( dword_530428 > 640 )
          dword_530428 = 640;
        if ( dword_53042C > 480 )
          dword_53042C = 480;
        dword_530440 = getTickCount();
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              errorCode = (*(int (__cdecl **)(int, struct tagRECT *, int, int *, signed int, _DWORD))(*(_DWORD *)dword_519714 + 20))(
                            dword_519714,
                            &dword_530430,
                            dword_519718,
                            &dword_530420,
                            16777216,
                            0);
              if ( errorCode != -2005532222 )
                break;
              errorCode = (*(int (__cdecl **)(int))(*(_DWORD *)dword_519714 + 108))(dword_519714);
              if ( errorCode == -2005532085 )
              {
                debugLog("ResetDisplayMode");
                errorCode = ((int (__cdecl *)(LPDIRECTDRAW *, signed int, signed int, signed int))(*directDrawObject)[21].lpVtbl)(
                              directDrawObject,
                              640,
                              480,
                              8);
                if ( errorCode )
                  fatalDirectDrawError((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 91);
                errorCode = (*(int (__cdecl **)(int))(*(_DWORD *)dword_519714 + 108))(dword_519714);
                if ( errorCode )
                  fatalDirectDrawError((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 95);
                dword_530430.left = dword_530420;
                dword_530430.top = *(&dword_530420 + 1);
                dword_530430.right = *(&dword_530420 + 2);
                dword_530430.bottom = *(&dword_530420 + 3);
              }
              if ( errorCode )
                fatalDirectDrawError((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 103);
            }
            if ( errorCode != -2005532242 || getTickCount() >= dword_530440 + 10000 )
              break;
            ++dword_5197D4;
          }
          if ( !errorCode )
            break;
          fatalDirectDrawError((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 108);
        }
        memset(&dword_52FF80, 0, 0x6Cu);
        *(_DWORD *)&dword_52FF80 = 108;
        v2 = (*(int (__cdecl **)(int, _DWORD, void *, signed int, _DWORD))(*(_DWORD *)dword_519718 + 100))(
               dword_519718,
               0,
               &dword_52FF80,
               1,
               0);
        errorCode = v2;
        if ( v2 )
          fatalDirectDrawError((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 118);
        if ( HeroWindowManager::instance->screenBuffer )
        {
          HeroWindowManager::instance->screenBuffer->contents = (unsigned __int8 *)dword_52FFA4;
          screenContents = (Bitmap *)dword_52FFA4;
        }
        else
        {
          screenContents = (Bitmap *)dword_52FFA4;
        }
        if ( errorCode )
          fatalDirectDrawError((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 129);
        EndPaint(hWnd, &Paint);
        dword_519708 = 0;
        result = 1;
      }
      else
      {
        result = 1;
      }
    }
  }
  return result;
}
