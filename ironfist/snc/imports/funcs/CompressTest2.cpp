{
  int v0; // ST30_4@4
  const void *a1; // [sp+Ch] [bp-28h]@1
  void *v2; // [sp+10h] [bp-24h]@1
  int v3; // [sp+1Ch] [bp-18h]@1
  int i; // [sp+20h] [bp-14h]@1
  void *v5; // [sp+28h] [bp-Ch]@1

  v3 = Random(20000, 100000);
  a1 = BaseAlloc(v3 + 5000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 7);
  v2 = BaseAlloc(v3 + 5000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 8);
  v5 = BaseAlloc(v3 + 5000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 9);
  for ( i = 0; i < v3; ++i )
    *((_BYTE *)a1 + i) = Random(0, 255);
  calc_crc_long((int)a1, v3);
  v0 = EncodeData(v2, a1, v3);
  DecodeData(v5, v2, v0);
  calc_crc_long((int)v5, v3);
  calc_crc_long((int)a1, v3);
  BaseFree((void *)a1, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 26);
  BaseFree(v2, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 27);
  BaseFree(v5, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 28);
}