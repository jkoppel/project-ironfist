char *__stdcall descriptorForTroopAmt(signed int amt, int queryType)
{
  char *result; // eax@2

  if ( debugLogLevel <= 0 )
  {
    if ( amt >= 5 )
    {
      if ( amt >= 10 )
      {
        if ( amt >= 20 )
        {
          if ( amt >= 50 )
          {
            if ( amt >= 100 )
            {
              if ( amt >= 250 )
              {
                if ( amt >= 500 )
                {
                  if ( amt >= 1000 )
                    result = legionStrings[queryType];
                  else
                    result = zoundsStrings[queryType];
                }
                else
                {
                  result = swarmStrings[queryType];
                }
              }
              else
              {
                result = throngStrings[queryType];
              }
            }
            else
            {
              result = hordeStrings[queryType];
            }
          }
          else
          {
            result = lotsStrings[queryType];
          }
        }
        else
        {
          result = packStrings[queryType];
        }
      }
      else
      {
        result = severalStrings[queryType];
      }
    }
    else
    {
      result = fewStrings[queryType];
    }
  }
  else
  {
    sprintf(descriptForTroopAmtBuf, "%d", amt);
    result = descriptForTroopAmtBuf;
  }
  return result;
}
