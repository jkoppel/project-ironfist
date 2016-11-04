{
  int v2; // [sp+10h] [bp-4h]@1

  v2 = 22 * a1 / 1500;
  if ( v2 < 0 )
    v2 = 0;
  if ( v2 <= 30 )
  {
    if ( v2 <= 26 )
    {
      if ( v2 > 23 )
        v2 = 23;
    }
    else
    {
      v2 = 24;
    }
  }
  else
  {
    v2 = 25;
  }
  return v2;
}
