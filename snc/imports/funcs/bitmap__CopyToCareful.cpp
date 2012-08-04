{
  bitmap *thisa; // ebx@1
  int i; // ebp@2
  unsigned __int8 *fromRow; // ecx@3
  int targRow; // esi@3

  thisa = this;
  if ( width >= 1 )
  {
    i = 0;
    while ( height > i )
    {
      fromRow = &thisa->contents[thisa->width * (i + offY)];
      targRow = i++ + targY;
      memcpy(&target->contents[target->width * targRow] + targX, &fromRow[offX], width);
    }
  }
}