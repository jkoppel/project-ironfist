{
  signed int v1; // eax@1
  int v2; // ecx@1

  v1 = 0;
  v2 = a1;
  while ( !*(_DWORD *)v2 )
  {
    v2 += 4;
    ++v1;
    if ( v1 >= 3 )
      return 1;
  }
  return 0;
}
