{
  int res; // [sp+10h] [bp-4h]@1

  res = 0;
  if ( ifForMusicThen101 == 101 )
  {
    if ( *(_DWORD *)&musicVolume >= 1 )
    {
      if ( *(_DWORD *)&musicVolume <= 10 )
      {
        res = weight * (11 - *(_DWORD *)&musicVolume) / 10;
        if ( res < 1 )
          res = 1;
      }
    }
  }
  else
  {
    if ( *(_DWORD *)&soundVolume >= 1 )
    {
      if ( *(_DWORD *)&soundVolume <= 10 )
      {
        res = weight * (11 - *(_DWORD *)&soundVolume) / 10;
        if ( res < 1 )
          res = 1;
      }
    }
  }
  if ( res < 0 )
    res = 0;
  if ( res > 127 )
    res = 127;
  return res;
}
