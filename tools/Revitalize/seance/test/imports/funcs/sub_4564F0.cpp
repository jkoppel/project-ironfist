{
  void *result; // eax@1
  signed int i; // [sp+10h] [bp-Ch]@3
  signed int j; // [sp+10h] [bp-Ch]@6
  signed int k; // [sp+10h] [bp-Ch]@9
  int v5; // [sp+14h] [bp-8h]@3
  unsigned __int8 *v6; // [sp+18h] [bp-4h]@3

  result = (void *)this;
  if ( *(_DWORD *)(this + 186) && !dword_4F2E80 )
  {
    v6 = HeroWindowManager::instance->screenBuffer->contents;
    result = *(void **)(this + 186);
    v5 = *(_DWORD *)(this + 186);
    for ( i = 0; i < 16; ++i )
    {
      result = memcpy(v6, (const void *)v5, 0x1E0u);
      v6 += 640;
      v5 += 480;
    }
    for ( j = 16; j < 464; ++j )
    {
      memcpy(v6, (const void *)v5, 0x10u);
      result = memcpy(v6 + 464, (const void *)(v5 + 16), 0x10u);
      v6 += 640;
      v5 += 32;
    }
    for ( k = 464; k < 480; ++k )
    {
      result = memcpy(v6, (const void *)v5, 0x1E0u);
      v6 += 640;
      v5 += 480;
    }
  }
  return result;
}
