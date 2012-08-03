{
  int result; // eax@3
  int v2; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  v2 = (int)this;
  for ( i = 26; i >= 1; --i )
    result = arithCodeBitPlusFollow(v2, ((unsigned int)bigL >> (i - 1)) & 1);
  return result;
}