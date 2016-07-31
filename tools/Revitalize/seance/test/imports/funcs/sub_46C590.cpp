{
  signed int v3; // [sp+14h] [bp-Ch]@1
  int i; // [sp+18h] [bp-8h]@1
  int v5; // [sp+1Ch] [bp-4h]@1

  v3 = 1;
  v5 = 0;
  for ( i = 0; *(_DWORD *)((char *)this + 4 * a2 + 13639) > i; ++i )
  {
    if ( (char *)this + 24234 * a2 + 1154 * i != (void *)-13647
      && !(*((_BYTE *)this + 24234 * a2 + 1154 * i + 13855) & 0x10)
      && (*((_BYTE *)this + 24234 * a2 + 1154 * i + 13918) || *((_BYTE *)this + 24234 * a2 + 1154 * i + 13920)) )
      v5 |= v3;
    v3 *= 2;
  }
  return v5;
}
