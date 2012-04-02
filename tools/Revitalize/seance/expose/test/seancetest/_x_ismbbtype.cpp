signed int __cdecl x_ismbbtype(unsigned __int8 a1, int a2, unsigned __int8 a3)
{
  int v3; // ecx@2
  signed int result; // eax@5

  if ( (unsigned __int8)byte_521581[a1] & a3 )
    goto LABEL_9;
  v3 = 0;
  if ( a2 )
    v3 = (unsigned __int16)(a2 & _ctype[a1 + 1]);
  if ( v3 )
LABEL_9:
    result = 1;
  else
    result = 0;
  return result;
}
