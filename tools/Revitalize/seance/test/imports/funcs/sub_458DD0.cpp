{
  signed int result; // eax@3
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; i < 768; ++i )
  {
    result = i;
    *((_BYTE *)this + i) = (signed int)*((_BYTE *)this + i) >> 2;
  }
  return result;
}
