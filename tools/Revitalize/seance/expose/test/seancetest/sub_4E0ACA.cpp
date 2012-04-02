double __usercall sub_4E0ACA<st0>(int a1<ebp>, double result<st0>)
{
  __int16 v2; // fps@2
  char v6; // al@2
  __int16 v7; // ax@11
  int v8; // ebx@18

  if ( dword_520B28 )
    return result;
  UNDEF(v2);
  *(double *)(a1 - 720) = result;
  v6 = *(_BYTE *)(a1 - 144);
  if ( !v6 )
    goto LABEL_7;
  if ( v6 != -1 && v6 != -2 )
  {
    if ( !v6 )
      return result;
    *(_DWORD *)(a1 - 142) = v6;
    goto LABEL_18;
  }
  v7 = *(_WORD *)(a1 - 714) & 0x7FF0;
  if ( v7 )
  {
    if ( v7 != 32752 )
    {
LABEL_7:
      if ( *(_WORD *)(a1 - 164) & 0x20 || !(v2 & 0x20) )
        return result;
      *(_DWORD *)(a1 - 142) = 8;
      goto LABEL_18;
    }
    *(_DWORD *)(a1 - 142) = 3;
    if ( fabs(result) > 1.797693134862316e308 )
      result = result * 1.797693134862316e308;
  }
  else
  {
    *(_DWORD *)(a1 - 142) = 4;
    if ( fabs(result) < 2.225073858507201e-308 )
      result = result * 0.0;
  }
LABEL_18:
  v8 = *(_DWORD *)(a1 - 148) + 1;
  *(_DWORD *)(a1 - 138) = v8;
  if ( !(*(_BYTE *)(a1 - 712) & 1) )
  {
    *(_DWORD *)(a1 - 134) = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(a1 - 134 + 4) = *(_DWORD *)(a1 + 12);
    if ( *(_BYTE *)(v8 + 12) != 1 )
    {
      *(_DWORD *)(a1 - 126) = *(_DWORD *)(a1 + 16);
      *(_DWORD *)(a1 - 126 + 4) = *(_DWORD *)(a1 + 20);
    }
  }
  *(double *)(a1 - 118) = result;
  _87except(*(_BYTE *)(*(_DWORD *)(a1 - 148) + 14), a1 - 142, a1 - 164);
  return *(double *)(a1 - 118);
}
