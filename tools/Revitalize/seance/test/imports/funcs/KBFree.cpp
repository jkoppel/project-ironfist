{
  signed int v3; // eax@2
  FILE *v4; // ebx@8
  int v5; // eax@11
  signed int v6; // ecx@13
  int v7; // ebx@14
  char *v8; // edx@14
  FILE *v9; // ebp@17
  FILE *v10; // ebx@24
  void *v11; // [sp+10h] [bp-2C4h]@1
  int v12; // [sp+14h] [bp-2C0h]@1
  char OutputString[500]; // [sp+18h] [bp-2BCh]@9
  char v14; // [sp+20Ch] [bp-C8h]@16

  v12 = a2;
  v11 = a1;
  if ( !poolOfMemoryBlockInfos )
  {
    logUpTo7Ints((int)"IME", numLoadedFiles, -999, -999, -999, -999, -999, -999);
    poolOfMemoryBlockInfos = malloc(0x24220u);
    v3 = 0;
    do
    {
      v3 += 74;
      *((_BYTE *)poolOfMemoryBlockInfos + v3 - 74) = 0;
    }
    while ( v3 < 148000 );
  }
  if ( debugLogLevel == 4 )
    logUpTo7Ints((int)"Free ", (int)v11, -999, -999, -999, -999, -999, -999);
  if ( v11 )
  {
    v5 = numLoadedFiles-- - 1;
    if ( numLoadedFiles < 0 )
      logUpTo7Ints((int)"MemEntries Below 0", v5, -999, -999, -999, -999, -999, -999);
    v6 = 0;
    do
    {
      v7 = 74 * v6;
      v8 = (char *)poolOfMemoryBlockInfos + 74 * v6;
      if ( *(void **)(v8 + 1) == v11 )
      {
        if ( debugLogLevel == 4 )
        {
          sprintf(
            &v14,
            "KBFree    Size %d   Ptr %d   File %s  Line %d",
            *(_DWORD *)(v8 + 5),
            v11,
            v8 + 9,
            *(_DWORD *)(v8 + 70));
          if ( debugLogLevel >= 2 )
          {
            v9 = fopen("KB.LOG", "at+");
            if ( v9 )
            {
              strcpy(OutputString, &v14);
              *(_WORD *)&OutputString[strlen(OutputString)] = word_51EFD8;
              fputs(OutputString, v9);
              fclose(v9);
              if ( debugLogLevel == 4 )
                OutputDebugStringA(OutputString);
            }
          }
        }
        *((_BYTE *)poolOfMemoryBlockInfos + v7) = 0;
        v6 = 99999;
        totalSpaceAllocatedByKBAlloc -= *(_DWORD *)((char *)poolOfMemoryBlockInfos + v7 + 5);
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
      sprintf(globBuf, "Bad Delete,  File '%13s'  Line % 4d, ptr %12d", v12, caller_lineno, v11);
      if ( debugLogLevel >= 2 )
      {
        v10 = fopen("KB.LOG", "at+");
        if ( v10 )
        {
          strcpy(OutputString, globBuf);
          *(_WORD *)&OutputString[strlen(OutputString)] = word_51EFD8;
          fputs(OutputString, v10);
          fclose(v10);
          if ( debugLogLevel == 4 )
            OutputDebugStringA(OutputString);
        }
      }
    }
  }
  else
  {
    if ( debugLogLevel >= 2 )
    {
      v4 = fopen("KB.LOG", "at+");
      if ( v4 )
      {
        strcpy(OutputString, "NULL POINTER");
        *(_WORD *)&OutputString[strlen(OutputString)] = word_51EFD8;
        fputs(OutputString, v4);
        fclose(v4);
        if ( debugLogLevel == 4 )
          OutputDebugStringA(OutputString);
      }
    }
  }
}
