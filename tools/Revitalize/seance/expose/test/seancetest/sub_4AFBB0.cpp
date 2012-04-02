int __stdcall sub_4AFBB0(int a1, signed int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15)
{
  double v15; // st7@112
  double v16; // st7@112
  signed int v17; // eax@112
  double v18; // st7@112
  int result; // eax@112
  char v20; // [sp+3Ch] [bp-60h]@110
  int v21; // [sp+40h] [bp-5Ch]@12
  int v22; // [sp+44h] [bp-58h]@1
  char v23; // [sp+48h] [bp-54h]@105
  int v24; // [sp+4Ch] [bp-50h]@98
  char v25; // [sp+50h] [bp-4Ch]@105
  char v26; // [sp+54h] [bp-48h]@105
  int v27; // [sp+58h] [bp-44h]@86
  char v28; // [sp+5Ch] [bp-40h]@105
  int i; // [sp+60h] [bp-3Ch]@1
  char v30; // [sp+64h] [bp-38h]@105
  int v31; // [sp+68h] [bp-34h]@1
  char v32; // [sp+6Ch] [bp-30h]@112
  int v33; // [sp+88h] [bp-14h]@1
  float v34; // [sp+8Ch] [bp-10h]@105
  int v35; // [sp+90h] [bp-Ch]@96
  int v36; // [sp+94h] [bp-8h]@6
  float v37; // [sp+98h] [bp-4h]@14

  v31 = *(_BYTE *)(a1 + 3);
  v33 = 0;
  v22 = -1;
  for ( i = 19; i < 30; ++i )
  {
    if ( (1 << i) & *(_DWORD *)(a1 + 24) )
    {
      ++v33;
      v22 = i;
    }
  }
  v36 = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( (signed int)*(_WORD *)(a1 + 2 * i + 13) > 0 )
      ++v36;
  }
  if ( a2 )
    v21 = 1;
  else
    v21 = *(_BYTE *)(a1 + 28) + 1;
  v37 = (double)sub_432720(v31, a2, v21);
  if ( a2 >= 25 && a2 <= 29 )
    v37 = v37 - (double)sub_432720(v31, a2 - 5, 1);
  if ( a2 == 30 )
    v37 = v37 - (double)sub_432720(v31, 29, 1);
  if ( !a2 && (signed int)*(_BYTE *)(a1 + 28) > 1 )
    v37 = v37 - (double)sub_432720(v31, 0, *(_BYTE *)(a1 + 28));
  switch ( a2 )
  {
    case 6:
      if ( *(_BYTE *)(a1 + 55) )
        v37 = -99.0;
      goto LABEL_105;
    case 0:
      if ( *(_BYTE *)(a1 + 3) && *(_BYTE *)(a1 + 3) != 1 )
      {
        if ( *(_BYTE *)(a1 + 28) )
        {
          if ( (signed int)*(_BYTE *)(a1 + 28) >= 4 && dword_532C54 < 35
            || (signed int)*(_BYTE *)(a1 + 28) >= 3 && dword_532C54 < 25
            || (signed int)*(_BYTE *)(a1 + 28) >= 2 && dword_532C54 < 15 )
            v37 = v37 * 0.55;
        }
        else
        {
          v37 = v37 * 1.2;
        }
      }
      else
      {
        if ( ((signed int)*(_BYTE *)(a1 + 28) < 4 || dword_532C54 >= 40)
          && ((signed int)*(_BYTE *)(a1 + 28) < 3 || dword_532C54 >= 30)
          && ((signed int)*(_BYTE *)(a1 + 28) < 2 || dword_532C54 >= 20) )
          v37 = v37 * 0.65;
        else
          v37 = v37 * 0.4;
      }
      goto LABEL_105;
    case 1:
      if ( *(_BYTE *)(a1 + 3) == 5 && *(_BYTE *)(a1 + 26) & 0x20 )
      {
        v37 = 1500.0;
      }
      else
      {
        if ( dword_532C54 < 21 )
          v37 = 0.0;
      }
      goto LABEL_105;
    case 7:
      if ( dword_532C54 < 3 && !(*(_BYTE *)(a1 + 26) & 0x20) )
        v37 = 0.0;
      goto LABEL_105;
    case 10:
      if ( dword_532C54 < 21 )
        v37 = 0.0;
      goto LABEL_105;
    case 11:
      if ( gameObject->day < 6 )
        v37 = 0.0;
      goto LABEL_105;
    case 8:
    case 9:
    case 12:
    case 15:
      goto LABEL_63;
    case 13:
      if ( !*(_BYTE *)(a1 + 3) || *(_BYTE *)(a1 + 3) == 2 || *(_BYTE *)(a1 + 3) == 1 || *(_BYTE *)(a1 + 3) == 5 )
        goto LABEL_63;
      goto LABEL_105;
    case 3:
      v37 = 0.0;
      goto LABEL_105;
    case 4:
      v37 = (*(float *)&curPlayer->_4[20] + 0.66) * v37;
      v37 = (*(float *)&curPlayer->_4[24] * 2.0 + 0.33) * v37;
      v37 = ((double)v33 * 0.33 + 0.66) * v37;
      if ( (*(_BYTE *)(a1 + 3) || !(*(_BYTE *)(a1 + 26) & 0x10)) && gameObject->day < 6 )
        v37 = 0.0;
      goto LABEL_105;
    case 2:
      if ( *(_BYTE *)(a1 + 3) != 5 )
      {
        if ( !*(_BYTE *)(a1 + 3) && *(_BYTE *)(a1 + 26) & 0x20 || *(_BYTE *)(a1 + 3) == 2 && *(_BYTE *)(a1 + 26) & 0x20 )
        {
          v37 = 1000.0;
        }
        else
        {
LABEL_63:
          if ( dword_532C54 < 16 )
            v37 = 0.0;
        }
      }
      goto LABEL_105;
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
      if ( v36 == 5 )
      {
        v27 = 0;
        for ( i = 0; i < 5; ++i )
        {
          if ( LOBYTE((&buildingShortNames[3 * *(_BYTE *)(a1 + 3) + 27])[a2 + 1]) == *(_BYTE *)(i + a1 + 8) )
            v27 = 1;
        }
        if ( !v27 )
          goto LABEL_105;
      }
      v37 = (*(float *)&curPlayer->_4[20] + 0.66) * v37;
      v37 = (*(float *)&curPlayer->_4[24] * 2.0 + 0.33) * v37;
      v37 = (1.0 - (double)sub_418EF0((int)curPlayer, v31, a2, 0) * 0.05) * v37;
      if ( a2 - 19 < v22 )
        v37 = (1.66 - (double)v33 * 0.33) * v37;
      if ( *(_BYTE *)(a1 + 24) & 0x10 )
        v37 = v37 * 1.1;
      v35 = 0;
      break;
    case 14:
      goto LABEL_105;
  }
  while ( v35 < 12 )
  {
    v24 = dwelling_creatures[*(_BYTE *)(a1 + 3)][v35];
    if ( (1 << (v35 + 19)) & *(_DWORD *)(a1 + 24)
      && (signed int)*(_WORD *)(a1 + 2 * v35 + 30) > 0
      && (double)creature_table[LOBYTE((&buildingShortNames[3 * *(_BYTE *)(a1 + 3) + 27])[a2 + 1])].fight_value_aux < (double)creature_table[v24].fight_value_aux * 1.2 )
    {
      v37 = 0.0;
      break;
    }
    ++v35;
  }
LABEL_105:
  sub_4B1110(a1, 0, (int)&v30, (int)&v28, (int)&v26, (int)&v25, (int)&v23, (int)&v34);
  v37 = (1.0 - v34 * 3.0) * v37;
  if ( *(_BYTE *)(a1 + 57) != curPlayerIdx )
    v37 = v37 * 0.85;
  if ( v37 < 0.0 )
    v37 = 0.0;
  if ( a2 )
    v20 = 0;
  else
    v20 = *(_BYTE *)(a1 + 28);
  sub_432120(v31, a2, &v32, v20);
  v15 = sub_4B2A50((int)&v32);
  v16 = v15 * v37;
  v37 = v16;
  *(_DWORD *)a3 = (signed __int64)v16;
  v17 = sub_4B13F0((int)&v32);
  v18 = v37 / (double)v17;
  result = a4;
  *(float *)a4 = v18;
  return result;
}
