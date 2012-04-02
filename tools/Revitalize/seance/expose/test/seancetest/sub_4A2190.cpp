int __stdcall sub_4A2190(int a1)
{
  int v1; // ebp@0
  int result; // eax@1
  int v3; // ST6C_4@2
  int v4; // eax@2
  int v5; // ST34_4@12
  int v6; // ST30_4@12
  float v7; // ST68_4@12
  float v8; // [sp+4Ch] [bp-28h]@17
  signed int v9; // [sp+54h] [bp-20h]@9
  int v10; // [sp+58h] [bp-1Ch]@6
  int v11; // [sp+58h] [bp-1Ch]@7
  signed int v12; // [sp+5Ch] [bp-18h]@2

  result = a1;
  if ( !*(_DWORD *)(a1 + 68) )
  {
    v3 = abs(*(_DWORD *)(a1 + 8) - *(_DWORD *)(a1 + 44));
    v4 = abs(*(_DWORD *)(a1 + 12) - *(_DWORD *)(a1 + 48));
    v12 = (signed __int64)sqrt((double)(v4 * v4 + v3 * v3));
    if ( *(_DWORD *)(a1 + 100) >= v12 )
      *(float *)(a1 + 112) = (double)(*(_DWORD *)(a1 + 100) - v12) / (double)*(signed int *)(a1 + 100);
    else
      *(_DWORD *)(a1 + 112) = 0;
    if ( *(_DWORD *)(a1 + 92) != *(_DWORD *)(a1 + 96) )
    {
      v10 = *(_DWORD *)(a1 + 96) - *(_DWORD *)(a1 + 92);
      if ( v10 <= 0 )
        v11 = v10 - 1;
      else
        v11 = v10 + 1;
      v9 = (unsigned __int64)(signed __int64)((double)v11 * *(float *)(a1 + 112)) + *(_DWORD *)(a1 + 92);
      if ( v9 < 1 )
        v9 = 1;
      *(_DWORD *)(a1 + 20) = v9;
    }
    *(_DWORD *)(a1 + 76) = -(*(_DWORD *)(a1 + 20) >> 1);
    *(_DWORD *)(a1 + 80) = *(_DWORD *)(a1 + 76) + *(_DWORD *)(a1 + 20) - 1;
    v5 = *(_DWORD *)(a1 + 12) - *(_DWORD *)(a1 + 48);
    v6 = *(_DWORD *)(a1 + 8) - *(_DWORD *)(a1 + 44);
    *(float *)(a1 + 56) = atan2(
                            v1,
                            COERCE_UNSIGNED_INT64((double)v6),
                            COERCE_UNSIGNED_INT64((double)v6) >> 32,
                            COERCE_UNSIGNED_INT64((double)v5),
                            COERCE_UNSIGNED_INT64((double)v5) >> 32);
    v7 = (double)((*(_DWORD *)(a1 + 108) + *(_DWORD *)(a1 + 104)) / 200);
    *(float *)(a1 + 60) = (2.5 - *(float *)(a1 + 112)) / 2.0 * v7 + *(float *)(a1 + 56);
    if ( *(_DWORD *)(a1 + 104) || (result = a1, *(_DWORD *)(a1 + 108)) )
    {
      if ( (double)v12 > (double)*(signed int *)(a1 + 32) * 1.5 || (result = a1, *(_DWORD *)(a1 + 116)) )
      {
        if ( *(_DWORD *)(a1 + 104) == *(_DWORD *)(a1 + 108) )
          v8 = (double)*(signed int *)(a1 + 104) / 100.0;
        else
          v8 = (double)unseededNextRand(*(_DWORD *)(a1 + 104), *(_DWORD *)(a1 + 108)) / 100.0;
        result = a1;
        *(float *)(a1 + 56) = (2.0 - *(float *)(a1 + 112)) / 1.5 * v8 + *(float *)(a1 + 56);
      }
    }
  }
  return result;
}
