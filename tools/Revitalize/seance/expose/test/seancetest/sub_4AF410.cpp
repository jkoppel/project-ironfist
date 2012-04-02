void __stdcall sub_4AF410(int a1, int a2, __int64 a3, int a4, int a5, int a6, int a7, int a8, int a9, int *a10, int *a11, int *a12, int *a13)
{
  float v13; // ST9C_4@22
  float v14; // ST94_4@32
  float v15; // [sp+74h] [bp-40h]@58
  float v16; // [sp+78h] [bp-3Ch]@3
  float v17; // [sp+7Ch] [bp-38h]@3
  float v18; // [sp+80h] [bp-34h]@8
  float v19; // [sp+84h] [bp-30h]@19
  float v20; // [sp+8Ch] [bp-28h]@33
  signed int i; // [sp+90h] [bp-24h]@37
  signed int j; // [sp+90h] [bp-24h]@48
  float v23; // [sp+9Ch] [bp-18h]@7
  int v24; // [sp+A0h] [bp-14h]@1
  float v25; // [sp+A8h] [bp-Ch]@1
  float v26; // [sp+ACh] [bp-8h]@1
  int v27; // [sp+B0h] [bp-4h]@1

  v24 = 0;
  v27 = 0;
  v25 = (double)getArmyStrength((ArmyInfo *)a1, (Hero *)a2, 1, 0, 0, a5);
  v26 = (double)getArmyStrength((ArmyInfo *)a3, HIDWORD(a3), 1, a5, a6, 0);
  if ( a4 )
    v26 = (double)getArmyStrength((ArmyInfo *)a4, 0, 1, 0, 0, 0) + v26;
  v16 = (double)getArmyStrength((ArmyInfo *)a1, (Hero *)a2, 0, 0, 0, 0);
  v17 = (double)getArmyStrength((ArmyInfo *)a3, HIDWORD(a3), 0, 0, 0, 0);
  if ( a4 )
    v17 = (double)getArmyStrength((ArmyInfo *)a4, 0, 0, 0, 0, 0) + v17;
  if ( a5 )
    v26 = v26 * 1.11;
  v23 = v26;
  if ( a7 == -1 )
  {
    v18 = ((double)gameObject->difficulty * 0.15 + 0.7) * v25;
    if ( !curPlayer->personality )
      v18 = v18 * 1.08;
  }
  else
  {
    v18 = v25;
    if ( dword_524810[a7] )
    {
      v23 = v26 * 1.14;
    }
    else
    {
      if ( !curPlayer->personality )
        v18 = v25 * 1.08;
    }
  }
  if ( v18 < 1.0 )
    v18 = 1.0;
  if ( v23 < 1.0 )
    v23 = 1.0;
  v19 = 2.75;
  if ( v18 > 1000000.0 || v23 > 1000000.0 )
    v19 = 2.0;
  v13 = pow(v18, v19);
  *(float *)a8 = v13 / (pow(v23, v19) + v13);
  if ( *(float *)a8 >= 0.08 )
  {
    if ( *(float *)a8 >= 0.12 )
    {
      if ( *(float *)a8 >= 0.2 )
      {
        if ( *(float *)a8 >= 0.3 )
        {
          if ( *(float *)a8 < 0.4 )
            *(float *)a8 = *(float *)a8 - 0.02;
        }
        else
        {
          *(float *)a8 = *(float *)a8 - 0.04;
        }
      }
      else
      {
        *(float *)a8 = *(float *)a8 - 0.05;
      }
    }
    else
    {
      *(float *)a8 = *(float *)a8 - 0.07000000000000001;
    }
  }
  else
  {
    *(_DWORD *)a8 = 0;
  }
  *(_DWORD *)a9 = (signed __int64)((1.0 - *(float *)a8) * v16);
  *a10 = (signed __int64)(v17 * *(float *)a8);
  *a11 = (signed __int64)((1.0 - *(float *)a8) * v16 + (double)*(signed int *)a9 * *(float *)a8);
  *a12 = (signed __int64)((1.0 - *(float *)a8) * (double)*a10 + v17 * *(float *)a8);
  v14 = 1.33 - *(float *)&curPlayer->_4[24];
  *a13 = (signed __int64)((double)-*a11 * v14 * v14);
  if ( a7 >= 0 )
  {
    v20 = *(float *)&curPlayer->_4[24] + 0.66;
    if ( dword_524810[a7] )
      *a13 = (signed __int64)((double)*a12 * v20 * v20 * *(float *)&dword_51D5C0 + (double)*a13);
    else
      *a13 = (signed __int64)((double)*a12 * *(float *)&dword_51D5C4 * v20 * v20 + (double)*a13);
  }
  *a13 = (signed __int64)((double)*a13 * *(float *)&curPlayer->_4[100]);
  if ( a2 )
  {
    for ( i = 0; i < 14; ++i )
    {
      if ( (signed int)*(_BYTE *)(i + a2 + 213) >= 0 )
      {
        if ( (signed int)*(_BYTE *)(i + a2 + 213) < 37 )
          v24 += dword_4F2050[*(_BYTE *)(a2 + i + 213)];
      }
    }
    if ( gameObject->winConditionType == 2 && *(_BYTE *)(a2 + 2) == gameObject->winConditionArgument )
      v24 += 50000;
    *a13 = (signed __int64)((double)*a13 - (1.0 - *(float *)a8) * (double)(v24 + 1400));
    *a13 = (signed __int64)((double)sub_4290E0(a3, SHIDWORD(a3)) * *(float *)(a2 + 232) * *(float *)a8 * 0.8
                          + (double)*a13);
  }
  if ( HIDWORD(a3) )
  {
    for ( j = 0; j < 14; ++j )
    {
      if ( (signed int)*(_BYTE *)(j + HIDWORD(a3) + 213) >= 0 && (signed int)*(_BYTE *)(j + HIDWORD(a3) + 213) < 37 )
        v27 += dword_4F2050[*(_BYTE *)(HIDWORD(a3) + j + 213)];
    }
    if ( gameObject->_2[0] == 2 && *(_BYTE *)(HIDWORD(a3) + 2) == *(_WORD *)&gameObject->_2[1] )
      v27 += 50000;
    if ( dword_524810[*(_BYTE *)(HIDWORD(a3) + 3)] )
      v15 = *(float *)&dword_51D5C0;
    else
      v15 = *(float *)&dword_51D5C4;
    *a13 = (signed __int64)((double)(v27 + 1250) * v15 * *(float *)a8 + (double)*a13);
  }
  if ( debugLogLevel >= 9 )
  {
    logUpTo7Ints(
      (int)"POBA",
      (signed __int64)v18,
      (signed __int64)v23,
      (signed __int64)(*(float *)&curPlayer->_4[24] * 100.0),
      0,
      v24,
      v27,
      (signed __int64)*(float *)&curPlayer->_4[100]);
    logUpTo7Ints(
      (int)"POB",
      (signed __int64)v25,
      (signed __int64)v26,
      (signed __int64)(*(float *)a8 * 100.0),
      *a10,
      *a11,
      *a12,
      *a13);
  }
}
