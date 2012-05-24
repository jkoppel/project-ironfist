// Debug-logs a string followed by 7 integers.
// ;To log less than 7, fill some of the arguments with -999.
// ;What logging is done depends on debugLogLevel
void __fastcall logUpTo7Ints(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // ebx@15
  char v9; // [sp+10h] [bp-2BCh]@2
  char OutputString[500]; // [sp+D8h] [bp-1F4h]@16

  if ( a8 == -999 )
  {
    if ( a7 == -999 )
    {
      if ( a6 == -999 )
      {
        if ( a5 == -999 )
        {
          if ( a4 == -999 )
          {
            if ( a3 == -999 )
              sprintf(&v9, "%s : % 8d", a1, a2);
            else
              sprintf(&v9, "%s : % 8d % 8d", a1, a2, a3);
          }
          else
          {
            sprintf(&v9, "%s : % 8d % 8d % 8d", a1, a2, a3, a4);
          }
        }
        else
        {
          sprintf(&v9, "%s : % 8d % 8d % 8d % 8d", a1, a2, a3, a4, a5);
        }
      }
      else
      {
        sprintf(&v9, "%s : % 8d % 8d % 8d % 8d % 8d", a1, a2, a3, a4, a5, a6);
      }
    }
    else
    {
      sprintf(&v9, "%s : % 8d % 8d % 8d % 8d % 8d % 8d", a1, a2, a3, a4, a5, a6, a7);
    }
  }
  else
  {
    sprintf(&v9, "%s : % 8d % 8d % 8d % 8d % 8d % 8d % 8d", a1, a2, a3, a4, a5, a6, a7, a8);
  }
  if ( debugLogLevel >= 2 )
  {
    v8 = fopen("KB.LOG", (int)"at+");
    if ( v8 )
    {
      strcpy(OutputString, &v9);
      *(_WORD *)&OutputString[strlen(OutputString)] = word_51EFD8;
      fputs(OutputString, v8);
      fclose(v8);
      if ( debugLogLevel == 4 )
        OutputDebugStringA(OutputString);
    }
  }
}
