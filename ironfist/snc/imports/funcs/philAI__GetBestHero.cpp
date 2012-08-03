{
  double v3; // st7@3
  int result; // eax@8
  char v5; // [sp+24h] [bp-20h]@3
  int v6; // [sp+28h] [bp-1Ch]@3
  float v7; // [sp+2Ch] [bp-18h]@3
  float v8; // [sp+30h] [bp-14h]@1
  int v9; // [sp+34h] [bp-10h]@3
  int i; // [sp+38h] [bp-Ch]@1
  int v11; // [sp+3Ch] [bp-8h]@1
  int v12; // [sp+40h] [bp-4h]@1

  v11 = -1;
  v12 = -1027211264;
  v8 = -99.0;
  for ( i = 0; i < 2; ++i )
  {
    v6 = (int)&gpGame->heroes[gpCurPlayer->heroesForPurchase[i]];
    philAI::ValueOfBuyingHero(a1, v6, (int)&v5, (int)&v9);
    v3 = ((double)Random(1, 10) + 90.0) * *(float *)&v9 / 100.0;
    v7 = v3;
    if ( v3 > v8 )
    {
      v11 = i;
      v12 = v9;
      v8 = v7;
    }
    if ( giDebugLevel >= 5 )
    {
      sprintf(gText, "Town:%2d  Hero    : % 15i   Raw BC = %8.2f,  RandBC = %8.2f.", *(_BYTE *)a1, i, *(float *)&v9, v7);
      LogStr(gText);
    }
  }
  *(_DWORD *)a2 = a1;
  *(_DWORD *)(a2 + 4) = 1;
  *(_DWORD *)(a2 + 8) = v11;
  *(_DWORD *)a3 = v12;
  result = 12 * *(_BYTE *)(a1 + 4) + 12 * gpGame->map.width * *(_BYTE *)(a1 + 5);
  if ( *(&gpGame->map.tiles->objType + result) == 170 )
  {
    result = a3;
    *(float *)a3 = *(float *)a3 - 200.0;
  }
  return result;
}