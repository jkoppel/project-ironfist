{
  int v6; // eax@1
  int result; // eax@2
  int v8; // edi@2

  v6 = 2 * (a4 + 4 * a1);
  if ( dword_4F3B3C[v6] <= a3 )
  {
    v8 = a5;
    goto LABEL_8;
  }
  result = dword_4F3B38[v6];
  v8 = a5;
  if ( result <= a3 )
    goto LABEL_5;
  if ( !a5 )
    return *(&dword_4F3B38[2 * (a4 + 4 * a1)] + (a2 & 1));
  if ( dword_4F3C58[2 * a4] > a3 )
  {
LABEL_8:
    if ( v8 && a6 )
      a1 = 9;
    return *(&dword_4F3B38[2 * (a4 + 4 * a1)] + (a2 & 1));
  }
LABEL_5:
  if ( a5 )
    result = dword_4F3C58[2 * a4];
  return result;
}
