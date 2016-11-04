{
  void *result; // eax@3

  if ( a2 != 2 || a1 != 5 )
  {
    if ( a2 < 19 || a2 > 30 )
    {
      if ( a2 )
      {
        if ( a2 == 13 )
        {
          result = memcpy(a3, (char *)&unique_structures + 28 * a1, 0x1Cu);
        }
        else
        {
          if ( a2 < 16 )
            result = memcpy(a3, (char *)&general_structures + 28 * a2, 0x1Cu);
        }
      }
      else
      {
        result = memcpy(a3, &dword_4F3DD8[7 * (a4 + 1)], 0x1Cu);
      }
    }
    else
    {
      result = memcpy(a3, &dwellings_table[12 * a1] + a2 - 19, 0x1Cu);
    }
  }
  else
  {
    result = memcpy(a3, &dword_51AC78, 0x1Cu);
  }
  return result;
}
