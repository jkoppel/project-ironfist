{
  unsigned int v0; // ST30_4@4
  void *a1; // [sp+Ch] [bp-28h]@1
  void *v2; // [sp+10h] [bp-24h]@1
  int v3; // [sp+1Ch] [bp-18h]@1
  int i; // [sp+20h] [bp-14h]@1
  void *v5; // [sp+28h] [bp-Ch]@1

  v3 = unseededNextRand(20000, 100000);
  a1 = KBAlloc(v3 + 5000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 7);
  v2 = KBAlloc(v3 + 5000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 8);
  v5 = KBAlloc(v3 + 5000, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 9);
  for ( i = 0; i < v3; ++i )
    *((_BYTE *)a1 + i) = unseededNextRand(0, 255);
  sub_46DC60((int)a1, v3);
  v0 = sub_4D63A0(v2, a1, v3);
  sub_4D6670(v5, v2, v0);
  sub_46DC60((int)v5, v3);
  sub_46DC60((int)a1, v3);
  KBFree(a1, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 26);
  KBFree(v2, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 27);
  KBFree(v5, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFE08 + 28);
}
