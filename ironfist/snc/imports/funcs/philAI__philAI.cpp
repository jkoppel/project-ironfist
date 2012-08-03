{
  signed int i; // [sp+10h] [bp-4h]@1

  for ( i = 0; i < 6; ++i )
  {
    giBuildShipyard[i] = -1;
    giBuildBoat[i] = -1;
    giBuildBoatStuffTurn[i] = 0;
  }
  return this;
}