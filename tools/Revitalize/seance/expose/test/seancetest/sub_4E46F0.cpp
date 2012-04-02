int __cdecl sub_4E46F0()
{
  void **v0; // ecx@8
  signed int v1; // eax@8
  int v2; // esi@10
  unsigned int v3; // edx@10
  int result; // eax@11

  if ( dword_538E10 )
  {
    if ( (signed int)dword_538E10 < 20 )
      dword_538E10 = 20;
  }
  else
  {
    dword_538E10 = 512;
  }
  dword_537E0C = (int)calloc(dword_538E10, 4u);
  if ( !dword_537E0C )
  {
    dword_538E10 = 20;
    dword_537E0C = (int)calloc(0x14u, 4u);
    if ( !dword_537E0C )
      _amsg_exit(26);
  }
  v0 = &off_521838;
  v1 = 0;
  do
  {
    v1 += 4;
    *(_DWORD *)(dword_537E0C + v1 - 4) = v0;
    v0 += 8;
  }
  while ( v1 < 80 );
  v2 = 0;
  v3 = (unsigned int)&unk_521848;
  do
  {
    result = *(_DWORD *)(*(int *)((char *)dword_538E20 + ((v2 & 0xFFFFFFE7) >> 3)) + 36 * (v2 & 0x1F));
    if ( result == -1 || !result )
      *(_DWORD *)v3 = -1;
    v3 += 32;
    ++v2;
  }
  while ( v3 < (unsigned int)&unk_5218A8 );
  return result;
}
