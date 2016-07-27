{
  void *this; // [sp+Ch] [bp-38h]@1
  const void *v3; // [sp+10h] [bp-34h]@1
  void *a1a; // [sp+14h] [bp-30h]@1
  signed int v5; // [sp+18h] [bp-2Ch]@3
  int v6; // [sp+1Ch] [bp-28h]@5
  unsigned __int8 *v7; // [sp+20h] [bp-24h]@9
  signed int j; // [sp+24h] [bp-20h]@3
  void *v9; // [sp+28h] [bp-1Ch]@1
  signed int i; // [sp+2Ch] [bp-18h]@1
  signed int l; // [sp+30h] [bp-14h]@11
  signed int k; // [sp+34h] [bp-10h]@9
  int v13; // [sp+3Ch] [bp-8h]@3
  signed int v14; // [sp+40h] [bp-4h]@1

  this = a2;
  v3 = a1;
  v14 = -1;
  a1a = KBAlloc(0x300u, "F:\\h2xsrc\\Source\\KB.CPP", word_50D970 + 13);
  v9 = KBAlloc(0x100u, "F:\\h2xsrc\\Source\\KB.CPP", word_50D970 + 14);
  memset(a1a, 0, 0x300u);
  memset(v9, 0, 0x100u);
  for ( i = 10; i < 246; ++i )
  {
    v13 = (*((_BYTE *)v3 + 3 * i) + *((_BYTE *)v3 + 3 * i + 2) + *((_BYTE *)v3 + 3 * i + 1)) / 3;
    v5 = 999;
    for ( j = 10; j < 36; ++j )
    {
      v6 = abs(v13 - (*((_BYTE *)this + 3 * j) + *((_BYTE *)this + 3 * j + 2) + *((_BYTE *)this + 3 * j + 1)) / 3);
      if ( v5 > v6 )
      {
        v5 = v6;
        v14 = j;
      }
    }
    memcpy((char *)a1a + 3 * i, (char *)this + 3 * v14, 3u);
    *((_BYTE *)v9 + i) = v14;
  }
  sub_4CAAC0(v3, a1a, 8);
  v7 = HeroWindowManager::instance->screenBuffer->contents;
  for ( k = 0; k < 640; ++k )
  {
    for ( l = 0; l < 480; ++l )
    {
      *v7 = *((_BYTE *)v9 + *v7);
      ++v7;
    }
  }
  HeroWindowManager::drawWindowsFromBufferWithWinG(HeroWindowManager::instance);
  sub_49CFB0((PaletteContents *)this);
  KBFree(a1a, (int)"F:\\h2xsrc\\Source\\KB.CPP", word_50D970 + 49);
  KBFree(v9, (int)"F:\\h2xsrc\\Source\\KB.CPP", word_50D970 + 50);
}
