void __thiscall Font::drawString(Font *this, const char *str, int x, int y, signed int regionWidth, int regionHeight, int a7, int alignType)
{
  unsigned int len; // kr04_4@1
  Font *thisa; // [sp+10h] [bp-48h]@1
  signed int v10; // [sp+14h] [bp-44h]@13
  int heightNeededToDisplay; // [sp+1Ch] [bp-3Ch]@2
  int v12; // [sp+24h] [bp-34h]@1
  signed int msgWidth; // [sp+28h] [bp-30h]@1
  int v14; // [sp+2Ch] [bp-2Ch]@14
  const char v15; // [sp+40h] [bp-18h]@27
  int v16; // [sp+44h] [bp-14h]@1
  int i; // [sp+48h] [bp-10h]@1
  int msgOffset; // [sp+4Ch] [bp-Ch]@1

  thisa = this;
  len = strlen(str) + 1;
  msgOffset = 0;
  v16 = 0;
  v12 = 0;
  i = 0;
  msgWidth = 0;
  if ( alignType & 4 )
  {
    alignType -= 4;
    heightNeededToDisplay = Font::numLinesNeededToDisplay(thisa, str, regionWidth) * thisa->lineHeight;
    if ( heightNeededToDisplay < regionHeight )
      v16 = (regionHeight - heightNeededToDisplay) / 2;
  }
  thisa->field_18 = 0;
  while ( i < (signed int)(len - 1) && str[i] && (v16 + thisa->lineHeight <= regionHeight || !v16) )
  {
    while ( str[i] && str[i] != '\n' && msgWidth <= regionWidth )
      msgWidth += Font::charWidth(thisa, str[i++]);
    v10 = msgWidth;
    if ( msgWidth > regionWidth )
    {
      --i;
      v14 = 0;
      while ( str[i] != ' ' )
      {
        if ( i < v12 )
          break;
        msgWidth -= Font::charWidth(thisa, str[i]);
        if ( v16 + 2 * thisa->lineHeight > regionHeight )
        {
          if ( msgWidth < regionWidth )
            break;
        }
        if ( !v14 )
        {
          if ( msgWidth < regionWidth )
            v14 = i;
        }
        --i;
      }
      if ( i <= v12 )
      {
        i = v14;
        msgWidth = v10;
      }
      if ( str[i] == ' ' )
        msgWidth -= Font::charWidth(thisa, str[i]);
    }
    v15 = str[i];
    str[i] = 0;
    if ( alignType )
    {
      if ( alignType == 1 )
      {
        msgOffset = (regionWidth - msgWidth) / 2;
      }
      else
      {
        if ( alignType == 2 )
          msgOffset = regionWidth - msgWidth;
      }
    }
    else
    {
      msgOffset = 0;
    }
    Font::drawLine(thisa, (char *)&str[v12], msgOffset + x, v16 + y, a7, x, y, regionWidth, regionHeight);
    str[i] = v15;
    v16 += thisa->lineHeight;
    v12 = i++ + 1;
    msgWidth = 0;
  }
}
