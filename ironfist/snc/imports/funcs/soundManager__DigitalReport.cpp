{
  signed __int32 result; // eax@2

  if ( gbNoSound )
  {
    result = 0;
  }
  else if ( this->hdidriver )
  {
    if ( always4 == 1 )
    {
      result = AIL_sample_volume(samp);
    }
    else if ( always4 == 4 )
    {
      result = AIL_sample_status(samp) == 4;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}