int __cdecl fgetc(FILE *a1)
{
  int v1; // eax@1
  int v2; // ebx@2

  _lock_file(a1);
  v1 = a1->_cnt - 1;
  a1->_cnt = v1;
  if ( v1 < 0 )
    v2 = _filbuf(a1);
  else
    v2 = *a1->_ptr++;
  _unlock_file(a1);
  return v2;
}
