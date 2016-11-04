{
  int numVisited; // [sp+10h] [bp-8h]@1
  signed int i; // [sp+14h] [bp-4h]@1

  numVisited = 0;
  for ( i = 0; i < 48; ++i )
  {
    if ( gameObject->obeliskVisitedMasks[i] & (1 << playerIdx) )
      ++numVisited;
  }
  return numVisited;
}
