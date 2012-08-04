{
  int result; // eax@1
  __int16 v2; // [sp+Ch] [bp-8h]@1
  int a1a; // [sp+10h] [bp-4h]@3

  v2 = a1;
  result = 32 * a1;
  if ( dword_532CF0[24 * a1] != -1 )
  {
    SetCommState((HANDLE)dword_532CF0[24 * a1], (LPDCB)&dword_532CF0[24 * a1 + 2]);
    SetCommTimeouts((HANDLE)dword_532CF0[24 * v2], (LPCOMMTIMEOUTS)&dword_532CF0[24 * v2 + 9]);
    CloseHandle((HANDLE)dword_532CF0[24 * v2]);
    dword_532CF0[24 * v2] = -1;
    while ( 1 )
    {
      a1a = pop_node((int)&dword_532D40[24 * v2]);
      if ( !a1a )
        break;
      BaseFree((void *)a1a, (int)"F:\\h2xsrc\\Source\\comwin.cpp", word_51DF7C + 13);
    }
    while ( 1 )
    {
      result = pop_node((int)&dword_532D48[24 * v2]);
      if ( !result )
        break;
      BaseFree((void *)result, (int)"F:\\h2xsrc\\Source\\comwin.cpp", word_51DF7C + 17);
    }
  }
  return result;
}