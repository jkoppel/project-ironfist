signed __int64 __stdcall sub_4B0CF0(int a1, int a2, int a3, int a4)
{
  signed __int64 result; // qax@22
  int v5; // [sp+2Ch] [bp-30h]@1
  signed int v6; // [sp+2Ch] [bp-30h]@8
  signed int v7; // [sp+2Ch] [bp-30h]@15
  signed int i; // [sp+34h] [bp-28h]@1
  bool v9; // [sp+38h] [bp-24h]@12
  signed int v10; // [sp+3Ch] [bp-20h]@1
  int v11; // [sp+40h] [bp-1Ch]@1
  int v12; // [sp+44h] [bp-18h]@1
  int v13; // [sp+48h] [bp-14h]@1
  int v14; // [sp+4Ch] [bp-10h]@1
  int v15; // [sp+50h] [bp-Ch]@1
  int v16; // [sp+54h] [bp-8h]@1
  int v17; // [sp+58h] [bp-4h]@1

  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 2500;
  v10 = sub_4B13F0((int)&v11);
  v5 = *(_DWORD *)(a2 + 57) + 2000;
  for ( i = 0; i < 14; ++i )
  {
    if ( (signed int)*(_BYTE *)(i + a2 + 213) >= 0 && (signed int)*(_BYTE *)(i + a2 + 213) < 82 )
    {
      if ( *(_BYTE *)(i + a2 + 213) != 81 )
        v5 += dword_4F2050[*(_BYTE *)(i + a2 + 213)];
    }
  }
  v6 = (signed __int64)((*(float *)&curPlayer->_4[28] + 1.0 - *(float *)&curPlayer->_4[24])
                      * (double)(*(_DWORD *)(a2 + 57) / 2 + v5));
  v9 = *(_BYTE *)(a2 + 23) == 2 || *(_BYTE *)(a2 + 23) == 3 || *(_BYTE *)(a2 + 23) == 4 || *(_BYTE *)(a2 + 23) == 5;
  if ( *(_BYTE *)(a1 + 3) == *(_BYTE *)(a2 + 23) )
  {
    v7 = (signed __int64)((0.16 + 1.0) * (double)v6);
  }
  else
  {
    if ( ((signed int)*(_BYTE *)(a1 + 28) < 2 || !v9) && ((signed int)*(_BYTE *)(a1 + 28) >= 2 || v9) )
      v7 = (signed __int64)((1.0 - 0.16 / 2.0) * (double)v6);
    else
      v7 = (signed __int64)((0.16 / 2.0 + 1.0) * (double)v6);
  }
  result = (signed __int64)(sub_4B2A50((int)&v11) * (double)v7);
  *(float *)a4 = (double)(signed int)result / (double)v10;
  *(_DWORD *)a3 = result;
  return result;
}
