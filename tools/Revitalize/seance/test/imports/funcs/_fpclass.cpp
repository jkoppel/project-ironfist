{
  signed int v2; // eax@2
  signed int result; // eax@5
  int v4; // eax@9

  if ( (HIWORD(a2) & 0x7FF0) == 32752 )
  {
    v2 = _sptype(a1, a2);
    switch ( v2 )
    {
      case 1:
        result = 512;
        break;
      case 2:
        result = 4;
        break;
      case 3:
        result = 2;
        break;
      default:
        result = 1;
        break;
    }
  }
  else
  {
    v4 = HIWORD(a2) & 0x8000;
    if ( a1 | a2 & 0x7FFFFFFF )
    {
      if ( !(HIWORD(a2) & 0x7FF0) && (a2 & 0xFFFFF || a1) )
        result = (unsigned int)v4 < 1 ? 128 : 16;
      else
        result = (unsigned int)v4 < 1 ? 256 : 8;
    }
    else
    {
      result = (unsigned int)v4 < 1 ? 64 : 32;
    }
  }
  return result;
}
