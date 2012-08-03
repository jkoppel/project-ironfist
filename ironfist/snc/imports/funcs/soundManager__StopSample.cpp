{
  signed int i; // [sp+10h] [bp-8h]@3

  if ( !gbNoSound && this->hdidriver )
  {
    AIL_end_sample(a2);
    for ( i = 0; i < 10; ++i )
      DelayMilli(5);
  }
}