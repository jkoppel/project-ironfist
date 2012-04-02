{
  CreatureStack *thisa; // [sp+Ch] [bp-18h]@1
  int neighbor; // [sp+10h] [bp-14h]@9
  int nNeighbors; // [sp+14h] [bp-10h]@5
  int v8; // [sp+18h] [bp-Ch]@4
  signed int neighborIdx; // [sp+1Ch] [bp-8h]@7
  int v10; // [sp+20h] [bp-4h]@2

  thisa = this;
  if ( this->creature.creature_flags & TWO_HEXER )
    v10 = 0;
  else
    v10 = 192;
  v8 = 1;
  if ( this->creature.creature_flags & TWO_HEXER )
    nNeighbors = 8;
  else
    nNeighbors = 6;
  for ( neighborIdx = 0; nNeighbors > neighborIdx; ++neighborIdx )
  {
    if ( !CreatureStack::neighboringHexOccupied(thisa, hex, neighborIdx, focusLevel, a5, &neighbor) )
      v10 |= v8;
    v8 *= 2;
  }
  return v10;
}
