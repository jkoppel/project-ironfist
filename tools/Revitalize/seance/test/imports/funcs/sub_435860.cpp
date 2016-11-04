{
  int v6; // [sp+Ch] [bp-574h]@1
  int v7; // [sp+10h] [bp-570h]@1
  char v8; // [sp+14h] [bp-56Ch]@2
  int v9; // [sp+174h] [bp-40Ch]@1
  int j; // [sp+178h] [bp-408h]@27
  int fd; // [sp+17Ch] [bp-404h]@4
  int i; // [sp+180h] [bp-400h]@7
  char buf[58]; // [sp+184h] [bp-3FCh]@9
  int v14; // [sp+1BEh] [bp-3C2h]@9
  int v15; // [sp+1C2h] [bp-3BEh]@30
  int v16; // [sp+1C6h] [bp-3BAh]@30
  char v17[930]; // [sp+1CAh] [bp-3B6h]@30
  char v18; // [sp+56Ch] [bp-14h]@30

  v6 = a2;
  v7 = a1;
  v9 = 0;
  if ( a4 == 1 )
    sprintf(&v8, "%sSTANDARD.HS", ".\\DATA\\");
  else
    sprintf(&v8, "%sCAMPAIGN.HS", ".\\DATA\\");
  fd = _open(&v8, 32768);
  if ( fd == -1 )
    v9 = 1;
  if ( v9 )
  {
    for ( i = 0; i < 10; ++i )
    {
      memset(&buf[100 * i], 0, 0x64u);
      *(&v14 + 25 * i) = -1;
    }
  }
  else
  {
    for ( i = 0; i < 10; ++i )
      _read(fd, &buf[100 * i], 0x3E8u);
    _close(fd);
  }
  dword_4F74A4 = 1;
  dword_4F74A0 = a4;
  dword_4F749C = -1;
  dword_5247B0 = v7;
  for ( i = 0; i < 10; ++i )
  {
    if ( *(&v14 + 25 * i) <= v7 && a4 == 1
      || *(&v14 + 25 * i) >= v7 && !a4
      || *(&v14 + 25 * i) >= v7 && a4 == 2
      || *(&v14 + 25 * i) == -1 )
    {
      dword_4F749C = i;
      break;
    }
  }
  if ( i >= 10 )
  {
    dword_4F74A4 = 0;
  }
  else
  {
    for ( j = 8; i <= j; --j )
      memcpy(&buf[25 * (4 * j + 4)], &buf[100 * j], 0x64u);
    sub_4CAEF0("Please enter your name for the high score list.", (int)&v18, 16, 0, 0, 1);
    memset(&buf[100 * i], 0, 0x64u);
    strcpy(&buf[100 * i], &v18);
    strcpy(&buf[100 * i + 17], a5);
    *(&v14 + 25 * i) = v7;
    *(&v15 + 25 * i) = v6;
    *(&v16 + 25 * i) = a3;
    v17[100 * i] = gameObject->_10[32];
    if ( !a4 && gameObject->_1[204] )
      v17[100 * i] = 1;
    fd = _open(&v8, 33537, 128);
    if ( fd == -1 )
      sub_436DF0(&v8);
    for ( i = 0; i < 10; ++i )
      _write(fd, &buf[100 * i], 0x64u);
    _close(fd);
  }
  return 0;
}
