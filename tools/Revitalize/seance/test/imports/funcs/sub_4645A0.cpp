{
  signed int v0; // eax@9
  int v1; // eax@12
  char v3; // [sp+10h] [bp-18h]@9
  unsigned int v4; // [sp+24h] [bp-4h]@1

  v4 = getTickCount() % 0xF4240u;
  sprintf(byte_526B70, "%06d", v4);
  dword_525294 = -1;
  dword_526304 = 0;
  dword_525290 = 0;
  do
  {
    if ( sub_464980() )
    {
      byte_526DC8[dword_512308] = 0;
      if ( dword_512308 != 10 || strncmp(byte_526DC8, "ID", 2u) )
        continue;
      if ( !strncmp(&byte_526DC8[2], byte_526B70, 6u) )
      {
        sprintf(globBuf, "Duplicate ID Strings!\nSorry Please Try Again\n");
        sub_435D90(globBuf);
        sub_46D360();
      }
      strncpy(byte_5252A0, &byte_526DC8[2], 6u);
      dword_526304 = byte_526DD1 - 48;
      dword_525290 = byte_526DD1 - 48 + 1;
      dword_525294 = -1;
    }
    dword_52529C = getTickCount();
    if ( dword_52529C / 1000 != dword_525294 / 1000 )
    {
      dword_525294 = dword_52529C;
      sprintf(&v3, "ID%s_%i", byte_526B70, dword_525290);
      v0 = strlen(&v3);
      sub_464AB0((int)&v3, v0);
    }
    yieldToGlobalUpdater();
  }
  while ( dword_525290 < 2 );
  do
    v1 = sub_464980();
  while ( (_BYTE)v1 );
  return v1;
}
