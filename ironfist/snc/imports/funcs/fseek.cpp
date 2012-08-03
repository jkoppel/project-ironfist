{
  int v3; // esi@1

  _lock_file(a1);
  v3 = _fseek_lk(a1, a2, a3);
  _unlock_file(a1);
  return v3;
}