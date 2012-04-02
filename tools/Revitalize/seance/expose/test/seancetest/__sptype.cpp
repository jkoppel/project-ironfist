signed int __cdecl _sptype(int a1, int a2)
{
  signed int result; // eax@3

  if ( a2 != 2146435072 || a1 )
  {
    if ( a2 != -1048576 || a1 )
    {
      if ( (HIWORD(a2) & 0x7FF8) == 32760 )
      {
        result = 3;
      }
      else
      {
        if ( (HIWORD(a2) & 0x7FF8) == 32752 && (a2 & 0x7FFFF || a1) )
          result = 4;
        else
          result = 0;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}
