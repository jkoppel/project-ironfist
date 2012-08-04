{
  void *v1; // [sp+Ch] [bp-4h]@1

  v1 = this;
  if ( !gbInSmackMgr && (void *)*(&bMenu + 7 * giCurExe + 5) != this )
  {
    if ( giGraphicsType == 1 )
    {
      if ( !gbDDrawAttached )
        return;
      *(&bMenu + 7 * giCurExe + 5) = 1;
      if ( SetGraphicsType((void *)2) )
        DDSetFullScreenStatus(v1);
    }
    else if ( this )
    {
      DDSetFullScreenStatus(this);
    }
    else if ( gbWinGAttached )
    {
      SetGraphicsType((void *)1);
    }
    if ( v1 )
      CheckChangeCursor(0, 0, 1);
  }
}