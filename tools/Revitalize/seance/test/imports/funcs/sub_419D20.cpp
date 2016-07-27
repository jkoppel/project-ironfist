{
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; i < 144; ++i )
  {
    if ( *((_BYTE *)this + 7 * i + 23739) == a2 && *((_BYTE *)this + 7 * i + 23740) == a3 )
      return i;
  }
  return -1;
}
