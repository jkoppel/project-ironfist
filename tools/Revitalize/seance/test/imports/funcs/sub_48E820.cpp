{
  int v16; // [sp+10h] [bp-5Ch]@13
  int i; // [sp+18h] [bp-54h]@17
  int j; // [sp+18h] [bp-54h]@48
  int k; // [sp+18h] [bp-54h]@52
  signed int l; // [sp+18h] [bp-54h]@55
  int m; // [sp+18h] [bp-54h]@60
  signed int n; // [sp+18h] [bp-54h]@77
  signed int ii; // [sp+18h] [bp-54h]@80
  int v24[5]; // [sp+1Ch] [bp-50h]@79
  int v25; // [sp+30h] [bp-3Ch]@84
  int v26[5]; // [sp+34h] [bp-38h]@79
  int v27; // [sp+48h] [bp-24h]@9
  int v28; // [sp+4Ch] [bp-20h]@11
  int v29; // [sp+50h] [bp-1Ch]@55
  int v30; // [sp+58h] [bp-14h]@62
  int v31; // [sp+5Ch] [bp-10h]@66
  int v32; // [sp+60h] [bp-Ch]@64
  int v33; // [sp+64h] [bp-8h]@66
  int v34; // [sp+68h] [bp-4h]@71

  sub_450880(this);
  if ( (_DWORD)a8 == -1 )
  {
    a8 = a6;
  }
  else
  {
    *(_QWORD *)&this->field_2B2 = a8;
    this->field_2BA = *(_DWORD *)(a2 + 25) < (signed int)a8;
    if ( sub_452F20(this, 0) )
      sub_447A00(this, 0, 0);
    this->field_2B2 = -1;
  }
  memset(dword_5247BC, -1, 5u);
  memset((char *)dword_5247BC + 5, 0, 0xAu);
  v27 = 5 - a11 - a14;
  if ( v27 < 1 )
    v27 = 1;
  v28 = 0;
  setRandomSeed(a8 + HIDWORD(a8));
  if ( v27 == 5 && !(creature_table[a3].creature_flags & 4) )
  {
    v16 = nextRandomInt(0, 100);
    if ( v16 >= 25 )
    {
      if ( v16 < 50 )
        v27 = 4;
    }
    else
    {
      v27 = 3;
    }
  }
  for ( i = 0; i < v27; ++i )
  {
    if ( v27 >> 1 != i
      || a3 != 1
      && a3 != 3
      && a3 != 5
      && a3 != 7
      && a3 != 9
      && a3 != 12
      && a3 != 15
      && a3 != 17
      && a3 != 21
      && a3 != 23
      && a3 != 25
      && a3 != 32
      && a3 != 35
      && a3 != 36
      && a3 != 40
      && a3 != 43
      && a3 != 45
      && a3 != 48
      && a3 != 50
      && a3 != 52
      && a3 != 54
      || nextRandomInt(0, 100) >= 50
      || a10
      || a13 )
      *((_BYTE *)dword_5247BC + i + v28) = a3;
    else
      *((_BYTE *)dword_5247BC + i + v28) = a3 + 1;
    *(_WORD *)((char *)dword_5247BC + 2 * (i + v28) + 5) = a4 / v27 + (a4 % v27 > i);
  }
  v28 += v27;
  if ( a11 )
  {
    v27 = a11;
    for ( j = 0; j < v27; ++j )
    {
      *((_BYTE *)dword_5247BC + j + v28) = a9;
      *(_WORD *)((char *)dword_5247BC + 2 * (j + v28) + 5) = a10 / v27 + (a10 % v27 > j);
    }
  }
  v28 += v27;
  if ( a14 )
  {
    v27 = a14;
    for ( k = 0; k < v27; ++k )
    {
      *((_BYTE *)dword_5247BC + k + v28) = a12;
      *(_WORD *)((char *)dword_5247BC + 2 * (k + v28) + 5) = a13 / v27 + (a10 % v27 > k);
    }
  }
  v29 = v27;
  for ( l = 0; l < 5; ++l )
  {
    if ( (signed int)*(_WORD *)((char *)dword_5247BC + 2 * l + 5) <= 0 )
      *((_BYTE *)dword_5247BC + l) = -1;
  }
  for ( m = 0; m < 5; ++m )
    *(&v30 + m) = m;
  switch ( v29 )
  {
    case 1:
      v32 = 0;
      v30 = 2;
      break;
    case 2:
      v31 = 1;
      v33 = 0;
      v30 = 3;
      break;
    case 3:
      v30 = 3;
      v31 = 0;
      v32 = 1;
      v33 = 2;
      break;
    default:
      if ( a14 != 1 || a11 != 1 )
      {
        if ( a14 != 1 || a11 != 2 )
        {
          if ( a11 == 2 )
          {
            v31 = 4;
            v34 = 1;
          }
        }
        else
        {
          v31 = 2;
          v32 = 4;
          v33 = 3;
          v34 = 1;
        }
      }
      else
      {
        v31 = 4;
        v34 = 1;
      }
      break;
  }
  for ( n = 0; n < 5; ++n )
  {
    v26[n] = *((_BYTE *)dword_5247BC + n);
    v24[n] = *(_WORD *)((char *)dword_5247BC + 2 * n + 5);
  }
  for ( ii = 0; ii < 5; ++ii )
  {
    *((_BYTE *)dword_5247BC + ii) = LOBYTE(v26[*(&v30 + ii)]);
    *(_WORD *)((char *)dword_5247BC + 2 * ii + 5) = v24[*(&v30 + ii)];
  }
  if ( a7 )
    v25 = sub_4938B0(this, a8, 0, dword_5247BC, 0, a2, (const void *)(a2 + 101), a6, SBYTE4(a6), a8 + HIDWORD(a8), 1);
  else
    v25 = sub_4938B0(this, a8, a2, (const void *)(a2 + 101), 0, 0, dword_5247BC, a6, SBYTE4(a6), a8 + HIDWORD(a8), 1);
  sub_450820((int)this, 0);
  return v25;
}
