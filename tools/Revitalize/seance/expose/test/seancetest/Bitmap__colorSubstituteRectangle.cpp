void __fastcall Bitmap::colorSubstituteRectangle(Bitmap *bmp, int x, int y, int width, int height, int substitutionIdx)
{
  unsigned __int8 *row; // esi@1
  int wid; // esi@2

  row = &bmp->contents[y * bmp->width];
  bitmapColorSubstRectI = 0;
  for ( bitmapColorSubstRectPixel = &row[x]; bitmapColorSubstRectI < height; ++bitmapColorSubstRectI )
  {
    wid = bmp->width;
    bitmapColorSubstRectJ = 0;
    for ( bitmapColorSubstRectNextRow = &bitmapColorSubstRectPixel[wid];
          bitmapColorSubstRectJ < width;
          ++bitmapColorSubstRectJ )
    {
      *bitmapColorSubstRectPixel = globalColorSubstitutionThing[substitutionIdx][*bitmapColorSubstRectPixel];
      ++bitmapColorSubstRectPixel;
    }
    bitmapColorSubstRectPixel = bitmapColorSubstRectNextRow;
  }
}
