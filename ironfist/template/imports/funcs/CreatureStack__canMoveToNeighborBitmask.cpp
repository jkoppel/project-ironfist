{
  CreatureStack *thisa; // [sp+Ch] [bp-10h]@1
  signed int v4; // [sp+10h] [bp-Ch]@1
  signed int neighborIdx; // [sp+14h] [bp-8h]@1
  int v6; // [sp+18h] [bp-4h]@1

  thisa = this;
  v6 = 0;
  v4 = 1;
  for ( neighborIdx = 0; neighborIdx <= 5; ++neighborIdx )
  {
    if ( !CreatureStack::canMoveToNeighbor(thisa, targHex, neighborIdx) )
      v6 |= v4;
    v4 *= 2;
  }
  return v6 | 0xC0;
}
