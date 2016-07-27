{
  DWORD v3; // ebx@1
  LPVOID result; // eax@2
  signed int v5; // eax@4
  LPVOID v6; // ebp@6
  signed int v7; // ecx@8
  int v8; // edx@9
  char *v9; // eax@9
  const char *v10; // edi@10
  unsigned int v11; // ecx@10
  int v12; // ebx@14
  char v13[4]; // [sp+10h] [bp-2BCh]@1
  char OutputString[4]; // [sp+D8h] [bp-1F4h]@10

  *(_DWORD *)v13 = a2;
  v3 = a1;
  if ( a1 )
  {
    if ( !poolOfMemoryBlockInfos )
    {
      logUpTo7Ints((int)"IME", numLoadedFiles, -999, -999, -999, -999, -999, -999);
      poolOfMemoryBlockInfos = malloc(0x24220u);
      v5 = 0;
      do
      {
        v5 += 74;
        *((_BYTE *)poolOfMemoryBlockInfos + v5 - 74) = 0;
      }
      while ( v5 < 148000 );
    }
    totalSpaceAllocatedByKBAlloc += v3;
    v6 = malloc(v3);
    if ( !v6 )
      fatalOutOfMemoryError();
    v7 = 0;
    ++numLoadedFiles;
    do
    {
      v8 = 74 * v7;
      v9 = (char *)poolOfMemoryBlockInfos + 74 * v7;
      if ( !*v9 )
      {
        *v9 = 1;
        v10 = *(const char **)v13;
        *(_DWORD *)((char *)poolOfMemoryBlockInfos + v8 + 1) = v6;
        *(_DWORD *)((char *)poolOfMemoryBlockInfos + v8 + 5) = v3;
        v11 = strlen(v10) + 1;
        *(_DWORD *)OutputString = v11;
        memcpy((char *)poolOfMemoryBlockInfos + v8 + 9, v10, v11);
        *(_DWORD *)((char *)poolOfMemoryBlockInfos + v8 + 70) = caller_lineno;
        v7 = 99999;
      }
      ++v7;
    }
    while ( v7 < 2000 );
    if ( debugLogLevel == 4 )
    {
      sprintf(v13, "KBAlloc    Size %d   Ptr %d   File %s  Line %d", v3, v6, *(_DWORD *)v13, caller_lineno);
      if ( debugLogLevel >= 2 )
      {
        v12 = fopen("KB.LOG", (int)"at+");
        if ( v12 )
        {
          strcpy(OutputString, v13);
          *(_WORD *)&OutputString[strlen(OutputString)] = word_51EFD8;
          fputs(OutputString, v12);
          fclose(v12);
          if ( debugLogLevel == 4 )
            OutputDebugStringA(OutputString);
        }
      }
    }
    result = v6;
  }
  else
  {
    result = 0;
  }
  return result;
}
