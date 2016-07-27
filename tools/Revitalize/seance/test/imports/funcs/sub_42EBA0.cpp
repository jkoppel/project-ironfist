{
  char v0; // [sp+Ch] [bp-2Ch]@3
  int i; // [sp+34h] [bp-4h]@1

  for ( i = 0; i < 100; ++i )
  {
    sprintf(&v0, "Test # %d", i);
    sub_4CAA50(&v0);
    sub_42E880();
  }
}
