{
  int result; // eax@4
  void *thisa; // [sp+Ch] [bp-1Ch]@1
  signed int v6; // [sp+10h] [bp-18h]@1
  int v7; // [sp+14h] [bp-14h]@1
  char v8; // [sp+24h] [bp-4h]@2

  thisa = this;
  v6 = sub_419C90(this, a2, a3);
  v7 = *((_DWORD *)dword_524784
       + (unsigned __int8)((unsigned __int8)(*(_WORD *)(*(_DWORD *)((char *)thisa + 2878)
                                                      + 12 * a3 * *(_DWORD *)((char *)thisa + 2886)
                                                      + 12 * a2
                                                      + 4) >> 8) >> -5));
  if ( *(_BYTE *)v7 == -1 )
    v8 = unseededNextRand(0, 5);
  else
    v8 = *((_BYTE *)thisa + byte_524220[*(_BYTE *)v7] + 1113);
  *((_WORD *)thisa + 50 * v6 + 1492) = 10;
  sub_4270A0((GameInfo *)thisa, a2 - 5, a3 - 3, a2 + 2, a3 + 1, 38, 0, 31, 35, 32 * v8, 48, 35);
  sub_4270A0((GameInfo *)thisa, a2 - 5, a3 - 3, a2 + 2, a3 + 1, 38, 32, 255, 37, 32 * v8, 48, 35);
  sub_4270A0((GameInfo *)thisa, a2 - 5, a3 - 3, a2 + 2, a3 + 1, 38, 0, 31, 35, 32 * v8, 49, 35);
  result = sub_4270A0((GameInfo *)thisa, a2 - 5, a3 - 3, a2 + 2, a3 + 1, 38, 32, 255, 37, 32 * v8, 49, 35);
  LOBYTE(result) = v8;
  *((_BYTE *)thisa + 100 * v6 + 2902) = v8;
  return result;
}
