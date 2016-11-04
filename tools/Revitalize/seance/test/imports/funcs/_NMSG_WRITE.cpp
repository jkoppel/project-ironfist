{
  int v1; // ecx@1
  unsigned int result; // eax@1
  int v3; // ebx@4
  char *v4; // ebp@11
  HANDLE v5; // esi@14
  DWORD NumberOfBytesWritten; // [sp+10h] [bp-1A8h]@16
  char v7; // [sp+14h] [bp-1A4h]@13
  __int16 v8; // [sp+2Ch] [bp-18Ch]@13
  char v9[60]; // [sp+78h] [bp-140h]@12
  CHAR Filename; // [sp+B4h] [bp-104h]@9
  __int16 v11; // [sp+C8h] [bp-F0h]@10
  char v12; // [sp+CAh] [bp-EEh]@10

  v1 = 0;
  result = (unsigned int)dword_521798;
  do
  {
    if ( *(_DWORD *)result == a1 )
      break;
    result += 8;
    ++v1;
  }
  while ( result < (unsigned int)&dword_521820 );
  v3 = 8 * v1;
  if ( dword_521798[2 * v1] == a1 )
  {
    if ( dword_520D0C != 1 && (dword_520D0C || dword_520D10 != 1) )
    {
      if ( a1 != 252 )
      {
        if ( !GetModuleFileNameA(0, &Filename, 0x104u) )
        {
          memcpy(&Filename, "<program name unknown>", 0x14u);
          v11 = *(_WORD *)"n>";
          v12 = aProgramNameUnk[22];
        }
        v4 = &Filename;
        if ( strlen(&Filename) + 1 > 0x3C )
        {
          v4 = &v9[strlen(&Filename) + 1];
          strncpy(v4, "...", 3u);
        }
        memcpy(&v7, "Runtime Error!\n\nProgram: ", 0x18u);
        v8 = *(_WORD *)" ";
        strcat(&v7, v4);
        strcat(&v7, "\n\n");
        strcat(&v7, *(const char **)&off_52179C[v3]);
        result = __crtMessageBoxA(&v7, "Microsoft Visual C++ Runtime Library");
      }
    }
    else
    {
      v5 = *(HANDLE *)(dword_538E20 + 72);
      if ( v5 == (HANDLE)-1 )
        v5 = GetStdHandle(0xFFFFFFF4u);
      result = WriteFile(
                 v5,
                 *(LPCVOID *)&off_52179C[v3],
                 strlen(*(const char **)&off_52179C[v3]),
                 &NumberOfBytesWritten,
                 0);
    }
  }
  return result;
}
