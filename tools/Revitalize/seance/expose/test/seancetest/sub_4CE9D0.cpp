void __thiscall sub_4CE9D0(MouseManager *this)
{
  int v1; // eax@2

  if ( dword_4F19B0 )
  {
    v1 = this->cursorDisabled + 1;
    this->cursorDisabled = v1;
    if ( v1 == 1 )
      sub_4CE410(this, 1);
  }
  else
  {
    ShowCursor(0);
  }
}
