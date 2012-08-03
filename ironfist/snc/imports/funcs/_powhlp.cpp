{
  signed int result; // eax@3
  int v4; // ecx@20
  double v5; // [sp+0h] [bp-8h]@1
  double v6; // [sp+0h] [bp-8h]@22
  __int64 v7; // [sp+0h] [bp-8h]@27

  v5 = fabs(a1);
  if ( a2 == 1.797693134862316e308 )
  {
    if ( v5 <= 1.0 )
    {
      if ( v5 >= 1.0 )
      {
        *(_DWORD *)(a3 + 4) = LODWORD(byte_522704);
        result = 1;
        *(_DWORD *)a3 = LODWORD(_d_ind);
      }
      else
      {
        result = 0;
        *(_DWORD *)a3 = 0;
        *(_DWORD *)(a3 + 4) = 0;
      }
    }
    else
    {
      *(_DWORD *)(a3 + 4) = HIDWORD(_d_inf);
      result = 0;
      *(_DWORD *)a3 = LODWORD(_d_inf);
    }
    return result;
  }
  if ( a2 == -1.797693134862316e308 )
  {
    if ( v5 <= 1.0 )
    {
      if ( v5 >= 1.0 )
      {
        *(_DWORD *)(a3 + 4) = LODWORD(byte_522704);
        result = 1;
        *(_DWORD *)a3 = LODWORD(_d_ind);
      }
      else
      {
        *(_DWORD *)(a3 + 4) = HIDWORD(_d_inf);
        result = 0;
        *(_DWORD *)a3 = LODWORD(_d_inf);
      }
    }
    else
    {
      result = 0;
      *(_DWORD *)a3 = 0;
      *(_DWORD *)(a3 + 4) = 0;
    }
    return result;
  }
  if ( a1 == 1.797693134862316e308 )
  {
    if ( a2 <= 0.0 )
    {
      *(_DWORD *)a3 = 0;
      if ( a2 >= 0.0 )
      {
        *(_DWORD *)(a3 + 4) = 1072693248;
        result = 0;
      }
      else
      {
        *(_DWORD *)(a3 + 4) = 0;
        result = 0;
      }
    }
    else
    {
      *(_DWORD *)(a3 + 4) = HIDWORD(_d_inf);
      result = 0;
      *(_DWORD *)a3 = LODWORD(_d_inf);
    }
    return result;
  }
  if ( a1 != -1.797693134862316e308 )
    return 0;
  v4 = _d_inttype(a2);
  if ( a2 > 0.0 )
  {
    if ( v4 == 1 )
      v6 = -_d_inf;
    else
      v6 = _d_inf;
    *(_DWORD *)(a3 + 4) = HIDWORD(v6);
    result = 0;
    *(_DWORD *)a3 = LODWORD(v6);
    return result;
  }
  if ( a2 >= 0.0 )
  {
    *(_DWORD *)a3 = 0;
    *(_DWORD *)(a3 + 4) = 1072693248;
    return 0;
  }
  if ( v4 == 1 )
    v7 = _d_mzero;
  else
    v7 = 0i64;
  *(_DWORD *)(a3 + 4) = HIDWORD(v7);
  result = 0;
  *(_DWORD *)a3 = v7;
  return result;
}