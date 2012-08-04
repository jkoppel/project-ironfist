{
  int v1; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  v1 = (int)this;
  bigL = 0;
  bigR = 33554432;
  bigD = 0;
  for ( i = 1; i <= 26; ++i )
    bigD = bsGetBit(v1) + 2 * bigD;
}