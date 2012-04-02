int __thiscall Font::getFlattenedStringWidth(Font *this, const char *str)
{
  unsigned int v2; // kr04_4@1
  Font *thisa; // [sp+Ch] [bp-2Ch]@1
  int width; // [sp+18h] [bp-20h]@1
  int i; // [sp+2Ch] [bp-Ch]@1

  thisa = this;
  v2 = strlen(str) + 1;
  i = 0;
  width = 0;
  while ( (signed int)(v2 - 1) > i && str[i] )
  {
    while ( str[i] && str[i] != '\n' )
      width += Font::charWidth(thisa, str[i++]);
  }
  return width;
}
