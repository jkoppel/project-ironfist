{
  signed int result; // eax@10
  widget *v3; // [sp+14h] [bp-10h]@8
  widget *v4; // [sp+1Ch] [bp-8h]@5
  signed int i; // [sp+20h] [bp-4h]@2

  if ( iCurBottomView )
  {
    for ( i = 0; i < 12; ++i )
    {
      if ( this->someComponents[0][i] )
      {
        heroWindow::RemoveWidget(this->adventureScreen, this->someComponents[0][i]);
        v4 = this->someComponents[0][i];
        if ( v4 )
          ((void (__thiscall *)(widget *))v4->vtable->cleanUp)(v4);
      }
      if ( this->someComponents[1][i] )
      {
        heroWindow::RemoveWidget(this->adventureScreen, this->someComponents[1][i]);
        v3 = this->someComponents[1][i];
        if ( v3 )
          ((void (__thiscall *)(widget *))v3->vtable->cleanUp)(v3);
      }
      this->someComponents[0][i] = 0;
      result = i;
      this->someComponents[1][i] = 0;
    }
    dword_50EAA4 = -1;
    iCurBottomView = 0;
    iLastAnimFrame = -1;
  }
  return result;
}