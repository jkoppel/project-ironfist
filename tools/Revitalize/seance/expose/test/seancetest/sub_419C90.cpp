signed int __thiscall sub_419C90(void *this, int a2, int a3)
{
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; i < 72; ++i )
  {
    if ( *((_BYTE *)this + 100 * i + 2903) == a2 && *((_BYTE *)this + 100 * i + 2904) == a3 )
      return i;
  }
  return -1;
}
