{
  int v3[7]; // [sp+14h] [bp-24h]@1
  int i; // [sp+30h] [bp-8h]@1
  Player *v5; // [sp+34h] [bp-4h]@1

  sub_432120(*(_BYTE *)(a1 + 3), a2, v3, *(_BYTE *)(a1 + 28));
  v5 = &gameObject->players[curPlayerIdx];
  for ( i = 0; i < 7; ++i )
  {
    if ( v5->resources[i] < v3[i] )
      return 0;
  }
  return 1;
}
