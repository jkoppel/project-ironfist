{
  int result; // eax@4
  char *v2; // [sp+28h] [bp-48h]@1
  float v3[7]; // [sp+2Ch] [bp-44h]@6
  float v4; // [sp+48h] [bp-28h]@4
  int i; // [sp+4Ch] [bp-24h]@1
  int v6; // [sp+50h] [bp-20h]@1
  int v7[7]; // [sp+54h] [bp-1Ch]@3

  v2 = &gpGame->players[a1]._4[8];
  v6 = 0;
  for ( i = 0; i < 7; ++i )
  {
    v7[i] = (signed __int64)(((double)(5 * *(_DWORD *)&v2[4 * i + 52]) * 0.7 + (double)gpGame->players[a1].resources[i])
                           * (double)dword_4F1DE0[i]);
    v6 += v7[i];
  }
  result = v6 / 7;
  v4 = (double)(v6 / 7);
  for ( i = 0; i < 7; ++i )
  {
    v3[i] = (double)v7[i] / v4;
    result = i;
    gafAITurnCostResource[i] = (double)dword_4F1DE0[i] / (v3[i] / 2.0 + 0.5);
  }
  return result;
}