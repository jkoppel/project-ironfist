{
  int v4; // edi@1

  _lock_file((unsigned int)a4);
  v4 = _fread_lk((void *)a1, a2, a3, a4);
  _unlock_file((unsigned int)a4);
  return v4;
}