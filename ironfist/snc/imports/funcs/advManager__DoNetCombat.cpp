{
  int v4; // [sp+14h] [bp-38h]@1
  int v5; // [sp+18h] [bp-34h]@1
  void *a1a; // [sp+1Ch] [bp-30h]@1
  int v7; // [sp+20h] [bp-2Ch]@1
  int v8; // [sp+24h] [bp-28h]@1
  void *v9; // [sp+28h] [bp-24h]@1
  int v10; // [sp+2Ch] [bp-20h]@1
  void *v11; // [sp+34h] [bp-18h]@1
  char v12; // [sp+38h] [bp-14h]@1
  void *v13; // [sp+3Ch] [bp-10h]@1
  int v14; // [sp+40h] [bp-Ch]@1
  void *v15; // [sp+44h] [bp-8h]@1
  int v16; // [sp+48h] [bp-4h]@1

  v9 = 0;
  a1a = 0;
  v13 = 0;
  v15 = 0;
  v11 = 0;
  advManager::ReceiveHeroTownData(
    a1,
    (int)&v7,
    (int)&v5,
    (int)&v4,
    &v9,
    &a1a,
    &v13,
    &v15,
    &v11,
    (int)&v10,
    (int)&v8,
    (int)&v16,
    (int)&v12,
    (int)&gbRetreatWin,
    (int)&gbCombatSurrender);
  v14 = *((_BYTE *)v9 + 3);
  v12 = advManager::DoCombat(this, __PAIR__(v4, v5), (int)v9, a1a, (int)v13, (int)v15, v11, v10, v8, v16, 0);
  if ( !gbHumanPlayer[v14] )
    advManager::SendHeroTownData(
      v5,
      v4,
      (int)v9,
      a1a,
      v13,
      (int)v15,
      v11,
      v10,
      v8,
      v16,
      v7,
      v12,
      gbRetreatWin,
      gbCombatSurrender);
  if ( a1a )
    BaseFree(a1a, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518B64 + 70);
  if ( v11 )
    BaseFree(v11, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518B64 + 73);
  if ( v13 )
    BaseFree(v13, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518B64 + 76);
  if ( v15 )
    BaseFree(v15, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518B64 + 79);
  if ( v9 )
    BaseFree(v9, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518B64 + 82);
  gbRetreatWin = 0;
  return 1;
}