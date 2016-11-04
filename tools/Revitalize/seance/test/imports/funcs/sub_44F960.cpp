{
  char *result; // eax@2

  if ( debugLogLevel <= 0 )
  {
    if ( a1 >= 5 )
    {
      if ( a1 >= 10 )
      {
        if ( a1 >= 20 )
        {
          if ( a1 >= 50 )
          {
            if ( a1 >= 100 )
            {
              if ( a1 >= 250 )
              {
                if ( a1 >= 500 )
                {
                  if ( a1 >= 1000 )
                    result = off_4F7098[a2];
                  else
                    result = off_4F708C[a2];
                }
                else
                {
                  result = off_4F7080[a2];
                }
              }
              else
              {
                result = off_4F7074[a2];
              }
            }
            else
            {
              result = off_4F7068[a2];
            }
          }
          else
          {
            result = off_4F705C[a2];
          }
        }
        else
        {
          result = off_4F7050[a2];
        }
      }
      else
      {
        result = off_4F7044[a2];
      }
    }
    else
    {
      result = off_4F7038[a2];
    }
  }
  else
  {
    sprintf(byte_524EB0, "%d", a1);
    result = byte_524EB0;
  }
  return result;
}
