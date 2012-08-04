{
  int result; // eax@3
  char spriteIdx; // [sp+18h] [bp+8h]@8

  if ( (unsigned __int8)chr != '{' && (unsigned __int8)chr != '}' )
  {
    if ( (unsigned __int8)chr == ' ' )
      chr = 'i';
    if ( (unsigned __int8)chr == '\x1F' )
      chr = '_';
    spriteIdx = chr - 32;
    if ( (signed int)(unsigned __int8)spriteIdx > 95 )
      spriteIdx = 95;
    result = this->whetherFirstShortIsMoreThan13 + this->icon->headersAndImageData[(unsigned __int8)spriteIdx].width;
  }
  else
  {
    result = 0;
  }
  return result;
}