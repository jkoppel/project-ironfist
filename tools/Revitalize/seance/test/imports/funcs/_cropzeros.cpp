{
  unsigned int i; // edx@1
  unsigned __int64 v2; // qax@4
  char v3; // cl@13

  for ( i = a1; *(_BYTE *)i; ++i )
  {
    if ( *(_BYTE *)i == byte_5211F0 )
      break;
  }
  v2 = __PAIR__(i, i) + 4294967296i64;
  if ( *(_BYTE *)v2 )
  {
    for ( ; *HIDWORD(v2); ++HIDWORD(v2) )
    {
      if ( *HIDWORD(v2) == 101 )
        break;
      if ( *HIDWORD(v2) == 69 )
        break;
    }
    for ( LODWORD(v2) = HIDWORD(v2)--; *HIDWORD(v2) == 48; --HIDWORD(v2) )
      ;
    if ( *HIDWORD(v2) == byte_5211F0 )
      --HIDWORD(v2);
    do
    {
      v3 = *(_BYTE *)v2;
      ++HIDWORD(v2);
      LODWORD(v2) = v2 + 1;
      *HIDWORD(v2) = v3;
    }
    while ( v3 );
  }
  return v2;
}
