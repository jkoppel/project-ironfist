{
  signed int v3; // eax@2
  int v4; // ebx@8
  int v5; // eax@11
  signed int v6; // ecx@13
  int v7; // ebx@14
  char *v8; // edx@14
  int v9; // ebp@17
  int v10; // ebx@24
  int v11; // [sp+10h] [bp-2C4h]@1
  int v12; // [sp+14h] [bp-2C0h]@1
  char OutputString[500]; // [sp+18h] [bp-2BCh]@9
  char v14; // [sp+20Ch] [bp-C8h]@16

  v12 = a2;
  v11 = (int)a1;
  if ( !gpMemEntry )
  {
    LogInt((int)"IME", iMemEntries, -999, -999, -999, -999, -999, -999);
    gpMemEntry = malloc(0x24220u);
    v3 = 0;
    do
    {
      v3 += 74;
      *((char *)gpMemEntry + v3 - 74) = 0;
    }
    while ( v3 < 148000 );
  }
  if ( giDebugLevel == 4 )
    LogInt((int)"Free ", v11, -999, -999, -999, -999, -999, -999);
  if ( v11 )
  {
    v5 = iMemEntries-- - 1;
    if ( iMemEntries < 0 )
      LogInt((int)"MemEntries Below 0", v5, -999, -999, -999, -999, -999, -999);
    v6 = 0;
    do
    {
      v7 = 74 * v6;
      v8 = (char *)gpMemEntry + 74 * v6;
      if ( *(_DWORD *)(v8 + 1) == v11 )
      {
        if ( giDebugLevel == 4 )
        {
          sprintf(
            &v14,
            "KBFree    Size %d   Ptr %d   File %s  Line %d",
            *(_DWORD *)(v8 + 5),
            v11,
            v8 + 9,
            *(_DWORD *)(v8 + 70));
          if ( giDebugLevel >= 2 )
          {
            v9 = fopen("KB.LOG", (int)"at+");
            if ( v9 )
            {
              strcpy(OutputString, &v14);
              *(_WORD *)&OutputString[strlen(OutputString)] = word_51EFD8;
              fputs(OutputString, v9);
              fclose(v9);
              if ( giDebugLevel == 4 )
                OutputDebugStringA(OutputString);
            }
          }
        }
        *((_BYTE *)gpMemEntry + v7) = 0;
        v6 = 99999;
        giTotalMemAllocated -= *(_DWORD *)((char *)gpMemEntry + v7 + 5);
      }
      ++v6;
    }
    while ( v6 < 2000 );
    if ( v6 >= 99999 )
    {
      free(v11);
    }
    else
    {
      sprintf(gText, "Bad Delete,  File '%13s'  Line % 4d, ptr %12d", v12, caller_lineno, v11);
      if ( giDebugLevel >= 2 )
      {
        v10 = fopen("KB.LOG", (int)"at+");
        if ( v10 )
        {
          strcpy(OutputString, gText);
          *(_WORD *)&OutputString[strlen(OutputString)] = word_51EFD8;
          fputs(OutputString, v10);
          fclose(v10);
          if ( giDebugLevel == 4 )
            OutputDebugStringA(OutputString);
        }
      }
    }
  }
  else if ( giDebugLevel >= 2 )
  {
    v4 = fopen("KB.LOG", (int)"at+");
    if ( v4 )
    {
      strcpy(OutputString, "NULL POINTER");
      *(_WORD *)&OutputString[strlen(OutputString)] = word_51EFD8;
      fputs(OutputString, v4);
      fclose(v4);
      if ( giDebugLevel == 4 )
        OutputDebugStringA(OutputString);
    }
  }
}