{
  void *result; // eax@1
  signed int i; // [sp+10h] [bp-Ch]@3
  signed int j; // [sp+10h] [bp-Ch]@6
  signed int k; // [sp+10h] [bp-Ch]@9
  int v6; // [sp+14h] [bp-8h]@3
  unsigned __int8 *v7; // [sp+18h] [bp-4h]@3

  result = (void *)this;
  if ( *(_DWORD *)(this + 186) && !dword_4F2E80 )
  {
    v7 = gpWindowManager->screenBuffer->contents;
    result = *(void **)(this + 186);
    v6 = *(_DWORD *)(this + 186);
    for ( i = 0; i < 16; ++i )
    {
      result = memcpy(v7, (const void *)v6, 0x1E0u);
      v7 += 640;
      v6 += 480;
    }
    for ( j = 16; j < 464; ++j )
    {
      memcpy(v7, (const void *)v6, 0x10u);
      result = memcpy(v7 + 464, (const void *)(v6 + 16), 0x10u);
      v7 += 640;
      v6 += 32;
    }
    for ( k = 464; k < 480; ++k )
    {
      result = memcpy(v7, (const void *)v6, 0x1E0u);
      v7 += 640;
      v6 += 480;
    }
  }
  return result;
}