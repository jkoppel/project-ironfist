{
  __int16 v5; // [sp+14h] [bp-4h]@1

  *(_BYTE *)&byte_527218 = a2;
  byte_527219 = a3;
  byte_52721A = 0;
  byte_52721B = a4;
  v5 = 0;
  word_52721C = 0;
  memcpy((char *)&byte_527218 + 6, a1, a4);
  sub_46DCF0((int)&v5, (int)&byte_527218, a4 + 6);
  word_52721C = v5;
  return a4 + 6;
}
