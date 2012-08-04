{
  int v2; // ST58_4@4
  int v3; // ST54_4@4
  int v4; // ST4C_4@6
  int v5; // ST48_4@6
  int v6; // ST40_4@8
  int v7; // ST3C_4@8
  int v8; // ST34_4@9
  int v9; // ST30_4@9
  int v10; // ST28_4@13
  int v11; // ST24_4@13
  int v12; // ST1C_4@14
  int v13; // ST18_4@14
  int result; // eax@19
  int v15[40]; // [sp+5Ch] [bp-160h]@15
  int v16; // [sp+FCh] [bp-C0h]@9
  int v17; // [sp+100h] [bp-BCh]@9
  int j; // [sp+104h] [bp-B8h]@9
  int v19; // [sp+108h] [bp-B4h]@3
  int i; // [sp+10Ch] [bp-B0h]@1
  int v21; // [sp+110h] [bp-ACh]@20
  int v22[40]; // [sp+114h] [bp-A8h]@15
  int v23; // [sp+1B4h] [bp-8h]@1
  int v24; // [sp+1B8h] [bp-4h]@1

  v23 = 0;
  v24 = a1;
  for ( i = a2; ; i = v15[v23] )
  {
    while ( i - v24 > 10 )
    {
      v19 = (v24 + i) >> 1;
      if ( fullGt(*((_DWORD *)zptr + v24), *((_DWORD *)zptr + ((v24 + i) >> 1))) )
      {
        v2 = v19;
        v3 = *((_DWORD *)zptr + v24);
        *((_DWORD *)zptr + v24) = *((_DWORD *)zptr + v19);
        *((_DWORD *)zptr + v2) = v3;
      }
      if ( fullGt(*((_DWORD *)zptr + v24), *((_DWORD *)zptr + i)) )
      {
        v4 = i;
        v5 = *((_DWORD *)zptr + v24);
        *((_DWORD *)zptr + v24) = *((_DWORD *)zptr + i);
        *((_DWORD *)zptr + v4) = v5;
      }
      if ( fullGt(*((_DWORD *)zptr + v19), *((_DWORD *)zptr + i)) )
      {
        v6 = i;
        v7 = *((_DWORD *)zptr + v19);
        *((_DWORD *)zptr + v19) = *((_DWORD *)zptr + i);
        *((_DWORD *)zptr + v6) = v7;
      }
      v8 = i - 1;
      v9 = *((_DWORD *)zptr + v19);
      *((_DWORD *)zptr + v19) = *((_DWORD *)zptr + i - 1);
      *((_DWORD *)zptr + v8) = v9;
      v16 = *((_DWORD *)zptr + i - 1);
      j = v24;
      v17 = i - 1;
      while ( 1 )
      {
        do
          ++j;
        while ( fullGt(v16, *((_DWORD *)zptr + j)) );
        do
          --v17;
        while ( fullGt(*((_DWORD *)zptr + v17), v16) );
        if ( v17 <= j )
          break;
        v10 = v17;
        v11 = *((_DWORD *)zptr + j);
        *((_DWORD *)zptr + j) = *((_DWORD *)zptr + v17);
        *((_DWORD *)zptr + v10) = v11;
      }
      v12 = i - 1;
      v13 = *((_DWORD *)zptr + j);
      *((_DWORD *)zptr + j) = *((_DWORD *)zptr + i - 1);
      *((_DWORD *)zptr + v12) = v13;
      if ( i - j >= j - v24 )
      {
        v22[v23] = j + 1;
        v15[v23++] = i;
        i = j - 1;
      }
      else
      {
        v22[v23] = v24;
        v15[v23++] = j - 1;
        v24 = j + 1;
      }
    }
    for ( j = v24 + 1; ; ++j )
    {
      result = j;
      if ( i < j )
        break;
      v21 = *((_DWORD *)zptr + j);
      v17 = j;
      do
      {
        if ( !fullGt(*((_DWORD *)zptr + v17 - 1), v21) )
          break;
        *((_DWORD *)zptr + v17) = *((_DWORD *)zptr + v17 - 1);
        --v17;
      }
      while ( v24 < v17 );
      *((_DWORD *)zptr + v17) = v21;
    }
    if ( !v23 )
      break;
    --v23;
    v24 = v22[v23];
  }
  return result;
}