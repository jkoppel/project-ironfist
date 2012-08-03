{
  int v4; // esi@1
  int v5; // edi@1
  int result; // eax@2
  unsigned __int8 *v7; // eax@3

  v4 = a1;
  v5 = a2;
  do
  {
    result = v5--;
    if ( result <= 0 )
      break;
    v7 = (unsigned __int8 *)v4++;
    result = write_char(*v7, a3, a4);
  }
  while ( *(_DWORD *)a4 != -1 );
  return result;
}