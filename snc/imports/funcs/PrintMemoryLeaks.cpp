{
  signed int v0; // ebx@3
  int v1; // ebp@6
  char OutputString[500]; // [sp+10h] [bp-1F4h]@7

  if ( giDebugLevel >= 1 && gpMemEntry )
  {
    v0 = 0;
    LogInt((int)"Total Memory Leaks", iMemEntries, -999, -999, -999, -999, -999, -999);
    do
    {
      if ( *((_BYTE *)gpMemEntry + v0) )
      {
        sprintf(
          gText,
          "Memory Leak,  File '%13s'  Line % 4d, ptr %12d   size %6d",
          (char *)gpMemEntry + v0 + 9,
          *(_DWORD *)((char *)gpMemEntry + v0 + 70),
          *(_DWORD *)((char *)gpMemEntry + v0 + 1),
          *(_DWORD *)((char *)gpMemEntry + v0 + 5));
        if ( giDebugLevel >= 2 )
        {
          v1 = fopen("KB.LOG", (int)"at+");
          if ( v1 )
          {
            strcpy(OutputString, gText);
            *(_WORD *)&OutputString[strlen(OutputString)] = word_51EFD8;
            fputs(OutputString, v1);
            fclose(v1);
            if ( giDebugLevel == 4 )
              OutputDebugStringA(OutputString);
          }
        }
      }
      v0 += 74;
    }
    while ( v0 < 148000 );
  }
}