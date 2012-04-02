int __thiscall sub_4AC340(void *this)
{
  int result; // eax@3
  signed int i; // [sp+14h] [bp-4h]@1

  for ( i = 0; i < 5; ++i )
  {
    result = *((_BYTE *)this + i + 101);
    if ( result != -1 )
    {
      result = *((_BYTE *)this + i + 101);
      if ( result >= 0 )
        result = *((_BYTE *)this + i + 101);
    }
  }
  return result;
}
