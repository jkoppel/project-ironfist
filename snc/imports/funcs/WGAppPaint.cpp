{
  HDC v1; // ST3C_4@2
  HWND hWnd; // [sp+10h] [bp-74h]@1
  struct tagPAINTSTRUCT Paint; // [sp+20h] [bp-64h]@2
  int v5; // [sp+60h] [bp-24h]@2
  int v6; // [sp+64h] [bp-20h]@2
  __int32 v7; // [sp+68h] [bp-1Ch]@2
  char v8; // [sp+70h] [bp-14h]@1
  struct tagRECT Rect; // [sp+74h] [bp-10h]@2

  hWnd = this;
  v8 = 0;
  if ( dword_530418 )
  {
    v1 = BeginPaint(this, &Paint);
    SelectPalette(v1, hpalApp, 0);
    RealizePalette(v1);
    GetClientRect(hWnd, &Rect);
    v7 = Rect.right - Rect.left;
    v5 = 0 / iMainWinScreenWidth;
    v6 = 0 / iMainWinScreenHeight;
    if ( giScrollX )
      v5 += giScrollX;
    if ( giScrollY )
      v6 += giScrollY;
    ++dword_519704;
    if ( iMainWinScreenWidth != 640 || iMainWinScreenHeight != 480 )
    {
      thunk_WinGStretchBlt();
    }
    else
    {
      v7 = Paint.rcPaint.right - (unsigned __int16)(Paint.rcPaint.left & 0xFFFC) + 1;
      thunk_WinGBitBlt();
    }
    EndPaint(hWnd, &Paint);
  }
  return 1;
}