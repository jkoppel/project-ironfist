{
  HERO_CONSTANTS i; // [sp+10h] [bp-4h]@1

  for ( i = 0; i < MAX_ARTIFACTS; ++i )
  {
    if ( this->artifacts[i] == artifact )
      return 1;
  }
  return 0;
}
