{
  int result; // eax@2
  unsigned __int8 v1; // ST0C_1@3
  int v2; // eax@3
  int v3; // eax@3
  int v4; // eax@3
  int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; ; ++i )
  {
    result = i;
    if ( lastPP <= i )
      break;
    v1 = *((_DWORD *)words + i) >> 24;
    v2 = NORMALISELO(i - 1);
    SETSECOND(v2, v1);
    v3 = NORMALISELO(i - 2);
    SETTHIRD(v3, v1);
    v4 = NORMALISELO(i - 3);
    SETFOURTH(v4, v1);
  }
  return result;
}