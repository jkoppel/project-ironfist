{
  unsigned int len; // kr04_4@1
  int v4; // ST1C_4@19
  font *thisa; // [sp+Ch] [bp-38h]@1
  int v7; // [sp+14h] [bp-30h]@1
  int width; // [sp+18h] [bp-2Ch]@1
  int firstCharIdxNextLine; // [sp+1Ch] [bp-28h]@9
  int linesNeeded; // [sp+24h] [bp-20h]@1
  int i; // [sp+38h] [bp-Ch]@1

  thisa = this;
  len = strlen(msg) + 1;
  linesNeeded = 0;
  v7 = 0;
  i = 0;
  width = 0;
  while ( i < (signed int)(len - 1) && msg[i] )
  {
    while ( msg[i] && msg[i] != '\n' && maxWidth >= width )
      width += font::GetCharacterWidth(thisa, msg[i++]);
    if ( maxWidth < width )
    {
      --i;
      firstCharIdxNextLine = 0;
      while ( msg[i] != ' ' && i >= v7 )
      {
        width -= font::GetCharacterWidth(thisa, msg[i]);
        if ( !firstCharIdxNextLine )
        {
          if ( maxWidth > width )
            firstCharIdxNextLine = i;
        }
        --i;
      }
      if ( i <= v7 )
        i = firstCharIdxNextLine;
      if ( msg[i] == ' ' )
        v4 = width - font::GetCharacterWidth(thisa, msg[i]);
    }
    ++linesNeeded;
    v7 = i++ + 1;
    width = 0;
  }
  return linesNeeded;
}