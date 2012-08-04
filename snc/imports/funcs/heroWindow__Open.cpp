{
  signed int result; // eax@2
  heroWindow *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( this->flags2 & 1 )
  {
    result = 3;
  }
  else if ( this->flags1 & 2 && heroWindow::SaveBackground(this) )
  {
    result = 3;
  }
  else
  {
    thisa->idx = idx;
    heroWindow::DrawWindow(thisa, redraw);
    thisa->flags2 |= 1u;
    result = 0;
  }
  return result;
}