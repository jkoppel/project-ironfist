int __cdecl sub_4BD380()
{
  int result; // eax@2
  int a1; // [sp+10h] [bp-10h]@3
  DWORD NumberOfBytesWritten; // [sp+14h] [bp-Ch]@9
  HANDLE *v3; // [sp+18h] [bp-8h]@1
  unsigned int i; // [sp+1Ch] [bp-4h]@6

  v3 = (HANDLE *)dword_532CF0;
  while ( 1 )
  {
    result = (int)v3;
    if ( *v3 == (HANDLE)-1 )
      break;
    result = sub_4BC830((int)(v3 + 22));
    a1 = result;
    if ( !result )
    {
      result = sub_4BC830((int)(v3 + 20));
      a1 = result;
    }
    if ( !a1 )
      break;
    for ( i = 0; *v3 != (HANDLE)-1 && *(_WORD *)(a1 + 8) > i; i += NumberOfBytesWritten )
    {
      if ( !WriteFile(*v3, (LPCVOID)(a1 + i + 10), *(_WORD *)(a1 + 8) - i, &NumberOfBytesWritten, 0) )
        sub_4BC8B0("Write communications data");
    }
    KBFree((void *)a1, (int)"F:\\h2xsrc\\Source\\comwin.cpp", word_51E050 + 28);
  }
  return result;
}
