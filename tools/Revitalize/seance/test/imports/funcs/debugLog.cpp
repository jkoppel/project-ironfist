{
  const char *msga; // edi@1
  int v2; // ebx@2
  char OutputString[500]; // [sp+Ch] [bp-1F4h]@3

  msga = (const char *)msg;
  if ( debugLogLevel >= 2 )
  {
    v2 = fopen("KB.LOG", (int)"at+");
    if ( v2 )
    {
      strcpy(OutputString, msga);
      *(_WORD *)&OutputString[strlen(OutputString)] = word_51EFD8;
      fputs(OutputString, v2);
      fclose(v2);
      if ( debugLogLevel == 4 )
        OutputDebugStringA(OutputString);
    }
  }
}
