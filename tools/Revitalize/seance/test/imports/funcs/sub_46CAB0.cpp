{
  void *v4; // [sp+Ch] [bp-14h]@1
  int v5; // [sp+14h] [bp-Ch]@1
  signed int v6; // [sp+18h] [bp-8h]@1
  int i; // [sp+1Ch] [bp-4h]@1

  v4 = this;
  v6 = 1;
  v5 = 0;
  for ( i = 0; *(_DWORD *)((char *)v4 + 4 * a2 + 13639) > i; ++i )
  {
    if ( v6 & a3 && (char *)v4 + 24234 * a2 + 1154 * i != (void *)-13647 )
    {
      if ( !(*((_BYTE *)v4 + 24234 * a2 + 1154 * i + 13855) & 0x10) )
        v5 += sub_481D30((int)((char *)v4 + 24234 * a2 + 1154 * i + 13647));
    }
    v6 *= 2;
  }
  return v5;
}
