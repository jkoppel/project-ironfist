{
  int result; // eax@3
  void *v3; // [sp+10h] [bp-54h]@1
  int hexIdx; // [sp+14h] [bp-50h]@8
  char v5[40]; // [sp+18h] [bp-4Ch]@4
  int v6; // [sp+40h] [bp-24h]@4
  float v7; // [sp+44h] [bp-20h]@15
  int i; // [sp+48h] [bp-1Ch]@1
  int v9; // [sp+4Ch] [bp-18h]@1
  float v10; // [sp+50h] [bp-14h]@1
  int v11; // [sp+54h] [bp-10h]@10
  float v12; // [sp+58h] [bp-Ch]@1
  signed int neighborIdx; // [sp+5Ch] [bp-8h]@8
  float v14; // [sp+60h] [bp-4h]@4

  v3 = this;
  v9 = -1;
  v10 = -99999.0;
  v12 = (double)(9 * *(_DWORD *)(a2 + 150));
  for ( i = 0; ; ++i )
  {
    result = 1 - *(_DWORD *)((char *)v3 + 62127);
    if ( *(_DWORD *)((char *)v3 + 4 * result + 13639) <= i )
      break;
    memset(v5, 0, 0x28u);
    v14 = 0.0;
    v6 = (int)((char *)v3 + 24234 * (1 - *(_DWORD *)((char *)v3 + 62127)) + 1154 * i + 13647);
    if ( v6 && !(*(_BYTE *)(v6 + 208) & 0x10) && *(_DWORD *)(v6 + 150) > 0 )
    {
      v14 = sub_46BB80(v6, v12);
      *(&v5[20 * *(_DWORD *)(v6 + 230)] + *(_DWORD *)(v6 + 234)) = 1;
      hexIdx = *(_DWORD *)(v6 + 122);
      for ( neighborIdx = 0; neighborIdx < 6; ++neighborIdx )
      {
        v11 = getHexNeighbor(hexIdx, neighborIdx);
        if ( v11 >= 0
          && v11 < 117
          && *((_BYTE *)v3 + 98 * v11 + 1316) != -1
          && *((_BYTE *)v3 + 98 * v11 + 1317) != -1
          && !*(&v5[20 * *((_BYTE *)v3 + 98 * v11 + 1316)] + *((_BYTE *)v3 + 98 * v11 + 1317)) )
        {
          v7 = sub_46BB80(
                 (int)((char *)v3
                     + 24234 * *((_BYTE *)v3 + 98 * v11 + 1316)
                     + 1154 * *((_BYTE *)v3 + 98 * v11 + 1317)
                     + 13647),
                 v12);
          *(&v5[20 * *((_BYTE *)v3 + 98 * v11 + 1316)] + *((_BYTE *)v3 + 98 * v11 + 1317)) = 1;
          if ( *((_BYTE *)v3 + 98 * v11 + 1316) == *(_DWORD *)((char *)v3 + 62127) )
            v14 = v14 - v7;
          else
            v14 = v7 + v14;
        }
      }
      if ( v9 == -1 || v14 > (double)v10 )
      {
        v10 = v14;
        v9 = i;
        couldBeCreatureActionType = 2;
        notTargetForAISpell = hexIdx;
      }
    }
  }
  return result;
}
