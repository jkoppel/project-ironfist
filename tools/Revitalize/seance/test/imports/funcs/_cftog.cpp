{
  int v4; // ebx@1
  int v5; // ebp@1
  int v6; // eax@4
  char *result; // eax@6
  int v8; // [sp+10h] [bp-28h]@1
  int v9; // [sp+14h] [bp-24h]@1
  char v10; // [sp+20h] [bp-18h]@1

  _fltout2(*(_DWORD *)a1, *(_DWORD *)(a1 + 4), &v8, &v10);
  v4 = v9 - 1;
  v5 = ((unsigned int)(v8 - 45) < 1) + a2;
  _fptostr(((unsigned int)(v8 - 45) < 1) + a2, a3, &v8);
  if ( v9 - 1 < -4 || a3 <= v9 - 1 )
  {
    result = (char *)_cftoe2(a2, a3, a4, (int)&v8, 1u);
  }
  else
  {
    if ( v4 < v9 - 1 )
    {
      do
        v6 = v5++;
      while ( *(_BYTE *)v6 );
      *(_BYTE *)(v5 - 2) = 0;
    }
    result = _cftof2((char *)a2, a3, (int)&v8, 1);
  }
  return result;
}
