{
  signed int i; // [sp+10h] [bp-8h]@1
  int numArtifacts; // [sp+14h] [bp-4h]@1

  numArtifacts = 0;
  for ( i = 0; i < 14; ++i )
  {
    if ( this->artifacts[i] >= 0 )
      ++numArtifacts;
  }
  return numArtifacts;
}
