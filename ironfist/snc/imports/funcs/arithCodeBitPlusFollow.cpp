{
  int result; // eax@1
  char v3; // [sp+Ch] [bp-8h]@1
  int v4; // [sp+10h] [bp-4h]@1

  v3 = a2;
  v4 = a1;
  result = bsPutBit(a1, a2);
  while ( bitsOutstanding )
  {
    result = bsPutBit(v4, 1 - v3);
    --bitsOutstanding;
  }
  return result;
}