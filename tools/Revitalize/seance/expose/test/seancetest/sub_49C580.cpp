void __cdecl sub_49C580()
{
  void *v0; // ST34_4@5

  if ( !dword_519DB8 )
  {
    if ( WinGRecommendDIBFormat(&dword_52FFF0) )
    {
      word_52FFFE = 8;
      dword_530000 = 0;
      dword_5192F4 = dword_52FFF8;
    }
    else
    {
      dword_52FFF0 = 40;
      word_52FFFC = 1;
      word_52FFFE = 8;
      dword_530000 = 0;
      dword_530004 = 0;
      dword_530010 = 0;
      dword_530014 = 0;
    }
    dword_52FFF4 = 640;
    dword_52FFF8 = -480;
    sub_49CF80();
    dword_519DB8 = (HDC)WinGCreateDC();
    dword_52FFF4 = 640;
    dword_52FFF8 = -480;
    v0 = (void *)WinGCreateBitmap(dword_519DB8, &dword_52FFF0, &dword_52FFF0 + 266);
    dword_530004 = dword_5192F4 * dword_52FFF8 * dword_52FFF4;
    dword_519DBC = SelectObject(dword_519DB8, v0);
    screenContents = (Bitmap *)dword_530418;
    PatBlt(dword_519DB8, 0, 0, couldBeScreenWidth, couldBeScreenHeight, 0x42u);
  }
}
