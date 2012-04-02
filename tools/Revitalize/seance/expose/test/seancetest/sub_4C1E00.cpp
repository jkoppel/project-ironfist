signed int __thiscall sub_4C1E00(int this, int a2, int a3)
{
  signed int result; // eax@3
  int v4; // [sp+Ch] [bp-3Ch]@1
  int v5; // [sp+10h] [bp-38h]@45
  int v6; // [sp+14h] [bp-34h]@31
  int v7; // [sp+18h] [bp-30h]@1
  int v8; // [sp+1Ch] [bp-2Ch]@1
  int v9; // [sp+20h] [bp-28h]@1
  int v10; // [sp+24h] [bp-24h]@1
  int v11; // [sp+28h] [bp-20h]@7
  int v12; // [sp+34h] [bp-14h]@1
  int v13; // [sp+38h] [bp-10h]@1
  int v14; // [sp+40h] [bp-8h]@1
  int v15; // [sp+44h] [bp-4h]@7

  v4 = this;
  v10 = byte_4F1DC0[4 * a2];
  v8 = byte_4F1DC1[4 * a2];
  v12 = v10 + *(_DWORD *)(this + 470);
  v14 = v8 + *(_DWORD *)(this + 474);
  v9 = *(_DWORD *)(this + 470) + 7;
  v7 = *(_DWORD *)(this + 474) + 7;
  v13 = v12 + 7;
  if ( v12 < -7 || mapWidth - 8 < v12 )
    return 0;
  if ( v14 < -7 || mapHeight - 8 < v14 )
    return 0;
  v15 = **(_DWORD **)(this + 174) + 12 * (v14 + 7) * *(_DWORD *)(*(_DWORD *)(this + 174) + 8) + 12 * v13;
  v11 = **(_DWORD **)(this + 174) + 12 * v7 * *(_DWORD *)(*(_DWORD *)(this + 174) + 8) + 12 * v9;
  if ( *(_BYTE *)(v15 + 8) & 8 )
    return 0;
  if ( tileToTerrainType[*(_WORD *)v15] )
  {
    if ( *(_DWORD *)(this + 634) == 6 && *(_BYTE *)(v15 + 9) != 28 )
      return 0;
  }
  else
  {
    if ( *(_DWORD *)(this + 634) != 6 && *(_BYTE *)(v15 + 9) != 171 && *(_BYTE *)(v15 + 9) != 160 )
      return 0;
    if ( !tileToTerrainType[*(_WORD *)v11]
      && byte_4F1DC0[4 * a2]
      && byte_4F1DC1[4 * a2]
      && (tileToTerrainType[*(_WORD *)(**(_DWORD **)(this + 174)
                                     + 12 * v7 * *(_DWORD *)(*(_DWORD *)(this + 174) + 8)
                                     + 12 * (v10 + v9))]
       || tileToTerrainType[*(_WORD *)(**(_DWORD **)(this + 174)
                                     + 12 * (v7 + v8) * *(_DWORD *)(*(_DWORD *)(this + 174) + 8)
                                     + 12 * v9)]) )
      return 0;
  }
  if ( (1 << a2) & 0x83 )
  {
    if ( *(_BYTE *)(v11 + 3) != 255
      && ((*(_BYTE *)(v11 + 2) >> 2) & 0x3F) != 47
      && !(*(_BYTE *)(v11 + 8) & 0x80)
      && *(_BYTE *)(v11 + 9) != 167 )
      return 0;
    if ( *(_BYTE *)(v15 + 7) != 255 )
    {
      v6 = **(_DWORD **)(this + 174) + 12 * (v14 + 8) * *(_DWORD *)(*(_DWORD *)(this + 174) + 8) + 12 * v13;
      if ( *(_BYTE *)(v6 + 3) != 255 )
      {
        if ( ((*(_BYTE *)(v6 + 2) >> 2) & 0x3F) != 47 && !(*(_BYTE *)(v6 + 8) & 0x80) )
          return 0;
      }
    }
  }
  if ( !((1 << a2) & 0x38) )
    goto LABEL_53;
  if ( *(_BYTE *)(v15 + 3) != 255
    && ((*(_BYTE *)(v15 + 2) >> 2) & 0x3F) != 47
    && !(*(_BYTE *)(v15 + 8) & 0x80)
    && *(_BYTE *)(v15 + 9) != 167
    && (!a3 || !(*(_BYTE *)(v15 + 9) & 0x80) || !sub_458D40(v15)) )
    return 0;
  if ( *(_BYTE *)(v11 + 7) == 255
    || (v5 = **(_DWORD **)(v4 + 174)
           + 12 * (*(_DWORD *)(v4 + 470) + *(_DWORD *)(v4 + 658))
           + 12 * *(_DWORD *)(*(_DWORD *)(v4 + 174) + 8) * (*(_DWORD *)(v4 + 474) + *(_DWORD *)(v4 + 666) + 1),
        *(_BYTE *)(v5 + 3) == 255)
    || ((*(_BYTE *)(v5 + 2) >> 2) & 0x3F) == 47
    || *(_BYTE *)(v5 + 8) & 0x80
    || *(_BYTE *)(v5 + 9) & 0x80 )
LABEL_53:
    result = 1;
  else
    result = 0;
  return result;
}
