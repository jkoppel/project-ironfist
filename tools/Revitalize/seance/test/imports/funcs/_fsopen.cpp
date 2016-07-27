{
  int v3; // esi@1
  int result; // eax@2
  int v5; // edi@3

  v3 = _getstream();
  if ( v3 )
  {
    v5 = _openfile(a1, a2, a3, v3);
    _unlock_file(v3);
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}
