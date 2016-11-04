{
  signed int v2; // [sp+38h] [bp-8h]@1
  int v3; // [sp+3Ch] [bp-4h]@9
  signed int v4; // [sp+3Ch] [bp-4h]@12

  v2 = a1;
  if ( gameObject->_1[682] == 144 )
  {
    v2 = (signed __int64)((double)a1 * 0.6);
  }
  else
  {
    if ( gameObject->_1[682] == 108 )
    {
      v2 = (signed __int64)((double)a1 * 0.8);
    }
    else
    {
      if ( gameObject->_1[682] != 72 && gameObject->_1[682] == 36 )
        v2 = (signed __int64)((double)a1 * 1.4);
    }
  }
  if ( v2 > 60 )
  {
    if ( v2 > 120 )
    {
      v4 = (signed __int64)((double)140 - 30.0);
      if ( v2 > 360 )
        v3 = (signed __int64)((double)(signed int)(signed __int64)((double)v4 - 60.0) - (double)(v2 - 360) * 0.125);
      else
        v3 = (signed __int64)((double)v4 - (double)(v2 - 120) * 0.25);
    }
    else
    {
      v3 = (signed __int64)((double)140 - (double)(v2 - 60) * 0.5);
    }
  }
  else
  {
    v3 = 200 - v2;
  }
  if ( v3 < 20 )
    v3 = 20;
  return v3;
}
