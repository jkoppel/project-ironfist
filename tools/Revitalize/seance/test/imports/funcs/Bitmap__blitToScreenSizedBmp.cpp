{
  int v8; // ebx@2
  int v9; // ebp@3
  int v10; // eax@3
  const void *v11; // esi@4
  Bitmap *thisa; // [sp+10h] [bp-4h]@1

  thisa = this;
  yieldToGlobalUpdater();
  if ( width == 640 )
  {
    memcpy(&buf->contents[640 * yTarg] + xTarg, &thisa->contents[640 * yFrom] + xFrom, 640 * height);
  }
  else
  {
    v8 = height;
    if ( height > 0 )
    {
      v9 = 640 * yFrom;
      v10 = 640 * yTarg;
      do
      {
        v11 = &thisa->contents[xFrom] + v9;
        v9 += 640;
        memcpy(&buf->contents[xTarg] + v10, v11, width);
        v10 += 640;
        --v8;
      }
      while ( v8 );
    }
  }
  yieldToGlobalUpdater();
}
