{
  int result; // eax@3
  unsigned __int8 v3; // [sp+Ch] [bp-Ch]@1
  int v4; // [sp+10h] [bp-8h]@1
  signed int i; // [sp+14h] [bp-4h]@1

  v3 = a2;
  v4 = a1;
  for ( i = 7; i >= 0; --i )
    result = bsPutBit(v4, ((unsigned int)v3 >> i) & 1);
  return result;
}