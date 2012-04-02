signed int __thiscall sub_435DC0(void *this)
{
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; i < 6; ++i )
  {
    if ( (void *)*((_BYTE *)&byte_5247A0 + i) == this )
      return i;
  }
  return -1;
}
