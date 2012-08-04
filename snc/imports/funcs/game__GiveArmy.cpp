{
  signed int i; // [sp+14h] [bp-4h]@2

  if ( slot >= 0 )
  {
    i = slot;
    arm->creatureTypes[slot] = creatureType;
    arm->quantities[slot] = 0;
LABEL_14:
    arm->creatureTypes[i] = creatureType;
    arm->quantities[i] += amt;
    return;
  }
  for ( i = 0; i < 5 && arm->creatureTypes[i] != creatureType; ++i )
    ;
  if ( i >= 5 )
  {
    for ( i = 0; i < 5; ++i )
    {
      if ( arm->creatureTypes[i] < 0 )
      {
        arm->quantities[i] = 0;
        break;
      }
    }
  }
  if ( i < 5 )
    goto LABEL_14;
}