void __cdecl sub_4C8D10()
{
  signed int v0; // ebx@3
  FILE *v1; // ebp@6
  char OutputString[500]; // [sp+10h] [bp-1F4h]@7

  if ( debugLogLevel >= 1 && poolOfMemoryBlockInfos )
  {
    v0 = 0;
    logUpTo7Ints((int)"Total Memory Leaks", numLoadedFiles, -999, -999, -999, -999, -999, -999);
    do
    {
      if ( *((_BYTE *)poolOfMemoryBlockInfos + v0) )
      {
        sprintf(
          globBuf,
          "Memory Leak,  File '%13s'  Line % 4d, ptr %12d   size %6d",
          (char *)poolOfMemoryBlockInfos + v0 + 9,
          *(_DWORD *)((char *)poolOfMemoryBlockInfos + v0 + 70),
          *(_DWORD *)((char *)poolOfMemoryBlockInfos + v0 + 1),
          *(_DWORD *)((char *)poolOfMemoryBlockInfos + v0 + 5));
        if ( debugLogLevel >= 2 )
        {
          v1 = fopen("KB.LOG", "at+");
          if ( v1 )
          {
            strcpy(OutputString, globBuf);
            *(_WORD *)&OutputString[strlen(OutputString)] = word_51EFD8;
            fputs(OutputString, v1);
            fclose(v1);
            if ( debugLogLevel == 4 )
              OutputDebugStringA(OutputString);
          }
        }
      }
      v0 += 74;
    }
    while ( v0 < 148000 );
  }
}
