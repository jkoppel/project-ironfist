signed int __cdecl sub_4AA1C0()
{
  signed int i; // [sp+Ch] [bp-4h]@1

  for ( i = 1; i <= 43; ++i )
  {
    if ( !sub_4AA210(i) )
      return 0;
  }
  return 1;
}
