signed int __thiscall redrawWindow(HWND this)
{
  signed int result; // eax@2

  if ( graphicsLibraryToUse == 1 )
    result = wingRedrawWindow(this);
  else
    result = directDrawRedrawWindow(this);
  return result;
}
