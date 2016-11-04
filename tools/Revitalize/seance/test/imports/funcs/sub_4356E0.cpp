{
  int i; // [sp+Ch] [bp-4h]@1

  for ( i = 0; i < *(_DWORD *)&dword_5240A4; ++i )
  {
    if ( *((_DWORD *)dword_524784 + i) )
      KBFree(*((void **)dword_524784 + i), (int)"F:\\h2xsrc\\Source\\KB.CPP", word_50D804 + 6);
  }
  if ( dword_524784 )
    KBFree(dword_524784, (int)"F:\\h2xsrc\\Source\\KB.CPP", word_50D804 + 9);
  dword_524784 = 0;
  if ( dword_5249EC )
    KBFree(dword_5249EC, (int)"F:\\h2xsrc\\Source\\KB.CPP", word_50D804 + 13);
  dword_5249EC = 0;
  *(_DWORD *)&dword_5240A4 = 0;
}
