{
  float v5; // ST24_4@1
  __int16 v6; // fps@1
  char v7; // c0@1
  int result; // eax@2
  float v9; // [sp+20h] [bp-Ch]@1

  v5 = (double)(unsigned __int16)word_4EE2A8[a1] * *(float *)&dword_522BF8;
  UNDEF(v6);
  v9 = (double)(unsigned __int16)word_4EE2A8[a2] / v5;
  if ( v7 )
  {
    *(_DWORD *)a4 = 1;
    *(_DWORD *)a3 = (signed __int64)(1.0 / v9);
    result = curPlayer->resources[a1];
    *(_DWORD *)a5 = result;
  }
  else
  {
    *(_DWORD *)a4 = 0;
    *(_DWORD *)a3 = (signed __int64)(v9 + 0.999);
    result = curPlayer->resources[a1] / *(_DWORD *)a3;
    *(_DWORD *)a5 = result;
  }
  return result;
}
