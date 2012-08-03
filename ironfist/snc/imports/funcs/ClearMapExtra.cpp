{
  int i; // [sp+Ch] [bp-4h]@1

  for ( i = 0; i < *(_DWORD *)&iMaxMapExtra; ++i )
  {
    if ( *((_DWORD *)ppMapExtra + i) )
      BaseFree(*((void **)ppMapExtra + i), (int)"F:\\h2xsrc\\Source\\KB.CPP", word_50D804 + 6);
  }
  if ( ppMapExtra )
    BaseFree(ppMapExtra, (int)"F:\\h2xsrc\\Source\\KB.CPP", word_50D804 + 9);
  ppMapExtra = 0;
  if ( pwSizeOfMapExtra )
    BaseFree(pwSizeOfMapExtra, (int)"F:\\h2xsrc\\Source\\KB.CPP", word_50D804 + 13);
  pwSizeOfMapExtra = 0;
  *(_DWORD *)&iMaxMapExtra = 0;
}