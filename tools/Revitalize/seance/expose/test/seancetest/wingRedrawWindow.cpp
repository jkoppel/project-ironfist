signed int __thiscall wingRedrawWindow(HWND this)
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
    SelectPalette(v1, logicalPaletteHandle, 0);
    RealizePalette(v1);
    GetClientRect(hWnd, &Rect);
    v7 = Rect.right - Rect.left;
    v5 = 0 / couldBeScreenWidth;
    v6 = 0 / couldBeScreenHeight;
    if ( dword_4F2E78 )
      v5 += dword_4F2E78;
    if ( dword_4F2E7C )
      v6 += dword_4F2E7C;
    ++dword_519704;
    if ( couldBeScreenWidth != 640 || couldBeScreenHeight != 480 )
    {
      WinGStretchBlt();
    }
    else
    {
      v7 = Paint.rcPaint.right - (unsigned __int16)(Paint.rcPaint.left & 0xFFFC) + 1;
      WinGBitBlt();
    }
    EndPaint(hWnd, &Paint);
  }
  return 1;
}
