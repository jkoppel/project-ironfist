void __cdecl sub_4D5060()
{
  int i; // [sp+Ch] [bp-4h]@3

  if ( dword_537920 )
  {
    sprintf(globBuf, L" ");
    debugLog(globBuf);
  }
  sub_4D4C20();
  dword_537930 = -1;
  for ( i = 0; dword_5347A4 >= i; ++i )
  {
    if ( !*((_DWORD *)dword_51FDC4 + i) )
    {
      dword_537930 = i;
      break;
    }
  }
  if ( dword_537930 == -1 )
    unknown_libname_27();
}
