{
  int v2; // [sp+10h] [bp-4h]@1

  v2 = a1 / 5;
  if ( !(a1 / 5) && a1 >= 3 )
    v2 = 1;
  if ( v2 <= 33 )
  {
    if ( v2 <= 28 )
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
