{
  void *v0; // eax@2
  BOOL v1; // esi@2
  signed int result; // eax@3
  void *v3; // ecx@7

  if ( dword_520FC4 )
  {
    v0 = calloc(1u, 0x30u);
    v1 = (BOOL)v0;
    if ( v0 )
    {
      if ( _get_lc_lconv(v0) )
      {
        _free_lc_lconv(v1);
        free(v1);
        result = 1;
      }
      else
      {
        *(_DWORD *)v1 = *off_5226E8;
        *(_DWORD *)(v1 + 4) = off_5226E8[1];
        *(_DWORD *)(v1 + 8) = off_5226E8[2];
        off_5226E8 = (void **)v1;
        _free_lc_lconv(dword_521B30);
        free((BOOL)dword_521B30);
        result = 0;
        dword_521B30 = (void *)v1;
      }
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    off_5226B8 = *off_5226E8;
    off_5226BC = off_5226E8[1];
    v3 = off_5226E8[2];
    off_5226E8 = &off_5226B8;
    off_5226C0 = v3;
    _free_lc_lconv(dword_521B30);
    free((BOOL)dword_521B30);
    result = 0;
    dword_521B30 = 0;
  }
  return result;
}
