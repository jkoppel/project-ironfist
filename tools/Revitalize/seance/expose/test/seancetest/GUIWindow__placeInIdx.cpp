signed int __thiscall GUIWindow::placeInIdx(GUIWindow *this, int idx, int redraw)
{
  signed int result; // eax@2
  GUIWindow *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( this->flags2 & 1 )
  {
    result = 3;
  }
  else
  {
    if ( this->flags1 & 2 && GUIWindow::grabBitmapFromScreen(this) )
    {
      result = 3;
    }
    else
    {
      thisa->idx = idx;
      GUIWindow::repaint(thisa, redraw);
      thisa->flags2 |= 1u;
      result = 0;
    }
  }
  return result;
}
