{
  signed int v4; // eax@1
  int v5; // edx@1
  int v6; // eax@1
  __int64 v8; // [sp+Ch] [bp-28h]@1
  int v9; // [sp+14h] [bp-20h]@1
  __int16 v10; // [sp+18h] [bp-1Ch]@1
  char v11; // [sp+1Ah] [bp-1Ah]@1
  char v12; // [sp+1Ch] [bp-18h]@1

  __dtold(&v8, &a1);
  v4 = _I10_OUTPUT(v8, v9, 17, 0, (int)&v10);
  v5 = a3;
  *(_DWORD *)(a3 + 8) = v4;
  v6 = v10;
  *(_DWORD *)v5 = v11;
  *(_DWORD *)(v5 + 4) = v6;
  *(_DWORD *)(v5 + 12) = strcpy(a4, &v12);
  return v5;
}