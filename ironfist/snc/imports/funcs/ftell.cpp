{
  int v1; // esi@1

  _lock_file(a1);
  v1 = _ftell_lk(a1);
  _unlock_file(a1);
  return v1;
}