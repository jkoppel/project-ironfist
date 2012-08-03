{
  signed int v2; // esi@1

  _lock_file(a2);
  v2 = _ungetc_lk(a1, a2);
  _unlock_file(a2);
  return v2;
}