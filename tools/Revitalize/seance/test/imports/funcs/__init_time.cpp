{
  void *v0; // eax@2
  BOOL v1; // esi@2
  signed int result; // eax@3

  if ( dword_520FCC )
  {
    v0 = calloc(1u, 0xACu);
    v1 = (BOOL)v0;
    if ( v0 )
    {
      if ( _get_lc_time(v0) )
      {
        _free_lc_time(v1);
        free(v1);
        result = 1;
      }
      else
      {
        off_5226A4 = (char *(*)[43])v1;
        _free_lc_time(dword_521B20);
        free((BOOL)dword_521B20);
        result = 0;
        dword_521B20 = (void *)v1;
      }
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    off_5226A4 = (char *(*)[43])off_5225F8;
    _free_lc_time(dword_521B20);
    free((BOOL)dword_521B20);
    result = 0;
    dword_521B20 = 0;
  }
  return result;
}
