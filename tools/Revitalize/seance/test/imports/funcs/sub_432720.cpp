{
  int result; // eax@3

  if ( a1 != 5 || a2 != 5 )
  {
    if ( a2 >= 19 && a2 <= 30 )
    {
      result = *(&dword_4F411C[12 * a1] + a2);
    }
    else
    {
      if ( a2 <= 15 )
      {
        if ( a2 )
        {
          if ( a2 == 13 )
            result = dword_4F4150[a1];
          else
            result = dword_4F4100[a2];
        }
        else
        {
          result = dword_4F40E8[a3];
        }
      }
      else
      {
        result = 0;
      }
    }
  }
  else
  {
    result = 1000;
  }
  return result;
}
