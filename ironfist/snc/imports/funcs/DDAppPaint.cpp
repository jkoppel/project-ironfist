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
  if ( gbWinGraphBusy )
  {
    result = 1;
  }
  else if ( gbMinimized )
  {
    result = 1;
  }
  else if ( lpDD )
  {
    gbWinGraphBusy = 1;
    BeginPaint(this, &Paint);
    GetClientRect(hWnd, &Rect);
    if ( !Paint.rcPaint.right || !Paint.rcPaint.bottom )
    {
      Paint.rcPaint.left = Rect.left;
      Paint.rcPaint.top = Rect.top;
      Paint.rcPaint.right = Rect.right;
      Paint.rcPaint.bottom = Rect.bottom;
    }
    if ( Paint.rcPaint.right < 640 )
      ++Paint.rcPaint.right;
    if ( Paint.rcPaint.bottom < 480 )
      ++Paint.rcPaint.bottom;
    rc.left = Paint.rcPaint.left;
    rc.top = Paint.rcPaint.top;
    rc.right = Paint.rcPaint.right;
    rc.bottom = Paint.rcPaint.bottom;
    v9 = ((5 * (dword_530438 - rc.left) + 5) << 7) / iMainWinScreenWidth;
    v8 = 160 * (3 * (dword_53043C - dword_530434) + 3) / iMainWinScreenHeight;
    v6 = 640 * rc.left / iMainWinScreenWidth;
    v7 = 480 * dword_530434 / iMainWinScreenHeight;
    if ( giScrollX )
    {
      v6 = giScrollX + 16;
      v9 = 448;
    }
    if ( giScrollY )
    {
      v7 = giScrollY + 16;
      v8 = 448;
    }
    dword_530420 = v6;
    dword_530428 = v6 + v9 - 1;
    dword_530424 = v7;
    dword_53042C = v7 + v8 - 1;
    Point.y = 0;
    Point.x = 0;
    ClientToScreen(hwndApp, &Point);
    OffsetRect(&rc, Point.x, Point.y);
    errorCode = (*(int (__cdecl **)(int, _DWORD))(*(_DWORD *)lpDDSOne + 128))(lpDDSOne, 0);
    if ( errorCode )
      DDSD((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 71);
    if ( dword_530420 < 0 )
      dword_530420 = 0;
    if ( dword_530424 < 0 )
      dword_530424 = 0;
    if ( dword_530428 > 640 )
      dword_530428 = 640;
    if ( dword_53042C > 480 )
      dword_53042C = 480;
    lPaintStart = KBTickCount();
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          errorCode = (*(int (__cdecl **)(int, struct tagRECT *, int, int *, signed int, _DWORD))(*(_DWORD *)lpDDSPrimary
                                                                                                + 20))(
                        lpDDSPrimary,
                        &rc,
                        lpDDSOne,
                        &dword_530420,
                        16777216,
                        0);
          if ( errorCode != -2005532222 )
            break;
          errorCode = (*(int (__cdecl **)(int))(*(_DWORD *)lpDDSPrimary + 108))(lpDDSPrimary);
          if ( errorCode == -2005532085 )
          {
            LogStr("ResetDisplayMode");
            errorCode = ((int (__cdecl *)(LPDIRECTDRAW *, signed int, signed int, signed int))(*lpDD)[21].lpVtbl)(
                          lpDD,
                          640,
                          480,
                          8);
            if ( errorCode )
              DDSD((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 91);
            errorCode = (*(int (__cdecl **)(int))(*(_DWORD *)lpDDSPrimary + 108))(lpDDSPrimary);
            if ( errorCode )
              DDSD((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 95);
            rc.left = dword_530420;
            rc.top = *(&dword_530420 + 1);
            rc.right = *(&dword_530420 + 2);
            rc.bottom = *(&dword_530420 + 3);
          }
          if ( errorCode )
            DDSD((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 103);
        }
        if ( errorCode != -2005532242 || KBTickCount() >= lPaintStart + 10000 )
          break;
        ++iBusyRetry;
      }
      if ( !errorCode )
        break;
      DDSD((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 108);
    }
    memset(&dword_52FF80, 0, 0x6Cu);
    *(_DWORD *)&dword_52FF80 = 108;
    v2 = (*(int (__cdecl **)(int, _DWORD, void *, signed int, _DWORD))(*(_DWORD *)lpDDSOne + 100))(
           lpDDSOne,
           0,
           &dword_52FF80,
           1,
           0);
    errorCode = v2;
    if ( v2 )
      DDSD((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 118);
    if ( gpWindowManager->screenBuffer )
    {
      gpWindowManager->screenBuffer->contents = (unsigned __int8 *)dword_52FFA4;
      lpInitWin = (bitmap *)dword_52FFA4;
    }
    else
    {
      lpInitWin = (bitmap *)dword_52FFA4;
    }
    if ( errorCode )
      DDSD((MACRO_DDERR)errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519858 + 129);
    EndPaint(hWnd, &Paint);
    gbWinGraphBusy = 0;
    result = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}