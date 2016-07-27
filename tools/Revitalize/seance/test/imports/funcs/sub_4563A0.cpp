{
  void *result; // eax@1
  int v2; // [sp+Ch] [bp-10h]@1
  signed int i; // [sp+10h] [bp-Ch]@2
  signed int j; // [sp+10h] [bp-Ch]@5
  signed int k; // [sp+10h] [bp-Ch]@8
  int v6; // [sp+14h] [bp-8h]@2
  unsigned __int8 *v7; // [sp+18h] [bp-4h]@2

  v2 = this;
  result = (void *)this;
  if ( !*(_DWORD *)(this + 186) )
  {
    *(_DWORD *)(this + 186) = KBAlloc(0x7400u, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50FAE8 + 4);
    v6 = *(_DWORD *)(v2 + 186);
    result = HeroWindowManager::instance->screenBuffer->contents;
    v7 = HeroWindowManager::instance->screenBuffer->contents;
    for ( i = 0; i < 16; ++i )
    {
      result = memcpy((void *)v6, v7, 0x1E0u);
      v7 += 640;
      v6 += 480;
    }
    for ( j = 16; j < 464; ++j )
    {
      memcpy((void *)v6, v7, 0x10u);
      result = memcpy((void *)(v6 + 16), v7 + 464, 0x10u);
      v7 += 640;
      v6 += 32;
    }
    for ( k = 464; k < 480; ++k )
    {
      result = memcpy((void *)v6, v7, 0x1E0u);
      v7 += 640;
      v6 += 480;
    }
  }
  return result;
}
