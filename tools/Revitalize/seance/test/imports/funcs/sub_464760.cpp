{
  unsigned int v0; // ST20_4@2
  signed int v2; // eax@12
  char v3; // [sp+14h] [bp-14h]@12

  if ( dword_526314 )
  {
    if ( dword_526314 == 1 )
    {
      if ( sub_464980() )
      {
        byte_526DC8[dword_512308] = 0;
        if ( dword_512308 != 10 )
          return 0;
        if ( strncmp(byte_526DC8, "ID", 2u) )
          return 0;
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
        v2 = strlen(&v3);
        sub_464AB0((int)&v3, v2);
      }
      if ( dword_525290 >= 2 )
        ++dword_526314;
    }
    else
    {
      if ( dword_526314 == 2 && !sub_464980() )
        return 1;
    }
  }
  else
  {
    v0 = getTickCount() % 0xF4240u;
    sprintf(byte_526B70, "%06d", v0);
    dword_525294 = -1;
    dword_526304 = 0;
    dword_525290 = 0;
    ++dword_526314;
  }
  return 0;
}
