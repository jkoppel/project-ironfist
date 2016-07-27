{
  signed int i; // [sp+14h] [bp-4h]@2

  if ( slot >= 0 )
  {
    i = slot;
    army->creatureTypes[slot] = creatureType;
    army->quantities[slot] = 0;
LABEL_14:
    army->creatureTypes[i] = creatureType;
    army->quantities[i] += amt;
    return;
  }
  for ( i = 0; i < 5 && army->creatureTypes[i] != creatureType; ++i )
    ;
  if ( i >= 5 )
  {
    for ( i = 0; i < 5; ++i )
    {
      if ( army->creatureTypes[i] < 0 )
      {
        army->quantities[i] = 0;
        break;
      }
    }
  }
  if ( i < 5 )
    goto LABEL_14;
}
