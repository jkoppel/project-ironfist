{
  HGDIOBJ v0; // ST14_4@2

  if ( hdcImage )
  {
    v0 = SelectObject(hdcImage, gbmOldMonoBitmap);
    DeleteObject(v0);
    DeleteDC(hdcImage);
    hdcImage = 0;
  }
  if ( hpalApp )
  {
    DeleteObject(hpalApp);
    hpalApp = 0;
  }
}