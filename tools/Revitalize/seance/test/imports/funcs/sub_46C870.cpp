{
  void *v4; // [sp+Ch] [bp-18h]@1
  signed int v5; // [sp+10h] [bp-14h]@1
  signed int i; // [sp+14h] [bp-10h]@1
  signed int v7; // [sp+18h] [bp-Ch]@1
  int v8; // [sp+1Ch] [bp-8h]@4
  signed int v9; // [sp+20h] [bp-4h]@1

  v4 = this;
  v5 = 1;
  v9 = 999999999;
  v7 = -1;
  for ( i = 0; *(_DWORD *)((char *)v4 + 4 * a2 + 13639) > i; ++i )
  {
    if ( v5 & a3 )
    {
      v8 = sub_481D30((int)((char *)v4 + 24234 * a2 + 1154 * i + 13647));
      if ( v9 > (unsigned int)v8 )
      {
        v7 = i;
        v9 = v8;
      }
    }
    v5 *= 2;
  }
  return v7;
}
