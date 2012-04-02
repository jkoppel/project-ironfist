void __thiscall Bitmap::copyFromAllowOOB(Bitmap *this, Bitmap *fromBMP, __int16 x, __int16 y)
{
  unsigned int width; // esi@2
  Bitmap *froma; // ecx@2
  int height; // edi@4
  Dimension32 modDim; // qdi@7
  int xAlt; // edx@8
  int yAlt; // ebx@11
  int origWidth; // eax@13
  int origHeight; // eax@15
  Bitmap *thisa; // [sp+10h] [bp-Ch]@1

  thisa = this;
  if ( x < 0 )
  {
    froma = fromBMP;
  }
  else
  {
    width = this->width;
    froma = fromBMP;
    if ( fromBMP->width >= (signed int)(x + width) )
    {
      if ( y >= 0 )
      {
        height = thisa->height;
        if ( fromBMP->height >= y + height )
        {
          blit(fromBMP, x, y, width, height, thisa, 0, 0);
          return;
        }
      }
    }
  }
  modDim.width = thisa->width;
  modDim.height = thisa->height;
  if ( x >= 0 )
  {
    xAlt = x;
  }
  else
  {
    modDim.width += x;
    xAlt = 0;
  }
  if ( y >= 0 )
  {
    yAlt = y;
  }
  else
  {
    modDim.height += y;
    yAlt = 0;
  }
  origWidth = froma->width;
  if ( modDim.width + xAlt > origWidth )
    modDim.width = origWidth - xAlt;
  origHeight = froma->height;
  if ( yAlt + modDim.height > origHeight )
    modDim.height = origHeight - yAlt;
  if ( *(signed __int64 *)&modDim >= 0 )
    blit(froma, xAlt, yAlt, modDim.width, modDim.height, thisa, 0, 0);
}
