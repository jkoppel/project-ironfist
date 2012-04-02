void __thiscall sub_4D2920(void *this)
{
  void *v1; // [sp+Ch] [bp-8h]@1

  v1 = this;
  if ( !dword_537928 )
    unknown_libname_27();
  dword_537928 = 0;
  if ( *((_BYTE *)v1 + 12) == 119 )
  {
    while ( *((_DWORD *)v1 + 2) < 8 )
    {
      ++*((_DWORD *)v1 + 2);
      *((_DWORD *)v1 + 1) *= 2;
    }
    if ( putc(*((_BYTE *)v1 + 4), *(FILE **)v1) == -1 )
      sub_4D5F60();
    ++dword_534BDC;
    if ( fflush(*(FILE **)v1) == -1 )
      sub_4D5F60();
  }
  if ( *(_BYTE *)(*(_DWORD *)v1 + 12) & 0x20 )
    sub_4D5F60();
  if ( fclose(*(FILE **)v1) == -1 )
    sub_4D5F60();
}
