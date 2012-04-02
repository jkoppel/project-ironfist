int __cdecl fputc(int a1, FILE *a2)
{
  int v2; // eax@1
  int v3; // ebx@2

  _lock_file(a2);
  v2 = a2->_cnt - 1;
  a2->_cnt = v2;
  if ( v2 < 0 )
  {
    v3 = _flsbuf(a1, a2);
  }
  else
  {
    *a2->_ptr = a1;
    v3 = *a2->_ptr++;
  }
  _unlock_file(a2);
  return v3;
}
