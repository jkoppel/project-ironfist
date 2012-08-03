{
  int v4; // edi@1
  int result; // eax@2

  v4 = a2;
  do
  {
    result = v4--;
    if ( result <= 0 )
      break;
    result = write_char(a1, a3, a4);
  }
  while ( *(_DWORD *)a4 != -1 );
  return result;
}