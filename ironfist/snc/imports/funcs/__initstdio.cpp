{
  FILE *v0; // ecx@8
  signed int v1; // eax@8
  int v2; // esi@10
  unsigned int v3; // edx@10
  int result; // eax@11

  if ( _nstream )
  {
    if ( (signed int)_nstream < 20 )
      _nstream = 20;
  }
  else
  {
    _nstream = 512;
  }
  __piob = (int)calloc(_nstream, 4);
  if ( !__piob )
  {
    _nstream = 20;
    __piob = (int)calloc(20, 4);
    if ( !__piob )
      _amsg_exit(26);
  }
  v0 = _iob;
  v1 = 0;
  do
  {
    v1 += 4;
    *(_DWORD *)(__piob + v1 - 4) = v0;
    ++v0;
  }
  while ( v1 < 80 );
  v2 = 0;
  v3 = (unsigned int)&unk_521848;
  do
  {
    result = *(_DWORD *)(*(int *)((char *)__pioinfo + ((v2 & 0xFFFFFFE7) >> 3)) + 36 * (v2 & 0x1F));
    if ( result == -1 || !result )
      *(_DWORD *)v3 = -1;
    v3 += 32;
    ++v2;
  }
  while ( v3 < (unsigned int)&unk_5218A8 );
  return result;
}