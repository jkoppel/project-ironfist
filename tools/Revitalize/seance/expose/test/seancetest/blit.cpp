void __fastcall blit(Bitmap *from, int x1, int y1, unsigned int width, int height, Bitmap *to, unsigned int x2, int y2)
{
  Bitmap *froma; // ebx@1
  int v9; // ecx@1
  unsigned __int8 *v10; // esi@1

  froma = from;
  blitFromRow = (int)(&from->contents[y1 * from->width] + x1);
  v9 = y2 * to->width;
  v10 = to->contents;
  blitI = 0;
  for ( blitToRow = (int)(&v10[v9] + x2); blitI < height; ++blitI )
  {
    memcpy((void *)blitToRow, (const void *)blitFromRow, width);
    blitFromRow += froma->width;
    blitToRow += to->width;
  }
}
